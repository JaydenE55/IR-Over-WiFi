#define BLYNK_PRINT Serial

//Required Libraries
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t IRPin = 13; //Defines What Pin Is Used For The IR Blaster, Change 13 If You Want To Use A Different Pin.
IRsend irsend(IRPin); 

//Fill In Your Blynk Auth Key, Network Name, and Password.
char auth[] = "BlynkAuthKey";
char ssid[] = "NetworkName";
char pass[] = "NetworkPassword";

void setup(){
  irsend.begin(); //Starts The IR Send Library
  Serial.begin(115200); //Starts The Serial Connection
  Blynk.begin(auth, ssid, pass); //Initiates The Connection To Blynk and Your Network
}

void loop()
{
  Blynk.run(); //Starts Blynk
}

// This Is A Simple Button
BLYNK_WRITE(V0) {  // V0 Defines What Pin It Should Be Recieving Values From In The Blynk App
if (param.asInt() == 1) {
  irsend.sendNEC(IR-Code,32); // Replace "IR-Code" With The Code For Your Device, 32 Is How Many Bits The Code Is. Leave It At 32 or It May Not Work.
  Serial.println("Power Sent"); // Outputs a Message In The Serial Monitor When It Runs
}
}

// This Is a Step Button, Essentially Two Button's In One Widget. I Used It To Adjust Temperature
BLYNK_WRITE(V1) {  // V1 Defines What Pin It Should Be Recieving Values From In The Blynk App
switch (param.asInt()) {
case -1: // This Section Is When You Press Down Or - On The Widget
  irsend.sendNEC(IR-Code,32); // Replace "IR-Code" With The Code For Your Device, 32 Is How Many Bits The Code Is. Leave It At 32 or It May Not Work.
  Serial.println("Temp Down Sent"); // Outputs a Message In The Serial Monitor When It Runs
  break;
case 1: // This Section Is When You Press Up Or + On The Widget
  irsend.sendNEC(IR-Code,32); // Replace "IR-Code" With The Code For Your Device, 32 Is How Many Bits The Code Is. Leave It At 32 or It May Not Work.
  Serial.println("Temp Up Sent"); // Outputs a Message In The Serial Monitor When It Runs
  break;
}
}
