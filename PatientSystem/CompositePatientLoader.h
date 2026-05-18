#pragma once

#include "AbstractPatientDatabaseLoader.h"

#include <memory>
#include <vector>

class CompositePatientLoader : public AbstractPatientDatabaseLoader
{
public:
    void addLoader(std::unique_ptr<AbstractPatientDatabaseLoader> loader);

    virtual void initialiseConnection() override;
    virtual void loadPatients(std::vector<Patient*>& patientsIn) override;
    virtual void closeConnection() override;

private:
    std::vector<std::unique_ptr<AbstractPatientDatabaseLoader>> _loaders;
};