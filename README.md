# SerialMQ
SerialMQ, connection between openFrameworks, Max/MSP &lt;----> Arduino

1. This repo is a openFramewors wrapper for serial communication with Arduino
2. In the /External folder, there is wrapper for Arduino and Max/MSP. Each has their own README that explain how to use the code.

# Usage
Assuming the data sent from Arduino is something like
```
cmd0 message1
cmd1 message2
```
commands are separated by newline character (\n)
command and message are seperated by space (currently not change able, will add the feature in next update)
1. Use `setConnectId()` to set serial port (Default: 0)
2. Use `setBaudRate()` to set baud rate (Default: 9600)
3. Use `setReceivedMsgSep()` to set delimiter for received message (Default: '\n');
4. Use `setSendMsgSep()` to set delimiter for sending message (Default: '\n') 
4. `connect()` will create separate thread (ofThread) to listening the serial port
5. Use `getValue(std::string key)` to get message. key is the command (cmd0, cmd1) and return string is the message (message1, message2)
6. Use `getCounter(std::string key)` to get counter for each command. The counter will automatically plus 1 once received new message for corresponding command. It is use to make sure the data is updated by Arduino or not.
7. Use `sendMsg(std::string msg)` to send message to Arduino

The example code is locate in /src


#TODO
1. Add features for changing delimiter to separate command and message
2. Add protection to prevent counter from overflow.
