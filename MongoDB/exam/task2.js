db.messages.aggregate(
	[
		{$unwind: "$headers.To"},
		{$group:{_id:{from:"$headers.From", to:"$headers.To"}, "ncount": {"$sum":1}}},
		{$sort:{ ncount:-1}},
		{$limit:1}
	]
)

