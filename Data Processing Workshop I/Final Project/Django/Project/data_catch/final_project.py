import sqlalchemy
import pandas as pd
import os
import time
from sqlalchemy.sql.expression import label
HOSTNAME = "127.0.0.1"
PORT = "3306"
DATABASE = "final"
USERNAME = "root"
PASSWORD = "xsjxsy1014"
DB_URl = "mysql+pymysql://{username}:{password}@{host}:{port}/{db}?charset=utf8".\
    format(username=USERNAME,password=PASSWORD,host=HOSTNAME,port=PORT,db=DATABASE)
engine=sqlalchemy.create_engine(DB_URl,pool_size=0,pool_pre_ping=True)
conn=engine.connect()#give the connection
metadata = sqlalchemy.MetaData(engine)#create metadata by using engine
company=sqlalchemy.Table('account_company',metadata,autoload=True)
job=sqlalchemy.Table('account_job',metadata,autoload=True)
#print(eval(pd.read_table('D:\paChong\job\阿里巴巴集团__阿里集团-后端C++开发工程师-北京.txt').columns[0])['company_name'])
#读取所有的文件名
file_names=[]
cid=200001
jid=1001
#use a company list to remove duplicate
companyN={}
start=time.time()
for i in os.walk('G:\Desktop\python\Django\Project\data_catch\job\job'):
    file_names.append(i)
for i in file_names[0][2]:
    #try:
        if jid>2000:#max job of a company support is 1000
            jid=1001
        class_id=4
        path1="G:/Desktop/python/Django/Project/data_catch/job/job/"+i
        dic=eval(pd.read_table(path1).columns[0])
        company_name=dic['company_name']
        job_name=dic['job_name']
        bonus=dic['bonus']
        geo=dic['geography']
        salary=dic['salary']
        detail_url=dic['detail_url']
        if company_name not in companyN.keys():
            query1=sqlalchemy.insert(company).values(company_id=cid,company_name=company_name,city=geo)
            ResultProxy=conn.execute(query1)
            companyN[company_name]=cid
            cid+=1
            jid=1001
        print(job_name)
        if 'java' in job_name.lower():
            class_id=0
        if 'python' in job_name.lower():
            class_id=1
        if 'c++' in job_name or 'C++' in job_name:
            class_id=2
        if 'php' in job_name.lower():
            class_id=3
        job_id=int(str(jid)+str(companyN[company_name]))
        query2=sqlalchemy.insert(job).values(job_id=job_id,job_name=job_name,salary=salary,label=str(bonus),class_id=class_id,detail_URL=detail_url)
        ResultProxy=conn.execute(query2)
        jid+=1
        print(class_id)
        print('导入成功！')
    # except:
    #     print('not given!')
end=time.time()
print('time cost :',end-start)
conn.close()
engine.dispose()