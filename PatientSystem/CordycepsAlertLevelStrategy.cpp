#include "CordycepsAlertLevelStrategy.h"

#include "Vitals.h"

AlertLevel CordycepsAlertLevelStrategy::calculateAlertLevel(
    const Patient& patient,
    const Vitals& vitals
) const
{
    if (vitals.RR() > 40) {
        return AlertLevel::Red;
    }

    if (vitals.RR() > 30) {
        return AlertLevel::Orange;
    }

    if (vitals.RR() > 20) {
        return AlertLevel::Yellow;
    }

    return AlertLevel::Green;
}