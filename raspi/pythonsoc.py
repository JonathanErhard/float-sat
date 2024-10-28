#! bin/python3
import os
os.system("lxterminal -e /home/floatsatgroup2/FloatsatProject/uart-python-led-router/tst")
os.system("lxterminal -e sudo /home/floatsatgroup2/FloatsatProject/ledCommunications/a.out")
import math
import socket
import queue
import threading
import subprocess
import time
import os
import struct
import cv2
from pyzbar.pyzbar import decode

from picamera2 import MappedArray, Picamera2, Preview

qcd = cv2.QRCodeDetector()

width = 1280
height = 960

picam2 = Picamera2()
picam2.start_preview(Preview.QTGL)
config = picam2.create_preview_configuration(main={"size": (width, height)})
picam2.configure(config)
picam2.set_controls({"ExposureTime": 50000, "AnalogueGain": 1.0})

picam2.start()

cx = math.tan(62.2*math.pi/180)
cy = math.tan(48.8*math.pi/180)

qr_encodes = {"Mattei": "1", "Aparna" : "2" , "Simon": "3", "Konstantin": "4", "Madjid": "5", "Fernando": "6"}

#x = format(math.atan(x_pixel_pos)*180/math.pi, '+010.5f')
#sendingQueue.put("F"+qr_encodes[b.data.decode('utf-8')]+x+"#")
current_codes = {}
prev_data = "no data yet"
def camThreadFunc(name): 
  global current_codes, prev_data
  while True:
    rgb = picam2.capture_array("main")

    
    barcodes = decode(rgb)
    if len(barcodes) > 0:
      for b in barcodes:
        x_pixel_pos = b.rect.left+b.rect.width/2 -width/2
        y_pixel_pos = b.rect.top+b.rect.height/2 -height/2
         
        print(b.data.decode('utf-8'), -(53.5/width)*x_pixel_pos)
        if b.data.decode('utf-8') in qr_encodes:
          current_codes[qr_encodes[b.data.decode('utf-8')]] = [-(53.5/width)*x_pixel_pos , -(53.5/width)*y_pixel_pos]
        else:
          current_codes["7"] = [-(53.5/width)*x_pixel_pos, -(53.5/width)*y_pixel_pos]
          prev_data = b.data.decode('utf-8')
          print("SET DATA: "+prev_data)
    else:
      pass
    

camThread = threading.Thread(target=camThreadFunc, args=(1,))
camThread.start()

UDP_IP = "127.0.0.1"
UDP_PORT_IN = 5555
UDP_PORT_OUT = 5556

sock_in = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock_in.bind((UDP_IP, UDP_PORT_IN))

sock_out = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock_out.connect((UDP_IP, UDP_PORT_OUT))

def to_float(c):
  float_bits = 0
  for i in range(8):
    current_number = ord(c[i]) - ord('a')
    float_bits += current_number << (i*4)
  result = struct.unpack('f', struct.pack('I', float_bits))[0]
  return float(result)

sendingQueue = queue.Queue()

def senderThreadFunc(name):
  while True:
    if not sendingQueue.empty():
      msg = sendingQueue.get()
      if len(msg) > 64 :
        print("msg from py to Rodos too long")
      else:
        print("sendin", msg)
        toSend = msg.encode()
        sock_out.sendto(toSend, (UDP_IP, UDP_PORT_OUT))
    time.sleep(0.1)
        

def recvThreadFunc(name):
  global current_codes
  global prev_data
  
  while True:
    data, addr = sock_in.recvfrom(64)
    data_str = data.decode();
    print("got", data_str)
    if data_str.startswith("PAY_START"):
      #sendingQueue.put("LTURNON#")
      current_codes = {}
      threading.Timer(10, stop_search).start()
    elif data_str.startswith("PSENDDATA"):
      print("I'm forced against my will to send some data")
      sendingQueue.put("L"+prev_data+"#")
      y = format(0.0, '+010.5f')
      x = format(0.0, '+010.5f')
      sendingQueue.put("F"+"9"+x+y+"T"+"#")  # TODO if things crash, this is the problem xD 
		

def stop_search():
  global current_codes, prev_data, sendingQueue
  print("search end")
  print(current_codes)
  sendingQueue.put("LTURNOFF#")
  closest = ()
  closest_val = 9999999999999999999
  key = ""
  for b,a in current_codes.items():
    if abs(a[0]) < closest_val:
      closest_val = a[0]
      closest = a
      key = b

  #closest: x/y coords rel to camera
  #key: which qr code we scanned (1=Matei=GroundStation)
  #prev_data: data from previous data qr-code
  
  if closest_val == 9999999999999999999:
    sendingQueue.put("F00#")
  else:
    x_pos = closest[0]
    stat = "F"
    if key=="1" : 
      GS_offset = 11.0
      x_pos += GS_offset
      print(x_pos)
      if abs(x_pos)<5: #offset from QR code to LED at dist = 14.0cm (bowl to plate of GS)
          print("sending data via LED: "+prev_data)
          sendingQueue.put("L"+prev_data+"#")
          stat = "T"
      else:
          print("Telling STM to adjust pos")
          stat="F"
          
      y = format(closest[1], '+010.5f')
      x = format(x_pos, '+010.5f')
      sendingQueue.put("F"+key+x+y+stat+"#")
      return           
      
    if abs(x_pos) < 15:
      y = format(closest[1], '+010.5f')
      x = format(x_pos, '+010.5f')
      sendingQueue.put("F"+key+x+y+stat+"#")
    else:
      sendingQueue.put("F00#")  
    
senderThread = threading.Thread(target=senderThreadFunc, args=(1,))
senderThread.start()

recvThread = threading.Thread(target=recvThreadFunc, args=(1,))
recvThread.start()


      
