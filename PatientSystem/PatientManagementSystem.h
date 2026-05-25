#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>


// forward declare several classes
class AbstractPatientDatabaseLoader;
class HospitalAlertSystemFacade;
class GPNotificationSystemFacade;
class Patient;
class HospitalAlertObserver;
class GPAlertObserver;

class PatientManagementSystem
{
public:

	PatientManagementSystem();
	~PatientManagementSystem();

	// initialise the patient records
	void init();
	void run();

	// ask the user for a patient and vitals and add those vitals to the patient
	void addVitalsRecord();

	void printWelcomeMessage() const;
	void printMainMenu() const;
	void printPatients() const;

protected:
	std::vector<Patient*> _patients;
	std::map<std::string, Patient*> _patientLookup;

	std::unique_ptr<HospitalAlertObserver> _hospitalAlertObserver;
	std::unique_ptr<GPAlertObserver> _gpAlertObserver;

	std::unique_ptr<AbstractPatientDatabaseLoader> _patientDatabaseLoader;

};

