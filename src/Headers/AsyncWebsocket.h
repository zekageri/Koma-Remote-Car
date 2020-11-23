#ifndef AsyncWebsocket_h
#define AsyncWebsocket_h

AsyncWebSocketClient * globalClient = NULL;
void onWsEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len){
  if(type == WS_EVT_CONNECT){
    Serial.println("Async_WebSocket_Connected");
    globalClient = client;
  } else if(type == WS_EVT_DISCONNECT){
    globalClient = NULL;
    Serial.println("Async_WebSocket_Disconnected");
  }else if(type == WS_EVT_DATA){
    for(int i=0; i < len; i++) {
      Fl_Data[i] = (char)data[i];
    }
    Can_Process_Controll = true;
  /*
    StaticJsonDocument<500> doc;
    DeserializationError error = deserializeJson(doc, data);
    if (error) {return;}else{
      int Y = doc["Y"]; int X = doc["X"];
      if(Prev_X != X){
        Prev_X = X;
        Turn.write(X);
      }
      if(Prev_Y != Y){
        Prev_Y = Y;
        if(Y == 180){Y = 230;}
        ESC.write(Y);
      }
    }
    */
  }
}


#endif