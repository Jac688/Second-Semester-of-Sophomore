
# coding: utf-8

# Before you turn this problem in, make sure everything runs as expected. First, **restart the kernel** (in the menubar, select Kernel$\rightarrow$Restart) and then **run all cells** (in the menubar, select Cell$\rightarrow$Run All).
# 
# Make sure you fill in any place that says `YOUR CODE HERE` or "YOUR ANSWER HERE", as well as your name and collaborators below:

# In[3]:


NAME = "Jack"
ID = "1930026143"


# ---

# # Lab 4
# 
# ## Due: 2021-03-26 13:00 pm

# In[14]:


import numpy as np


# # Exercise 1:
# 
# Create an one dimensional array x with 100 integers, each integer is randomly selected from 0-9 with equal probability.  
# hint:randint

# In[62]:


#Todo
def create_array():
    # YOUR CODE HERE
    return np.random.randint(0, 10, 100)
    raise NotImplementedError()


# In[61]:


x=create_array()
print(x)


# In[20]:


assert create_array().all()>=0


# ### Exercise 2: 
# 
# Reverse the elements in x, i.e., first element becomes last, and so on...
# 

# In[40]:


#TODO for exercise 2
def reverse_array(x):
    # YOUR CODE HERE
    
    for i in range(int(len(x)/2)):
        temp = x[i]
        x[i] = x[-(i+1)]
        x[len(x)-1-i] = temp
    return x
    raise NotImplementedError()


# ### Exercise 3:
# 
# Find indices of non-zero elements from x, and put the indices into variable y.
# How many elements in your array x are non-zeros?

# In[53]:


#TODO for exercise 4
def find_nonzeros(x):
    # YOUR CODE HERE
    lst = []
    cnt = 0
    for i in range(len(x)):
        if x[i] != 0:
            lst.append(i)
            cnt+=1
    y = np.array([i for i in lst])
    print(y)
    return cnt
    raise NotImplementedError()
find_nonzeros([1,2,4,5,6,0])


# ### Exercise 4:
# 
# Find the mean of the original random array x.

# In[54]:


#TODO for exercise 4
def find_mean(x):
    # YOUR CODE HERE
    sum = 0
    for i in range(len(x)):
        sum+=x[i]
    return sum/len(x)
    raise NotImplementedError()
find_mean([1,2,3,4])


# ### Exercise 5:
# 
# Count how many elements are larger than 5 (>5) in the array of x

# In[87]:


# Todo for exercise 5
def count_larger5(x):
    # YOUR CODE HERE
    cnt = 0
    for i in range(len(x)):
        if x[i] > 5:
            cnt+=1
    return cnt
    raise NotImplementedError()
    
count_larger5(np.array([6,7,8,9,3,6]))


# ### Exercise 6
# 
# Reshape the array x into a two dimensional 10x10 matrix, and calculate the square root of each element, save the result to another 10x10 matrix z.

# In[73]:


#TODO for exercise 6
import math
def res_cal_squareRoot(x):
    # YOUR CODE HERE
    lst = []
    y = x.reshape((10, 10))
    return  np.sqrt(y)
    raise NotImplementedError()
                       


# In[74]:


z=res_cal_squareRoot(x)


# ## Exercise 7
# 
# Find out all the elements that are larger than 1 in z, replace them with 1.2

# In[85]:


# Todo for exercise 7
# Hint: use fancy indexing 

def find_replace(z):
    # YOUR CODE HERE
    return np.where(z > 1, 1.2, z)
    raise NotImplementedError()
find_replace(np.array([1,2,3,4,5,7,0.2]))


# ## Exercise 8
# We created a random matrix X of two-dimensional normal distribution with the shape of (100,2).  
# 1. Split this matrix into two parts randomly, 80% for trainning, and remaining 20% for testing.
# 2. Plot the points (train, test) in a graph with different colors, such as red for trainning, yellow for testing.

# In[45]:


get_ipython().run_line_magic('matplotlib', 'inline')
import matplotlib.pyplot as plt
import seaborn; seaborn.set()
import numpy as np

mean = [0,0]
cov = [[1,2], [2,5]]
X = np.random.multivariate_normal(mean, cov, 100)
plt.scatter(X[:,0], X[:,1])

# To do for exerise 8
# YOUR CODE HERE
indices1 = np.random.choice(X.shape[0], 20, replace=False)
indices2 = [i  for i in range(100) if i not in indices1]

test = X[indices1]
train = X[indices2]
plt.scatter(test[:,0],test[:,1],facecolor='y')
plt.scatter(train[:,0],train[:,1],facecolor='r')


# ### Exercise 9
# 
# For the "count rainy days in seatle" example in lecture notes 05, do the following:
# 1. What's the percentage of rainy days in year 2014 in seatle?
# 2. How many days are rainy but with less than 0.3 inches rain?
# 3. Suppose autumn is from Sept. 20 to Dec. 22, what is the MEAN precipitation in autum 2014 in seatle? 
# 4. What is the MEAN precipitation in RAINY days in seatle 2014? 
# 5. What is the MEAN precipitation in NON-AUTUMN days in seatle 2014?

# In[28]:


import numpy as np
import pandas as pd

# use pandas to extract rainfall inches as a NumPy array
rainfall = pd.read_csv('Seattle2014.csv')['PRCP'].values
print(rainfall)
inches = rainfall / 254.0  # 1/10mm -> inches
rainy = (inches > 0)
days = np.arange(365)


#Todo for exercise 9.1
#return the percentage of rainy days in year 2014
def calc_rainydays():
    # YOUR CODE HERE
    rainydays = np.sum(rainy == true)
    return rainydays
    raise NotImplementedError()


# In[24]:


#Todo for exercise 9.2
#rainy days with less than 0.3 inches rain 
def calc_lessraindays():
    # YOUR CODE HERE
    lessraindays = np.sum(0.3>=rainfall>0)
    return lessraindays
    raise NotImplementedError()


# In[30]:


#Todo for exercise 9.3
#MEAN precipitation in autumn 2014 in seatle
def mean_autumn():
    # YOUR CODE HERE
    day_rainy = dstack(days, rainfall)
    autumn_rainy = day_rainy[np.where((day_rainy[:,0]>263) &(day_rainy[:,0]) <356)]
    avg = np.mean(autumn_rainy)
    return avg[:,1]
    
    


# In[26]:


#Todo for exercise 9.4
#MEAN precipitation in RAINY days in seatle 2014
def mean_rainydays():
    # YOUR CODE HERE
    day_rainy = dstack(rainy,rainfall)
    raifall_rainy = day_rainy[np.where(day_rainy[:,0]==True)]
    avg = np.mean(autumn_rainy)
    return avg[:,1]
    raise NotImplementedError()


# In[ ]:


#Todo for exercise 9.5
#MEAN precipitation in NON-AUTUMN days in seatle 2014
def mean_nonautumn():
    # YOUR CODE HERE
    day_rainy = dstack(days, rainfall)
    non_autumn_rainy = day_rainy[np.where((day_rainy[:,0]<=263) &(day_rainy[:,0])>=356)]
    avg = np.mean(non_autumn_rainy)
    return avg[:,1]
    raise NotImplementedError()


# In[ ]:


q1

