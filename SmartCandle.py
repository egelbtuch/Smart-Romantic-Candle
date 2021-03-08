import subprocess
import time
import os
from bluetooth import *
            

buf_size = 2048;

# Create the client socket
sock=BluetoothSocket(RFCOMM)
sock.connect(('24:**:**:**:**:**', 1))
print("connected")
subprocess.Popen(['omxplayer','/home/pi/Downloads/Black.mp4'],stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=subprocess.PIPE, close_fds=True)

while True:
    data = sock.recv(buf_size)
    data = data.decode('utf-8')
    if data == "ON":
        subprocess.Popen(['vlc-ctrl',  'play',  '-p /home/pi/Music/Playlist.xspf'])
        os.system('killall omxplayer.bin')
        subprocess.Popen(['omxplayer','/home/pi/Downloads/Burning.mp4'],stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=subprocess.PIPE, close_fds=True)
        data = sock.recv(buf_size)
        data = data.decode('utf-8')
        while data != "OFF":
            data = sock.recv(buf_size)
            data = data.decode('utf-8')
            if data == "SONG":
                subprocess.Popen(['vlc-ctrl',  'next'])
                data = sock.recv(buf_size)
                data = data.decode('utf-8')
            elif data == "VOLUME":
                subprocess.Popen(['vlc-ctrl',  'volume', '+.01'])
                data = sock.recv(buf_size)
                data = data.decode('utf-8')
                    
        subprocess.Popen(['vlc-ctrl',  'quit'])
        os.system('killall omxplayer.bin')
        subprocess.Popen(['omxplayer','/home/pi/Downloads/Black.mp4'],stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=subprocess.PIPE, close_fds=True)
        os.system('killall omxplayer.bin')
