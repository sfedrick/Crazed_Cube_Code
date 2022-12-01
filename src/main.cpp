#include <Arduino.h>

// #include "useful_funcs.h"
// #include "rc_funcs.h"
// #include "pin_def_globals.h"

// char keyboard[10];

// int idx=0;
// bool ready = false;
// int val =0;


// long int t1 = millis();
// long int printme = 0;

// #define onboard 13


// int direction[3];

// int debug;

// void setup() {
//   // put your setup code here, to run once:
//   pinMode(onboard,OUTPUT);
//   Serial.begin(9600);
//   Serial.print(" I am Starting \r\n");
//   idx = 0;
//   wheel_servos[0].attach(WHEEL1);
//   wheel_servos[1].attach(WHEEL2);
//   wheel_servos[2].attach(WHEEL3);
//   wheel_servos[3].attach(WHEEL4);
// }

// void loop() {
  
//   get_keyboard_input(idx,keyboard,ready);

//   if(ready && printme%10000==0){
//     Serial.println("current wheel speed w1,w2,w3,w4");
//     Serial.print(wheel_speeds[0]);
//     Serial.print(",");
//     Serial.print(wheel_speeds[1]);
//     Serial.print(",");
//     Serial.print(wheel_speeds[2]);
//     Serial.print(",");
//     Serial.print(wheel_speeds[3]);
//     Serial.println(" ");


//     Serial.println("Direction y,x,cw");
//     Serial.print(direction[0]);
//     Serial.print(",");
//     Serial.print(direction[1]);
//     Serial.print(",");
//     Serial.print(direction[2]);
//     Serial.println(" ");


  

//     char2int(3,keyboard, direction);
//     // delay(1000);
//   }

//   y = direction[0];
//   x = direction[1];
//   cw = direction[2];

//  set_holonomic_direction(wheel_speeds,y, x,cw);
//  holonomic_parralax_move(wheel_speeds, wheel_servos,VELOCITY);
//  printme++;
// }

//color code 

int s0=3,s1=4,s2=5,s3=6;
int out=2;
int flag=0;
byte counter=0;
byte countR=0,countG=0,countB=0;
void setup()
 {
 Serial.begin(9600);
 pinMode(s0,OUTPUT);
 pinMode(s1,OUTPUT);
 pinMode(s2,OUTPUT);
 pinMode(s3,OUTPUT);

 }

  void timer0_init(void)
 {
  TCCR2A=0x00;
  TCCR2B=0x07;   //the clock frequency source 1024 points
  TCNT2= 100;    //10 ms overflow again
  TIMSK2 = 0x01; //allow interrupt
 }

void ISR_INTO()
 {
 counter++;
 }


void TCS()
 {
 flag=0;
 digitalWrite(s1,HIGH);
 digitalWrite(s0,HIGH);
 digitalWrite(s2,LOW);
 digitalWrite(s3,LOW);
 attachInterrupt(0, ISR_INTO, CHANGE);
 timer0_init();

 }

 int i=0;
 ISR(TIMER2_OVF_vect)//the timer 2, 10ms interrupt overflow again. Internal overflow interrupt executive function
{
    TCNT2=100;
    flag++;
 if(flag==1)
  {
    countR=counter;
    digitalWrite(s2,HIGH);
    digitalWrite(s3,HIGH);
  }
  else if(flag==2)
   {
    countG=counter;
    digitalWrite(s2,LOW);
    digitalWrite(s3,HIGH);
   }
   else if(flag==3)
    {
    countB=counter;
    digitalWrite(s2,LOW);
    digitalWrite(s3,LOW);

    }
    else if(flag==4)
     {
     flag=0;
     }
       counter=0;
}
void loop()
 {
  TCS();
  Serial.print("red=");
  Serial.println(countR,DEC);
  
  Serial.print("green=");
  Serial.println(countG,DEC);

  Serial.print("blue=");
  Serial.println(countB,DEC);
  Serial.println("\n");
  delay(1000);
 }