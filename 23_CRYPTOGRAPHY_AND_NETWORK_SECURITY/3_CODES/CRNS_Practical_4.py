# CS 345 - CRNS
#PRACTICAL-4
#PERFORMED BY : PARTH N PATEL
# ID : 19DCS098

#LANGUAGE OF CODE: PYTHON

#IMPORTING math LIBRARY 
import math
 

#TAKING INPUT FOR THE PRIME NUMBERS
print("PLEASE SELECT TWO PRIME NUMBERS: ")
p = int(input("ENTER THE FIRST PRIME NUMBER : "))
print()
q = int(input("ENTER THE SECOND PRIME NUMBER : "))
print()
 
#VALIDATING WHETHER THE NUMBERS ARE PRIME OR NOT 
#FUNCTION TO VALIDATE IF NUMBER IS PRIME OR NOT

def validate_Prime(x):
    if(x==2):  
        #2 IS THE ONLY EVEN NUMBER
        return True
    elif((x<2) or ((x%2)==0)):
        #NUMBERS LESS THAN 2 AND DIVISBLE BY ANOTHER NUMBER 
        # ARE NOT PRIME NUMBERS
        return False
    elif(x>2):
        for i in range(2,x):
            if not(x%i):
                return False
    return True
 
#CECKING IF P AND Q ARE PRIME OR NOT
check_p = validate_Prime(p)
check_q = validate_Prime(q)

#LOOP TILL PRIME NUMBERS ARE ENTERED
while(((check_p==False)or(check_q==False))):
    p = int(input("Enter a prime number for p: "))
    q = int(input("Enter a prime number for q: "))
    check_p = validate_Prime(p)
    check_q = validate_Prime(q)
 
#MAIN LOGIC BUILDING FOR THE RSA 

#FINDING THE RSA MODULUS
n = p * q
print("RSA MODULUS : ",n)
print()

#EULER'S TOITENT
r= (p-1)*(q-1)
print("EULER'S TOITENT : ",r)
print()
 
#CALCULATING THE GCD
def find_GCD(e,r):
    while(r!=0):
        e,r=r,e%r
    return e
 
#EUCLID'S ALGORITHM

def euclid_Algorithm(e,r):
    for i in range(1,r):
        while(e!=0):
            a,b=r//e,r%e
            if(b!=0):
                print("%d = %d*(%d) + %d"%(r,a,e,b))
            r=e
            e=b
 
#EXTENDED EUCLID'S ALGORITHM
def extended_Euclid_Algorithm(a,b):
    if(a%b==0):
        return(b,0,1)
    else:
        gcd,s,t = extended_Euclid_Algorithm(b,a%b)
        s = s-((a//b) * t)
        print("%d = %d*(%d) + (%d)*(%d)"%(gcd,a,t,s,b))
        return(gcd,t,s)
 
#MULTIPLICATIVE INVERSE
def multiplicative_Inverse(e,r):
    gcd,s,_=extended_Euclid_Algorithm(e,r)
    if(gcd!=1):
        return None
    else:
        if(s<0):
            print("s=%d. SINCE %d IS LESS THAN 0, s = s(modr), i.e., s=%d."%(s,s,s%r))
        elif(s>0):
            print("s=%d."%(s))
        return s%r
 
#CALCULATING THE VALUE OF e
#FINDS THE HIGHEST POSSIBLE VALUE OF 'e' BETWEEN 1 and 1000 THAT MAKES (e,r) COPRIME.
for i in range(1,1000):
    if(find_GCD(i,r)==1):
        e=i
print("THE VALUE OF e : ",e)
print()
 

#CALCULATION OF 'd', PRIVATE KEY, AND PUBLIC KEY.
print("EUCLID'S ALGORITHM:")
euclid_Algorithm(e,r)
print()
print("EUCLID'S EXTENDED ALGORITHM:")
d = multiplicative_Inverse(e,r)
print()
print("THE VALUE OF D : ",d)
print()
#PUBLIC KEY 
public = (e,n)
#PRIVATE KEY
private = (d,n)

print("PRIVATE KEY : ",private)
print("PUBLIC KEY  : ",public)
print()

 
#ENCRYPTION
def encrypt(pub_key,n_text):
    e,n=pub_key
    x=[]
    m=0
    for i in n_text:
        if(i.isupper()):
            m = ord(i)-65
            c=(m**e)%n
            x.append(c)
        elif(i.islower()):               
            m= ord(i)-97
            c=(m**e)%n
            x.append(c)
        elif(i.isspace()):
            spc=400
            x.append(400)
    return x
     
 

 
#Message
plain_Text = input("PLEASE ENTER THE MESSAGE TO BE ENCRYPTED : ")
print()
print("YOUR MESSAGE :",plain_Text)

cipher_Text=encrypt(public,plain_Text)
print()
print("THE ENCRYPTED CIPHER TEXT : ")
print()
print(cipher_Text)
print()

print("PARTH PATEL\n19DCS098")
    