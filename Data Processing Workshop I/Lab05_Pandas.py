
# coding: utf-8

# Before you turn this problem in, make sure everything runs as expected. First, **restart the kernel** (in the menubar, select Kernel$\rightarrow$Restart) and then **run all cells** (in the menubar, select Cell$\rightarrow$Run All).
# 
# Make sure you fill in any place that says `YOUR CODE HERE` or "YOUR ANSWER HERE", as well as your name and ID below:

# In[ ]:


NAME = "Jack"
ID = "1930026143"


# ---

# # Lab 5
# ## Due: 2021.04.02 13:00 pm

# ### Exercise1
# In the following python function definition, we want to create a one-dimensional array-like pandas series object (out_series) containing an array of data (in_list in the augument) using Pandas package and then convert the Panda module Series back to a Python list (out_list) and output them. Please finish the code and test output_list is the same as in_list.  

# In[8]:


import pandas as pd
in_list = [2,4,6,8,10]


# In[18]:


def series_and_list(in_list):
    # YOUR CODE HERE
    output_series = pd.Series(in_list)
    output_list = output_series.values
    return output_series,output_list


# In[25]:


#You can write your test code here.
print((in_list == series_and_list(in_list)[1]).all())


# ### Exercise 2 
# Create a DataFrame from a dictionary and convert the first column of a DataFrame as a **Series**.
# 
# Example:  
# 
# Original DataFrame
# 
# 
# | |col1 | col2|col3|
# |----|----|----|----|
# |0    | 1    | 4   |  7|
# |1    | 2    | 5     |5|
# |2     |3     |6     |8|
# |3     |4    | 9  |  12|
# |4     |7     |5     |1|
# |5   | 11    | 0   | 11|  
# 
# 
# Ouput:
# 
#   
#     0     4  
#     1     5  
#     2     6  
#     3     9  
#     4     5  
#     5     0    
# 
# Name: col2, dtype: int64
# <class 'pandas.core.series.Series'>

# In[61]:


import pandas as pd
def create_df2series(data):
        # YOUR CODE HERE
        frame = pd.DataFrame(d)
        s1 = frame.col2
        return s1


# In[63]:


#You can write your own test here.
pd.DataFrame(create_df2series(d)).columns=='col2'


# In[62]:


d = {'col1': [1, 2, 3, 4, 7, 11], 'col2': [4, 5, 6, 9, 5, 0], 'col3': [7, 5, 8, 12, 1,11]}
assert pd.DataFrame(create_df2series(d)).columns=='col2'


# ### Exercise 3
# Create a subset of a given series below in which the value are between 2 and  8.
# 
# Input:
# 
#     0     0
#     1     1
#     2     2  
#     3     3  
#     4     4  
#     5     5  
#     6     6  
#     7     7  
#     8     8
#     9     9
# 
# dtype: int64
# 
# Ouput:
# 
#     2     2  
#     3     3  
#     4     4  
#     5     5  
#     6     6  
#     7     7  
#     8     8
# 
# dtype: int64

# In[76]:


import pandas as pd
def find_subset(input_s):
    # YOUR CODE HERE
    ser = pd.Series(input_s)
    subset_s = ser[(ser >= 2) & (ser <= 8)]
    return subset_s


# In[77]:


#You can write your own tests here.
find_subset(range(10))


# ### Exercise 4
# 
# Write a program to create Series given by the data list [1,2,3,4,5] and index list ['A', 'B', 'C', 'D', 'E'] ,return this series as **s1** ,  
# then change the order of index by the given a new index list['B','A','D','C','E'], return this series as **s2**.   
# Then, sort the index by alphabetic order and return this series as **s3**.

# In[113]:


import pandas as pd
def create_series(data_list,index_list):
    # YOUR CODE HERE
    s1 = pd.Series(data_list,index = index_list)
    print(s1['B'])
    s2 = pd.Series([s1['B'],s1['A'],s1['D'],s1['C'],s1['E']],index = ['B','A','D','C','E'])
    s3 = s1.sort_index()
    return s1,s2,s3


# In[114]:


data_list = [1,2,3,4,5]
indx_list = ['A', 'B', 'C', 'D', 'E']
s1,s2,s3=create_series(data_list,indx_list)


# In[115]:


#You can write your own tests here.
print(s1,s2,s3)


# In[116]:


d1 = {'A': [1], 'B': [2], 'C': [3],'D':[4],'E':[5]}

assert ((s1 == pd.DataFrame(d1)).all()).all()


# In[117]:


d2 = { 'B': [2], 'A': [1], 'D':[4],'C': [3],'E':[5]}

assert ((s2 == pd.DataFrame(d2)).all()).all()


# In[118]:


d3 = {'A': [1], 'B': [2], 'C': [3],'D':[4],'E':[5]}

assert ((s3 == pd.DataFrame(d3)).all()).all()


