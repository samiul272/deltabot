#include <math.h> 

const double h =  0.04;
const double L =  0.205;
const double l =  0.513;
const double sB = 0.183;
const double sP = 0.10;
double offset[3] = {90 , 93, 87};

double wB ;//= sB / (2 * sqrt(3));
double uB ;//= sB / sqrt(3);
double wP ;//= sP / (2 * sqrt(3));
double uP ;//= sP / sqrt(3);

double a ;//= wB - uP;
double b ;//= sP / 2 - (sqrt(3) * wB / 2);
double c ;

double E[3];
double F[3];
double G[3];
double theta[3];

void initKin()
{
   wB = sB / (2 * sqrt(3));
   uB = sB / sqrt(3);
   wP = sP / (2 * sqrt(3));
   uP = sP / sqrt(3);
  
   a = wB - uP;
   b = sP / 2 - (sqrt(3) * wB / 2);
   c = wP - wB / 2;
}
void invKin(double x, double y, double z)
{
 // Serial.println(x);
  //Serial.println(y);
  //Serial.println(z);
   
  E[0] = 2 * L * (y + a);
  F[0] = 2 * z * L;
  G[0] = x * x + y * y + z * z + a * a + L * L + 2 * a * y - l * l;

  E[1] = -L * (sqrt(3) * (x + b) + y + c);
  F[1] = 2 * z * L;
  G[1] = x * x + y * y + z * z + b * b + c * c + L * L + 2 * (b * x + c * y) - l * l;

  E[2] = L * (sqrt(3) * (x - b) - y - c);
  F[2] = 2 * z * L;
  G[2] = x * x + y * y + z * z + b * b + c * c + L * L + 2 * (-b * x + c * y) - l * l;
//  Serial.println(String(E[1]) + " " + String(E[2]) + " " + String(E[3]));
//  Serial.println(String(F[1]) + " " + String(F[2]) + " " + String(F[3]));
//  Serial.println(String(G[1]) + " " + String(G[2]) + " " + String(G[3]));
  for (int i = 0; i <= 2; i++) {
//    double num = F[i] + sqrt(E[i] * E[i] + F[i] * F[i] - G[i] * G[i]);
//    double den = G[i] - E[i];
    theta[i] = 2*atan(F[i] + sqrt(E[i]*E[i] + F[i]*F[i] - G[i]*G[i]))/(G[i] - E[i]+.0001);
    //Serial.println(theta[i]);
    theta[i] = round(theta[i] * 180 / 3.1415) + offset[i] ;
   // Serial.println(theta[i]);
    
  }
}


