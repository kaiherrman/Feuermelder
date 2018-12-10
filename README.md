# Feuermelder
Wer kennt das nicht, das Haus brennt, du bist nicht zuhause und kannst die Feuerwehr nicht rufen.
Mit unserer praktischen Anwendung bekommst du eine Benachrichtung, und du entscheidest selbst zwischen Versicherung und Feuerwehr

### General installation
First you need to setup the [Arduino IDE](https://www.arduino.cc/en/Main/Software).
After that you have to install the Addahfruit Huzzah 8266 support. Please follow this [instruction](https://arduino-esp8266.readthedocs.io/en/latest/installing.html).

### Server (Sensor) installation: 
First you need to install the DMT.h libary (Version 1.2.3).
We are using an old version because the new version isn't working, see [Issue](https://github.com/adafruit/DHT-sensor-library/issues/62 ).
Change your upload speed to 115200 and select the right port.
After that please upload the server.ino code to the Arduino IDE and upload it to the Arduino.