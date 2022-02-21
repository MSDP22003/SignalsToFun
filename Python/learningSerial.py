import serial  # import Serial Library
import numpy  # Import numpy
import matplotlib.pyplot as plt  # import matplotlib library
from drawnow import *

EMG1 = []
EMG2 = []
arduinoData = serial.Serial('COM3', 115200)  # Creating our serial object named arduinoData
plt.ion()  # Tell matplotlib you want interactive mode to plot live data
cnt = 0


def makeFig():  # Create a function that makes our desired plot
    # plt.ylim(80, 90)  # Set y min and max values
    plt.title('My Live Streaming Sensor Data')  # Plot the title
    plt.grid(True)  # Turn the grid on
    plt.ylabel('EMG1')  # Set ylabels
    plt.plot(EMG1, 'ro-', label='Degrees F')  # plot the temperature
    plt.legend(loc='upper left')  # plot the legend
    plt2 = plt.twinx()  # Create a second y axis
    # plt.ylim(93450, 93525)  # Set limits of second y axis- adjust to readings you are getting
    plt2.plot(EMG2, 'b^-', label='EMG2')  # plot EMG2 data
    plt2.set_ylabel('Pressrue (Pa)')  # label second y axis
    plt2.ticklabel_format(useOffset=False)  # Force matplotlib to NOT autoscale y axis
    plt2.legend(loc='upper right')  # plot the legend


while True:  # While loop that loops forever
    while (arduinoData.inWaiting() == 0):  # Wait here until there is data
        pass  # do nothing
    arduinoString = arduinoData.readline()  # read the line of text from the serial port
    dataArray = arduinoString.split(',')  # Split it into an array called dataArray
    ESig1 = float(dataArray[0])  # Convert first element to floating number and put in temp
    ESig2 = float(dataArray[1])  # Convert second element to floating number and put in P
    EMG1.append(ESig1)  # Build our EMG1 array by appending temp readings
    EMG2.append(ESig2)  # Building our EMG2 array by appending P readings
    drawnow(makeFig)  # Call drawnow to update our live graph
    plt.pause(.001)  # Pause Briefly. Important to keep drawnow from crashing
    cnt = cnt + 1
    if (cnt > 50):  # If you have 50 or more points, delete the first one from the array
        EMG1.pop(0)  # This allows us to just see the last 50 data points
        EMG2.pop(0)