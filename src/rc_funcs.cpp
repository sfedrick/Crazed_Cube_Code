 #include <Arduino.h>
 #include <Servo.h> 
int Sconstrain(int X,int a,int b){
  if(X<a){
    return a;
  }
  else if( X>b){
    return b;
  }
  else{
    return X;
  }
}



void set_holonomic_direction(int *wheel_speeds,int y, int x ,int cw) {
  int vx = y;
  int vy = x;
  int w = -cw;

  wheel_speeds[0] = (vx + vy - w); // front left 
  wheel_speeds[1]  = (vx - vy + w);// front right 
  wheel_speeds[2] = (vx - vy - w); // rear left
  wheel_speeds[3] = (vx + vy + w); // rear right


  wheel_speeds[0] =Sconstrain(wheel_speeds[0],-1,1);
  wheel_speeds[1] =Sconstrain(wheel_speeds[1],-1,1);
  wheel_speeds[2] =Sconstrain(wheel_speeds[2],-1,1);
  wheel_speeds[3] =Sconstrain(wheel_speeds[3],-1,1);

}

int parralax_servo_conv(int wheelspeed){
  if(wheelspeed > 0){
    return map(wheelspeed,0,100,100,180);
  }
  else if( wheelspeed < 0){
    wheelspeed = wheelspeed*-1;
    return map(wheelspeed,0,100,100,180);
  }
  else{
    return 0;
  }

}

void holonomic_parralax_move(int *wheel_speeds, Servo *wheel_servos,int velocity){
  // i<4 for four wheels
  for (int i=0; i < 4 ; i++){
    int ws = wheel_speeds[i]*velocity;
    ws = parralax_servo_conv(ws);
    wheel_servos[i].write(ws);
  }

}