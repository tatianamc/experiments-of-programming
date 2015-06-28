db.zips.aggregate([
    {$project: 
     {
		city: "$city",
		pop: "$pop",
		first_char: {$substr : ["$city",0,1]},
     }	 
   },
   {$sort : {first_char : 1}}, 
   {$match: {first_char: /^\d.*$/}},
   {$group:{_id:"", "pop": {"$sum":"$pop"}}}
])