import pymongo
import datetime
from pymongo import MongoClient
from bson.objectid import ObjectId

# The web framework gets post_id from the URL and passes it as a string
def get(post_id):
    # Convert from string to ObjectId:
    document = client.db.collection.find_one({'_id': ObjectId(post_id)})

################
# Connection
################

# client = MongoClient() connect on the default
# client = MongoClient('localhost', 27017)
# or
client = MongoClient('mongodb://localhost:27017/')

db = client.mydb
# or
#db = client['mydb']

#Getting collections
collection = db.testData
#or
#collection = db['testData']

################
# Data insert
################

post = {
	"author": "Igor",
	"text": "My first blog post!",
	"tags": ["mongo","python", "good"],
	"date": datetime.datetime.utcnow()
}

posts = db.posts
post_id = posts.insert(post)
#print(post_id)
print(db.collection_names())

################
# Getting a Single Document With find_one()
################
print(posts.find_one())
# query
print(posts.find_one({"author": "Igor"}))

################
# Querying By ObjectId
################

posts.find_one({"_id":post_id})

new_posts = [{"author": "Mike",
              "text": "Another post!",
              "tags": ["bulk", "insert"],
              "date": datetime.datetime(2009, 11, 12, 11, 14)},
             {"author": "Eliot",
               "title": "MongoDB is fun",
               "text": "and pretty easy too!",
               "date": datetime.datetime(2009, 11, 10, 10, 45)}]
#posts.insert(new_posts)

# count documents
print(posts.count())

# get some documents
# get coursor
for post in posts.find():
	print(post)

# or
print("*************")
for post in posts.find({"author": "Mike"}):
	print(post)

#################
# Range Queries
#################

d = datetime.datetime(2009, 11, 12, 12)
for post in posts.find({"date": {"$lt": d}}).sort("author"):
	print(post)

###############
# Indexing
###############

print(posts.find({"date": {"$lt": d}}).sort("author").explain()["cursor"])
print(posts.find({"date": {"$lt": d}}).sort("author").explain()["nscanned"])

from pymongo import ASCENDING, DESCENDING
print(posts.create_index([("date", DESCENDING), ("author", ASCENDING)]))
print(posts.find({"date": {"$lt": d}}).sort("author").explain()["nscanned"])