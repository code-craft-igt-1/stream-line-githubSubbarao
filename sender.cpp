#include <iostream>
#include <cstdlib>
#include "../include/sender.h"

void sendVitalValues() {
    SensorStub obj;
    for ( int i = 1; i <= 50; i++ ) {
        std::cout <<
        obj.generateRandomSensorValue(TEMPERATURE_LOWER_LIMIT, TEMPERATURE_UPPER_LIMIT) << "," <<
        obj.generateRandomSensorValue(PULSERATE_LOWER_LIMIT, PULSERATE_LOWER_LIMIT) << "," <<
        obj.generateRandomSensorValue(SPO2_LOWER_LIMIT, SPO2_UPPER_LIMIT) << std::endl;
    }
}
int main() {
    sendVitalValues();
    return 0;
}
