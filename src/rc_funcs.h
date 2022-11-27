#ifndef RC_FUNCS_H
   
    #include <Arduino.h>
    #include <Servo.h> 
    // sets the value for wheel array to correspond to the desired direction
    // y is forward, x is left or right, cw is clockwise 
    void set_holonomic_direction(int *wheel_speeds, int y, int x ,int cw);
    // helper function for set_holonomic_direction to floor wheel speeds to -1,0, or 1
    int Sconstrain(int X,int a,int b);
    //convert a wheel speed value of -100 to 100 to parrallax servo command
    int parralax_servo_conv(int wheelspeed);

    //move parralax servos 
    void holonomic_parralax_move(int *wheel_speeds, Servo *wheel_servos, int velocity);
   
#endif