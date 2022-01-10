import serial
ser = serial.Serial('COM3', baudrate = 9600, timeout = 1)  #initializing comm port


def getValues():	   #function to request and return data point from arduino
	ser.write(b'g')    #writing byte to serial bus
	arduinoData = ser.readline().decode('ascii')  #reading serial info off bus, decoding it 
	return arduinoData #returning data point


while 1:
	userInput = input('Get data point?: ')
	if userInput == 'y':      #user must input 'y' to get joystick value
		print(getValues())


