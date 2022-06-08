
# coding: utf-8

# Before you turn this problem in, make sure everything runs as expected. First, **restart the kernel** (in the menubar, select Kernel$\rightarrow$Restart) and then **run all cells** (in the menubar, select Cell$\rightarrow$Run All).
# 
# Make sure you fill in any place that says `YOUR CODE HERE` or "YOUR ANSWER HERE", as well as your name and collaborators below:

# In[1]:


NAME = "Jack"
ID = "1930026143"


# ---

# # Lab 3
# ## Due: 2021-03-19 13:00 pm
# Read the requirements and finsih the exercises. For each exercise, the test cases are also given using ``assert`` statement.
# - Assert statement syntax: ``assert condition``.
# - If the condition is true, it does nothing and your program just continues to execute. But if the assert condition evaluates to false, it raises an ``AssertionError`` exception with an optional error message.

# In[2]:


assert "hello" == "hello"


# In[3]:


#assert "hello" == "Hello" 

#AssertionError                            Traceback (most recent call last)
#<ipython-input-2-07052b3c5a3a> in <module>
#----> 1 assert "hello" == "Hello"

#AssertionError: 


# ### Exercise 1:
# 
# Define a function called ``concatenate``, which takes a list and a separator (str) as the arguments and will concatenate all elements in a list using the separator into a string and return it.
# - Input: ``[1,2,3,4,5],'*'``; Output: ``'1*2*3*4*5'``
# - Input:``['d','a',4], '#'`` ; Output:``'d#a#4'``

# In[4]:


#TODO for exercise1
def concatenate(input_list,sep):
    # YOUR CODE HERE
    lst = []
    for i in input_list:
        # Travese and change all to string
        lst.append(str(i))
    return sep.join(lst)   


# In[5]:


assert concatenate(['d','a',4],'#')=='d#a#4'
assert concatenate(['d','a','t','a'],'%')== "d%a%t%a"


# ### Exercise 2:
# 
# Define a function called ``XORList``, which has two lists as arguments, i.e., *list1* and *list2*. The function will return a set containing elements present in *list1* or *list2*, but not both. 
# - Input: list1=["White", "Black", "Red"], list2=["Red", "Green"]
# - Output: {"White","Green", "Black"}
# 

# In[6]:


#TODO for exercise2
def XORList(list1,list2):
    # YOUR CODE HERE
    # Change list to set
    set1 = set(list1)
    set2 = set(list2)
    # Union
    set_u = set1 | set2
    # Intersection
    set_i = set1 & set2
    # ^ = Union - Intersection
    return (set_u-set_i)


# In[7]:


assert XORList(["White", "Black", "Red"],["Red", "Green"]) == set(['White','Black','Green'])


# ### Exercise 3: 
# 
# Define a function ``gFilter``, which takes two arguments, *arg1* and *arg2*:
# - The *arg1* is a integer with default value 0
# - The *arg2* is a tuple of integers
# 
# Return a new tuple as the result, which contains all elements in *arg2* that are greater than *arg1*. 
# - Note that the order of elements in *arg2* should be kept in the result
# - Input: ``gFilter(2,1,2,3)``, output: ``(3,)``
# - Input: ``gFilter(*(-1,2,3))``, output:``(2,3)``
# 

# In[8]:


#TODO for exercise 3
def gFilter(arg1=0,*arg2):
    # YOUR CODE HERE
    # *arg2 means to a tuple as argument
    lst = list(arg2)
    for i in arg2:
        if i <= arg1:
            # remove the smller elements
            lst.remove(i)
    return(tuple(lst))


# In[9]:


assert gFilter(2,1,2,3) == (3,)
assert gFilter(*(-1,2,3))== (2,3)


# ### Exercise 4:
# Define a function ``checkPasswd`` which takes one string argument and checks whether the string is a valid password or not. A password is valid if
# - It contains no less than 8 characters
# - It starts with digit and contains at least 1 lower-case letter and 1 upper-case letter.
# 
# For example ``checkPasswd('aA12331222')`` returns ``False`` while ``checkPasswd('1bbA1212121')`` returns
# ``True``.
# 
# **Hint: Use regular expression**
# - ``re.search(pattern, string)``, will return the first match and ``None`` if not found.

