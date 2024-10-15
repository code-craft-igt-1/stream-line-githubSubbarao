#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "sensordata.h"
#include "statistics.h"

#include <string>
#include <vector>

namespace processor {
    double findMinValOfVec(const std::vector<double>& vec);
    double findMaxValOfVec(const std::vector<double>& vec);
    double findMovingAvgVec(const std::vector<double>& vec, int lastNvalue);
    void computeStatistics(const SensorDataVec& sensorDataVec);
    void printStatistics(const Statistics& stats);
    void readDataAndComputeStatistics(SensorDataVec& sensorData);
}  // namespace processor

#endif  // PROCESSOR_H
