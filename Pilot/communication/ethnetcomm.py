"""Module for ethernet communication"""
import socket
import logging

LOGGER = logging.getLogger(__file__)

class TCPClient(object):
    """A TCP Client starting a connection on a certain IP and port"""
    def __init__(self):
        pass
    pass

class TCPServer:
    """A TCP Server listening on a certain port and establishing a connection with a TCP Client"""
    # socket
    # ip adress
    # port

    def __init__(self, address):
        self._socket = socket.create_server(address)
    