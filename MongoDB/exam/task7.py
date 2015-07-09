
import pymongo
import sys

# establish a connection to the database
connection = pymongo.MongoClient("mongodb://localhost")

db=connection.test
images = db.images
albums = db.albums

def remove_image(_id):

    # get a handle to the school database
    db=connection.test
    images = db.images

    try:
        result = images.delete_many({'_id':_id})
        #print ("num removed: ", result.deleted_count)

    except Exception as e:
        print ("Exception: ", type(e), e)


def deleteimages():

    print ("run removing")

    
    try:
        query = {}
        cursor = images.find(query)

        for image in cursor:
            cnt = albums.find({"images":image["_id"]}).count()
            if cnt==0:
                remove_image(image["_id"])


    except Exception as e:
        print ("Unexpected error:", type(e), e)


deleteimages()