from pynput import keyboard
import logging
import time

logging.basicConfig(level=logging.DEBUG)
LOGGER = logging.getLogger(__file__)

def on_press(key):
    try:
        LOGGER.debug('alphanumeric key {0} pressed'.format(
            key.char))
    except AttributeError:
        LOGGER.debug('special key {0} pressed'.format(
            key))

def on_release(key):
    LOGGER.debug('{0} released'.format(
        key))
    if key == keyboard.Key.esc:
        # Stop listener
        return False

# Collect events until released
"""
with keyboard.Listener(
        on_press=on_press,
        on_release=on_release) as listener:
    listener.join()

# ...or, in a non-blocking fashion:
"""
listener = keyboard.Listener(
    on_press=on_press,
    on_release=on_release)
listener.start()

while True:
    time.sleep(1)