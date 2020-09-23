import logging
import math

from pynput import keyboard
from .limits import keyboard_limits
from .drive_parameters import CAR_ENGINE,STEERING_SERVO

LOGGER = logging.getLogger(__file__)

class Keyboard:
    """Keyboard event listener:
    On pressing w,a,s,d values on a x or y-axis are increased or decreased.
    w,s -> y-axis
    a,d -> x-axis

    The listener is non-blocking
    """
    def __init__(self,yaxis_range=512,xaxis_range=512):
        self.xaxis = 0
        self.yaxis = 0
        self._set_keyboard_parameter(yaxis_range,xaxis_range)
        
        self.power = self._keyboard_to_power(0)
        self.steering = self._keyboard_to_steering(0)
        
        self.listener = keyboard.Listener(
        on_press=self.on_press,
        on_release=self.on_release)
        self.listener.start()
        
    def on_press(self,key):
        #implement brake/reverse functionaliy
        try:
            if key.char == "w" and self.yaxis < self._KEY_LIMITS.yaxis_max:
                self.yaxis += 1
                self.power = self._keyboard_to_power(self.yaxis)
            elif key.char == "s"and self.yaxis > self._KEY_LIMITS.yaxis_min:
                self.yaxis -= 1
                self.power = self._keyboard_to_power(self.yaxis)
            elif key.char == "a"and self.xaxis < self._KEY_LIMITS.xaxis_max:
                self.xaxis += 5
                self.steering = self._keyboard_to_steering(self.xaxis)
            elif key.char =="d" and self.xaxis > self._KEY_LIMITS.xaxis_min:
                self.xaxis -= 5
                self.steering = self._keyboard_to_steering(self.xaxis)
                
            LOGGER.debug(f"xaxis:{self.xaxis} x-Limits:{self._KEY_LIMITS.xaxis_min} {self._KEY_LIMITS.xaxis_max}\
                           yaxis:{self.yaxis} y-Limits:{self._KEY_LIMITS.yaxis_min} {self._KEY_LIMITS.yaxis_max}")

        except AttributeError:
            LOGGER.debug('special key {0} pressed'.format(
                key))

    def on_release(self,key):
        if key == keyboard.Key.esc:
            # Stop listener
            return False
    
    def _keyboard_to_power(self,keyboard_input):
        power = self._p_to_k_range * (keyboard_input - self._KEY_LIMITS.yaxis_min)+CAR_ENGINE.dutycycle_min
        return round(power,2)

    def _keyboard_to_steering(self,keyboard_input):
        steering = self._s_to_k_range* (keyboard_input -self._KEY_LIMITS.xaxis_min)+STEERING_SERVO.pulsewidth_us_min
        return round(steering)

    def _set_keyboard_parameter(self,yaxis_range,xaxis_range):
        power_range = CAR_ENGINE.dutycycle_max - CAR_ENGINE.dutycycle_min
        self._p_to_k_range = power_range/yaxis_range

        yaxis_min = math.floor(-(CAR_ENGINE.dutycycle_center - CAR_ENGINE.dutycycle_min)\
                            /self._p_to_k_range)
        yaxis_max = yaxis_min + yaxis_range

        steering_range = STEERING_SERVO.pulsewidth_us_max - STEERING_SERVO.pulsewidth_us_min
        self._s_to_k_range = steering_range/xaxis_range

        xaxis_min = math.floor(-(STEERING_SERVO.pulsewidth_us_center - STEERING_SERVO.pulsewidth_us_min)\
                            /self._s_to_k_range)
        
        xaxis_max = xaxis_min + xaxis_range
        
        self._KEY_LIMITS = keyboard_limits(xaxis_range=xaxis_range,
                             xaxis_max=xaxis_max,
                             xaxis_min=xaxis_min,
                             yaxis_range=yaxis_range,
                             yaxis_max=yaxis_max,
                             yaxis_min=yaxis_min)
