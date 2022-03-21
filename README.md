# P22003 Software Directions

## Arduino Setup
#### Purpose:
The Arduino code collects data from the Myoware muscle sensor and converts it into a motor speed. It also contains 
the brains behind the calibration capabilities.

There are two Arduino files, one for each of the two motors:
```
Big Motor (Gear Spin): BigMotor.ino
Small Motor (Belt Movement): SmallMotor.ino
```


#### Directions:
1. Open the file titled "FILE NAME" for the motor you want to run
2. In the Arduino IDE select the COM port

   a. Tools --> Port
3. Import the Stepper library 
   
   a. Tools --> Manage Libraries --> find "Stepper" --> "Install"
4. Upload the code to the Arduino hardware
  
   a. Click the arrow next to the check mark in the top left corner


## Python Setup

#### Purpose
The Python code adds a visual representation of the Myoware muscle signal. The graph allows the project user to see the 
effects of their muscle movement in real time with labeled axes. 
#### Requirements
- Python 3.x (tested with python3.9) https://www.python.org/downloads/
- pip (comes with python)

##### Code Setup
Type the following into Command Prompt
    
 ```
 cd *file location*
 cd Python 
 pip install -r requirements.txt
 python main.py
 *enter COM port # from Arduino set up*
 ```

 or install and run using the pycharm configuration below. 


###### IDE Setup
1. Use an IDE of Choice. Good ones to use are:
    1. https://www.jetbrains.com/pycharm/download/#section=windows
    2. https://code.visualstudio.com/
    
###### Pycharm Setup
1. File -> Settings -> Project: #### -> Python Interpreter
2. Click on the Gear on the upper right 
3. Click on "add"
4. On the left, click on System Interpreter
5. On the dropdown that appears, choose your python installation
6. After clicking Okay a bunch, There should be a brief loading bar and then the installed packages in that python install should apepar
7. Right clicking on your file and clicking "run <filename>.py" should now run the file. 
   1. If you get errors it is likely because you have not installed the correct dependencies

###### Visual Studio Code Setup
   1. Just use the built in terminal