# ### Exercise 5
# 
# Write a program with Pandas to create a DataFrame from the given dictionary and labels and select the rows where the score is missing, i.e. is NaN.
# 

# In[147]:


import pandas as pd
import numpy as np
exam_data  = {'name': ['Anastasia', 'Dima', 'Katherine', 'James', 'Emily', 'Michael', 'Matthew', 'Laura', 'Kevin', 'Jonas'],
        'score': [12.5, 9, 16.5, np.nan, 9, 20, 14.5, np.nan, 8, 19],
        'attempts': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
        'qualify': ['yes', 'no', 'yes', 'no', 'no', 'yes', 'yes', 'no', 'no', 'yes']}
labels = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j']


# In[174]:


def find_rows(exam_data , labels):
    # YOUR CODE HERE
    frame = pd.DataFrame(exam_data)
    frame['labels'] = labels

    ans_rows = frame[frame['score']!=frame['score']]
    print(ans_rows)
    return ans_rows


# In[176]:


#You can write your own tests here.


# In[177]:


df = find_rows(exam_data , labels)
assert(df['name']==['James', 'Laura']).all()


# ### Exercise 6
# 
# Write a program with Pandas to create a data frame from the given dictionary and index and then insert a new column 'color' in existing DataFrame.

# In[190]:


import pandas as pd
import numpy as np
exam_data  = {'name': ['Anastasia', 'Dima', 'Katherine', 'James', 'Emily', 'Michael', 'Matthew', 'Laura', 'Kevin', 'Jonas'],
        'score': [12.5, 9, 16.5, np.nan, 9, 20, 14.5, np.nan, 8, 19],
        'attempts': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
        'qualify': ['yes', 'no', 'yes', 'no', 'no', 'yes', 'yes', 'no', 'no', 'yes']}
labels = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j']
# insert a new column called color into the dataframe
color = ['Red','Blue','Orange','Red','White','White','Blue','Green','Green','Red']


# In[195]:


def insert_column(exam_data , labels):
    # YOUR CODE HERE
    df = pd.DataFrame(exam_data)
    df['labels'] = labels
    df['color'] = ['Red','Blue','Orange','Red','White','White','Blue','Green','Green','Red']
    return df
insert_column(exam_data , labels)


# In[180]:


#You can write your own tests here.


# ### Exercise 7
# Write a program with Pandas to convert a given list of lists into a Dataframe, return as **df**, and remove the first 2 rows, return the remaining DataFrame as **s2**.

# In[215]:


import pandas as pd
def remove_first2rows(input_data , labels):
    # YOUR CODE HERE
    df = pd.DataFrame(input_data, index = labels)
    s2 = df.iloc[2:, :]

    return df,s2


# In[218]:


#You can write your own tests here.
input_data1 = [1, 3, 2, 3, 2, 3, 1, 1, 2, 1]
labels1 = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j']
remove_first2rows(input_data1,labels1)[0]
remove_first2rows(input_data1,labels1)[1]


# ### Exercise 8
# 
# Write a  program to create a DataFrame from given information, and then select all columns except 'col3', return this Dataframe.

# In[ ]:


import pandas as pd
d = {'col1': [1, 2, 3, 4, 7], 'col2': [4, 5, 6, 9, 5], 'col3': [7, 8, 12, 1, 11]}


# In[231]:


def create_dataframe(d):
    # YOUR CODE HERE
    frame = pd.DataFrame(d)
    df = frame.iloc[:,:2]
    return df


# In[232]:


#You can write your own tests here.
create_dataframe(d)


# In[259]:


assert create_dataframe(d)['col2'].iloc[2]==6


# ### Exercise 9
# 
# Consider the medical data generated in Section 2.3 of 08_Pandas_part2.ipynb:

# In[260]:


import numpy as np
# hierarchical indices and columns
index = pd.MultiIndex.from_product([[2013, 2014], [1, 2]],
                                   names=['year', 'visit'])
columns = pd.MultiIndex.from_product([['Bob', 'Guido', 'Sue'], ['HR', 'Temp']],
                                     names=['subject', 'type'])

# mock some data
data = np.round(np.random.randn(4, 6), 1)
data[:, ::2] *= 10
data += 37

# create the DataFrame
health_data = pd.DataFrame(data, index=index, columns=columns)
health_data


# Calculate the maximum heart rate (HR) and temperature (Temp) of each person for all visits for all years. The result should be a conventionally indexed DataFrame with rows indicating the type and column labels indicating person name in alphabetical order.

# In[262]:


def HR_TEMP_Max_Namelist():
    # YOUR CODE HERE
    HR_max = health_data.max(level='year')
    print(HR_max)
    ans = HR_max.sort_index(axis=1)
    return ans
HR_TEMP_Max_Namelist()


# In[ ]:


#You can write your own tests here.

