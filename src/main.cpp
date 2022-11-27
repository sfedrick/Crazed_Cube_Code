#include <Arduino.h>

#include "useful_funcs.h"
#include "rc_funcs.h"
#include "pin_def_globals.h"

char keyboard[10];

int idx=0;
bool ready = false;
int val =0;
Servo myservo;  // create servo object to control a servo

#define onboard 13


#define onboard 13
void setup() {
  // put your setup code here, to run once:
  pinMode(onboard,OUTPUT);
  Serial.begin(9600);
  Serial.print(" I am Starting \r\n");
  idx = 0;
  myservo.attach(9);
}

void loop() {
  get_keyboard_input(idx,keyboard,ready);
  if(ready){
    Serial.println("outside function");
    Serial.println(val);
    char2int(4,keyboard, wheel_speed);
    // delay(1000);
  }
  // val = map(angle_int[0], 0, 9, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  // myservo.write(val);                  // sets the servo position according to the scaled value
  // delay(1000);                           // waits for the servo to get there 
 
}