#include "HospitalAlertObserver.h"

HospitalAlertObserver::HospitalAlertObserver() :
    _hospitalAlertSystem(std::make_unique<HospitalAlertSystemFacade>())
{
}

void HospitalAlertObserver::notify(Patient* patient)
{
    _hospitalAlertSystem->sendAlertForPatient(patient);
}