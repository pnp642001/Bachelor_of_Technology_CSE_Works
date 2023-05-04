#PROJECT BY: PARTH NITESHKUMAR PATEL
#ID: I-003
#VERIFICATION STATUS: VERIFIED BY THE TEAM LEADER
#ACCESS LEVEL: SHOW ACCESS ALLOWED
#POST VERIFICATION MODIFICATION ACCESS: DENIED

'''
ADDITIONAL COMMENTS:
1.The development of HTML forms falls outside the scope of I-003's responsibilities, as this is the responsibility of the development team.

2.All coding related to Flask has been completed by the developers and is not within the scope of I-003's duties.

3.As part of the project's functionality, I-003's code included a section that stored data obtained from web scraping in a MongoDB database.
However, to maintain the privacy of the individuals and in compliance with the company's policy,
the verifier has removed this portion of the code from I-003's project.
'''

#IMPORTING THE IMP LIBRARIES
#THESE ARE SOME IMPORTANT LIBRARIES TO DO THE WEB SCRAPPING


from flask import Flask, render_template, request,jsonify
from flask_cors import CORS,cross_origin

import requests #for making HTTP requests to websites and APIs.

from bs4 import BeautifulSoup as bs #FOR BEAUTIFYING THE DATA

from urllib.request import urlopen as uReq
#The urllib library in Python is a standard library used for
#working with URLs and making HTTP requests.
#It provides several modules that allow you to interact with different aspects of URLs and HTTP protocols.

import logging
# The logging library in Python is a standard library used for generating log messages from applications.

logging.basicConfig(filename="scrapper.log" , level=logging.INFO)

app = Flask(__name__)

@app.route("/", methods = ['GET'])
def homepage():
    return render_template("index.html")

@app.route("/review" , methods = ['POST' , 'GET'])
def index():
    if request.method == 'POST':
        try:
            #STORING THE STRING PROVIDED BY THE USER.
            #PREPARING IT FOR THE SCRAPPING BY REMOVING WHITE SPACES
            searchString = request.form['content'].replace(" ","")

            #MANUALLY GENERATING THE LINK.
            flipkart_url = "https://www.flipkart.com/search?q=" + searchString

            # REQUESTING THE WEBSITE FOR THE RESPONSE
            uClient = uReq(flipkart_url)
            flipkartPage = uClient.read()

            #CLOSING THE OBJECT
            uClient.close()

            #BEAUTIFYING THE DATA RECEIVED
            flipkart_html = bs(flipkartPage, "html.parser")

            #FETCHING THE DIV CONTAINER WHERE THE REQUIRED DATA IS LOCATED
            #CLASS NAME IS FOUND DURING THE INSPECTION PROCESS
            bigboxes = flipkart_html.findAll("div", {"class": "_1AtVbE col-12-12"})

            #DELETING THE FIRST 3 DIV CONTAINERS' DATA AS IT IS NOT REQUIRED.
            #THEY CONTAINS TITLE AND OTHER DETAILS AND NOT THE PRODUCT DETAILS
            del bigboxes[0:3]

            #SELECTING THE FIRST PRODUCT
            box = bigboxes[0]

            #FETCHING THE LINK FOR THE REVIEWS
            productLink = "https://www.flipkart.com" + box.div.div.div.a['href']

            #REQUESTING THE DATA ONCE AGAIN
            prodRes = requests.get(productLink)
            prodRes.encoding='utf-8'

            #BEAUTIFYING THE DATA
            prod_html = bs(prodRes.text, "html.parser")
            print(prod_html)

            #FETCHING THE REVIEW DESCRIPTION
            commentboxes = prod_html.find_all('div', {'class': "_16PBlm"})

            #THE CODE FROM LINE 81-84 IS ADDED BY EAVM-122
            filename = searchString + ".csv"
            fw = open(filename, "w")
            headers = "Product, Customer Name, Rating, Heading, Comment \n"
            fw.write(headers)
            reviews = []

            #FETCHING THE DESCRIPTION OF ALL THE REVIEWS RECEIVED IN THE DATA
            for commentbox in commentboxes:
                try:
                    #name.encode(encoding='utf-8')
                    #FETCHING THE REVIEW DESCRIPTION FROM EACH LINK VISITED
                    name = commentbox.div.div.find_all('p', {'class': '_2sc7ZR _2V5EHH'})[0].text

                except:
                    logging.info("name")

                try:
                    #rating.encode(encoding='utf-8')
                    #FETCHING THE RATING
                    rating = commentbox.div.div.div.div.text


                except:
                    rating = 'No Rating'
                    logging.info("rating")

                try:
                    #commentHead.encode(encoding='utf-8')
                    commentHead = commentbox.div.div.div.p.text

                except:
                    commentHead = 'No Comment Heading'
                    logging.info(commentHead)
                try:
                    comtag = commentbox.div.div.find_all('div', {'class': ''})
                    #custComment.encode(encoding='utf-8')
                    custComment = comtag[0].div.text
                except Exception as e:
                    logging.info(e)

                #CREATING A TEMPORARY DICTIONARY TO STORE THE REVIEW DETAILS
                mydict = {"Product": searchString, "Name": name, "Rating": rating, "CommentHead": commentHead,
                          "Comment": custComment}

                #APPENDING THE TEMPORARY DICTIONARY TO THE LIST
                reviews.append(mydict)
            logging.info("log my final result {}".format(reviews))

            #RENDERING THE REVIEWS TO THE FLASK SERVER
            return render_template('result.html', reviews=reviews[0:(len(reviews)-1)])
        except Exception as e:
            logging.info(e)
            return 'something is wrong'
    # return render_template('results.html')

    else:
        return render_template('index.html')


if __name__=="__main__":
    app.run(host="0.0.0.0")
