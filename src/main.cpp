#include <Headers/Includes.h>

void setup() {
  Default_Setup();
  Turn.write(90);
}


static const inline void Servo_Testing(){
    if(!Is_Stop){
        Turn.write(Servo_Controll);
    }
}

static const inline void Process_Data(){
  if(Can_Process_Controll){
    Can_Process_Controll = false;
    StaticJsonDocument<500> doc;
    DeserializationError error = deserializeJson(doc, Fl_Data);
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
  }
}

void loop() {
  //ArduinoOTA.handle();
  //Servo_Testing();
  Process_Data();
  vTaskDelay(1);
}