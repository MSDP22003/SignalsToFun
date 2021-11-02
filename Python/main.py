import matplotlib.pyplot as plt
from matplotlib import style
from matplotlib.animation import FuncAnimation
import serial

# initialize serial port
ser = serial.Serial('COM4', 9600)
# specify timeout
ser.timeout = 10
ser.close()
ser.open()
emgsignal = ser.readline()

# this is printing serial parameters
if ser.is_open:
    print("\nSerial port now open. Configuration:\n")
    print(ser, "\n")

#style.use('fivethirtyeight') #makes graph more aesthetic but rn it's making things worse

fig = plt.figure()
ax1 = fig.add_subplot(1,1,1) #means the subplot is on a grid system thats 1x1
ys = []  # defining the place to store y values

def animate(i): #i is the interval
    if (ser.inWaiting() > 0):
        emgsignal = ser.read(ser.inWaiting()).decode('ascii') # read the bytes and convert from binary array to ASCII
        vals = emgsignal.split("\r\n") #splits this by everywhere that theres a carriage return/new line
        newys = []

        for v in vals: #for loop for every value in the array called vals
            if v != '': #making sure no lines that are empty are being processed
                newys.append(float(v.strip('\n\r'))) #getting rid of the new line & carriage return, removing any stragglers, & converting the serial input to a float
        print(ys)
        ys.extend(newys)
        xs = [k for k in range(len(ys))]
        ax1.clear() #clears any data that was previously on the graph
        ax1.set_xlim([len(ys)-len(newys)*10, len(ys)+100])
        ax1.set_ylim([0, 25])
        plt.xlabel('Perhaps Time? Maybe?')
        plt.ylabel("Signal that's currently noise")

        plt.title('Early Testing of Live Graph\n11/1/21')  # \n starts a new line
        ax1.plot(xs, ys)

ani = FuncAnimation(fig, animate, interval=50) #updates the graph called fig with the function called animate every 1000 ms
plt.show()