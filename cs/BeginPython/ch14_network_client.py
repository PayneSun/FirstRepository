'''
    ch14_network_client.py
    
    2018/06/12
'''


import socket


s = socket.socket()

host = socket.gethostname()
port = 1234

s.connect((host, port))
print s.recv(1024)