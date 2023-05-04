#!/usr/bin/env python
# coding: utf-8

# In[3]:


a=20 #int
b=11.55 #float
c=2+3j #Complex number


# In[6]:


type(a)#type()- used to find the datatype of the varaible


# In[7]:


type(b)


# In[8]:


type(c)


# In[10]:


print(dir(a)) #dir()-will give information about all the attributes and functions


# In[12]:


id(b)#id()- gives the memory address of the variable


# In[13]:


id(a)


# In[14]:


id(c)


# In[16]:


2**10 # **- exponential operator


# # Strings

# String is a collection characters, numbers, and special symbols
# They are:
# 1. Sequential
# 2. Ordered
# 3. Immutable

# In[20]:


s1="Hello"
s2='Hello World'


# In[21]:


type(s1)


# In[22]:


s2


# In[24]:


s1[0] # we can access a specific character from the strings


# In[27]:


s2.replace('H','h') # replace()-to replace characters from the strings


# In[28]:


print(dir(s1))


# # String Operations 

# 1. Contactenation
# 2. Repetetion
# 3. Indexing

# In[30]:


"Hello"+" World" # String contactenation


# In[31]:


print("Hello"+"\t"+"India")


# In[32]:


print("Hello"+"\n"+"Everyone")


# In[34]:


"@"*20 #String repetetion


# In[36]:


s="Hello World"
print(s)


# -11 -10 -9 -8 -7 -6 -5 -4 -3 -2  -1 (Negative Thinking)
# 
# H e l l o   W o r l d 
# 
# 0 1 2 3 4 5 6 7 8 9 10              (Positive Thinking)

# In[37]:


s[-10]


# In[38]:


s[2]


# # Slicing the Strings

# string_object(start:stop:step)
# 
# Default Setting:
# 
# start---> 0
# 
# stop----> end
# 
# step----> 1

# In[39]:


s[:]


# In[40]:


s[4:]


# In[43]:


s[5::2]


# In[45]:


s[1:9:2] 
# start-->1
# stop--->9
# step--->2


# In[49]:


s[-1:]


# In[ ]:




