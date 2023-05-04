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
from flask import Flask

app = Flask(__name__)

if app.config["ENV"] == "production":
    app.config.from_object("config.DevelopmentConfig")
elif app.config["ENV"] == "testing":
    app.config.from_object("config.TestingConfig")
else:
    app.config.from_object("config.ProductionConfig")

from app import views
