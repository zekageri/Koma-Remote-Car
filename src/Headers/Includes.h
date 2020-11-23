#ifndef Includes_h
#define Includes_h

#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoOTA.h>
#include <Update.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
//#include <ESPmDNS.h>
#include <ArduinoJson.h>
#include <DNSServer.h>

#include <ESP32_Servo.h> 

#define FS_NO_GLOBALS
#include <FS.h>
#include "LITTLEFS.h"

#include <Headers/Defines.h>
#include <Headers/AsyncWebSocket.h>
#include <Headers/CaptivePortal.h>

#include <Headers/Motor_Setup.h>
#include <Headers/Default_Setup.h>

#endif