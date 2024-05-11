#include <BluetoothSerial.h>

#define TROUBLE_SHOOT 0

#define DELAY 300   //RED BLUE YELLOW GREEN
#define TRAY_1 19 
#define TRAY_2 21
#define TRAY_3 22
#define TRAY_4 23

#define DELAY_A 700 //2700
#define DELAY_B 700//2800
#define DELAY_C 200//2800
#define DELAY_D 800//2700

#define TRAY_1_ENABLE (digitalWrite(TRAY_1,0))
#define TRAY_2_ENABLE (digitalWrite(TRAY_2,0))
#define TRAY_3_ENABLE (digitalWrite(TRAY_3,0))
#define TRAY_4_ENABLE (digitalWrite(TRAY_4,0))

#define TRAY_1_DISABLE (digitalWrite(TRAY_1,1))
#define TRAY_2_DISABLE (digitalWrite(TRAY_2,1))
#define TRAY_3_DISABLE (digitalWrite(TRAY_3,1))
#define TRAY_4_DISABLE (digitalWrite(TRAY_4,1))

#define IR_1 25
#define IR_2 26
#define IR_3 27
#define IR_4 32

#define PULSE 17
#define DIRECTION 18

bool enable_1st_tray = 0;
bool enable_2nd_tray = 0;
bool enable_3rd_tray = 0;
bool enable_4th_tray = 0;

bool ir_detect = 0;
String command = " ";
char cmd = ' ';
uint32_t previous_millis = 0;
uint16_t time_interval = 20000;
uint32_t millis_test = 0;

BluetoothSerial SerialBT;
void ir_check() {
  if (TROUBLE_SHOOT) {Serial.println("ir_checking");}
  if (!digitalRead(IR_1)) { ir_detect = 1; } 
  if (!digitalRead(IR_2)) { ir_detect = 1; }
  if (!digitalRead(IR_3)) { ir_detect = 1; }
  if (!digitalRead(IR_4)) { ir_detect = 1; }
}
void disable_all () {
  if (TROUBLE_SHOOT) {Serial.println("disabling_enabled");}
   ir_detect = 0;
   command = " ";
   previous_millis = 0;
   TRAY_1_DISABLE;
   TRAY_2_DISABLE;
   TRAY_3_DISABLE;
   TRAY_4_DISABLE;
}



void start_motorA()
{
  if (TROUBLE_SHOOT) { Serial.println("motor started"); }
while  (((millis() - previous_millis) <= time_interval)&&(!ir_detect)) {
     yield();
    digitalWrite (PULSE, 1);
    delayMicroseconds(DELAY);
    digitalWrite (PULSE, 0);
    delayMicroseconds(DELAY);
    ir_check();} 
    while(SerialBT.available() > 0) { char fl = SerialBT.read(); yield(); }
    for(uint i = 0; i < 25000; i ++ )
    {
      digitalWrite (PULSE, 1);
      delayMicroseconds(DELAY);
      digitalWrite (PULSE, 0);
      delayMicroseconds(DELAY);
    }disable_all ();


}
    
void start_motorB()
{
  if (TROUBLE_SHOOT) { Serial.println("motor started"); }
while  (((millis() - previous_millis) <= time_interval)&&(!ir_detect)) {
     yield();
    digitalWrite (PULSE, 1);
    delayMicroseconds(DELAY);
    digitalWrite (PULSE, 0);
    delayMicroseconds(DELAY);
    ir_check();} 
    while(SerialBT.available() > 0) { char fl = SerialBT.read(); yield(); }
    for(uint i = 0; i < 25000; i ++ )
    {
      digitalWrite (PULSE, 1);
      delayMicroseconds(DELAY);
      digitalWrite (PULSE, 0);
      delayMicroseconds(DELAY);
    }disable_all ();


}
    
