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

long int t1 = millis();
long int printme = 0;

#define onboard 13

int y;
int x;
int cw;
int direction[3];

int debug;

void setup() {
  // put your setup code here, to run once:
  pinMode(onboard,OUTPUT);
  Serial.begin(9600);
  Serial.print(" I am Starting \r\n");
  idx = 0;
  wheel_servos[0].attach(WHEEL1);
  wheel_servos[1].attach(WHEEL2);
  wheel_servos[2].attach(WHEEL3);
  wheel_servos[3].attach(WHEEL4);
}

void loop() {
  
  get_keyboard_input(idx,keyboard,ready);

  if(ready && printme%10000==0){
    Serial.println("current wheel speed w1,w2,w3,w4");
    Serial.print(wheel_speeds[0]);
    Serial.print(",");
    Serial.print(wheel_speeds[1]);
    Serial.print(",");
    Serial.print(wheel_speeds[2]);
    Serial.print(",");
    Serial.print(wheel_speeds[3]);
    Serial.println(" ");


    Serial.println("Direction y,x,cw");
    Serial.print(direction[0]);
    Serial.print(",");
    Serial.print(direction[1]);
    Serial.print(",");
    Serial.print(direction[2]);
    Serial.println(" ");


  

    char2int(3,keyboard, direction);
    // delay(1000);
  }

 set_holonomic_direction(wheel_speeds,y, x,cw);
 holonomic_parralax_move(wheel_speeds, wheel_servos,VELOCITY);
 printme++;
}