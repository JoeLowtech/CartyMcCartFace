"""Parameters tied to the drive of the car, like motor engine and the steering servo"""
from collections import namedtuple

motor_parameters = namedtuple("motor_parameters",["dutycycle_max",
                                                  "dutycycle_min",
                                                  "dutycycle_center"])

CAR_ENGINE = motor_parameters(dutycycle_max=0.9,
                              dutycycle_min=0.3,
                              dutycycle_center=0.4)

servo_parameters = namedtuple("servo_parameters",["pulsewidth_us_max",
                                                  "pulsewidth_us_min",
                                                  "pulsewidth_us_center"])

STEERING_SERVO = servo_parameters(pulsewidth_us_max=1680,
                                  pulsewidth_us_min=1240,
                                  pulsewidth_us_center=1450)