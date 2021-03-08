# Smart-Romantic-Candle
# Artistic Vision
During the pandemic I used my extra time to learn about the stock market. After investing in my first few stocks I found myself constantly checking my Robinhood app to see how my stocks were doing. After months of sweating over the ups and downs of my stocks, I was hoping to create a piece of generative art that would portray the volatility of the market and the volatility of my emotions. When my stocks go down, burning money would rain on my screen, and when my stocks go up, green money would rain down. In a way, my work takes you through the up and down feelings the market is always bringing me. I was also able to display these emotions, through my LEDs, when my stocks go up they would light up into a green smiley face, and when they go down, the LEDs would light up into a red upside down smiley face.

# Materials
* Raspberry Pi 4B
* 8 RGB LED Module
* Female to Female Wires
* 9V Lithium Ion Battery Pack
* External Keyboard, Mouse & Monitor

# Project Overview
The project consisted of three scripts:
  * Python script that would read-in an updated stock price every 60 seconds and compare it to the previous price. If the new price was bigger than the old price it would write a 1 in a seperate text file, if it was smaller it would write a 0 in that text file. It would also update a seperate text file with the current price.
  * Another python script that would read the text file that had either a 0 or 1 in it and then turn on the LEDs to create a green smiley face if it was a 1 and a red upside down smiley face if it was a zero.
  * Processing Script that would read both text files to both update the display with the current price and use the 0 or 1 to determine whether the stock had gone up or down. When the stock goes up it would rain green money symbols and when it went down it would rain money symbols on fire.
# Processing
Information about installing Processing on your Raspberry Pi can be found [here](https://pi.processing.org/download/).
# NeoPixels
A detailed guide to setting up the wiring and turning on the LEDs [here](https://learn.adafruit.com/neopixels-on-raspberry-pi/raspberry-pi-wiring).
# Setting up the StockPi/Finnhub API
A detailed guide can be found [here](https://github.com/pranshuchittora/stockpi).
# Running on Boot
In order to run all of my scripts on boot I created a shell file run.sh, that had calls to all three of my scripts in it. Then, I made the shell file executable using `sudo chmod +x run.sh.` so I could add it to a bash file. Finally, after opening the bash file using `sudo nano ~/.bashrc` I added a call at the bottom to the run.sh executable file, so it would run the shell file on boot.
# Video
A video of my work can be found [here](https://www.youtube.com/watch?v=5K5YI9JsWlU).
