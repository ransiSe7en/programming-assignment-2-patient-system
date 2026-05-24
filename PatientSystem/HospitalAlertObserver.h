#pragma once

#include "PatientAlertObserver.h"
#include "HospitalAlertSystemFacade.h"

#include <memory>

class HospitalAlertObserver : public PatientAlertObserver
{
public:
    HospitalAlertObserver();

    virtual void notify(Patient* patient) override;

private:
    std::unique_ptr<HospitalAlertSystemFacade> _hospitalAlertSystem;
};