
# coding: utf-8

# Before you turn this problem in, make sure everything runs as expected. First, **restart the kernel** (in the menubar, select Kernel$\rightarrow$Restart) and then **run all cells** (in the menubar, select Cell$\rightarrow$Run All).
# 
# Make sure you fill in any place that says `YOUR CODE HERE` or "YOUR ANSWER HERE", as well as your name and collaborators below:

# In[1]:


NAME = "Jack"
ID = "1930026143"


# ###### 

# ---

# # Lab 1

# ## Due: 
# Mar. Fri  12:00 noon

# ### Exercise 1:
# 
# Create a new cell below with the "Insert Cell Below" option. Change the cell type to Markdown from the drop-down menu at the top of the screen. Practice writing some Markdown in the cell. The cell should include a bullet which contains a list of links to your five favorite websites, with an H1 header for the title. The links should not simply be the website URLs, but should instead show the name of the website, which you can click to get to the website. Also, color the name of the first entry in color red, and make the name of the second entry in bold.
# 
# #### For Markdown tips, take a look at the [Markdown cheatsheet](http://nestacms.com/docs/creating-content/markdown-cheat-sheet) at this link. Tips: you can view how to wrote Markdown in any of the cells in this notebook by double-clicking the cells!

# # <font color = Red><font face="Microsoft YaHei"><font size=5>Websites</font></font></font>
# *  **<font size = 3>Five favorite websites</font>**
#     * <a href="https://www.csdn.net/" target="_blank">CSDN</a></font>
#     * <a href="https://translate.google.cn/?sl=auto&tl=zh-CN&op=translate" target="_blank">Google translate</a>
#     * <a href="https://www.bilibili.com/" s target="_blank">bilibili</a>
#     * <a href="https://ispace.uic.edu.hk/"  target="_blank">ispace</a>
#     * <a href="https://home.firefoxchina.cn/"  target="_blank">Firefox</a>
#     
#     
#     
#    

# # Exercise 2:
# Write a Python program which accepts the name as input and print the hello message. 
# - If the input is "xxx", output should be "hello,xxx!".
# - Use ``input("msg")`` function, which displays the msg as prompt, reads the raw input and returns the string.

# In[2]:


#TODO for exercise2
a = input()
print('hello,'+a)


# ### Exercise3:
# 
# Define a float variable ``num1``, whose value is 0.2, an int variable ``num2`` with value 2 and a string variable ``num3`` with value "3". Calculate and output the sum of the numbers stored in the three variables.

# In[3]:


#TODO for exercise3
num1 = 0.2
num2 = 2
num3 = '3'
print(num1 + num2 + int(num3))  # change the type of num3(string) to integer


# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# 
# ### Exercise 4: 
# 
# Define a string variable ``numstr`` with value "110011" (a binary number enclosed in double quotes). Cauculate and output the number stored in the ``numstr`` variable in decimal.

# In[4]:


#TODO for exercise4
numstr =  "110011"
# '2' means to convert a binary string to a decimal integer
print(int(numstr, 2))  


# ### Exercise 5:
# 
# Define the following variables:
# - a list variable ``ls``, which stores three elements: 1,2.0,"3";
# - a tuple variable ``tup``, which stores the data type of ``ls`` elements;
# - a dictionary variable ``di``, which stores the key-value pairs of elements from list (keys) and elements from tuple (values).
# 
# Output the three variables.

# In[5]:


#TODO for exercise5
ls = [1, 2.0, "3"]
print(ls)
# store every types of elements in ls and output
tup = (type(ls[0]),type(ls[1]), type(ls[2]))
print(tup)
di = {}  # initalization

# use for in looop to add keys-values to di
for i in range(len(ls)):
    di[ls[i]]=tup[i]
print(di)


# ### Exercise 6:
# 
# Write a Python program to get the area of a circle with radius 4.56. (**Hint: use ``math`` package for computation.**)
# 
# 

# In[6]:


#TODO for exercise6
import math
radius = 4.56

# **2 means to square of radius 
area = radius**2*math.pi
print(area)


# ### Excercise 7:
# Suppose we have the following five students: 
# 
# | StudentID | StudentName |
# | ---------- | ----------|
# |1| Anna|
# |2| Bob|
# |3| Cindy|
# |4|David|
# 
# First, define a dictionary variable ``studentList`` to store the students information and use the StudentID as keys, StudentName as values. Ask the end user to input a number as student id and check whether the ``studentList`` contains that student.
# -  Use ``input("msg")`` function, which displays the msg as prompt, reads the raw input and returns the string.
# -  The data type of keys in ``studentList`` is int.
# - If the user inputs 1 or 2 or 3 or 4, the output should be ``True`` and ``False`` otherwise.
# 

# In[7]:


#TODO for exercise7
studentList = {1:'Anna', 2: 'Bob', 3:'Cindy', 4:'David'}
a = int(input())  # change string to integer

# use "in" to detemine if input in the dictionary
print(a in studentList.keys())


# ### Exercise 8:
# Write a Python program to get the fifth bit (from right) of the binary representation of number 1232, using **bitwise operation**.
# 

# In[8]:


#TODO for exercise8
i = 1232
b = bin(int(i))
print(b)  # output the binary of the number, type is string
print(i>>4 & 1)

