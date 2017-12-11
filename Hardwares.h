#include <Servo.h>
#include <Stepper.h>

const int pinD1 = 9;
const int pinD2 = 10;
const int pinD3 = 11;
const int lightPlus = 48;
const int lightMinus = 46;
const int grabber1=44;
const int grabber2=42;

const int gp = 0;
const int dz1 = 50;
const int dz2 = 100;
const int dz3 = -50;
const int org = -25;

Stepper stepper(200, 5, 6, 7, 8);
Servo D1,D2,D3;

int theta1_0=90;
int theta2_0=90;
int theta3_0=90;

int currPos = 0;

void powerServos()
{
  // TO-DO
  Serial.println("Powering Servos");
}

void initServos() {
  // put your setup code here, to run once:
  Serial.println("Initializing Servos");
  D1.attach(pinD1);  
  D2.attach(pinD2);  
  D3.attach(pinD3);
    
  D1.write(theta1_0);
  D2.write(theta2_0);
  D3.write(theta3_0);
  Serial.println("Done Initializing Servos");
  delay(100);  
}

void moveServos(float theta1, float theta2, float theta3, int steps, int stepDelay) {
  // put your main code here, to run repeatedly:

    int del1_0 = (D1.read());
    int del2_0 = (D2.read());
    int del3_0 = (D3.read());
    
    int del1 = (theta1-del1_0)/steps;
    int del2 = (theta2-del2_0)/steps;
    int del3 = (theta3-del3_0)/steps;

    
    for(int i = 0; i < steps; i++)
    {
    del1_0 += del1;
    del2_0 += del2;
    del3_0 += del3;
    D1.write(del1_0);
    D2.write(del2_0);
    D3.write(del3_0); 
    Serial.println("Step:" + String(i) + " " + String(del1_0) + ' ' + String(del2_0) + ' ' + String(del3_0));
    delay(stepDelay);     
    }
    D1.write(theta1);
    D2.write(theta2);
    D3.write(theta3);
    Serial.println(String(theta1) + ' ' + String(theta2) + ' ' + String(theta3));
    }  
void setupLights()
{
  pinMode(lightPlus,OUTPUT);
  pinMode(lightMinus,OUTPUT);
  digitalWrite(lightPlus,LOW);
  digitalWrite(lightMinus,LOW);  
}
void lightWorkSpace(int flg)
{
  if(flg!=0)
  {
    digitalWrite(lightPlus,HIGH);
  }
  else
  {
     digitalWrite(lightPlus,LOW)  ;  
  }
}
void initStepper()
{
  stepper.setSpeed(3);
  stepper.step(1);  
}

void moveStepper(String val)
{
  int steps;
  if(val.equals("gp"))
  {
    steps = gp - currPos;
    currPos=gp;
  }
  else if(val.equals("dz1"))
  {
    steps = dz1 - currPos;
    currPos=dz1;
  }
    else if(val.equals("dz2"))
  {
    steps = dz2 - currPos;
    currPos=dz2;
  }
    else if(val.equals("dz3"))
  {
    steps = dz3 - currPos;
    currPos=dz3;
  }
    else if(val.equals("org"))
  {
    steps = org - currPos;
    currPos=org;
  }
    else
  {
    Serial.println("Unrecognized Command");
  }
  stepper.step(steps);
}


void initialize_grabber(){
  pinMode(grabber1,OUTPUT);
  pinMode(grabber2,OUTPUT);
  Serial.println("Grabber Initialized");
}

void closeGrabber()
{
  digitalWrite(grabber1,HIGH);
  digitalWrite(grabber2,LOW);
  delay(4500);
  digitalWrite(grabber1,LOW);
}

void openGrabber()
{
  
  digitalWrite(grabber2,HIGH);
  digitalWrite(grabber1,LOW);
  delay(4500);
  digitalWrite(grabber2,LOW);
}

