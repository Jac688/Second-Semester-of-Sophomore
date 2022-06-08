
# coding: utf-8

# Before you turn this problem in, make sure everything runs as expected. First, **restart the kernel** (in the menubar, select Kernel$\rightarrow$Restart) and then **run all cells** (in the menubar, select Cell$\rightarrow$Run All).
# 
# Make sure you fill in any place that says `YOUR CODE HERE` or "YOUR ANSWER HERE", as well as your name and collaborators below:

# In[ ]:


NAME = "Jack"
ID = "1930026143"


# ---

# # Lab 2

# ### Exercise1
# 
# Consider a tuple ``tp=( 34, 53, 67, 86, 42, 28, 75, 49, 23, 65)``. Write a Python program to count the number of even and odd numbers in the tuple.

# In[3]:


#TODO for exercise1
tp=( 34, 53, 67, 86, 42, 28, 75, 49, 23, 65)
cnt_e = 0
cnt_o = 0
for i in tp:
    if i%2 == 0:
        cnt_e+=1
    else:
        cnt_o+=1
print('The number of even is: %d' %cnt_e)
print('The number of odd is: %d' %cnt_o)
        


# ### Exercise 2:
# 
# Write a Python program to traverse the numbers which are divisible by 10, between 1 and 100 (both included) and print all numbers in the same order and skip the printing if the number equals to 50 or 60.
# 

# In[1]:


#TODO for exercise2
lst = []  # Llist is a mutable sequence
for i in range(1,101):
    if i%10 == 0:
        if i != 50 and i != 60:
            lst.append(i)
print(lst)
    
    


# ### Exercise 3: 
# 
# Assign the list ['a', 'd', 'b', 'c', 'd', 'e'] to a variable. Perform the following operations:
# 1. Delete all 'd' from the list
# 2. Insert 'z' at index 3
# 3. Append 'o' to the end.
# 4. Delete element at index 2
# 
# Print the list after conducting all operations.

# In[1]:


#TODO for exercise3
lst=['a', 'd', 'b', 'c', 'd', 'e']
for i in range(len(lst)):
    if 'd' in lst:
        lst.remove('d')
        
lst.insert(3,'z')

lst.append('o')

lst.remove(lst[2])
print(lst)


# ### Exercise 4:
# 
# In the cell below, I will provide you with a string of characters that may appear quite random at first. Run the cell to assign the string to a variable. However, the string is in reality an reversed encoded message, **in which the character to keep is at every three character**.
# 
# Use Python to perform string slicing and reverse the sliced string to decode the message, and print the result to your notebook. 
# - Decoding by first perform string slicing and then reverse the sliced string.
# - The result is a familar expression, so if you are not getting a result that makes sense, try again!
# - **Hint: remember rules about Python indexing, which starts at 0, not 1!**

# In[ ]:


code = 'vaSjjDopesmvxnorrlnbI!'


# In[12]:


#TODO for exercise4
code = 'vaSjjDopesmvxnorrlnbI!'
print(list(reversed(code)))
for i in range(0,len(code),3):
    str = code[i:i+3]
    print(str[::-1], end=' ')


# ### Exercise 5:
# 
# Write a Python program to count the frequency of alphabets (``a-z`` and ``A-Z``) in a string. 
# 
# Sample String :``'http://Google.com'``
# 
# Expected Result : {'G': 1,'c': 1,'e': 1,'g': 1,'h': 1,'l': 1,'m': 1,'o': 3,'p': 1,'t': 2}

# In[8]:


# #TODO for exercise5
str = input()
dic = {}
for i in str:
    if 96<ord(i)<123 or 64<ord(i)<91:
        cnt = str.count(i)
        dic[i] = cnt
print(dic)
        
        


# ### Exercise 6:
# Write a Python function that takes a list as input and returns a new list which stores the duplicate elements of the first list. 
# 
# Sample List : [1,2,2,3,3,3,3,4,5]
# 
# New List : [2,3] 
# - Note: all the duplicate elements will only occur once in the new list.

# In[7]:


sample_list = [1,2,2,3,3,3,3,4,5]
#TODO for exercise6
lst = []
for i in sample_list:
    cnt = sample_list.count(i)
    if cnt >= 2:
        lst.append(i)
        
print(list(set(lst)))
        
        


# ### Exercise7:
# Given two lists ``lista=[1, 2, 3, 4, 5]``, ``listb = [5, 6, 7, 8, 9]``. Write a Python program to check if two lists have at least one element common in them.
# - If contains at least one element common in lists, print "True". Otherwise, return "False".

# In[6]:


#TODO for exercise7
lista = [1, 2, 3, 4, 5]
listb = [5, 6, 7, 8, 9]
cnt = 0
for i in lista:
    if i in listb:
        cnt+=1

if cnt>=1:
    print('True')
else:
    print('False')
        


# ### Exercise8:
# Given two lists: ``list1 = ['DS 2013','COMP 2003','DS 4023']``, ``list2=['Data Processing Workshop I','Data Structures and Algorithms','Machine Learning']``. Write a Python program to create a dictionary from two lists, using the items from ``list1`` as keys and items from ``list2`` as values.
# - For $k^{th}$ pair in the dictionary, the key is the $k^{th}$ element in list1 and value is k^{th} element in list2.

# In[9]:


#TODO for exercise8
list1 = ['DS 2013','COMP 2003','DS 4023']
list2 = ['Data Processing Workshop I','Data Structures and Algorithms','Machine Learning']
dic = {}
for i in range(len(list1)):
    dic[list1[i]] = list2[i]
print(dic)

