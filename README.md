# Patient Vitals Management System

Programming Assignment, Design Patterns with C++.

This project extends a patient vitals management system using four design patterns:

- Adapter Pattern – loads patients from `patients.txt` using `PatientFileLoaderAdapter`
- Composite Pattern – loads patients from both the database and file through `CompositePatientLoader`
- Strategy Pattern – calculates alert levels using disease-specific alert strategies
- Observer Pattern – notifies hospital and GP systems when a patient reaches a Red alert level

## Requirements

- Windows 10 or higher
- Visual Studio 2022
- C++ standard library only

## How to Build

1. Open `PatientSystem.sln` in Visual Studio 2022.
2. Select `Release` or `Debug`.
3. Build the solution.
4. Run `PatientSystem`.

## Important Note

The application reads patient data from:

```txt
PatientSystem/patients.txt
