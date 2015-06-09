
import pymongo
import sys

# establish a connection to the database
connection = pymongo.MongoClient("mongodb://localhost")

db=connection.students
grades = db.grades

def remove_student(_id):

    # get a handle to the school database
    db=connection.students
    grades = db.grades

    try:

        result = grades.delete_many({'_id':_id})

        print ("num removed: ", result.deleted_count)

    except Exception as e:
        print ("Exception: ", type(e), e)

def remove_all(students):
    # get a handle to the school database
    db=connection.grades
    grades = db.grades

    try:

        result = grades.delete_many(students)

        print ("num removed: ", result.deleted_count)

    except Exception as e:
        print ("Exception: ", type(e), e)


def find():

    print ("find, reporting for duty")

    query = {'type':'homework'}

    try:

        #cursor = grades.find(query) 

        #cursor = cursor.sort('student_id', pymongo.ASCENDING).skip(4).limit(1)
        
        cursor = grades.find(query).sort([('student_id',pymongo.ASCENDING),('score',pymongo.ASCENDING)])
         
        
        

        


    except Exception as e:
        print ("Unexpected error:", type(e), e)

    #for doc in cursor:
    #    print(doc)
    
    idx = -1
    #deletedstudents = []

    for doc in cursor:
        print(doc)
        if doc['student_id']!=idx:
            idx = doc['student_id']
            print(doc['_id'])
            remove_student(doc['_id'])
            #deletedstudents+=[doc]

    #print(len(deletedstudents))

    #remove_all(deletedstudents)


def find_one():

    print ("find one, reporting for duty")
    query = {'student_id':10}
    
    try:
        doc = scores.find_one(query)
        
    except Exception as e:
        print ("Unexpected error:", type(e), e)

    
    print (doc)


find()

