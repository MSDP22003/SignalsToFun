/
// Include the AccelStepper library:
#include <AccelStepper.h>

// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin 8
#define stepPin 9
#define motorInterfaceType 1

// Create a new instance of the AccelStepper class:
AccelStepper stepper1 = AccelStepper(motorInterfaceType, stepPin, dirPin);


int Max=100;// initial value, what somewhere close to noise
int EMG1Speed=0;
int EMG1=0;
int reset=0;
int calibrate=0;
const int Resetbutton= 2; //number of reset  button pin
const int calibratebutton=3; //number of calibration button pin

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
        Max=100;
      }
  else if (calibrate == HIGH) {
      if (EMG1>Max){
            Max=EMG1;
        }
      }
   else {
   
      if (EMG1<60){
        stepper1.step(0);
      }
      else if (EMG1>60 && EMG1 < Max/4){//120 is level of noise, may need to fine tune
      
        EMG1Speed = 200;//this line controls the speed that the motor spins at based on analog input
        stepper1.setSpeed(EMG1Speed); //this affects how quickly data is being collected
        stepper1.step(5);//Play around with number
        }
       else if (EMG1>Max/4 && EMG1 <Max/2){//120 is level of noise, may need to fine tune
      
        EMG1Speed = 400;//this line controls the speed that the motor spins at based on analog input
        stepper1.setSpeed(EMG1Speed); //this affects how quickly data is being collected
        stepper1.step(5);//Play around with number
       }
        else if (EMG1>Max/2 && EMG1 <=3*Max/4){//120 is level of noise, may need to fine tune
      
        EMG1Speed = 600;//this line controls the speed that the motor spins at based on analog input
        stepper1.setSpeed(EMG1Speed); //this affects how quickly data is being collected
        stepper1.step(5);//Play around with number
        }
        else if (EMG1>3*Max/4 && EMG1 < Max){//120 is level of noise, may need to fine tune
      
        EMG1Speed = 800;//this line controls the speed that the motor spins at based on analog input
        stepper1.setSpeed(EMG1Speed); //this affects how quickly data is being collected
        stepper1.step(5);//Play around with number
        }
      else {
        EMG1Speed = 1000;//this line controls the speed that the motor spins, 12 is based on max speed of motor, may need to be tweaked
         stepper1.setSpeed(EMG1Speed);; //this affects how quickly data is being collected
        stepper1.step(5);// can increase this number if needed, indirect relationship with speed of graph updating tho
        }
      }

        
Serial.print(0); // To freeze the lower limit
Serial.print(" ");
Serial.print(1024); // To freeze the upper limit
Serial.print(" ");
Serial.print(Max); // to visualize max value they produced during calibration, this line can be commented out as needed
Serial.print(" ");
Serial.println(EMG1); // To send all 'data' points to the plotter
}  
