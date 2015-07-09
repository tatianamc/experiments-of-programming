db.messages.find(
	{"headers.From": "email", "headers.To":"email"}
).count()