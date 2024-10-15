#ifndef STATISTICS_H
#define STATISTICS_H

#include <string>
#include <vector>

namespace processor {
    const double LAST_N_MOVING_AVG = 5;

    struct Statistics {
        double tempMinVal;
        double tempMaxVal;
        double pulseRateMinVal;
        double pulseRateMaxVal;
        double spo2MinVal;
        double spo2MaxVal;
        double tempMovingAvg;
        double pulseRateMovingAvg;
        double spo2MovingAvg;
    };
}  // namespace processor

#endif  // STATISTICS_H