# In[10]:


import re
#TODO for exercise 4
def checkPasswd(passwd):
    # YOUR CODE HERE
    cnt_l=0
    cnt_u=0
    
    # Use traveral to count the number of the upper and lower
    for i in passwd:
        if(i.isalpha() == True):
            if(65<=ord(i)<=90):
                cnt_u+=1
            else:
                (97<=ord(i)<=122)
                cnt_l+=1
    # Detemine if the length of passwd>8
    # Detemine if the first element is digit
    if(len(passwd)>=8 and re.search(passwd[0], '1234567890') != None):
        if(cnt_u >0 and cnt_l>0):
            return True
        else:
            return False
    else:
        return False


# In[11]:


assert checkPasswd('aA12331222')== False
assert checkPasswd('1bbA1212121') == True


# ### Exercise 5:
# Define a function ``gcd`` which returns the greatest common divisor (GCD) of two natural numbers ``x`` and ``y``.
# - The gcd of one number and zero is the number itself.
# 
# **Hint:Use function recursion to implement Euclidean algorithm**

# In[12]:


#TODO for exercise 5
def gcd(x,y):
    # YOUR CODE HERE
    
    # Use the method of division algorithm 
    while y!=0:
        temp = x%y;
        x = y;
        y = temp;
    return x


# In[13]:


assert gcd(12,6) == 6
assert gcd(45,60) ==15
assert gcd(5,24) == 1
assert gcd(12,0) == 12


# ### Exercise 6:
# Given the following UML, write a Python class
# 
# `+--------------------------------------+
# |                Student               |
# +--------------------------------------+
# | - ID: int                            |
# | - name: string                       |
# | - grades: dict                       |
# +--------------------------------------+
# | + __init__(self,ID,name,grades): void|
# | + getID(self): int                   |
# | + getName(self): string              |
# | + setName(self, name): void          |
# | + getGrade(self, coursename):int     |
# | + getCourses(self, grade):set        |
# | + getPassCourses(self): set          |
# +--------------------------------------+
# `
# - *grades* is a dictionary where the keys are course names and the values are grades of that course. The grades can be 'A','B','C','D'and 'F'.
# - *getID(self)* and *getName(self)* returns the ID and name of the student.
# - *setName(self,name)*: sets the student's name to the value of parameter name.
# - *getGrade(coursename)*: returns the grade of the given course.
# - *getCourses(self, grade)*: returns the course names with the given grade as a set.
# - *getPassCourses(self)*: returns the course names whose grades are not 'F' as a set.

# In[14]:


class Student:
    # TODO exercise 6
    def __init__(self,ID,name,grades):
        self.ID = ID
        self.name = name
        self.grades = grades
        
    def getID(self):
    # YOUR CODE HERE
        return self.ID
    
    
    def getName(self):
    # YOUR CODE HERE
        return self.name
    
    
    def setName(self, name):
    # YOUR CODE HERE
        self.name = name

    
    def getGrade(self, coursename):
    # YOUR CODE HERE
        return self.grades.get(coursename)
        
    
    def getCourses(self, grade):
    # YOUR CODE HERE
        # if the value of the course equal to grade, then put it in the list and turn to set
        courseSet =  set([i for i,v in self.grades.items() if v == grade])
        return courseSet
        
        
    def getPassCourses(self):
    # YOUR CODE HERE
        lst = []
        for i in list(self.grades.keys()):
            # add all the course which is not F into the list
            if self.grades.get(i) != 'F':
                lst.append(i)
            # Change the list to set
        passCourse = set(lst)
        return passCourse
        


# In[15]:


ID=123
name = "DSer"
grades={"Data Structures and Algorithm":'A',"Machine Learning":'A', "Data Processing Workshop I":'B', "Database Management Systems":'D',"Data Mining":'F'}
s = Student(ID,name,grades)


# In[16]:


assert s.getID()==123


# In[17]:


assert s.getPassCourses() == {"Data Structures and Algorithm","Machine Learning", "Data Processing Workshop I", "Database Management Systems"}

