## Smart Romantic Candle & Fireplace
# Artistic Vision
Over winter break my wife and I went to a graffiti workshop in Brooklyn where we learnt about the history and beauty behind graffiti and even got to practice some of the different techniques that the pros use. It is actually a lot harder than it looks! We have been searching for another way to do more graffiti (legally, of course) at home and this project was the perfect solution.

# Materials
* Raspberry Pi 4B
* ESP32-Wrover-Dev
* 1 LED
* Breadboard
* Photoresistor
* Bunch of Wires (2 were used for capacitive touch sensors)
* 9V Lithium Ion Battery Pack
* External Monitor
* Bottle of Rosé
* 2 Wine Glasses

# Project Overview
The project consisted of two scripts that allowed for serial Bluetooth communication between the Raspberry Pi and the ESP32:

* An Arduino script that setup the ESP32 for serial Bluetooth communication with the Raspberry Pi. The ESP32 would acquire three input values from the user/environment; two capacitive touch sensors and one photoresistor. One capacitive touch sensor would sense for a "double tap" while the other touch sensor would sense for any touch occurrence. The photoresistor would sense the amount of light in its environment. While on, the ESP32 would send messages to the Raspberry Pi based on the current input values.
* A python script that ran on the Raspberry Pi. The script would setup a connection over Bluetooth with the ESP32. Once the connection is made the Raspberry Pi would start receiving messages from the ESP32. These messages would be used to control both the fireplace and the music.

# Running the Simulator
In order to run this program, you first need to setup the hardware. Start by plugging in the ESP32 into the breadboard's GPIO at the top of the board. Then plug in the 2 push-buttons, the SPDT switch and the analog joystick into the GPIOS of your ESP32. Do this without obstructing your inputs with wires. Make sure that you plug the push-buttons and the switch into digital GPIO pins. Once the hardware is setup, edit any input pin numbers in the JoystickMouseControl.ino file to the GPIO pin numbers you used for your inputs. Then, load the file onto the ESP32 in the Arduino IDE. Open the serial monitor to check if your ESP32 is printing the proper values for your inputs. Then connect the ESP32 via a serial USB cable to the Raspberry Pi and turn it on. Finally, run the processing script, HI.pde, on the Raspberry Pi and start painting!

# Communicating Over Bluetooth

For the ESP32 to send data serially the script loaded on it must include `Serial.begin(9600)` in the setup. Everytime within the script you want to write data to the serial you use `Serial.write()`. To give your Raspberry Pi access to this data you must connect your Pi with a USB to your ESP32. In Processing, you have to add `import processing.serial.*` and `Serial myPort` to the top of your script. Then in setup you add `String portName = Serial.list()[1]` and `myPort = new Serial(this, portName, 9600)` specifing both the serial port you want to access and the baud rate being used to send the data. Then you can access the data coming in with something like `String val = myPort.readStringUntil('\n')`, depending on what the application is.

# Technical Issues
My main difficulty was figuring out how to use the joystick and a push-button as a USB mouse on the raspberry pi. After figuring that out I realized that the delays between each of my input's data-writes to serial was slowing the movements of the joystick mouse but without the delays the processing script was not reacting quick enough for the simulator to work smoothly. After a few iterations I found a good medium where neither thing was reacting too slowly to my inputs. Another issue that came up was that my 
raspberry pi was getting very hot and therefore I decided not to put it inside the enclosure.

# Video
A video of my work can be found [here](https://www.youtube.com/watch?v=FdYzZxUisu8).
