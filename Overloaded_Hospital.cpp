#include <iostream>
#include <fstream>

using namespace std;

// Function prototypes
double inPatientCharges(int days, double rate, double meds, double services);
double outPatientCharges(double meds, double services);

int main()
{
    ofstream outputFile;
    outputFile.open("./patient_charges.txt");

    char patientType;
    int days;
    double rate, meds, services;
    double totalCharges;

    // Ask if the patient was an in-patient or an out-patient
    cout << "Was the patient an in-patient or an out-patient? (I/O): ";
    cin >> patientType;

    // Get the patient data
    if (toupper(patientType) == 'I')
    {
        cout << "Enter the number of days spent in the hospital: ";
        cin >> days;
        cout << "Enter the daily rate: ";
        cin >> rate;
        cout << "Enter the hospital medication charges: ";
        cin >> meds;
        cout << "Enter the charges for hospital services: ";
        cin >> services;

        // Calculate the in-patient charges
        totalCharges = inPatientCharges(days, rate, meds, services);
    }
    else if (toupper(patientType) == 'O')
    {
        cout << "Enter the hospital medication charges: ";
        cin >> meds;
        cout << "Enter the charges for hospital services: ";
        cin >> services;

        // Calculate the out-patient charges
        totalCharges = outPatientCharges(meds, services);
    }
    else
    {
        cout << "Invalid patient type." << endl;
        return 0;
    }

    // Write the report to the file
    outputFile << "Patient charges:" << endl;
    outputFile << "-----------------" << endl;
    outputFile << "Total charges: $" << totalCharges << endl;

    // Close the file
    outputFile.close();

    cout << "Report saved to patient_charges.txt" << endl;

    return 0;
}

// Function to calculate in-patient charges
double inPatientCharges(int days, double rate, double meds, double services)
{
    return (days * rate) + meds + services;
}

// Function to calculate out-patient charges
double outPatientCharges(double meds, double services)
{
    return meds + services;
}