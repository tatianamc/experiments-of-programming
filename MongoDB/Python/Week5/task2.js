db.zips.aggregate([
{ $match: {$or:[{"state":"CA","pop":{$gt: 25000}},{"state":"NY","pop":{$gt: 25000}}]} },
{$group:{_id:"", "mean": {"$avg":"$pop"}}}
])