void start_motorC()
{
  if (TROUBLE_SHOOT) { Serial.println("motor started"); }
while  (((millis() - previous_millis) <= time_interval)&&(!ir_detect)) {
     yield();
    digitalWrite (PULSE, 1);
    delayMicroseconds(DELAY);
    digitalWrite (PULSE, 0);
    delayMicroseconds(DELAY);
    ir_check();} 
    while(SerialBT.available() > 0) { char fl = SerialBT.read(); yield(); }
    for(uint i = 0; i < 25000; i ++ )
    {
      digitalWrite (PULSE, 1);
      delayMicroseconds(DELAY);
      digitalWrite (PULSE, 0);
      delayMicroseconds(DELAY);
    }disable_all ();


}
    
void start_motorD()
{
  if (TROUBLE_SHOOT) { Serial.println("motor started"); }
while  (((millis() - previous_millis) <= time_interval)&&(!ir_detect)) {
     yield();
    digitalWrite (PULSE, 1);
    delayMicroseconds(DELAY);
    digitalWrite (PULSE, 0);
    delayMicroseconds(DELAY);
    ir_check();} 
    while(SerialBT.available() > 0) { char fl = SerialBT.read(); yield(); }
    for(uint i = 0; i < 25000; i ++ )
    {
      digitalWrite (PULSE, 1);
      delayMicroseconds(DELAY);
      digitalWrite (PULSE, 0);
      delayMicroseconds(DELAY);
    }
    
disable_all ();


}
void setup() {
pinMode(IR_1,INPUT_PULLUP);
pinMode(IR_2,INPUT_PULLUP);
pinMode(IR_3,INPUT_PULLUP);
pinMode(IR_4,INPUT_PULLUP);
pinMode(PULSE,OUTPUT);
pinMode(DIRECTION,OUTPUT);
pinMode(TRAY_1,OUTPUT);
pinMode(TRAY_2,OUTPUT);
pinMode(TRAY_3,OUTPUT);
pinMode(TRAY_4,OUTPUT);

digitalWrite (DIRECTION, 0);

disable_all ();

Serial.begin(9600);
Serial.setTimeout(5);
SerialBT.begin("KARASTASE_VM");
Serial.println("started");
SerialBT.setTimeout(1);
}

void serial_check() {

 if(SerialBT.available() > 0) { 
     previous_millis = millis();
     cmd =  SerialBT.read();if ((cmd == '\n'))
    {
     return;
    }
  
  if (TROUBLE_SHOOT) {Serial.println("received command is " +String(command));}
  data_process ();
 
}
}
void data_process () {
  if (TROUBLE_SHOOT) { Serial.println("data process activated");}
if ( cmd == 'A') {if (TROUBLE_SHOOT) {Serial.println("A received");}
                     Serial.println("A");   command = " ";TRAY_1_ENABLE; delay(DELAY_A); start_motorA();}
                     
if ( cmd == 'B') {if (TROUBLE_SHOOT) {Serial.println("B received");}
                     Serial.println("B");command = " ";TRAY_2_ENABLE; delay(DELAY_B); start_motorB();}

if ( cmd == 'C') {if (TROUBLE_SHOOT) {Serial.println("C received");}
                     Serial.println("C");command = " ";TRAY_3_ENABLE; delay(DELAY_C); start_motorC();}

if ( cmd == 'D') {if (TROUBLE_SHOOT) {Serial.println("D received");}
                     Serial.println("D");command = " ";TRAY_4_ENABLE; delay(DELAY_D); start_motorD();}
}
//
//void start_motor()
//{
//  if (TROUBLE_SHOOT) { Serial.println("motor started"); }
//while  (((millis() - previous_millis) <= time_interval)&&(!ir_detect)) {
//     yield();
//    digitalWrite (PULSE, 1);
//    delayMicroseconds(DELAY);
//    digitalWrite (PULSE, 0);
//    delayMicroseconds(DELAY);
//    ir_check();} 
//    while(SerialBT.available() > 0) { char fl = SerialBT.read(); yield(); }
//    for(uint i = 0; i < 25000; i ++ )
//    {
//      digitalWrite (PULSE, 1);
//      delayMicroseconds(DELAY);
//      digitalWrite (PULSE, 0);
//      delayMicroseconds(DELAY);
//    }



void loop() {
 serial_check();

}
