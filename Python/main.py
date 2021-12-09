import matplotlib.pyplot as plt
from matplotlib import style
from matplotlib.animation import FuncAnimation
import serial

# initialize serial port
arduinoData = serial.Serial('COM3', 9600)
arduinoData.timeout = 10  # specify timeout
arduinoData.close()
arduinoData.open()
arduinoData.readline()

EMG1 = []
EMG2 = []

# this is printing serial parameters
if arduinoData.is_open:
    print("\nSerial port now open. Configuration:\n")
    print(arduinoData, "\n")

# style.use('ggplot') #might make graph more aesthetic but rn it's making things worse

# fig = plt.figure()
fig, (ax1, ax2) = plt.subplots(2, sharex=True)
# ax1 = fig.add_subplot(1, 1, 1)  #means the subplot is on a grid system that's 1x1 #is no longer used for multiplots
emgsignal1 = []  # defining the place to store y values


def animate(i):  # i is the interval

    if arduinoData.inWaiting() > 0:
        # while True:  # While loop that loops forever
        #     while (arduinoData.inWaiting() == 0):  # Wait here until there is data
        #         pass  # do nothing
            arduinoString = arduinoData.readline().decode('ascii')  # read the line of text from the serial port
            dataArray = arduinoString.split(',')  # Split it into an array called dataArray
            ESig1 = float(dataArray[0])  # Convert first element to floating number and put in temp
            ESig2 = float(dataArray[1])  # Convert second element to floating number and put in P
            EMG1.append(ESig1)  # Build our EMG1 array by appending EMG1 readings
            EMG2.append(ESig2)  # Building our EMG2 array by appending EMG2 readings
            xs = [k for k in range(len(EMG1))]

            # graph formatting for graph 1
            ax1.clear()  # clears any data that was previously on the graph
            # ax1.set_xlim([len(EMG1) - len(ESig1) * 10, len(ESig1) + 100])
            ax1.set_ylim([0, 1250])
            # graph formatting for graph 2
            ax2.clear()  # clears any data that was previously on the graph
            # ax2.set_xlim([len(EMG2) - len(ESig2) * 10, len(ESig2) + 100])
            ax2.set_ylim([0, 1250])
            # graph labeling
            plt.xlabel('Units')
            plt.ylabel("EMG Data")
            fig.suptitle('Adding a Second EMG Sensor\n12/1/21')  # \n starts a new line

            # plots the data
            ax1.plot(xs, EMG1)
            ax2.plot(xs, EMG2)


# update the graph called fig with the function called animate every 1000 ms
ani = FuncAnimation(fig, animate, interval=50)

plt.show()
