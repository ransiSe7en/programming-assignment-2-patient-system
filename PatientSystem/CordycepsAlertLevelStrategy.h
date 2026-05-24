#pragma once

#include "AlertLevelStrategy.h"

class CordycepsAlertLevelStrategy : public AlertLevelStrategy
{
public:
    virtual AlertLevel calculateAlertLevel(
        const Patient& patient,
        const Vitals& vitals
    ) const override;
};