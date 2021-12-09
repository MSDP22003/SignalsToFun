#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 2048

// Define Motor Pins (2 Motors used)

#define motorPin1  8     // Blue   - 28BYJ48 pin 1
#define motorPin2  9     // Pink   - 28BYJ48 pin 2
#define motorPin3  10    // Yellow - 28BYJ48 pin 3
#define motorPin4  11    // Orange - 28BYJ48 pin 4

int EMG1Speed=0;
int EMG1=0;

Stepper stepper1(STEPS, motorPin1, motorPin3, motorPin2, motorPin4);

void setup() {
  Serial.begin(9600);
  stepper1.setSpeed(15); //this affects how quickly data is being collected
}

void loop() {
    EMG1 = analogRead(A0); // analog pin connected to EMG1 output
    EMG1Speed = 0;
    stepper1.step(EMG1Speed);
    Serial.println(EMG1);
     while(EMG1 >200){ //this line should be adaptable based on peoples baseline
      EMG1 = analogRead(A0);
      EMG1Speed = 2*(EMG1 + 200);//this line controls the speed that the motor spins at
      stepper1.step(EMG1Speed);
      Serial.println(EMG1);
     }    
}
