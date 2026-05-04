#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Patient.h"
#include "Vitals.h"

using namespace std;


std::vector<Patient*> PatientFileLoader::loadPatientFile(const std::string& file)
{
	vector<Patient*> patients{};

    std::ifstream inFile(file);
    if (inFile.is_open()) {
        // TODO: load your file here
        string line;

        while (getline(inFile, line)) {
            if (line.empty()) {
                continue;
            }

            string id;
            string name;
            string birthday;
            string diagnosis;
            string vitalsText;

            stringstream lineStream(line);

            getline(lineStream, id, '|');
            getline(lineStream, name, '|');
            getline(lineStream, birthday, '|');
            getline(lineStream, diagnosis, '|');
            getline(lineStream, vitalsText, '|');

            string lastName;
            string firstName;
            stringstream nameStream(name);
            getline(nameStream, lastName, ',');
            getline(nameStream, firstName, ',');

            std::tm birthdayTm{};
            stringstream birthdayStream(birthday);
            birthdayStream >> std::get_time(&birthdayTm, "%d-%m-%Y");

            Patient* patient = new Patient(firstName, lastName, birthdayTm);
            patient->addDiagnosis(diagnosis);

            if (!vitalsText.empty()) {
                string vitalsRecord;
                stringstream vitalsStream(vitalsText);

                while (getline(vitalsStream, vitalsRecord, ';')) {
                    string bodyTemperatureText;
                    string bloodPressureText;
                    string heartRateText;
                    string respitoryRateText;

                    stringstream recordStream(vitalsRecord);

                    getline(recordStream, bodyTemperatureText, ',');
                    getline(recordStream, bloodPressureText, ',');
                    getline(recordStream, heartRateText, ',');
                    getline(recordStream, respitoryRateText, ',');

                    float bodyTemperature = stof(bodyTemperatureText);
                    int bloodPressure = stoi(bloodPressureText);
                    int heartRate = stoi(heartRateText);
                    int respitoryRate = stoi(respitoryRateText);

                    Vitals* vitals = new Vitals(
                        bodyTemperature,
                        bloodPressure,
                        heartRate,
                        respitoryRate
                    );

                    patient->addVitals(vitals);
                }
            }

            patients.push_back(patient);
        }
    }

    return patients;
}
