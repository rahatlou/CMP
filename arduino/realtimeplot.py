import serial
import matplotlib.pyplot as plt

# turn on interactive mode
plt.ion()
fig=plt.figure()

# set boundaries on y axis
plt.ylim(5,65)


i=0
x=list()
y=list()

# connect to Arduino via serial port
ser = serial.Serial('/dev/cu.usbmodem14401',9600)


while True:

    #if(not ser.inWaiting()>0) :
    #    pass
    rawdata = ser.readline()

    plt.scatter(i, float(rawdata.decode()), marker='.')
    i += 1

    plt.show()
    plt.pause(0.001)
