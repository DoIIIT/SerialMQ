#include "SerialPrint.h"
#include "SerialMQ.h"
#include "StandardCplusplus.h"
#include <vector>

std::vector<String> cmdList;
SerialMQ serialMQ;
int led = 13;

void setup()
{
    Serial.begin(9600);
    pinMode(led, OUTPUT);

    for (int i = 0; i < 20; i++) {
        char numstr[6];
        sprintf(numstr, "cmd%d", i);
        cmdList.push_back(numstr);
    }
}

void loop()
{
    serialMQ.Update();
    static int count = 0;
    for (int i = 0; i < cmdList.size(); i++) {
        // to work with the parser, please format string as
        // cmd argument
        serialMQ.Send("%s %d", cmdList[i].c_str(), count);
    }
    // SerialMQ::Submit();

    if (serialMQ.getValue("led") == "LOW") {
        digitalWrite(led, LOW);
    } else if (serialMQ.getValue("led") == "HIGH") {
        digitalWrite(led, HIGH);
    }
    
    count++;
    delay(300);
}
