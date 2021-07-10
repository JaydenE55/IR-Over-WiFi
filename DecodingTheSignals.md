How to decode your remote signals

1. Open Arduino and connect the ESP/Arduino to your computer
2. From "Files" select example go down and from IRremoteESP8266 select the IRrecvDumpV2.
3. Upload to your ESP/Arduino.
4. If you used the IR Reciever I linked, then connect the "Data" Pin to Pin 14, Then Connect the "VCC" pin to 3.3v, and finally the "GND" pin to ground.
5. Point your remote at the IR reciever and click a button, look for a value starting in 0x, that will be your NEC code.
6. Save what button you pressed and the code linked to that button in a text document.
7. Now you have your codes, continue step 7 in "README.md".
