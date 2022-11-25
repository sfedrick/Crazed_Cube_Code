#include <Arduino.h>
#include "useful_funcs.h"

void get_keyboard_input(int &idx,char *angle_str, bool &ready){
    

    if (Serial.available() > 0) {
    angle_str[idx] = Serial.read();
    if (angle_str[idx] == LF) {
        Serial.print("Received new angle: ");
        angle_str[idx-1] = 0;
        Serial.println(angle_str);
        ready = true;
        idx = -1;
        }
    else{
        ready = false;
    }
    
    idx++;
    }

}