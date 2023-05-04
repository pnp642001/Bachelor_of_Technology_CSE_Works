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
import os
from   os import environ

class Config(object):

    DEBUG = False
    TESTING = False
    
    basedir    = os.path.abspath(os.path.dirname(__file__))

    SECRET_KEY = 'XXX'

    DB_NAME = "production-db"
    DB_USERNAME = "root"
    DB_PASSWORD = "XXX"

    UPLOADS = "/home/username/app/app/static/uploads"

    SESSION_COOKIE_SECURE = True
    DEFAULT_THEME = None


class ProductionConfig(Config):
    pass

class DevelopmentConfig(Config):
    DEBUG = True

    DB_NAME = "production-db"
    DB_USERNAME = "root"
    DB_PASSWORD = "pianalytix"

    UPLOADS = "/home/username/app/app/static/uploads"
    SESSION_COOKIE_SECURE = False


class TestingConfig(Config):
    DEBUG = True

    DB_NAME = "production-db"
    DB_USERNAME = "root"
    DB_PASSWORD = "pianalytix"

    UPLOADS = "/home/username/app/app/static/uploads"
    SESSION_COOKIE_SECURE = False

 
class DebugConfig(Config):
    DEBUG = False
