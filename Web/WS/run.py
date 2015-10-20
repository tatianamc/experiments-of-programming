import tornado.web
import tornado.httpserver
import tornado.ioloop
import time
from wsrpc import WebSocketRoute, WebSocket, wsrpc_static

class ExampleClassBasedRoute(WebSocketRoute):
    def init(self, **kwargs):
        return self.socket.call('whoAreYou', callback=self._handle_user_agent)

    def _handle_user_agent(self, ua):
        print ua

    def serverSideFunction(self, *args, **kwargs):
        return args, kwargs

WebSocket.ROUTES['test'] = ExampleClassBasedRoute
WebSocket.ROUTES['getTime'] = lambda: time.time()

if __name__ == "__main__":
    http_server = tornado.httpserver.HTTPServer(tornado.web.Application((
        # Генерирует url со статикой q.min.js и wsrpc.min.js
        # (подключать в том же порядке)
        wsrpc_static(r'/js/(.*)'),
        (r"/ws/", WebSocket),
        (r'/(.*)', tornado.web.StaticFileHandler, {
             'path': os.path.join(project_root, 'static'),
             'default_filename': 'index.html'
        }),
    ))
    http_server.listen(options.port, address=options.listen)
    WebSocket.cleapup_worker()
    tornado.ioloop.IOLoop.instance().start()