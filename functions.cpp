#include "functions.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void showMenu(){

    int menuChoice;
    bool isValidChoice = true;

    do{
        cout << "Welcome to the Office Manager!" << endl;
        cout << "Please select an option from the menu below:" << endl;
        cout << "1. Load Data" << endl;
        cout << "2. Add New Doctor" << endl;
        cout << "3. Add New Patient" << endl;
        cout << "4. Patient Queue Summary" << endl;
        cout << "5. Doctor Summary" << endl;
        cout << "6. Checkout Patient" << endl;
        cout << "7. Close Office" << endl;

        cout << "Please Enter Your Choice: ";
        cin >> menuChoice;

        isValidChoice = checkMenuChoice(menuChoice);
    } while (isValidChoice == false);
        
    ofstream officeLogs("logs.txt");

    switch(menuChoice){
            case 1:
                cout << "You chose to load data" << endl;
                officeLogs << "Loaded Data" << endl; 
                break;
            case 2:
                cout << "You chose to add a new doctor" << endl;
                officeLogs << "Added New Doctor" << endl;
                break;
            case 3:
                cout << "You chose to add a new patient" << endl;
                officeLogs << "Added New Patient" << endl;
                break;
            case 4:
                cout << "You chose to view the patient queue summary" << endl;
                officeLogs << "Viewed Patient Queue Summary" << endl;
                break;
            case 5:
                cout << "You chose to view the doctor summary" << endl;
                officeLogs << "Viewed Doctor Summary" << endl;
                break;
            case 6:
                cout << "You chose to check out a patient" << endl;
                officeLogs << "Checked Patient Out" << endl;
                break;
            case 7:
                cout << "You chose to close the office" << endl;
                officeLogs << "Closing Office" << endl;
                break;
            default:
                cout << "Invalid Choice" << endl;
                officeLogs << "Invalid Choice" << endl;
                break;
        }

}

void readIn(vector<Doctor2>& doctors, vector<Patient2>& patients, vector<double>& rooms) {
    ifstream inFile("officeMgr.dat");

    if (!inFile) {
        cout << "Unable to find the file." << endl;
        inFile.close();
        return;
    }

    Doctor2 doctor; 
    Patient2 patient;
    string line;
    int room;

    while (getline(inFile, line)) {
        if (line.empty()) {
            continue;
        }

        if (line == "Doctors") {
            //Repeats for each doctor
            for (int i = 0; i < 3; i++){
                // Make a new doc object
                doctor = Doctor2();

                //Read in the string  and non string doc data
                getline(inFile >> ws, doctor.fname);
                getline(inFile, doctor.lname);
                getline(inFile, doctor.streetAddress);
                getline(inFile, doctor.city);
                getline(inFile, doctor.state);

                inFile >> doctor.zipCode;
                inFile.ignore();
                getline(inFile, doctor.phoneNumber);

                getline(inFile, doctor.email);  

                inFile >> doctor.employeeID;
                inFile.ignore();

                //Add doc to the vector
                doctors.push_back(doctor);
            }
           
        }

        else if (line == "Patients"){
            for (int i = 0; i < 5; i++){
                //new patient object
                patient = Patient2();

                //Read in the string patient data
                getline(inFile >> ws, patient.time); //skip whitespace or else everything will be displaced by one
                getline(inFile, patient.fname);
                getline(inFile, patient.lname);
                getline(inFile, patient.streetAddress);
                getline(inFile, patient.city);
                getline(inFile, patient.state);
                
                inFile >> patient.zipCode;
                inFile.ignore();
                getline(inFile, patient.phoneNumber);

                getline(inFile, patient.email);
                getline(inFile, patient.dob);
                getline(inFile, patient.insuranceCompany);

                inFile >> patient.patientID;
                inFile.ignore();

                patients.push_back(patient);
            }
        }

        else if (line == "Rooms"){
            for (int i = 0; i < 5; i++){
                inFile >> room;
                rooms.push_back(room);
            }
        }
    }

    inFile.close();
}


bool checkMenuChoice(int menuChoice){
    if (menuChoice < 1 || menuChoice > 7){
        cout << "Invalid Choice. Please try again" << endl;
        cout << endl;
        return false;
    }
    else{
        return true;
    }
}