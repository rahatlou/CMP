# Vicinity sensor with Arduino

For a brief introduction to programming arduino boards see [Scientific Arduino](https://www.roma1.infn.it/people/organtini/publications/scientificArduino.pdf) by [Giovanni Organtini](http://www.roma1.infn.it/people/organtini/).

Objectives:
- getting familiar with arduino software logic
- use digital pins to manage LEDs [sketch](blink-LED.ino) [tutorial](http://www.circuitbasics.com/arduino-basics-controlling-led/)
- use the [HC-SR04 ultrasonic module](HCSR04.pdf) to implement a vicinity sensor [tutorial](https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/)
- modulate the LED brightness with [pulse-width modulation](https://create.arduino.cc/projecthub/muhammad-aqib/arduino-pwm-tutorial-ae9d71)  and the audio signal based on the detected distance [sketch](vicinity-sensor.ino)
- use python to read data from the [serial port](https://pythonhosted.org/pyserial/) and show real-time plot of the distance with matplotlib [python](realtimeplot.py)

## Arduino with python
In order to control an Arduino board from a computer, you need to use a protocol for the communication over the serial port.
You can use python and [pySerial](https://pythonhosted.org/pyserial/) to communicate over the serial port. However, you would need to define a communication protocol.

## pyFirmata
A popular standard protocol is [Firmata](https://github.com/firmata/protocol). See this nice tutorial to [get started with python on arduino](https://realpython.com/arduino-python/) using [Firmata](https://github.com/firmata/protocol).

[pyFirmata](https://pypi.org/project/pyFirmata/) is a python interface for the  [Firmata](https://github.com/firmata/protocol) protocol.

## python-arduino
An alternative Python Arduino Command API is provided in the [python-arduino3](https://pypi.org/project/arduino-python3/) package.
All details can be found also in the [git repository](https://github.com/thearn/Python-Arduino-Command-API).
