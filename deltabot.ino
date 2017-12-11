#include "Kinematics.h"
#include "Hardwares.h"


double x = 0.3;
double y = 0.5;
double z = -1.1;

void setup(){
  delay(2000);
  Serial.begin(115200);
  // declare all pin connections as input/output
  initServos();
  initKin();
  Serial.println("Ready");
}

void loop(){
  if(Serial.available()>0)
  {
    x=Serial.parseFloat();
    y=Serial.parseFloat();
    z=Serial.parseFloat();
//    theta[0] = x;
//    theta[1] = y;
//    theta[2] = z;
    if(Serial.read() != '\n'){
    invKin( x,  y,  z);
    Serial.println(String(theta[0])+','+String(theta[1])+','+String(theta[2]));
    //moveServos(theta[0],theta[1],theta[2],15,50);
    }  

  delay(1000);
}
}

