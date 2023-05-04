# This is the Python Mini-Project
# DEVELOPER NAME: PARTH N PATEL
# MENTOR: PROF. SACHIN PATEL


#PROJECT DETAILS:
#PROJECT IS ABOUT MAKING CAMERA MOTION-DETECTOR
#WHICH WILL DETECT ANY KIND OF MOTION AND WILL GIVE THE GRAPH OF IT
#THE GRAPH WILL HAVE LOG OF ENTRY TIME AND EXIT TIME OF THE OBJECTS
#.CSV FILE WILL BE GENERATED FROM motionDetector.py WHICH WILL BE USED BY plotting.py TO CREATE GRAPH

# HOW TO TEST OR RUN THE PROGRAM:
# RUN plotting.py


# THE PROJECT CONTAINS TWO PYTHON FILES
# ONE FOR THE MOTION DETECTION
# OTHER FOR CREATING THE GRAPH


#LIBRARIES USED IN THIS FILE:
# 1. OPEN CV
# 2. TIME
# 3. PANDAS   
# 4. DATETIME



from cv2 import cv2  # IMPORTING THE OPENCV LIBRARY

import time # IMPORTING TIME LIBRARY

import pandas # IMPORTING PANDAS

from datetime import datetime  # IMPORTING DATETIME

first_frame=None      #FOR CATCHING THE BACKGROUND

statusList=[None,None]  # FOR DETECTING THE MOTION VIA CHANGING STATUS CODE

times=list() # LIST FOR STORING THE ENTRY AND EXIT TIME

df=pandas.DataFrame(columns=["Entry","Exit"]) # CREATING DATAFRAME FOR CSV FILE

video=cv2.VideoCapture(0)   
#USING VIDEOCAPRTURE FUNCTION OF OPENCV TO START THE CAMERA-0 (INBUILT CAMERA)

# THE LOGIC CODE IS KEPT IN WHILE LOOP AS WE WANT TO PROCESS THE VIDEO TILL USER QUITS BY PRESSING Q

