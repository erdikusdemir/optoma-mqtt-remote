/*
 * code is compiled by erdi kusdemir. 2019.
 * 
procjetor remote controller for optoma hd39 darbee.
mqtt client used to send basic commands
power off         0
power on          1
bright/eco mode   2
hdmi1             3
hdmi2             4
*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRsend.h>

// Update these with values suitable for your network.

const char* ssid = "ssid";
const char* password = "pass for ssid";
const char* mqtt_server = "ip for mqtt server";
const char* mqtt_clientid = "projectorremote";
const char* mqtt_username = "user name for mqtt server";
const char* mqtt_password = "pass for mqtt server";
const char* outTopic = "projector/out";
const char* inTopic = "projector/in";

WiFiClient espClient;
PubSubClient client(espClient);

IRsend irsend(4);  // Set the GPIO to be used to sending the message.

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void setup_wifi() {
delay(10);
// We start by connecting to a WiFi network
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
irsend.begin();
}
//-----------------------------------------------callback---------------------------------------------
void callback(char* topic, byte* payload, unsigned int length) {
Serial.print("Message arrived [");
Serial.print(topic);
Serial.print("] ");
for (int i = 0; i < length; i++) {
Serial.print((char)payload[i]);
}
Serial.println();
// Switch on the LED if an 1 was received as first character
if ((char)payload[0] == '0') {//power off
Serial.println("ir power off");
irsend.sendNEC(0x4cb3748b); //power off
delay(100);
irsend.sendNEC(0x4cb3748b); //power off
}
if ((char)payload[0] == '1') {//power on
Serial.println("ir power on");
irsend.sendNEC(0x4cb340bf); //power on
}
if ((char)payload[0] == '2') {//brightness bright/eco
Serial.println("ir brightness mode");
irsend.sendNEC(0x4cb322dd); //brightness
delay(100);
irsend.sendNEC(0x4cb308f7); //sol
delay(100);
irsend.sendNEC(0x4cb3f00f); //ok
}
if ((char)payload[0] == '3') {//hdmi1
Serial.println("ir hdmi1");
irsend.sendNEC(0x4cb36897); //hdmi 1
} 
if ((char)payload[0] == '4') {//hdmi2
Serial.println("ir hdmi2");
irsend.sendNEC(0x4cb30cf3); //hdmi 2
} 
}
//-------------------------------------------------------------------------------------------------
void reconnect() {
// Loop until we're reconnected
while (!client.connected()) {
Serial.print("Attempting MQTT connection...");
// Attempt to connect
if (client.connect(mqtt_clientid, mqtt_username, mqtt_password)) {
Serial.println("connected");
// Once connected, publish an announcement...
client.publish(outTopic, "hello world");
// ... and resubscribe
client.subscribe(inTopic);
} else {
Serial.print("failed, rc=");
Serial.print(client.state());
Serial.println(" try again in 5 seconds");
// Wait 5 seconds before retrying
delay(5000);
}
}
}
void loop() {
if (!client.connected()) {
reconnect();
}
client.loop();
//-------------------------------------------publish---------------------------------------------
}//end loop
//-----------------------------------------------------------------------------------------  
