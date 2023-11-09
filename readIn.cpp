#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <"functions.h">


using namespace std;



void readIn(vector<Doctor>& doctors, vector<Patient>& patients, vector<double>& rooms) {
    ifstream inFile("officeMgr.dat");

    if (!inFile) {
        cout << "Unable to find the file." << endl;
        inFile.close();
        return;
    }

    Doctor doctor; 
    Patient patient;
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
                doctor = Doctor();

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
                patient = Patient();

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

int main() {
    vector<Doctor> doctors;
    vector<Patient> patients;
    vector<double> rooms;

    //TEST 1 CODE
    readIn(doctors, patients, rooms);

    for (int i = 0; i < doctors.size(); i++) {
        cout << doctors[i].fname << endl;
        cout << doctors[i].lname << endl;
        cout << doctors[i].streetAddress << endl;
        cout << doctors[i].city << endl;
        cout << doctors[i].state << endl;
        cout << doctors[i].zipCode << endl;
        cout << doctors[i].phoneNumber << endl;
        cout << doctors[i].email << endl;
        cout << doctors[i].employeeID << endl;
    }

    for (int j = 0; j < patients.size(); j++){
        cout << patients[j].time << endl;
        cout << patients[j].fname << endl;
        cout << patients[j].lname << endl;
        cout << patients[j].streetAddress << endl;
        cout << patients[j].city << endl;
        cout << patients[j].state << endl;
        cout << patients[j].email << endl;
        cout << patients[j].insuranceCompany << endl;
        cout << patients[j].dob << endl;
        cout << patients[j].zipCode << endl;
        cout << patients[j].phoneNumber << endl;
        cout << patients[j].patientID << endl;        
    }

    for (int k = 0; k < rooms.size(); k++){
        cout << rooms[k] << endl;
    }

    return 0;
}