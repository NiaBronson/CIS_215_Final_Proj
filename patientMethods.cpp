#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <chrono>

#include "functions.h"
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
    int arrivalHour, arrivalMinute, arrivalSecond;

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
    //Opening the logs file to output patient logs
    ofstream officeLogs;
    officeLogs.open("logs.txt");

    int arrivalHour, arrivalMinute, arrivalSecond;

    //Getting arrival time
    //Curr time won't update until recompilation 
    //Tried different methods
    //auto arrivalTime = std::chrono::system_clock::now();

    //Getting arrival time
    cout << "Patient Arrival Hour: " << endl;
    cin >> arrivalHour;
    cout << "Patient Arrival Minute: " << endl;
    cin >> arrivalMinute;
    cout << "Patient Arrival Second: " << endl;
    cin >> arrivalSecond;

    //Logging Patient data
    officeLogs << "Patient Arrival Time: " << arrivalHour << ":" << arrivalMinute << ":" << arrivalSecond << endl;

    //Getting patient data and adding patient to queue
    Patient currPatient = setPatientData();
    patientQueue.push(currPatient);


}



