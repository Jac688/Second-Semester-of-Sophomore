
# coding: utf-8

# Before you turn this problem in, make sure everything runs as expected. First, **restart the kernel** (in the menubar, select Kernel$\rightarrow$Restart) and then **run all cells** (in the menubar, select Cell$\rightarrow$Run All).
# 
# Make sure you fill in any place that says `YOUR CODE HERE` or "YOUR ANSWER HERE", as well as your name and ID below:

# In[ ]:


NAME = "Jack"
ID = "1930026143"


# ---

# # Assignment01
# ## Due: 2021-03-22 13:00 pm
# 

# #### Q1. Write a python program to check whether two lists of integers are circularly identical.
# - Input: ``firstL = [1,2,3,4], secondL = [2,3,4,1] ``; Output: ``True``
# - Input: ``firstL = [3,4,1,3,5], secondL = [5,3,4,3,1]``; Output:``False``

# In[78]:


def cirIdentical(list1, list2):
    # YOUR CODE HERE
    result = False
    
    # First to detemine the element in the list in same
    if set(list1) != set(list2):
        return result
    
    else:
        # The number of moves is the length minus one
        for i in range(1,len(list1)):  
            # Record the value of the first item
            temp = list1[0]
            # Move the whole thing one place to the left
            for j in range(len(list1)):
                if j != len(list1)-1:
                    list1[j] = list1[j+1]
百科                else:
                    list1[j] = temp
            # Each move is compared to list2
            if list1 == list2:
                result = True
                break;
                        
        
    return result
firstL = [1,2,3,4]
secondL = [2,3,4,1]
firstL1 = [3,4,1,3,5]
secondL1 = [5,3,4,3,1]
cirIdentical(firstL, secondL)
cirIdentical(firstL1, secondL1)


# In[75]:


firstL = [1,2,3,4]
secondL = [2,3,4,1]

firstL1 = [3,4,1,3,5]
secondL1 = [5,3,4,3,1]
assert cirIdentical(firstL, secondL) == True
assert cirIdentical(firstL1, secondL1) == False


# #### Q2. Write a Python program to remove items with duplicate values from Dictionary.
# - Input: ``{1:'a',2:'b',3:'a'}``, Output: ``{2:'b'}``
# - Input: ``{1:'a',2:'a',3:'a'}``, Output:``{}``

# In[54]:


def removeDup(inputDict):
    # YOUR CODE HERE
    lst = []
    # Traverse the key of the dictionary
    for i in inputDict.keys():
        cnt = 0
        for j in inputDict.values():
            # Counts how many identical values in dictionary
            if inputDict[i] == j:
                cnt+=1
        # Greater than 1 means the item is repeated
        if cnt > 1:
            lst.append(i)
            
    # Delete Duplicates
    for x in lst:
        inputDict.pop(x)
    
    result = inputDict
    return result    
        
removeDup({1:'a',2:'b',3:'a'})

    
    


# In[23]:


assert removeDup({1:'a',2:'b',3:'a'}) == {2:'b'}
assert removeDup({1:'a',2:'a',3:'a'}) == {}


# #### Q3.Write a Python program to remove empty tuple(s) from a list of tuples. 
# 
# - Input: ``[(), (), ('',), ('a', 'b'), ('a', 'b', 'c'), ('d')]``
# - Output: ``[('',), ('a', 'b'), ('a', 'b', 'c'), 'd']``

# In[8]:


def remove_empty_tuple(tuples_list):
    # YOUR CODE HERE
    # Choose the item which is not equal to Null from the tuples_list
    lst = [i for i in tuples_list if i != ()]
    return lst


# In[9]:


t_list1=[(), (), ('',), ('a', 'b'), ('a', 'b', 'c'), ('d')]
assert remove_empty_tuple(t_list1)==[('',), ('a', 'b'), ('a', 'b', 'c'), 'd']


# #### Q4.Write a Python program to check if a point ($x_p$,$y_p$) is in a circle (centered at ($x_c,y_c$) with redius $r$) or not.
# - Input: ``p=(2,3), center=(0,0), radius=5`` 
# - Output: True

# In[24]:


def check_in_circle(xp,yp,xc,yc,r):
    # YOUR CODE HERE
    xd = (xp - xc)**2
    yd = (yp - yc)**2
    # Get distance squared
    d  = xd + yd
    # The Pythagorean theorem, compare
    if d <= (r**2):
        return True
    else:
        return False
    raise NotImplementedError()


# In[25]:


assert check_in_circle(2,3,0,0,5)==True
assert check_in_circle(2,3,0,0,1) == False


# #### Q5. Write a Python program that checks whether a given number is prime or not. 
# Note : A prime number (or a prime) is a natural number greater than 1 and that has no positive divisors other than 1 and itself.
# - Input: ``1``, Output: ``False``
# - Input: ``17``, Output: ``True``

# In[26]:


def isPrime(num):
    # YOUR CODE HERE
    # Detemine if it's greater than 1 firstly
    if num > 1:
        cnt = 0
        # Mod for all values from 2 to num-1
        for i in range(2,num):
            if num % i == 0:
                cnt+=1;
        # That means there's no number that's divisible by it
        if cnt == 0:
            return True
        else: 
            return False   
        
    else:
        return False
            
    raise NotImplementedError()


# In[27]:


assert isPrime(10) == False
assert isPrime(53) == True


# #### Q6. Write a python function to check whether a given string is palindrome or not. 
# - A string is said to be palindrome if the reverse of the string is the same as string. 
# - Input: ``pip``, Output: ``True``
# - Input: ``install``, Output: ``False``

# In[31]:


def isPalindrome(str1):
# YOUR CODE HERE
    # It is printed in reverse order and assigned to str2
    str2 = str1[::-1]
    # Detemine if there are identical 
    if str2 == str1:
        return True
    else: 
        return False


# In[32]:


assert isPalindrome('pip')==True
assert isPalindrome('install')==False

