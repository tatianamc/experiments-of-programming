from bottle import route, run, template

import pymongo
from pymongo import MongoClient

@route('/hello/<name>')
def index(name):
    return template('<b>Hello {{name}}</b>!', name=name)


@route('/hell')
def index():
    # Connect to database
    connection = MongoClient('localhost',27017)

    db = connection.test

    #handle to names collection
    names = db.names

    item = names.find_one()
    name = item['name']
    return template('<b>Hello {{name}}</b>!', name=name)


run(host='localhost', port=8080)