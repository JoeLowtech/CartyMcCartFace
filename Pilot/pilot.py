"""Pilots the car with direct control"""
import logging
import time

import communication.Communicator as Communicator
from controller.keyboard import Keyboard

logging.basicConfig(level=logging.DEBUG)
LOGGER = logging.getLogger(__file__)

class Pilot:
    """Uses MCUCommunicator-Class and Keyboard-Class to control the drive of the car
    Args:
        HOST(string): IP of the host to connect to
        PORT(Int): Port of the host
        input(string): Type of controller the pilot should use
    """
    def __init__(self, HOST, PORT, input="Keyboard"):
        self.communication = Communicator.MCUCommunicator(HOST,PORT)
        if input == "Keyboard":
            self.keyboard = Keyboard()
        else :
            LOGGER.error("input not supported")


if __name__ == "__main__":
    car_pilot = Pilot("192.168.178.36", 9999)

    while True:
        time.sleep(1)

