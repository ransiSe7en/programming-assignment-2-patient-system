#include "GPAlertObserver.h"

GPAlertObserver::GPAlertObserver() :
    _gpNotificationSystem(std::make_unique<GPNotificationSystemFacade>())
{
}

void GPAlertObserver::notify(Patient* patient)
{
    _gpNotificationSystem->sendGPNotificationForPatient(patient);
}