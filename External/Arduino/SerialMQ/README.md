#NOTICE
I use Ino (http://inotool.org) to compile/upload Arduino file. I haven't test it in the tradional Arduino.app yet, but it should work.
Put the files under /lib in Arduino Libraries folder and it should work.

#DEPENDENCIES
Please install StandardCplusplus (https://github.com/maniacbug/StandardCplusplus) first.

#USAGE
The `SerialMQ` object will maintain a `std::map` which store the received *command* and *message* as *key* and *value* respectively.

Assuming the data sent from Arduino is something like

```
cmd0 message1
cmd1 message2
```
commands are separated by newline character (\n)
command and message are seperated by space 
(currently not changeable, will add the feature in next update)

In `loop()`, use `Update()` to update the `map` from serial port

Use `Send(format, variable, ...)` (same as printf) to send message to serial port

Use `serialMQ.getValue(String key)` to get corresponding message

Use `serialMQ.getCounter(String key)` to check the current counter (use to make sure whether the message is updated or not)
