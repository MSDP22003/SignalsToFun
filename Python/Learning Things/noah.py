# Run upload normal code to arduino, seems to be slow to capture, dont know why
import serial
import matplotlib.pyplot as plt

plt.ion()
fig=plt.figure()

i=0
x=list()
y=list()

ser = serial.Serial('COM4',9600)
ser.close()
ser.open()
while True:

    data = ser.readline()
    print(data.decode('utf-8'))
    x.append(i)
    y.append(data.decode())

    plt.scatter(i, float(data.decode('utf-8')))
    i += 1
    plt.show()
    plt.pause(0.0000000001)