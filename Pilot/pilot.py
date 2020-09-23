"""Pilots the car with direct control"""
import logging
import time

from communication.Communicator import MCUCommunicator
from controller.keyboard import Keyboard

logging.basicConfig(level=logging.DEBUG)
LOGGER = logging.getLogger(__file__)

class Pilot:
    """Uses MCUCommunicator-Class and Keyboard-Class to control the drive of the car
    Args:
        HOST(string): IP of the host to connect to
        PORT(int): Port of the host
        input(string): Type of controller the pilot should use
    """
    def __init__(self, HOST, PORT, input="Keyboard"):
        self.communication = MCUCommunicator(HOST,PORT)
        self.keyboard = None

        if input == "Keyboard":
            self.keyboard = Keyboard(yaxis_range=512)
        else :
            LOGGER.error("input not supported")
    
    def power(self):
        if self.keyboard:
            return self.keyboard.power
        else:
            return None

    def steering(self):
        if self.keyboard:
            return self.keyboard.steering
        else:
            return None

if __name__ == "__main__":
    car_pilot = Pilot("192.168.178.36", 9999)
    new_power = car_pilot.power()
    new_steering = car_pilot.steering()

    while True:
        LOGGER.debug(f"power : {car_pilot.power()}\
                       steering :{car_pilot.steering()}")
        
        if new_power != car_pilot.power() or new_steering != car_pilot.steering():
            new_power = car_pilot.power()
            new_steering = car_pilot.steering()
            car_pilot.communication.send_drive(new_steering,new_power)
                
        time.sleep(0.1)

