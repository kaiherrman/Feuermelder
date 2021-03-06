# Feuermelder
<img src="https://raw.githubusercontent.com/kaiherrman/Feuermelder/master/logo.png" alt="" style="max-width:100%" width="auto" height="150">

![Build Status](https://travis-ci.org/dwyl/esta.svg?branch=master)
![version](https://img.shields.io/badge/version-1.0.0-blue.svg?maxAge=2592000)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)  

<b>Deutsch:</b><br>
Wer kennt das nicht, das Haus brennt, du bist nicht zuhause und kannst die Feuerwehr nicht rufen.
Mit unserer praktischen Anwendung bekommst du eine Benachrichtung, und du entscheidest selbst zwischen Versicherung und Feuerwehr

<b>English:</b><br>
Who's a stranger to that: The house is on fire, you're not at home and can't call the fire department.
With our practical application you get a notification, and you decide yourself between insurance and fire department

---

## Installation Guide

### General installation
First you need to download and install the [Arduino IDE](https://www.arduino.cc/en/Main/Software).
After that you have to install the Adafruit Huzzah 8266 support. Please follow this [instruction](https://arduino-esp8266.readthedocs.io/en/latest/installing.html).

### Server (Sensor) installation: 
First you need to install the [DMT.h libary](https://github.com/adafruit/DHT-sensor-library) (Version 1.2.3).
We are using an old version because the new version isn't working, see [Issue](https://github.com/adafruit/DHT-sensor-library/issues/62 ).
Change your upload speed to 115200 and select the right port.
After that please copy the server.ino code into the Arduino IDE and upload it to the Arduino.

### Client (Actuator) installation:
Change your upload speed to 115200 and select the right port.
After that please copy the client.ino code into the Arduino IDE and upload it to the Arduino. 

<b>Important:</b> 
- Don't forget to change your Access Point Information in the code.
- Don't forget to update the address of the server inside the client code. The server will print the address inside the serial monitor.

---

## Circuit diagrams 

### Server: 
![alt text](https://raw.githubusercontent.com/kaiherrman/Feuermelder/master/Feuermelder_server_circuit_diagram.png)

### Client: 
![alt text](https://raw.githubusercontent.com/kaiherrman/Feuermelder/master/Feuermelder_client_circuit_diagram.png)
