#include <iostream>
#include <vector>
#include <queue>

#include "Patient.h"
using namespace std;

/*
Goals for this method:

Your code should prompt the office manager to enter patient details and add that
patient to the end of the queue.

- Get patient data
- Add patient to quueeueueueueu

Queue - first in, first out
Stack - first in, last out 

*/

vector <Patient> patients;
queue <Patient> patientQueue;

Patient setPatientData(){
    Patient currPatient;
    //Variables
    string name;
    string streetAddress;
    string city;
    string state;
    string email;
    string insuranceCompany;
    double zipCode;
    double phoneNumber;
    double DoB;
    long appointmentID;
    long patientID;

    cout << "Patient Name: " << endl;
    cin >> name;
    currPatient.nameSetter(name);

    cout << "Patient Street Address: " << endl;
    cin >> streetAddress;
    currPatient.streetAddressSetter(streetAddress);

    cout << "Patient City: " << endl;
    cin >> city;
    currPatient.citySetter(city);
    
    cout << "Patient State: " << endl;
    cin >> state;
    currPatient.stateSetter(state);

    //Consider special input parameters for this 
    cout << "Patient Email: " << endl;
    cin >> email;
    currPatient.emailSetter(email);

    cout << "Patient Insurance Company: " << endl;
    cin >> insuranceCompany;
    currPatient.insuranceCompanySetter(insuranceCompany);

    cout << "Patient Zip Code: " << endl;
    cin >> zipCode;
    currPatient.zipCodeSetter(zipCode);

    cout << "Patient Phone Number: " << endl;
    cin >> phoneNumber;
    currPatient.phoneNumberSetter(phoneNumber);

    cout << "Patient Date of Birth: " << endl;
    cin >> DoB;
    currPatient.DoBSetter(DoB);

    cout << "Patient Appointment ID: " << endl;
    cin >> appointmentID;
    currPatient.appointmentIDSetter(appointmentID);

    cout << "Patient ID: " << endl;
    cin >> patientID;
    currPatient.patientIDSetter(patientID);

    patients.push_back(currPatient);
    return currPatient;

}

void addPatient(){
    Patient Patient = setPatientData();
    patientQueue.push(Patient);
}

