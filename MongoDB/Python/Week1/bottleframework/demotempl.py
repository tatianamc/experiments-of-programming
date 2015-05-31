from bottle import route, run, template, debug

@route('/')
def home_page():
    mythings=['apple','orange','banana','peach']
    return template('index', {'username':'Igor', 'things':mythings})

debug(True)
run(host='localhost', port=8080)
