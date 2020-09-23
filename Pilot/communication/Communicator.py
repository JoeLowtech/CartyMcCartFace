import socketserver
import socket
import logging
from google.protobuf.internal.encoder import _VarintBytes

import communication.messages_pb2 as messages_pb2

LOGGER = logging.getLogger(__file__)

class MCUCommunicator:
    """Handles communication with the MCU via ethernet.
    Protobuf is used as message protocol.
    """
    def __init__(self,HOST,PORT):
        self.host = HOST
        self.port = PORT
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.message = messages_pb2.driveMessage()

        LOGGER.info(f"Connecting to {self.host}:{self.port}")
        self.socket.connect((self.host,self.port))
        LOGGER.info("Connected to server.")

    def send_drive(self,steering,power):
        """Send drive values to the microcontroller
        """
        self.message.steering = steering
        self.message.power = power
        message_to_send = self._encode_message()
        self.socket.sendall(message_to_send)

    def _encode_message(self):
        encoded_message = self.message.SerializeToString()
        #Add length of message at the front 
        return _VarintBytes(self.message.ByteSize()) + encoded_message
