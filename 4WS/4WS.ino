#include<Servo.h>

//4WS - Draft 1
//Date: 17.02.20 12:22 GMT

int mspeed = 0;
int steer_inp = A0;
int throt_inp = A1;
int mot[]={5,6};
Servo steer_f, steer_r;
float steer_ratio = 0.5;
int spd_thresh = 400;
void setup() {
  steer_f.attach(10);
  steer_r.attach(11);
  pinMode(mot[0],OUTPUT);
  pinMode(mot[1],OUTPUT);
}
void loop()
{
  update_speed();
  update_steering(); 
}
void update_speed()
{
  mspeed=map(analogRead(throt_inp),0,1023,0,255);
  analogWrite(mot[0],mspeed);
}
void update_steering()
{
  int steer_val=map(analogRead(steer_inp),0,1023,0,180);
  if(mspeed > spd_thresh)
  {
    steer_f.write(steer_val);
    steer_r.write(steer_val);
  }
  else
  {
    steer_f.write(steer_val);
    steer_r.write(-steer_val*steer_ratio);
  }
}
