# Programmer: Jack
# Student ID: 1930026143
# Date: 2020/1/24
# Requirements:
import warnings
warnings.filterwarnings('ignore')

#importing the libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

cars = pd.read_csv('CarPrice_Assignment.csv')
cars.head()

# cars.info
# cars.shape
# cars.info()
# cars.describe()

cars
CompanyName = cars['CarName'].apply(lambda x : x.split(' ')[0])
cars.insert(3,"CompanyName",CompanyName)
cars.drop(['CarName'],axis=1,inplace=True)
cars.head()
cars.CompanyName = cars.CompanyName.str.lower()
print(cars.head())

plt.figure(figsize=(20,10))

plt.subplot(1,2,1)
plt.title('Car Price Distribution Plot')
# 把y转换成更加近似于正态分布
sns.distplot(np.sqrt(np.log(cars.price+1)), color = 'green')
# sns.distplot(np.sqrt(np.log(cars.price+1)), color = 'green')

plt.subplot(1,2,2)
plt.title('Car Price Spread')
sns.boxplot(y=cars.price)

# plt.show()

# fin的the relationship between the price and cname, fueltype and type of cars
df = pd.DataFrame(cars.groupby(['CompanyName'])['price'].mean().sort_values(ascending = False))
df.plot.bar()
plt.title('Company Name vs Average Price')
# plt.show()

df = pd.DataFrame(cars.groupby(['fueltype'])['price'].mean().sort_values(ascending = False))
df.plot.bar()
plt.title('Fuel Type vs Average Price')
# plt.show()

df = pd.DataFrame(cars.groupby(['carbody'])['price'].mean().sort_values(ascending = False))
df.plot.bar()
plt.title('Car Type vs Average Price')
# plt.show()


def scatter(x, pos):
    plt.subplot(4, 2, pos)
    plt.scatter(cars[x], cars['price'], color='green')
    plt.title(x + ' vs Price')
    plt.ylabel('Price')
    plt.xlabel(x)


plt.figure(figsize=(10, 20))
scatter('carlength', 1)
scatter('carwidth', 2)
scatter('carheight', 3)
scatter('curbweight', 4)
plt.tight_layout()

def rela(x,y,z):
    sns.pairplot(cars, x_vars=[x,y,z], y_vars='price',size=4, aspect=1, kind='scatter')
    # plt.show()

rela('enginesize', 'boreratio', 'stroke')
rela('compressionratio', 'horsepower', 'peakrpm')
rela('wheelbase', 'citympg', 'highwaympg')

cars['price'] = cars['price'].astype('int')
temp = cars.copy()
table = temp.groupby(['CompanyName'])['price'].mean()
temp = temp.merge(table.reset_index(), how='left',on='CompanyName')
bins = [0,10000,20000,40000]
cars_bin=['Budget','Medium','Highend']
cars['carsrange'] = pd.cut(temp['price_y'],bins,right=False,labels=cars_bin)
cars.head()

'''
Inference :
    enginesize, boreratio, horsepower, wheelbase - seem to have a significant positive correlation with price.
    citympg, highwaympg - seem to have a significant negative correlation with price.
'''

cars['fueleconomy'] = (0.55 * cars['citympg']) + (0.45 * cars['highwaympg'])


cars_lr = cars[['price', 'fueltype', 'aspiration','carbody', 'drivewheel','wheelbase',
                  'curbweight', 'enginetype', 'cylindernumber', 'enginesize', 'boreratio','horsepower',
                    'fueleconomy', 'carlength','carwidth', 'carsrange']]
cars_lr.head()
sns.pairplot(cars_lr)
# plt.show()
# Defining the map function
'''
significant: 
- Car Range 
- Engine Type 
- Fuel type 
- Car Body 
- Aspiration 
- Cylinder Number 
- Drivewheel 
- Curbweight 
- Car Length
- Car width
- Engine Size 
- Boreratio 
- Horse Power 
- Wheel base 
- Fuel Economy 
'''
def dummies(x,df):
    temp = pd.get_dummies(df[x], drop_first = True)
    df = pd.concat([df, temp], axis = 1)
    df.drop([x], axis = 1, inplace = True)
    return df
# Applying the function to the cars_lr

cars_lr = dummies('fueltype',cars_lr)
cars_lr = dummies('aspiration',cars_lr)
cars_lr = dummies('carbody',cars_lr)
cars_lr = dummies('drivewheel',cars_lr)
cars_lr = dummies('enginetype',cars_lr)
cars_lr = dummies('cylindernumber',cars_lr)
cars_lr = dummies('carsrange',cars_lr)

from sklearn.feature_selection import RFE
from sklearn.linear_model import LinearRegression
import statsmodels.api as sm
from statsmodels.stats.outliers_influence import variance_inflation_factor

from sklearn.model_selection import train_test_split

