#include <iostream>
#include <cstdlib>
#include "sender.h"
#include <fstream>

void sendVitalValues() {
    SensorStub obj;
    std::ofstream fp;
    fp.open("Log.txt", std::ios::trunc);
    fp.close();

    fp.open("Log.txt", std::ios::app);
    for (int i = 1; i <= 5; i++) {
        auto temp = obj.generateRandomSensorValue(TEMPERATURE_LOWER_LIMIT, TEMPERATURE_UPPER_LIMIT);
        auto pulseRate = obj.generateRandomSensorValue(PULSERATE_LOWER_LIMIT, PULSERATE_UPPER_LIMIT);
        auto spo2 = obj.generateRandomSensorValue(SPO2_LOWER_LIMIT, SPO2_UPPER_LIMIT);
        std::cout << temp << " " << pulseRate << " " << spo2 << std::endl;
        fp << temp << " " << pulseRate << " " << spo2 << std::endl;
    }
    fp.close();
}
int main() {
    sendVitalValues();
    return 0;
}
