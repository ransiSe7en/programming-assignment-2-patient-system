#pragma once

#include "PatientAlertObserver.h"
#include "GPNotificationSystemFacade.h"

#include <memory>

class GPAlertObserver : public PatientAlertObserver
{
public:
    GPAlertObserver();

    virtual void notify(Patient* patient) override;

private:
    std::unique_ptr<GPNotificationSystemFacade> _gpNotificationSystem;
};