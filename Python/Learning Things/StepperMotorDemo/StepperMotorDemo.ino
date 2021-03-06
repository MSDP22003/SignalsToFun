/*
  Stepper Motor Demonstration 2
  Stepper-Demo2.ino
  Demonstrates Two 28BYJ-48 Unipolar Steppers with ULN2003 Driver
  Uses Accelstepper Library

  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

// Include the AccelStepper Library
#include <Stepper.h>

// Define Constants

// Define step constants
#define FULLSTEP 4
#define HALFSTEP 8

// Define Motor Pins (2 Motors used)

#define motorPin1  8     // Blue   - 28BYJ48 pin 1
#define motorPin2  9     // Pink   - 28BYJ48 pin 2
#define motorPin3  10    // Yellow - 28BYJ48 pin 3
#define motorPin4  11    // Orange - 28BYJ48 pin 4
                        
                        
#define motorPin5  2     // Blue   - 28BYJ48 pin 1
#define motorPin6  3     // Pink   - 28BYJ48 pin 2
#define motorPin7  4     // Yellow - 28BYJ48 pin 3
#define motorPin8  5     // Orange - 28BYJ48 pin 4
float  EMG1Speed=500;
float  EMG2Speed=500;

// Define two motor objects
// The sequence 1-3-2-4 is required for proper sequencing of 28BYJ48
Stepper stepper1(2048, motorPin1, motorPin3, motorPin2, motorPin4);
Stepper stepper2(2048, motorPin5, motorPin7, motorPin6, motorPin8);

void setup()
{
    stepper1.setSpeed(EMG1Speed);
    stepper2.setSpeed(EMG2Speed);
//  // 1 revolution Motor 1 CW
//  stepper1.setMaxSpeed(1000.0);
//  stepper1.setAcceleration(50.0);
//  stepper1.setSpeed(EMG1Speed);
 // stepper1.moveTo(2048);  
  
//  // 1 revolution Motor 2 CCW
//  stepper2.setMaxSpeed(1000.0);
//  stepper2.setAcceleration(50.0);
//  stepper2.setSpeed(EMG2Speed);
//  stepper2.moveTo(-2048); 
}


void loop()
{
// /Change direction at the limits
//  if (stepper1.distanceToGo() == 0) 
//    stepper1.moveTo(-stepper1.currentPosition());
//    else stepper1.moveTo(stepper1.currentPosition());
//  if (stepper2.distanceToGo() == 0) 
//    stepper2.moveTo(-stepper2.currentPosition());
//    else stepper2.moveTo(stepper2.currentPosition());
  stepper1.step();
  stepper2.step();
  stepper1.run();
  stepper2.run();
//
}
