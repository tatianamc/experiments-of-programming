
import pymongo
import sys

# establish a connection to the database
connection = pymongo.MongoClient("mongodb://localhost")
db=connection.test
qe = db.qu


def fill():

    try:

        for a in range(100):
            print(a)
            for b in range(100):
                for c in range(100):
                    qe.insert_one({"a":a, "b":b, "c":c})


    except Exception as e:
        print ("Unexpected error:", type(e), e)


fill()