# VIDEOS ARE STACK OF IMAGES CHANGING AT 30/60/ETC fps
# SO, ULTIMATELY WE WILL PROCESS THE IMAGES (FRAME)
while True:
    check,frame=video.read()  
    #READ() OF OPENCV WILL START CAPTURING THE IMAGE
    #THE IMAGES ARE STORED IN FORM OF NUMPY ARRAYS
                                
    status=0 # STATUS=0 STATES THAT THERE IS NO MOTION DETECTED IN THE CAMERA
  
    gray=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)  
    #CVTCOLOR() OF OPENCV USED FOR CONVERTING COLOR IMAGE TO GRAYSCALE IMAGE
    #GRAYSCALE IMAGE PROVIDES BETTER ACCURACY FOR MOTION DETECTION

    gray=cv2.GaussianBlur(gray,(21,21),0 )
    #GAUSSIANBLUR FROM OPENCV USED FOR SMOOTING THE IMAGE
    #IT REMOVES THE UNNECESSARY NOISE FROM THE IMAGE

    if first_frame is None:  #WE NEED BACKGROUND IMAGE FOR DETECTING THE MOTION
        first_frame=gray     #THIS ASSIGN A BACKGROUND IMAGE
        continue             #NORMALLY THE FIRST IMAGE IS TAKEN AS BACKGROUND

    deltaFrame=cv2.absdiff(first_frame,gray) 
    #ABSDIFF() FROM OPENCV IS USED TO GET THE DIFFERENCE
    #THE ABOVE FUNCTION GIVES ABSOLUTE DIFFERENCE BETWEEN THE CURRENT IMAGE AND BACKGROUND IMAGE
    #IF DIFFERENCE IS AFFIRMATIVE THEN MOTION IS DETECTED

    threshFrame=cv2.threshold(deltaFrame,30,255,cv2.THRESH_BINARY)[1] 
    #THRESHOLD() FROM OPENCV IS USED WHICH RETURNS TUPLE
    #the matter is straight-forward. For every pixel, the same threshold value is applied. 
    #If the pixel value is smaller than the threshold, it is set to 0, otherwise it is set to a maximum value 1



    threshFrame=cv2.dilate(threshFrame,None,iterations=2)
    #DILATE() FROM OPENCV IS USED
    #The areas of bright regions grow in size and hence the image size increases.
    
    (cnts,_)=cv2.findContours(threshFrame.copy(),cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
    #FINDCONTOURS() FROM OPENCV IS USED
    #Contours can be explained simply as a curve joining all the continuous points (along the boundary),
    # having same color or intensity.
    #THRESHHOLD() WAS APPLIED FOR GETTING BETTER ACCURACY IN THE ABOVE FUNCTION
    #IT IS SIMILAR TO FIND WHITE OBJECT FROM BLACK BACKGROUND

    for contour in cnts:
        if cv2.contourArea(contour)<13000: #CONTOURAREA() FROM OPENCV IS USED
            continue                       #PROVIDES THE AREA COVERED BY THE CONTOUR
        status=1
        (x,y,w,h)=cv2.boundingRect(contour)
        #BOUNDINGRECT() FROM OPENCV IS USED.
        #used to draw an approximate rectangle around the binary image. 
        #This function is used mainly to highlight the region of interest after obtaining contours from an image.

        cv2.rectangle(frame,(x,y),(x+w,y+h),(0,0,255),3) 
        #RECTANGLE() FROM OPENCV IS USED
        #used to draw a rectangle on any image.
    
    statusList.append(status) #APPENDING THE STATUS CODE

    statusList=statusList[-2:]  #DECREASING THE LIST TO LAST TWO ELEMENTS AS OTHER ELEMENTS ARE NOT NEED
    #THIS ALSO OPTIMIZES THE MEMORY

    if statusList[-1]==1 and statusList[-2]==0: #CHECKING WHETHER THE STATUS CODE HAS CHANGED OR NOT

        times.append(datetime.now()) #APPENDING THE CURRENT DATE AND TIME TO TIMES LIST

    elif statusList[-1]==0 and statusList[-2]==1: #CHECKING WHETHER THE STATUS CODE HAS CHANGED OR NOT
        
        times.append(datetime.now())  #APPENDING THE CURRENT DATE AND TIME TO TIMES LIST

   # cv2.imshow("gray",gray)  #SHOWS THE GREYSCALE IMAGE WHICH IS ONLY REQUIRED FOR BACKEND PURPOSE
   # cv2.imshow("Delta Frame",deltaFrame)  #SHOWS THE SMOOTHER IMAGE 
   # cv2.imshow("THRESH",threshFrame)       # SHOWS IMAGE AFTER THE THRESHOLD FUNCTION EXECUTED
   
    cv2.imshow("color",frame) 
    #IMSHOW() FROM OPENCV IS USED
    #THIS FUNCTION CREATES A WINDOW AND WILL SHOW THE IMAGE.

    key=cv2.waitKey(1) 
    #WAITKEY FROM OPENCV IS USED
    # display a frame for 1 ms, after which display will be automatically closed.

    if key==ord('q'):
        #ORD()- accepts a string of length 1 as an argument 
        #and returns the unicode code point representation of the passed argument

        if status==1:
            times.append(datetime.now())#APPENDING THE EXIT TIME WHEN USER TERMINATES THE CAM
        break

#print(times) #USED FOR DEVELOPMENT PURPOSE ONLY.
              # NO NEED TO DISPLAY TO USER

for i in range(0,len(times),2): #WILL ITERATE THE LOOP BY INCREMENTING TWICE

    df=df.append({"Entry":times[i],"Exit":times[i+1]},ignore_index=True)
    #DATAFRAME.APPEND() FROM PANDAS IS USED
    # function is used to append rows of other dataframe to the end of the given dataframe
    # returning a new dataframe object

df.to_csv("times.csv") #CONVERTING THE DATAFRAME INTO .CSV FILE

video.release() #WILL RELEASE THE CAMERA RESOURCE 
cv2.destroyAllWindows #DESTROY ALL THE WINDOWS WE CREATED
#RELEASE() AMD DESTROYALLWINDOWS() FROM OPENCV IS USED