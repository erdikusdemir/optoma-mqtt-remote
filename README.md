# optomamqttremote

This code is compiled from mqtt pubsub and esp8266 ir remote library.

Code is written for optoma hd39 darbee projector for baasic functions.

recorded ir codes are as follows;
protocol: NEC
bits: 32

irsend.sendNEC(0x4cb3708f); //menu tusu
irsend.sendNEC(0x4cb3748b); //power off
irsend.sendNEC(0x4cb340bf); //power on
irsend.sendNEC(0x4cb322dd); //brightness
irsend.sendNEC(0x4cb36897); //hdmi 1
irsend.sendNEC(0x4cb30cf3); //hdmi 2
irsend.sendNEC(0x4cb308f7); //sol
irsend.sendNEC(0x4cb348b7); //sag
irsend.sendNEC(0x4cb3f00f); //ok

default mqtt receive topic is "projector/in"
5 mqtt message is arranged
0 - power off
1 - power on
2 - bright/eco mode
3 - hdmi1
4 - hdmi2
