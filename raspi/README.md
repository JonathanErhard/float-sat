# Here are the applications running on the RasPi.
They get autostarted by this line in `/home/floatsatgroup2/.config/lxsession/LXDE-pi/autostart` :
```bash
@lxterminal -e python3 /home/floatsatgroup2/FloatsatProject/pythonsoc.py
```

## pythonsoc.py
This programm is launched on startup of the RasPi. It first starts the uart-python-led-router , then the LED Communication application.
It's job then is to watch the camera images for QR Codes, and send found contents to the router via (TO BE FINALIZED!)

To run: have opencv, opencvcontrib, pyzbar and pycamera2 installed. 

## rodos-uart-led-router
Establishes Connection with the STM board via UART. Distributes received messages via UDP to pythonsoc.py and ledCommunications, and forwards them to the STM board.

Uses rodos and Konstantin Winkels Rodos-Workspace (https://gitlab.com/rodos/rodos)

To build+run: ./scripts/build.sh

## ledCommunications
Controlls the LED. Gets/Sends messages to the router via UDP.
Uses cppgpio as a precompiled library (https://github.com/JoachimSchurig/CppGPIO)

To build: ./comp.sh (using the present precompiled libraries. If they dont work for some reason, recompile them for your platform)

To run: ./a.out
