# IR-Over-WiFi
AirCon-Control allows you to connect to an ESP8266 using Blynk and control your IR device wirelessly from your smartphone. 

## --DISCLAIMER--
This project will only work if your device your accepts Infared signals from a remote or similar device.
It also only accepts NEC format IR codes.

## Deprecated
With the migration to Blynk.cloud, it would be very difficult and time comsuming to convert this project to the new platform, so I am deeming the project dead.

## Getting Started
1. Download the Blynk App from the Google Play or App Store and install it and create an account.
2. Create a new project, once you've created your project you should've been emailed an authorization key, save that for later.
3. Click the + button on the top right and add a button and a step widget.
4. Click that button and change the output pin to V0.
5. Click The Step Button and change the pin to V1.
6. Download the code and the required dependencies located below.
7. Edit the Auth Key, WiFi Name, Password, IR Codes, and the pin used for the IR Blaster.
8. Then flash the ESP/Arduino with the edited code, and also plug your IR Blaster into the pin you set in step 7, VCC and ground. (please be sure to read all of the notes in the arduino code so that you know what to change)
9. Point the blaster at the device your controlling.
10. Open the Blynk app and click the + button at the top right and use the button's to control your device.

## WiFi Connection
This device will require internet access at all times to function properly. The ESP will only need internet access to communicate with Blynk's servers. I am in no way interfering with your connection to and from Blynk.

## Remote control over WiFi
1. Power on the ESP/Arduino.
2. Open the Blynk app 
3. Select the play button to start the connection
4. Click your Button
5. Watch it control your device.

## Requires Dependencies
|                    |                                                                 |
|--------------------|-----------------------------------------------------------------| 
| ESP8266 Libraries  | https://github.com/esp8266/Arduino                              | 
| Blynk Library      | https://github.com/blynkkk/blynk-library                        |
| IRRemote Library   | https://github.com/Arduino-IRremote/Arduino-IRremote            |
| ESP8266 Board      | http://arduino.esp8266.com/stable/package_esp8266com_index.json |

## Bill of Materials
|     |              |                                     |
|-----|--------------|-------------------------------------|
| Qty | Description  | Link                                |
| 1   | ESP8266/12E  | https://www.amzn.com/dp/B08B4P67N8/ |
| 1   | Jumper Wires | https://www.amzn.com/dp/B01EV70C78/ |
| 1   | IR Blaster   | https://www.amzn.com/dp/B01E20VQD8/ |

Note: The jumper wires are an assorted pack of F to F, M to M, and M to F.
The IR Blaster also includes a reciever, you could use that to find the IR codes.
To find the codes for your device, read "DecodingTheSignals.md".
