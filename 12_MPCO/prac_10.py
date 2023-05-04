import time
import RPi.GPIO as GPIO   
GPIO.setmode(GPIO.BOARD)
GPIO.setup(11,GPIO.OUTPUT)
while True:
    GPIO.output(11,True)
    GPIO.output(12,True)
    GPIO.output(13,True)
    GPIO.output(14,True)
    time.sleep(1)
    GPIO.output(11,False)
    GPIO.output(12,False)
    GPIO.output(13,False)
    GPIO.output(14,False)
    time.sleep(1)
