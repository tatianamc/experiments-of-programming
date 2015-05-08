```
$ npm install -g tsd
$ tsd query angular2 --action install
```

### Run type script compiler

```
npm install -g typescript@^1.5.0-beta
$ tsc --watch -m commonjs -t es5 --emitDecoratorMetadata app.ts
```

### Run server
# From the directory that contains index.html:
npm install -g http-server  # Or sudo npm install -g http-server
http-server                 # Creates a server at localhost:8080
# In a browser, visit localhost:8080/index.html