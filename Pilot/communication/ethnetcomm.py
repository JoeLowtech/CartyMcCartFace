"""Module for ethernet communication"""
import socketserver
import socket
import logging
import time
from google.protobuf.internal.encoder import _VarintBytes

from messages import messages_pb2

logging.basicConfig(level=logging.DEBUG)
LOGGER = logging.getLogger(__file__)

if __name__ == "__main__":
    HOST, PORT = "192.168.178.36", 9999
    message = messages_pb2.driveMessage()
    message.steering = 1500
    message.power = 1.0
    encoded_data = message.SerializeToString()
    data_to_send = _VarintBytes(message.ByteSize()) + encoded_data
    
    LOGGER.info(f"Connecting to {HOST}:{PORT}")
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        # Connect to server and send data
        sock.connect((HOST, PORT))
        LOGGER.info("Connected to server.")
        
        while True:
            LOGGER.info(f"send data: {data_to_send}")
            sock.sendall(data_to_send)
            time.sleep(1)

    