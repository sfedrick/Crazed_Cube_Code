#include <Arduino.h>
#include <Servo.h> 
#include "useful_funcs.h"
char angle_str[10];
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
  // put your main code here, to run repeatedly:
  // if(get_keyboard_input(idx,angle_str)){
  //   Serial.println(angle_str);
  // }
  // if (get_keyboard_input(idx,angle_str)){
  //   Serial.print("outside the function: ");
  //   Serial.println(angle_str);
  // }

  get_keyboard_input(idx,angle_str,ready);
  if(ready){
    Serial.println("outside function");
    Serial.println(angle_str);
    delay(1000);
  }
    
 
}