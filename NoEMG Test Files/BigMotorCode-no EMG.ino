/*Example sketch to control a stepper motor with A4988 stepper motor driver, AccelStepper library and Arduino: continuous rotation. More info: https://www.makerguides.com */

// Include the Stepper library:
#include <Stepper.h>

#define dirPin 8
#define stepPin 9


// Create a new instance of the AccelStepper class:
Stepper stepper = Stepper(200, stepPin, dirPin);

void setup() {
  // Set the maximum speed in rads per second:
}

void loop() {
  // Set the speed in rads per second:
  stepper.setSpeed(20);
  // Step the motor with a constant speed as set by setSpeed():
  stepper.step(5);
}
