import serial

# ask the user for the COM port info
comportnum = input("Enter the COM port #: ")
comport = "COM" + comportnum
# print(comport)

# initialize serial port
ser = serial.Serial(comport, 9600)
ser.timeout = 10  # specify timeout
ser.close()
ser.open()
ser.readline()

# this is printing serial parameters
if ser.is_open:
    print("\nSerial port now open. Configuration:\n")
    print(ser, "\n")