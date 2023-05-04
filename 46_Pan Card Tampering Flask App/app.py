#PROJECT BY: PARTH NITESHKUMAR PATEL
#ID: I-003
#VERIFICATION STATUS: VERIFIED BY THE TEAM LEADER(E-045)
#ACCESS LEVEL: SHOW ACCESS ALLOWED
#POST VERIFICATION MODIFICATION ACCESS: DENIED

'''
ADDITIONAL COMMENTS:
1.The development of HTML forms falls outside the scope of I-003's responsibilities, as this is the responsibility of the development team.

2.All coding related to Flask has been completed by the developers and is not within the scope of I-003's duties.

3.To uphold the confidentiality of our client and organization,certain lines of code were omitted from I-003's project during verification.
As the project was developed for financial purposes, this was done in accordance with our organization's policies.
It is important to note that I-003 is now prohibited from making any modifications to the verified code.
'''
'''
PROJECT DETAILS:

WE WILL DETECT THE TAMPERING OF THE PAN CARD USING COMPUTER VISION. THIS WILL ENABLE THE ORGANIZATION TO CHECK WHETHER THE PAN CARD
UPLOADED IS LEGITIMATE OR NOT

METHODOLOGY USED: AGILE (CUSTOMIZED)

PROJECT FLOW:

1. GET THE IMAGE FROM THE USER.

2. CHECK THE SIZE AND FORMAT OF THE IMAGE.

3. CHANGE THE FORMAT AND THE SIZE OF THE IMAGE IN ACCORDANCE WITH THE ORIGINAL IMAGE

4. CONVERT THE IMAGE INTO THE GRAYSCALE

5. FIND THE SIMILARITY INDEX OF THE IMAGES

6. FINDING THE THRESHOLD OF THE IMAGE

7. FIND THE CONTOURS

8. GRAB THOSE CONTOURS

9. DRAW BOUNDING RECTANGLES USING THE CONTOURS

10. PLOT THE DIFFERECE USING THE THRESHOLD IMAGE AND TAMPERED IMAGE

11. COMPARE ALL THE IMAGES

12. CHECK THE SIMILARITY SCORE

13. DECIDE THE TAMPERING

'''
from app import app

#THIS WILL RUN THE APPLICATION
if __name__ == '__main__':
   app.run()
