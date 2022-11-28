
#ifndef PIN_DEF_GLOBALS_H
    #include <Servo.h> 
    #define WHEEL1 11
    #define WHEEL2 10
    #define WHEEL3 9
    #define WHEEL4 3

    #define VELOCITY 50// a range from 0 to 100 

    Servo wheel1; // front left 
    Servo wheel2; // front right 
    Servo wheel3; // rear left
    Servo wheel4; // rear right

    Servo scan;

    //values of wheel speed can be -1,0, or 1 scale by VELOCITY
    int wheel_speeds[4]; // [front left, front right, rear left, rear right] 
    Servo wheel_servos[4]; // [front left, front right, rear left, rear right] 

#endif