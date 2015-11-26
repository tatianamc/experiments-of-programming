// Создание сертификата

makecert    
    -pe                                     Exportable private key
    -n "CN=Test"                            Subject name
    -ss my                                  Certificate store name
    -sr LocalMachine                        Certificate store location
    -a sha1                                 Signature algorithm
    -sky signature                          Subject key type is for signature purposes
    -r                                      Make a self-signed cert
    "output.cer"  

// вахно именно localhost написать
// makecert -pe -n "CN=localhost"  -ss my  -sr LocalMachine     -a sha1     -sky signature -r  "output.cer"  

// или так
makecert -sv key.pvk -n "CN=localhost"   -sr LocalMachine     -a sha1     -sky signature -r  "output2.cer"    
PVK2PFX -pvk key.pvk -spc output2.cer -pfx yourpfxout2.pfx -po 123

// После чего нужно сертификат зарегистировать в windows, для этого можно 2 раза кликнуть


Logs

Server run on: https://localhost:8088
Waiting for client message...
request:
GET / HTTP/1.1
Accept: text/html, application/xhtml+xml, image/jxr, */*
Accept-Language: en-US,en;q=0.7,ru;q=0.3
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2486.0 Safari/537.36 Edge/13.10586
Accept-Encoding: gzip, deflate
Host: localhost:8088
Connection: Keep-Alive


response:
HTTP/1.1 200 OK
Date: 26.11.2015 2:49:35
Server: nesterione-server
Content-Type: text/html; charset=UTF-8
Content-Length: 123
Connection: close

<form method='post'>hi, I'm https-server, input number:<br><input type='text' name='val' ><br><input type='submit' ></form>
Waiting for client message...
Waiting for client message...
request:
GET / HTTP/1.1
Accept: text/html, application/xhtml+xml, image/jxr, */*
Accept-Language: en-US,en;q=0.7,ru;q=0.3
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2486.0 Safari/537.36 Edge/13.10586
Accept-Encoding: gzip, deflate
Host: localhost:8088
Connection: Keep-Alive


response:
HTTP/1.1 200 OK
Date: 26.11.2015 2:49:44
Server: nesterione-server
Content-Type: text/html; charset=UTF-8
Content-Length: 123
Connection: close

<form method='post'>hi, I'm https-server, input number:<br><input type='text' name='val' ><br><input type='submit' ></form>
request:
POST / HTTP/1.1
Accept: text/html, application/xhtml+xml, image/jxr, */*
Referer: https://localhost:8088/
Accept-Language: en-US,en;q=0.7,ru;q=0.3
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2486.0 Safari/537.36 Edge/13.10586
Content-Type: application/x-www-form-urlencoded
Accept-Encoding: gzip, deflate
Host: localhost:8088
Content-Length: 8
Connection: Keep-Alive
Cache-Control: no-cache

val=5555
response:
HTTP/1.1 200 OK
Date: 26.11.2015 2:49:49
Server: nesterione-server
Content-Type: text/html; charset=UTF-8
Content-Length: 73
Connection: close

You entered value:<br><br>5555<br><br><a href='/' > Open Index Page </a>
Waiting for client message...
request:
POST / HTTP/1.1
Accept: text/html, application/xhtml+xml, image/jxr, */*
Referer: https://localhost:8088/
Accept-Language: en-US,en;q=0.7,ru;q=0.3
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2486.0 Safari/537.36 Edge/13.10586
Content-Type: application/x-www-form-urlencoded
Accept-Encoding: gzip, deflate
Host: localhost:8088
Content-Length: 9
Connection: Keep-Alive
Cache-Control: no-cache

val=hello
response:
HTTP/1.1 200 OK
Date: 26.11.2015 2:49:54
Server: nesterione-server
Content-Type: text/html; charset=UTF-8
Content-Length: 74
Connection: close

You entered value:<br><br>hello<br><br><a href='/' > Open Index Page </a>
Waiting for client message...
request:
GET / HTTP/1.1
Accept: */*
Accept-Language: en-US,en;q=0.7,ru;q=0.3
Accept-Encoding: gzip, deflate
User-Agent: Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 10.0; WOW64; Trident/7.0)
Host: localhost:8088
Connection: Keep-Alive


response:
HTTP/1.1 200 OK
Date: 26.11.2015 2:50:38
Server: nesterione-server
Content-Type: text/html; charset=UTF-8
Content-Length: 123
Connection: close

<form method='post'>hi, I'm https-server, input number:<br><input type='text' name='val' ><br><input type='submit' ></form>
Waiting for client message...
Waiting for client message...
request:
GET / HTTP/1.1
Host: localhost:8088
Connection: keep-alive
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2490.86 Safari/537.36
Accept-Encoding: gzip, deflate, sdch
Accept-Language: ru-RU,ru;q=0.8,en-US;q=0.6,en;q=0.4


response:
HTTP/1.1 200 OK
Date: 26.11.2015 2:50:51
Server: nesterione-server
Content-Type: text/html; charset=UTF-8
Content-Length: 123
Connection: close

<form method='post'>hi, I'm https-server, input number:<br><input type='text' name='val' ><br><input type='submit' ></form>
request:

response:
HTTP/1.1 200 OK
Date: 26.11.2015 2:50:51
Server: nesterione-server
Content-Type: text/html; charset=UTF-8
Content-Length: 123
Connection: close

<form method='post'>hi, I'm https-server, input number:<br><input type='text' name='val' ><br><input type='submit' ></form>
Waiting for client message...
request:
GET /favicon.ico HTTP/1.1
Host: localhost:8088
Connection: keep-alive
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2490.86 Safari/537.36
Accept: */*
Referer: https://localhost:8088/
Accept-Encoding: gzip, deflate, sdch
Accept-Language: ru-RU,ru;q=0.8,en-US;q=0.6,en;q=0.4


response:
HTTP/1.1 200 OK
Date: 26.11.2015 2:50:56
Server: nesterione-server
Content-Type: text/html; charset=UTF-8
Content-Length: 123
Connection: close

<form method='post'>hi, I'm https-server, input number:<br><input type='text' name='val' ><br><input type='submit' ></form>
Waiting for client message...
request:
POST / HTTP/1.1
Host: localhost:8088
Connection: keep-alive
Content-Length: 21
Cache-Control: max-age=0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8
Origin: https://localhost:8088
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2490.86 Safari/537.36
Content-Type: application/x-www-form-urlencoded
Referer: https://localhost:8088/
Accept-Encoding: gzip, deflate
Accept-Language: ru-RU,ru;q=0.8,en-US;q=0.6,en;q=0.4

val=hello+from+Chrome
response:
HTTP/1.1 200 OK
Date: 26.11.2015 2:51:05
Server: nesterione-server
Content-Type: text/html; charset=UTF-8
Content-Length: 86
Connection: close

You entered value:<br><br>hello+from+Chrome<br><br><a href='/' > Open Index Page </a>
Waiting for client message...
request:
GET /favicon.ico HTTP/1.1
Host: localhost:8088
Connection: keep-alive
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2490.86 Safari/537.36
Accept: */*
Referer: https://localhost:8088/
Accept-Encoding: gzip, deflate, sdch
Accept-Language: ru-RU,ru;q=0.8,en-US;q=0.6,en;q=0.4


response:
HTTP/1.1 200 OK
Date: 26.11.2015 2:51:10
Server: nesterione-server
Content-Type: text/html; charset=UTF-8
Content-Length: 123
Connection: close

<form method='post'>hi, I'm https-server, input number:<br><input type='text' name='val' ><br><input type='submit' ></form>
