<!DOCTYPE html>
<html>
<head>
	<title>Hellow Workld!</title>
</head>
<body>
<p>
	Welcome {{username}}
</p>
<ul>
	%for thing in things:
	<li>{{thing}}</li>
	%end
</ul>
</body>
</html>