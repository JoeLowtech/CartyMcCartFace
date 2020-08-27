import logging

from pynput import keyboard

LOGGER = logging.getLogger(__file__)

class Keyboard:
    
    def __init__(self):
        self.xaxis = 0
        self.yaxis = 0
        
        self.listener = keyboard.Listener(
        on_press=self.on_press,
        on_release=self.on_release)
        self.listener.start()
        
    def on_press(self,key):
        try:
            if key.char == "w":
                self.yaxis += 1
            elif key.char == "s":
                self.yaxis -= 1
            elif key.char =="a":
                self.xaxis -= 1
            elif key.char == "d":
                self.xaxis += 1
            LOGGER.debug(f"xaxis:{self.xaxis} yaxis: {self.yaxis}")

        except AttributeError:
            LOGGER.debug('special key {0} pressed'.format(
                key))

    def on_release(self,key):
        if key == keyboard.Key.esc:
            # Stop listener
            return False
