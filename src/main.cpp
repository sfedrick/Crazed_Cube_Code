#include <Arduino.h>
#include <Servo.h> 
#include "useful_funcs.h"
char angle_str[10];
int angle_int[10];
int idx=0;
bool ready = false;


#define onboard 13


#define onboard 13
void setup() {
  // put your setup code here, to run once:
  pinMode(onboard,OUTPUT);
  Serial.begin(9600);
  Serial.print(" I am Starting \r\n");
  idx = 0;
}

void loop() {
  get_keyboard_input(idx,angle_str,ready);
  if(ready){
    Serial.println("outside function");
    Serial.println(angle_str);
    char2int(2,angle_str, angle_int);
   
    delay(1000);
  }
    
 
}