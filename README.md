# Smart Romantic Candle & Fireplace

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
This link helped me setup the ESP32 for Bluetooth communication [here](https://www.instructables.com/ESP32-Bluetooth-Tutorial-How-to-Use-Inbuilt-Blueto/) and these two links helped me setup the Raspberry Pi for Bluetooth communication [here](https://helloraspberrypi.blogspot.com/2020/12/python-on-raspberry-pi-bluetooth.html) & [here](https://github.com/pybluez/pybluez).

# Technical Issues
It seemed like the capacitive sensors were causing a bunch of problems with the electronics that were in close proximity to them and even the Bluetooth connection (but I am not 100% sure). So I tried to steer those two wires away from the others as best as I could.

# Video
A video of my work can be found [here](https://www.youtube.com/watch?v=FdYzZxUisu8).
