#pragma once


#include "AbstractPatientDatabaseLoader.h"
#include "PatientFileLoader.h"

#include <string>

class PatientFileLoaderAdapter : public AbstractPatientDatabaseLoader
{
public:
    explicit PatientFileLoaderAdapter(const std::string& filePath);

    virtual void initialiseConnection() override;
    virtual void loadPatients(std::vector<Patient*>& patientsIn) override;
    virtual void closeConnection() override;

private:
    PatientFileLoader _fileLoader;
    std::string _filePath;
};