'''
    ch14_network_server.py
    
    2018/06/12
'''


import socket, select
from SocketServer import TCPServer, ForkingMixIn, ThreadingMixIn, StreamRequestHandler
from twisted.internet import reactor
from twisted.internet.protocol import Protocol, Factory

# s = socket.socket()
# 
# host = socket.gethostname()
# port = 1234
# s.bind((host, port))
# 
# s.listen(5)
# while True:
#     c, addr = s.accept()
#     print 'Got connection from',addr
#     c.send('Thank you for connecting')
#     c.close()


# class Server(ForkingMixIn, TCPServer):
#     pass
# 
# 
# class Handler(StreamRequestHandler):
#     def Handle(self):
#         addr = self.request.getpeername()
#         print 'Got connection from',addr
#         self.wfile.write('Thank you for connecting')
# 
# server = TCPServer(('', 1234), Handler)
# server.serve_forever()


# s = socket.socket()
# 
# host = socket.gethostname()
# port = 1234
# s.bind((host,port))
# 
# s.listen(5)
# inputs = [s]
# while True:
#     rs,ws,es = select.select(inputs, [], [])
#     for r in rs:
#         if r is s:
#             c, addr = s.accept()
#             print 'Got connection from', addr
#             inputs.append(c)
#         else:
#             try:
#                 data = r.recv(1024)
#                 disconnected = not data
#             except socket.error:
#                 disconnected = True
#             if disconnected:
#                 print r.getpeername(),'disconnected'
#                 inputs.remove(r)
#             else:
#                 print data
                
                
# s = socket.socket()
# host = socket.gethostname()
# port = 1234
# s.bind((host, port))
# 
# fdmap = {s.fileno(): s}
# 
# s.listen(5)
# p = select.select()
# p.register(s)
# while True:
#     events = p.poll()
#     for fd, event in events:
#         if fd = s.fileno():
#             c, addr = s.accept()
#             print 'Got connection from', addr
#             p.register(c)
#             fdmap[c.fileno()] = c
#         elif event & select.POLLIN:
#             data = fdmap[fd].recv(1024)
#             if not data:
#                 print fdmap[fd].getpeername,'disconnected'
#                 p.unregister(fd)
#                 del fdmap[fd]
#         else:
#             print data
    

class SimpleLogger(Protocol):
    def connectionMade(self):
        print 'Got connection from',self.transport.client
    def connectionLost(self):
        print self.transport.clinet,'disconnected'
    def dataReceived(self, data):
        print data

factory = Factory()
factory.protocol = SimpleLogger

reactor.listenTCP(1234, factory)
reactor.run()