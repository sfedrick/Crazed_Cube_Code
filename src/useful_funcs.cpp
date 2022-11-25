#include <Arduino.h>
#include "useful_funcs.h"

void get_keyboard_input(int &idx,char *char_array, bool &ready){
    if (Serial.available() > 0) {
    char_array[idx] = Serial.read();
    if (char_array[idx] == LF) {
        // Serial.print("Received new angle: ");
        char_array[idx-1] = 0;
        // Serial.println(char_array);
        ready = true;
        idx = -1;
        }
    else{
        ready = false;
    }
    
    idx++;
    }

}

void char2int(int num,char *char_array, int *int_array){
    for( int i=0; i<num; i++){
        int_array[i] = int(char_array[i] -  '0');
    }
}