#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>

class SensorStub {
public:
    SensorStub() {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
    }

    double generateRandomSensorValue(double minValue, double maxValue) const {
        double f = static_cast<double>(std::rand()) / RAND_MAX;
        return minValue + f * (maxValue - minValue);
    }
};
