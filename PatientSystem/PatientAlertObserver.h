#pragma once

class Patient;

class PatientAlertObserver
{
public:
    virtual ~PatientAlertObserver() = default;
    virtual void notify(Patient* patient) = 0;
};