#ifndef CaptivePortal_h
#define CaptivePortal_h


class CaptiveRequestHandler : public AsyncWebHandler {
public:
  CaptiveRequestHandler() {}
  virtual ~CaptiveRequestHandler() {}
  bool canHandle(AsyncWebServerRequest *request){
    return true;
  }

void handleRequest(AsyncWebServerRequest *request) {
    AsyncWebServerResponse* response = request->beginResponse(LITTLEFS, "/JoyStickTest.html", "text/html");
    //response->addHeader("Content-Encoding", "gzip");
    request->send(response);
 }

};

static const inline void Handle_Captive(){
    WiFi.softAP(AP_ssid); //, password
    delay(100);
    dnsServer.start(53, "*", WiFi.softAPIP());
    ws.onEvent(onWsEvent);
    server.addHandler(&ws);
    server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER);
    server.begin();
    delay(100);
    IPAddress IP = WiFi.softAPIP();
    Serial.print("Koma_Auto Started with ip: ");
    Serial.println(IP);
}


#endif