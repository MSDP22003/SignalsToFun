// change this to the number of steps on your motor
#define STEPS 4096

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
  //stepper1.setSpeed(10); //this affects how quickly data is being collected
}

void loop() {
 
      EMG1 = analogRead(A0);
      if (EMG1>120)\\120 is level of noise
      {
      EMG1Speed = 10*EMG1/600;//this line controls the speed that the motor spins at based on analog input \600 should be able to change based on individual
      stepper1.setSpeed(EMG1Speed); //this affects how quickly data is being collected
      stepper1.step(1);}
      Serial.print(0); // To freeze the lower limit
Serial.print(" ");
Serial.print(1000); // To freeze the upper limit
Serial.print(" ");
Serial.println(EMG1); // To send all three 'data' points to the plotter
  
}
