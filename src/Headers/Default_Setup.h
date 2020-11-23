#ifndef Default_Setup_h
#define Default_Setup_h

void WiFiEvent(WiFiEvent_t event)
{
    Serial.printf("[WiFi-event] event: %d\n", event);

    switch (event) {
        case SYSTEM_EVENT_WIFI_READY: 
            Serial.println("WiFi interface ready");
            WiFi.setHostname(hostName);
            break;
        case SYSTEM_EVENT_SCAN_DONE:
            Serial.println("Completed scan for access points");
            break;
        case SYSTEM_EVENT_STA_START:
            Serial.println("WiFi client started");
            break;
        case SYSTEM_EVENT_STA_STOP:
            Serial.println("WiFi clients stopped");
            break;
        case SYSTEM_EVENT_STA_CONNECTED:
            Serial.println("Connected to access point");
            break;
        case SYSTEM_EVENT_STA_DISCONNECTED:
            Serial.println("Disconnected from WiFi access point");
            break;
        case SYSTEM_EVENT_STA_AUTHMODE_CHANGE:
            Serial.println("Authentication mode of access point has changed");
            break;
        case SYSTEM_EVENT_STA_GOT_IP:
            Serial.print("Obtained IP address: ");
            Serial.println(WiFi.localIP());
            break;
        case SYSTEM_EVENT_STA_LOST_IP:
            Serial.println("Lost IP address and IP address is reset to 0");
            break;
        case SYSTEM_EVENT_STA_WPS_ER_SUCCESS:
            Serial.println("WiFi Protected Setup (WPS): succeeded in enrollee mode");
            break;
        case SYSTEM_EVENT_STA_WPS_ER_FAILED:
            Serial.println("WiFi Protected Setup (WPS): failed in enrollee mode");
            break;
        case SYSTEM_EVENT_STA_WPS_ER_TIMEOUT:
            Serial.println("WiFi Protected Setup (WPS): timeout in enrollee mode");
            break;
        case SYSTEM_EVENT_STA_WPS_ER_PIN:
            Serial.println("WiFi Protected Setup (WPS): pin code in enrollee mode");
            break;
        case SYSTEM_EVENT_AP_START:
            Serial.println("WiFi access point started");
            break;
        case SYSTEM_EVENT_AP_STOP:
            Serial.println("WiFi access point  stopped");
            break;
        case SYSTEM_EVENT_AP_STACONNECTED:
            Serial.println("Client connected");
            break;
        case SYSTEM_EVENT_AP_STADISCONNECTED:
            Serial.println("Client disconnected");
            break;
        case SYSTEM_EVENT_AP_STAIPASSIGNED:
            Serial.println("Assigned IP address to client");
            break;
        case SYSTEM_EVENT_AP_PROBEREQRECVED:
            Serial.println("Received probe request");
            break;
        case SYSTEM_EVENT_GOT_IP6:
            Serial.println("IPv6 is preferred");
            break;
    }}
static const inline void OTA_Request(){
ArduinoOTA.onStart([]() {
  });
  ArduinoOTA.onEnd([]() {
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    char p[32];
    sprintf(p, "Progress: %u%%\n", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    if (error == OTA_AUTH_ERROR){
    }
    else if(error == OTA_BEGIN_ERROR) {
    }
    else if(error == OTA_CONNECT_ERROR) {
    }
    else if (error == OTA_RECEIVE_ERROR) {
    }
    else if(error == OTA_END_ERROR) {
    } 
  });
}

static const inline void WiFi_AP(){
  WiFi.enableAP(true);
  WiFi.softAP(AP_ssid); //,AP_password
  delay(500);
}

static const inline void WiFi_STA(){
  WiFi.begin(STA_ssid, STA_password);
  while (WiFi.status() != WL_CONNECTED) {}
}

static const inline void Ota_Begin(){
  ArduinoOTA.setHostname(hostName);
  ArduinoOTA.setPort(3232);
  ArduinoOTA.begin();
}

static const inline void Requests(){
    /*server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        //request->send(LITTLEFS, "/New_Index.html");
        request->send(LITTLEFS, "/JoyStickTest.html");
    });*/

    server.on("/servo", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(LITTLEFS, "/servo.html");
    });

    server.on("/Stop_Servo", HTTP_GET, [](AsyncWebServerRequest *request){
        Is_Stop = true;
        Turn.detach();
        Servo_Controll = -1;
        AsyncWebServerResponse *response = request->beginResponse(200, "text/plain", "Stop_Ok");
        response->addHeader("Access-Control-Allow-Origin","*");
        request->send(response);
    });
    server.on("/Set_Servo", HTTP_GET, [](AsyncWebServerRequest *request){
        AsyncWebParameter* p = request->getParam(0);
        Servo_Controll = p->value().toInt();
        Turn.attach(14);
        Is_Stop = false;
        AsyncWebServerResponse *response = request->beginResponse(200, "text/plain", "Set_Ok");
        response->addHeader("Access-Control-Allow-Origin","*");
        request->send(response);
    });

    OTA_Request();
}

static const inline void Init_File_System(){
    Serial.begin(115200);
    LITTLEFS.begin();
}

static const inline void Init_Wifi(){
    //WiFi.onEvent(WiFiEvent);
    //WiFi_STA();
    //WiFi_AP();
    //server.begin();
    //Requests();
    //ws.onEvent(onWsEvent);
    //server.addHandler(&ws);
}

static const inline void Default_Setup(){
    Init_File_System();
    //WiFi.disconnect();
    Handle_Captive();
    //Init_Wifi();
    //Ota_Begin();
    Init_ESC();
}

#endif