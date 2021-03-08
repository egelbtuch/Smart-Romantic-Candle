# Smart Romantic Candle & Fireplace
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
In order to run this program, you first need to setup the hardware. Start by plugging in the ESP32 into the breadboard's GPIO at the top of the board. Then plug in the two capacitive touch sensor wires, the LED, and the photoresistor into the GPIOS of your ESP32. Once the hardware is setup, edit any input pin numbers in the SmartCandle.ino file to the GPIO pin numbers you used for your inputs. Then, follow the instructions below to setup Bluetooth communication on your ESP32 and Raspberry Pi. After that you want to install [vlc-ctrl](https://pypi.org/project/vlc-ctrl/) and [omxplayer](https://github.com/popcornmix/omxplayer) on the Raspberry Pi for control of the music and fireplace video. Then upload your favorite music to your Raspberry Pi and create a playlist in the VLC app. After that you have to upload a video for your fireplace. Finally, run an updated version of SmartCandle.py on your Raspberry Pi with the bluetooth address of your ESP32 and the file path to both your fireplace video and music playlist.

# Communicating Over Bluetooth
This link helped me setup the ESP32 for Bluetooth communication [here](https://www.instructables.com/ESP32-Bluetooth-Tutorial-How-to-Use-Inbuilt-Blueto/) and these two links helped me setup the Raspberry Pi for Bluetooth communication [here](https://helloraspberrypi.blogspot.com/2020/12/python-on-raspberry-pi-bluetooth.html) & [here](https://github.com/pybluez/pybluez).

# Technical Issues
It seemed like the capacitive sensors were causing a bunch of problems with the electronics that were in close proximity to them and even the Bluetooth connection (but I am not 100% sure). So I tried to steer those two wires away from the others as best as I could.

# Video
A video of my work can be found [here](https://www.youtube.com/watch?v=FdYzZxUisu8).
