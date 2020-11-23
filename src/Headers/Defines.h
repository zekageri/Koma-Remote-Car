#ifndef Defines_h
#define Defines_h

xTaskHandle ESC_Test_Task_Handle;

Servo ESC;
Servo Turn;
DNSServer dnsServer;
AsyncWebServer server(80);
AsyncWebServerRequest *request;
AsyncWebSocket    ws("/test");

int pos = 0;
int zeroThrottle = 90;
int maxThrottle = 120;
int minThrottle = 60;

int Prev_Y = 0;
int Prev_X = 0;
char Fl_Data[200];
String Full_Data = "";
boolean Can_Process_Controll = false;

char hostName[] = "AutoCont";

const char* AP_ssid = "Auto_Controll";
const char* AP_password = "Administrator";

const char* STA_ssid = "Emelet";
const char* STA_password = "Administrator";


void ESC_Test_Task(void * parameter);
static const inline void Requests();

boolean Is_Stop = true;
int Servo_Controll = -1;

#endif