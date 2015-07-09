var exp = db.qe.explain('executionStats')
exp.find({'a':{'$lt':20}, 'b':{'$gt': 10}}, {'a':1, 'c':1}).sort({'c':-1})