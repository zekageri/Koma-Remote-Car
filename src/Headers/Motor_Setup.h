#ifndef Motor_Setup_h
#define Motor_Setup_h


static const inline void Init_ESC_Test_Task(int Stack_Depth,int Core,int Priority){
    xTaskCreatePinnedToCore(ESC_Test_Task,"ESC_Test_Task",Stack_Depth,NULL,Priority,&ESC_Test_Task_Handle,Core);
}

static const inline void Init_ESC(){
    ESC.attach(22);
    Turn.attach(17);
}
/*
void ESC_Test_Task(void * parameter){
    Setup_ESC();
}
*/
#endif