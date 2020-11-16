// # Editor    :Holiday from DFRobot
// # Data      09.10.2013
//for Arduino

// # Product name:Triple Axis Accelerometer MMA7361
// # Product SKU:SEN0143
// # Version :  2.0

// # Description:
// # This sample shows how to measure the angle value using two axis value

//Notes by Dan Davis:
//used the Arduino Uno or Arduino Mega and breadboard with the triple axis accelerometer. 
// use IDE serial monitor to review data.
// the accelerommeter must be shaken vigorously to see the serial angle value data  change
//use breadboard for connections to the positive and ground rails.
//reference : https://wiki.dfrobot.com/Triple_Axis_Accelerometer_MMA7361_SKU_DFR0143

#include<math.h>
#include<stdio.h>

#define A_X  5
#define A_Y  4
#define A_Z  3

int val_x,val_y,val_z;
double b;
void setup()
{
  pinMode(A_X,INPUT);
  pinMode(A_Y,INPUT);
  pinMode(A_Z,INPUT);
  Serial.begin(9600);
}
void loop()
{
  float a;
   for (int i=0;i<10;i++)
  {
    val_x+=analogRead(A_X);delay(2);
    val_y+=analogRead(A_Y);delay(2);
    val_z+=analogRead(A_Z);delay(2);
  }
   val_x=val_x/10;
   val_y=val_y/10;
   val_z=val_z/10;
   delay(300);
   Serial.print(" X_Axis: ");
   Serial.print(val_x);
   Serial.print(" Z_Axis: ");
   Serial.print(val_z);
   Serial.print("      ");
   b=(double) (abs(val_x-320))/(abs(val_z-320));
   Serial.print(" B: ");
   Serial.print(b);
   Serial.print("      ");
   a=atan(b);
   Serial.print(" A: ");
   Serial.println(a/3.14*180);              //the value of Angle
   val_x=0;
   val_y=0;
   val_z=0;

}
