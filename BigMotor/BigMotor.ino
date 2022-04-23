// change this to the number of steps on your motor
#define STEPS 200
#include "Stepper.h"
// Define Motor Pins (2 Motors used)

#define dirPin  8     // Blue   - 28BYJ48 pin 1
#define stepPin  9     // Pink   - 28BYJ48 pin 2


int Max=50;// initial value, what somewhere close to noise
int EMG1Speed=0;
int EMG1=0;
int reset=0;
int calibrate=0;
int Min=10000;
const int Resetbutton= 2; //number of reset  button pin
const int calibratebutton=3; //number of calibration button pin
Stepper stepper1(STEPS, dirPin,stepPin);

void setup() {
  Serial.begin(9600);
  pinMode(Resetbutton, INPUT);
   pinMode(calibratebutton, INPUT);
  
}

void loop() {
 
EMG1 = analogRead(A0);
reset=digitalRead(Resetbutton);//read the state of reset button
calibrate=digitalRead(calibratebutton);// read the state of calibration button
//buttons will be equal to HIGH if pressed, and LOW if not pressed
  if (reset == HIGH){
        Max=50;
        Min=1000;
      }
  else if (calibrate == HIGH) {
      if (EMG1>Max){
            Max=EMG1;
        }
        if (EMG1<Min);
        Min=EMG1;
      }
   else {
   
      if (EMG1<(Min+20))//40 is arbitarty just to make it easier to stop the motor
      {
        stepper1.step(0);
      }
      else if(EMG1<Max/4){ //({//120 is level of noise, may need to fine tune
      
        EMG1Speed = 20;//this line controls the speed that the motor spins at based on analog input
        stepper1.setSpeed(EMG1Speed); //this affects how quickly data is being collected
        stepper1.step(5);
        }
      else if (EMG1>Max/4 && EMG1 <Max/2){//120 is level of noise, may need to fine tune
      
        EMG1Speed = 40;//this line controls the speed that the motor spins at based on analog input
        stepper1.setSpeed(EMG1Speed); //this affects how quickly data is being collected
        stepper1.step(5);
       }
        else if (EMG1>Max/2 && EMG1 <=3*Max/4){//120 is level of noise, may need to fine tune
      
        EMG1Speed = 60;//this line controls the speed that the motor spins at based on analog input
        stepper1.setSpeed(EMG1Speed); //this affects how quickly data is being collected
        stepper1.step(5);
        }
        else if (EMG1>3*Max/4 && EMG1 < Max){//120 is level of noise, may need to fine tune
      
        EMG1Speed = 80;//this line controls the speed that the motor spins at based on analog input
        stepper1.setSpeed(EMG1Speed); //this affects how quickly data is being collected
        stepper1.step(5);
        }
      else {
        EMG1Speed = 100;//this line controls the speed that the motor spins, 12 is based on max speed of motor, may need to be tweaked
        stepper1.setSpeed(EMG1Speed); //this affects how quickly data is being collected
        stepper1.step(5);// can increase this number if needed, indirect relationship with speed of graph updating tho
        }
      }

        
//Serial.print(0); // To freeze the lower limit
//Serial.print(" ");
//Serial.print(1024); // To freeze the upper limit
//Serial.print(" ");
//Serial.print(Max); // to visualize max value they produced during calibration, this line can be commented out as needed
//Serial.print(" ");
Serial.println(EMG1); // To send all 'data' points to the plotter
}  
