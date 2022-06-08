
# coding: utf-8

# Before you turn this problem in, make sure everything runs as expected. First, **restart the kernel** (in the menubar, select Kernel$\rightarrow$Restart) and then **run all cells** (in the menubar, select Cell$\rightarrow$Run All).
# 
# Make sure you fill in any place that says `YOUR CODE HERE` or "YOUR ANSWER HERE", as well as your name and ID below:

# In[ ]:


NAME = "Jack"
ID = "1930026143"


# ---

# # Assignment 2
# ## Due：2021-04-01 13：00 pm

# Q1.Write a NumPy program to remove all common values of the second array from the first one.

# In[78]:


import numpy as np

def remove_common_values(array1, array2):

    # YOUR CODE HERE
    common = np.intersect1d(array1,array2)
    for i in common:
        array1 = array1[np.where(array1[:]!=i)]
    res = array1
    return res


# Hint:
# 
# you may use np.intersect1d to fing out all common elements indices, and then delete them from the first array.

# In[79]:


import numpy as np
array1 = np.array([0, 10, 20, 40, 60])
array2 = [10, 30, 40]
assert (remove_common_values(array1, array2)==[0,20,60]).all()


# Q2.Write a NumPy program to construct an array by repeating n times, and then reverse the array.
# 
# Sample array: 
# [1, 2, 3, 4]
# 
# Expected Output:
# 
# First, repeating 2 times 
# [1 2 3 4 1 2 3 4]
# 
# then reverse it , the result:
# [4 3 2 1 4 3 2 1]
# 
# Hint:
# 
#  You may use np.tile() to repeat array elements.

# In[37]:


def repeat_reverse_array(ori_arr,n):
    # YOUR CODE HERE
    arr = ori_arr
    for i in range(n-1):
        c = np.copy(arr)
        ori_arr = np.concatenate([ori_arr, c])

    res = ori_arr[::-1]
    return res


# In[38]:


ori_arr=np.array([1,2,3,4])

res =repeat_reverse_array(ori_arr,3)
assert (res==[4, 3, 2, 1, 4, 3, 2, 1, 4, 3, 2, 1]).all()


# Q3.Write a NumPy program to remove the maximum and minimum values along the given axis of an array.
# 

# In[53]:


import numpy as np
def remove_min_max_value(array3):
    # YOUR CODE HERE
    array3 = np.array(array3)
    dmax = np.max(array3)
    dmin = np.min(array3)
    res = array3[np.where((array3[:]!=dmin) & (array3[:]!=dmax))]
    return res


# In[55]:


test1=[1, 2, 3, 4, 5, 6]
assert (remove_min_max_value(test1)==[2,3,4,5]).all()


# Q4.Find out all the elements that are between 3 and 8 in an array .

# In[58]:


import numpy as np
def array_operation(array4):
    # YOUR CODE HERE
    new_array = array4[np.where((array4[:]>=3) & (array4[:]<=8))]
    return new_array


# In[59]:



array4=np.array([1,5,7,8,4,3,2,2,9,6,3,3])
assert  (array_operation(array4)==[5, 7, 8, 4, 3, 6, 3, 3]).all()


# Q5. Write a NumPy program to do matrix multiplication on two input matrices, and output the result matrix. Your program should have exception handling for data mismatch, and if happens, return the data mismatch message "Data Mismatch!"to user. 

# In[75]:


import numpy as np
def matrix_multiplication(a, b):
    # YOUR CODE HERE
    try:
        res = np.dot(a, b)
    except:
        return "Data Mismatch!";
    else:
        return res


# In[76]:


m1=[1,2]
m2=[[1,2],[3,4]]
m3=[1,2,3]
assert (matrix_multiplication(m1, m2)==[7,10]).all()


# In[77]:


assert matrix_multiplication(m1, m3)=="Data Mismatch!"

