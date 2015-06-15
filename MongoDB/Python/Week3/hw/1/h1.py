
import pymongo
import sys

# establish a connection to the database
connection = pymongo.MongoClient("mongodb://localhost")

db=connection.school
students = db.students

def find():

    print ("find, reporting for duty")

    query = {}

    try:
        cursor = students.find(query).sort([('scores.type',pymongo.ASCENDING),('scores.score',pymongo.DESCENDING )])
    except Exception as e:
        print ("Unexpected error:", type(e), e)


    for doc in cursor:
        for tests in doc['scores']:
            works = []
            if tests['type'] == 'homework':
                works+= [tests]
        # Find min

        minhw = works[0]
        for work in works:
            if work['score']<minhw['score']:
                minhw = work

        students.update({'_id': doc['_id']},
                    {'$pull': {'scores': minhw}}
                )


find()

