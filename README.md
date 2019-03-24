# optomamqttremote

This code is compiled from mqtt [pubsub](https://github.com/knolleary/pubsubclient) and [esp8266 ir remote](https://github.com/markszabo/IRremoteESP8266) library.  

Code is written for optoma hd39 darbee projector for basic functions.  
Connect your IRled to pin D2(GPIO04) and gnd (short leg of LED) for Wemos D1 pro.
Put your SSID, password and MQTT server information and upload it.

recorded ir codes are for remote controller below as follows;  
<img src="https://github.com/erdikusdemir/optomamqttremote/blob/master/remote.jpg" width="400">


protocol: NEC  
bits: 32  

```
0x4cb340bf power on  
0x4cb3748b power off  
0x4CB36C93 user 1  
0x4CB3A659 user 2  
0x4CB36699 user 3  
0x4CB3827D brightness  
0x4CB342BD contrast  
0x4CB3A05F display mode  
0x4CB3E01F keystone  
0x4CB326D9 aspect ratio  
0x4CB3916E 3D mode  
0x4CB34AB5 mute  
0x4cb322dd brightness mode  
0x4CB3C639 sleep timer  
0x4CB38877 volume up  
0x4cb308f7 left  
0x4cb3f00f return  
0x4cb348b7 right  
0x4CB328D7 volume down  
0x4cb3708f menu  
0x4cb36897 hdmi 1  
0x4cb30cf3 hdmi 2  
0x4CB3D827 vga 1  
0x4CB37887 vga 2  
0x4CB338C7 Video  
0x4CB3E817 YPbPr  
```

default mqtt receive topic is "projector/in"  
5 mqtt message is arranged  
0 - power off  
1 - power on  
2 - bright/eco mode  
3 - hdmi1  
4 - hdmi2  
