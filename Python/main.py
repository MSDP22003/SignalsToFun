import matplotlib.pyplot as plt
from matplotlib import style
from matplotlib.animation import FuncAnimation
import serial

# ask the user for the COM port info
comportnum = input("Enter the COM port #: ")
comport = "COM" + comportnum

# initialize serial port
ser = serial.Serial(comport, 9600)
ser.timeout = 10  # specify timeout
ser.close()
ser.open()
ser.readline()

# this is printing the serial parameters
if ser.is_open:
    print("\nSerial port now open. Configuration:\n")
    print(ser, "\n")

# this sets the graph color scheme
style.use('dark_background')

fig = plt.figure()
ax1 = fig.add_subplot(1, 1, 1)  # means the subplot is on a grid system that's 1x1
emgsignal1 = []  # defining the place to store y values


def animate(i):  # i is the interval

    if ser.inWaiting() > 0:
        emgsignals = ser.read(ser.inWaiting()).decode('ascii')  # read the bytes and convert from binary array to ASCII
        vals = emgsignals.split("\r\n")  # splits this by everywhere that theres a carriage return/new line

        stringcount = len(vals)
        count = int(stringcount)

        newys = []

        for v in vals:  # for loop for every value in the array called vals
            if v != '':  # making sure no lines that are empty are being processed
                newys.append(float(v.strip('\n\r')))  # getting rid of the new line & carriage return, removing any stragglers, & converting the serial input to a float
        emgsignal1.extend(newys)
        xs = [k for k in range(len(emgsignal1))]

        # graph formatting for graph 1
        ax1.clear()  # clears any data that was previously on the graph
        ax1.set_xlim([len(emgsignal1) - len(newys) * 10, len(emgsignal1) + 100])
        ax1.set_ylim([0, 25]) # change this limit when you get actual EMG signal
        ax1.set_xticklabels('')

        # graph labeling
        ax1.set_xlabel('Time')
        ax1.set_ylabel("Electrical Signal")
        fig.suptitle('EMG Signal vs. Time \n Updated 3/2/2022')  # \n starts a new line

        # plots the data
        ax1.plot(xs, emgsignal1)

<<<<<<< Updated upstream
# update the graph called fig with the function called animate every 50 ms
ani = FuncAnimation(fig, animate, interval=50)
=======
# update the graph called fig with the function called animate every 1000 ms
ani = FuncAnimation(fig, animate, interval=100)
>>>>>>> Stashed changes

plt.show()