np.random.seed(0)
df_train, df_test = train_test_split(cars_lr, train_size = 0.7, test_size = 0.3, random_state = 100)
from sklearn.preprocessing import MinMaxScaler

scalar = MinMaxScaler()
num_vars = ['wheelbase', 'curbweight', 'enginesize', 'boreratio', 'horsepower','fueleconomy','carlength','carwidth','price']
df_train[num_vars] = scalar.fit_transform(df_train[num_vars])

plt.figure(figsize = (30, 25))
sns.heatmap(df_train.corr(), annot = True, cmap="YlGnBu")
# plt.show()
# Highly correlated variables to price are - curbweight, enginesize, horsepower, carwidth and highend

X_train = df_train
y_train = df_train.pop('price')
print(y_train)

# 特征选择，移除低方差特征，移除方差不满足一些阈值的一些x
lm = LinearRegression()
lm.fit(X_train,y_train)
rfe = RFE(lm, 10)
rfe = rfe.fit(X_train, y_train)

rfe_list = list(zip(X_train.columns,rfe.support_,rfe.ranking_))
print(rfe_list)

X_train_rfe = X_train[X_train.columns[rfe.support_]]

# 建立模型，观察数值
def build_model(X, y):
    X = sm.add_constant(X)  # Adding the constant
    lm = sm.OLS(y, X).fit()  # fitting the model
    print(lm.summary())  # model summary
    return X

# 共线性判断
def checkVIF(X):
    vif = pd.DataFrame()
    vif['Features'] = X.columns
    vif['VIF'] = [variance_inflation_factor(X.values, i) for i in range(X.shape[1])]
    vif['VIF'] = round(vif['VIF'], 2)
    vif = vif.sort_values(by="VIF", ascending=False)
    return (vif)
'''
F统计量的p值非常小，拒绝原假设，说明线性关系显著
两个回归系数的t统计量p值均为0，拒绝原假设，说明回归系数也都显著
'''

# delete the twelve and fueleconomy
X_train_new = build_model(X_train_rfe,y_train)
X_train_new = X_train_rfe.drop(["twelve"], axis = 1)
X_train_new = build_model(X_train_new,y_train)
X_train_new = X_train_new.drop(["fueleconomy"], axis = 1)

# curbweight vif > 5
checkVIF(X_train_new)
X_train_new = X_train_new.drop(["curbweight"], axis = 1)
X_train_new = build_model(X_train_new,y_train)
print(checkVIF(X_train_new))

# sedan vif > 5
X_train_new = X_train_new.drop(["sedan"], axis = 1)
X_train_new = build_model(X_train_new,y_train)
checkVIF(X_train_new)

# wagon p-value is 0.366>0.05
X_train_new = X_train_new.drop(["wagon"], axis = 1)
X_train_new.to_csv('G:/Desktop/x_train.csv')
y_train.to_csv('G:/Desktop/y_train.csv')
X_train_new = build_model(X_train_new,y_train)


checkVIF(X_train_new)
print(X_train_new)

lm = sm.OLS(y_train,X_train_new).fit()
y_train_price = lm.predict(X_train_new)
fig = plt.figure()
sns.distplot((y_train - y_train_price), bins = 20)
fig.suptitle('Error Terms', fontsize = 20)                  # Plot heading
plt.xlabel('Errors', fontsize = 18)

# pp plot
# residual = y_train - y_train_price
# pq = sm.ProbPlot(residual)
# pq.qqplot(line='q')
# var1 = np.array(X_train_new)[:,1]
# plt.figure(figsize = (30, 25))
# plt.scatter(np.array(X_train_new)[:,1], residual)
# plt.hlines(y = 0,
# xmin = np.min(var1),
# xmax = np.max(var1),
# color = 'red',
# linestyles = '--')
# plt.xlabel('var0')
# plt.ylabel('residual')
plt.show()

num_vars = ['wheelbase', 'curbweight', 'enginesize', 'boreratio', 'horsepower','fueleconomy','carlength','carwidth','price']
df_test[num_vars] = scalar.fit_transform(df_test[num_vars])

y_test = df_test.pop('price')
X_test = df_test

# Now let's use our model to make predictions.
X_train_new = X_train_new.drop('const',axis=1)
# Creating X_test_new dataframe by dropping variables from X_test
X_test_new = X_test[X_train_new.columns]

# Adding a constant variable
X_test_new = sm.add_constant(X_test_new)
y_pred = lm.predict(X_test_new)
X_train_new = sm.add_constant(X_train_new)
y_pred_train = lm.predict(X_train_new)

from sklearn.metrics import r2_score
train_score = r2_score(y_train, y_pred_train)
print(train_score)
test_score = r2_score(y_test, y_pred)
print(test_score)

fig = plt.figure()
plt.scatter(y_test,y_pred)
fig.suptitle('y_test vs y_pred', fontsize=20)              # Plot heading
plt.xlabel('y_test', fontsize=18)                          # X-label
plt.ylabel('y_pred', fontsize=16)







