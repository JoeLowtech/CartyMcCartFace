"""Module for ethernet communication"""
import socketserver
import socket
import logging
import time
# import ifaddr
logging.basicConfig(level=logging.DEBUG)
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
    pass

class MyTCPHandler(socketserver.BaseRequestHandler):
    """
    The request handler class for our server.

    It is instantiated once per connection to the server, and must
    override the handle() method to implement communication to the
    client.
    """

    def handle(self):
        # self.request is the TCP socket connected to the client
        self.data = self.request.recv(1024).strip()
        print("{} wrote:".format(self.client_address[0]))
        print(self.data)
        # just send back the same data, but upper-cased
        self.request.sendall(self.data.upper())

if __name__ == "__main__":
    HOST, PORT = "192.168.178.36", 9999
    data = bytes([0x00,0x01,0x02,0x03,0x04])

    LOGGER.info(f"Connecting to {HOST}:{PORT}")
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        # Connect to server and send data
        sock.connect((HOST, PORT))
        LOGGER.info("Connected to server.")
        
        while True:
            LOGGER.info("send data.")
            sock.sendall(data)
            time.sleep(1)

    