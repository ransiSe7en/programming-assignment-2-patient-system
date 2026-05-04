#include "PatientFileLoaderAdapter.h"

PatientFileLoaderAdapter::PatientFileLoaderAdapter(const std::string& filePath) :
    _filePath(filePath)
{
}

void PatientFileLoaderAdapter::initialiseConnection()
{
    // No connection needed
}

void PatientFileLoaderAdapter::loadPatients(std::vector<Patient*>& patientsIn)
{
    std::vector<Patient*> loadedPatients = _fileLoader.loadPatientFile(_filePath);

    for (Patient* patient : loadedPatients) {
        patientsIn.push_back(patient);
    }
}

void PatientFileLoaderAdapter::closeConnection()
{
    // No connection needed
}