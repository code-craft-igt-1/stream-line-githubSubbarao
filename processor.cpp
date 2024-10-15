#include "processor.h"

#include <iostream>
#include <vector>

namespace processor {
    double findMinValOfVec(const std::vector<double>& vec) {
        // Initialize min_value to the maximum possible value
        double min_value = std::numeric_limits<double>::max();

        // Iterate through the vector to find the minimum value
        for (int num : vec) {
            if (num < min_value) {
                min_value = num;
            }
        }

        return min_value;
    }

    double findMaxValOfVec(const std::vector<double>& vec) {
        // Initialize max_value to the min possible value
        double max_value = std::numeric_limits<double>::min();

        // Iterate through the vector to find the max value
        for (int num : vec) {
            if (num > max_value) {
                max_value = num;
            }
        }

        return max_value;
    }

    double findMovingAvgVec(const std::vector<double>& vec, int lastNvalue) {
        double sum = 0.0;
        size_t start = vec.size() > lastNvalue ? vec.size() - lastNvalue : 0;

        for (size_t i = start; i < vec.size(); ++i) {
            sum += vec[i];
        }

        return sum / (vec.size() - start);
    }

    void printStatistics(const Statistics& stats) {
        std::cout << "=======================" << std::endl;
        std::cout << "Current Min Value" << std::endl;
        std::cout << "=======================" << std::endl;
        std::cout << "Temp : " << stats.tempMinVal << "  |  "
            << "PulseRate : " << stats.pulseRateMinVal << "  |  "
            << "Spo2 : " << stats.spo2MinVal << std::endl;

        std::cout << "=======================" << std::endl;
        std::cout << "Current Max Value" << std::endl;
        std::cout << "=======================" << std::endl;
        std::cout << "Temp : " << stats.tempMaxVal << "  |  "
            << "PulseRate : " << stats.pulseRateMaxVal << "  |  "
            << "Spo2 : " << stats.spo2MaxVal << std::endl;

        std::cout << "=======================" << std::endl;
        std::cout << "Moving Avg of last " << LAST_N_MOVING_AVG << " values" << std::endl;
        std::cout << "=======================" << std::endl;
        std::cout << "Temp : " << stats.tempMovingAvg << "  |  "
            << "PulseRate : " << stats.pulseRateMovingAvg << "  |  "
            << "Spo2 : " << stats.spo2MovingAvg << std::endl;
        std::cout << "*****************" << std::endl << std::endl << std::endl;
    }

    void computeStatistics(const SensorDataVec& sensorDataVec) {
        Statistics stats;
        stats.tempMinVal = findMinValOfVec(sensorDataVec.tempVec);
        stats.pulseRateMinVal = findMinValOfVec(sensorDataVec.pulseRateVec);
        stats.spo2MinVal = findMinValOfVec(sensorDataVec.spo2Vec);

        stats.tempMaxVal = findMaxValOfVec(sensorDataVec.tempVec);
        stats.pulseRateMaxVal = findMaxValOfVec(sensorDataVec.pulseRateVec);
        stats.spo2MaxVal = findMaxValOfVec(sensorDataVec.spo2Vec);

        stats.tempMovingAvg = findMovingAvgVec(sensorDataVec.tempVec, LAST_N_MOVING_AVG);
        stats.pulseRateMovingAvg = findMovingAvgVec(sensorDataVec.pulseRateVec, LAST_N_MOVING_AVG);
        stats.spo2MovingAvg = findMovingAvgVec(sensorDataVec.spo2Vec, LAST_N_MOVING_AVG);

        printStatistics(stats);
    }

    void readDataAndComputeStatistics(SensorDataVec& sensorDataVec) {
        double sensorValue = 0.0;
        unsigned int sensorValueIndex = 0;
        double temp = 0.0;
        double pulseRate = 0.0;
        double spo2 = 0.0;

        while (std::cin >> sensorValue) {
            if (0 == sensorValueIndex % 3) {
                temp = sensorValue;
            }
            else if (1 == sensorValueIndex % 3) {
                pulseRate = sensorValue;
            }
            else {
                spo2 = sensorValue;
            }

            sensorValueIndex++;
            sensorDataVec.tempVec.push_back(temp);
            sensorDataVec.pulseRateVec.push_back(pulseRate);
            sensorDataVec.spo2Vec.push_back(spo2);

            computeStatistics(sensorDataVec);
        }
    }
} //namespace processor

int main() {
    processor::SensorDataVec sensorDataVec;
    processor::readDataAndComputeStatistics(sensorDataVec);

    //std::cout << "SensorData Available" << std::endl;
    //if (!sensorDataVec.tempVec.empty())
    //{
    //    for (unsigned int index = 0; index < sensorDataVec.tempVec.size(); index++) {
    //        std::cout << sensorDataVec.tempVec[index] << " " << 
    //            sensorDataVec.pulseRateVec[index] << " " << 
    //            sensorDataVec.spo2Vec[index] << std::endl;
    //    }
    //}

    return 0;
}
