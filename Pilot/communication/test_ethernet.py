import socket
from ethnetcomm import TCPServer

def test_class_creation():
    address = (192.168.178.)
    server = TCPServer()
    
    assert type(server._socket) is socket.socket
