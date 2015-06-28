db.posts.aggregate(
	[
		{$unwind: "$comments"},
		{$group:{_id:"$comments.author", "num_comment": {"$sum":1}}},
		{$sort:{num_comment:-1}}
	]
)