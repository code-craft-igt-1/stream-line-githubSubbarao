#ifndef SENSORDATA_H
#define SENSORDATA_H

#include <string>
#include <vector>

namespace processor {
    struct SensorDataVec {
        std::vector<double> tempVec;
        std::vector<double> pulseRateVec;
        std::vector<double> spo2Vec;
    };
}  // namespace processor

#endif  // SENSORDATA_H