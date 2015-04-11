import urllib.request

def read_test(filepath):
    quotes = open(filepath)
    contents = quotes.read()
    quotes.close()
    return contents
    
    
def check_profanity(text_to_check):
    con = urllib.request.urlopen("http://www.wdyl.com/profanity?q=" + text_to_check)
    output = con.read()
    print(output)
    con.close()
    

#some_text = read_test("sdf.txt")
some_text = "sdf"
check_profanity("sdf")
