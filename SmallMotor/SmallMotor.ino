// change this to the number of steps on your motor
#define STEPS 2048
#include "Stepper.h"
// Define Motor Pins (2 Motors used)

#define motorPin1  8     // Blue   - 28BYJ48 pin 1
#define motorPin2  9     // Pink   - 28BYJ48 pin 2
#define motorPin3  10    // Yellow - 28BYJ48 pin 3
#define motorPin4  11    // Orange - 28BYJ48 pin 4

int Max=100;// initial value, want somewhere close to noise
int EMG1Speed=0;
int EMG1=0;
int currentstate=1;// intial position of gear (only 4 options, 1,2,3,4 in order to simplify)
int nextstate=0;// will hold the postion that the motor should move to
int reset=0;
int calibrate=0;

int distance= 2048/3;// need to find this, is the number of steps to move a quarter of the way around arc


const int Resetbutton= 2 ;//number of reset  button pin
const int calibratebutton=3;//number of calibration button pin

Stepper stepper1(STEPS, motorPin1, motorPin3, motorPin2, motorPin4);

void setup() {
  Serial.begin(9600);
  pinMode(Resetbutton, INPUT);
   pinMode(calibratebutton, INPUT);
  stepper1.setSpeed(15);
  stepper1.step(-2048);
}

void loop() {
 
EMG1 = analogRead(A0);
reset=digitalRead(Resetbutton);//read the state of reset button
calibrate=digitalRead(calibratebutton);// read the state of calibration button
//buttons will be equal to HIGH if pressed
  if (reset == HIGH){
        Max=100;// 100 should be near or lower than noise
      }
  else if (calibrate == HIGH) {
      if (EMG1>Max){
            Max=EMG1;
        }
      }
   else {
   
      
      if (EMG1 <= Max/4) 
      {
        nextstate=1;
      }
      else if (EMG1> Max/4 &&  EMG1<= Max/2) {
        nextstate= 2;
      }
      else if(EMG1>Max/2 && EMG1 <= 3*Max/4){
        nextstate=3;
      }
     else if(EMG1<3*Max/4){
      nextstate=4;
     }
      }
      if (currentstate!=nextstate) {
      stepper1.step((nextstate - currentstate)*distance);
      currentstate=nextstate;//updates the location of belt
      }
      
//Serial.print(0); // To freeze the lower limit
//Serial.print(" ");
//Serial.print(1000); // To freeze the upper limit
//Serial.print(" ");
//Serial.print(Max); // to visualize max value they produced during calibration, this line can be commented out as needed
//Serial.print(" ");
Serial.println(EMG1); // 
}
