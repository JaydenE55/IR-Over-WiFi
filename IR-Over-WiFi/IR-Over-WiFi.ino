#define BLYNK_PRINT Serial
//Required Libraries
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

// Fill in information here.
char auth[] = ""; // Fill in your Blynk Authorization Key.
char ssid[] = ""; // Fill in your WiFi SSID/Name.
char pass[] = ""; // Fill in your WiFi password.
int IRPin = 0; // Fill in what pin you want to use for the IR Blaster.


IRsend irsend(IRPin); 

void setup(){
  irsend.begin(); // Starts The IR Send Library.
  Serial.begin(115200); // Starts The Serial Connection.
  Blynk.begin(auth, ssid, pass); // Starts Blynk
}

void loop()
{
  Blynk.run(); // Runs Blynk.
}

// Here are your buttons, I have included 2 different types, a normal button and a step button.
// If you need more buttons just copy one and paste it, be sure to change the virtual pin or it wont work.
// Each button has a description on what it does and what it can be used for.

// This Is A Simple Button. Ex. Power Button
BLYNK_WRITE(V0) {  // V0 Defines What Pin It Should Be Recieving Values From In The Blynk App.
if (param.asInt() == 1) {
  irsend.sendNEC(IR-Code,32); // Replace "IR-Code" With The Code For Your Device.
}
}

// This Is a Step Button, Essentially Two Button's In One Widget. Ex. Volume Control
BLYNK_WRITE(V1) {  // V1 Defines What Pin It Should Be Recieving Values From In The Blynk App.
switch (param.asInt()) {
case -1: // This Section Is When You Press Down Or - On The Widget
  irsend.sendNEC(IR-Code,32); // Replace "IR-Code" With The Code For Your Device.
  break;
case 1: // This Section Is When You Press Up Or + On The Widget
  irsend.sendNEC(IR-Code,32); // Replace "IR-Code" With The Code For Your Device.
  break;
}
}
