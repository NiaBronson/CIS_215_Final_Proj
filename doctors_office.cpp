#include "doctors_office.h"

#include <chrono>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<Patient> patients;
queue<Patient> patientQueue;
// Map of doctors and their availability
// True indicates available, false indicates unavailable
std::map<Doctor, bool> doctorAvailability;
std::map<Patient, Appointment> appointments;
std::map<double, bool> officeRooms;
std::map<long, Patient> patientsMap;

// MENU FUNCTIONS
int showMenu() {
    int menuChoice;
    bool isValidChoice = true;

    do {
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

    // Added in office logs
    ofstream officeLogs("logs.txt");
    officeLogs.open("logs.txt");

    switch (menuChoice) {
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
    officeLogs.close();
    return menuChoice;
}

bool checkMenuChoice(int menuChoice) {
    if (menuChoice < 1 || menuChoice > 7) {
        cout << "Invalid Choice. Please try again" << endl;
        cout << endl;
        return false;
    } else {
        return true;
    }
}

// DATA SETTING FUNCTIONS
Patient setPatientData() {
    Patient currPatient;
    // Variables
    string name;
    string streetAddress;
    string city;
    string state;
    string email;
    string insuranceCompany;
    double zipCode;
    string phoneNumber;
    string DoB;
    long appointmentID;
    long patientID;
    int arrivalHour, arrivalMinute, arrivalSecond;

    cout << "Patient First Name: " << endl;
    cin >> name;
    currPatient.fNameSetter(name);

    cout << "Patient Last Name: " << endl;
    cin >> name;
    currPatient.lNameSetter(name);

    cout << "Patient Street Address: " << endl;
    cin >> streetAddress;
    currPatient.streetAddressSetter(streetAddress);

    cout << "Patient City: " << endl;
    cin >> city;
    currPatient.citySetter(city);

    cout << "Patient State: " << endl;
    cin >> state;
    currPatient.stateSetter(state);

    // Consider special input parameters for this
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

Doctor setDoctorData() {
    Doctor currDoc;
    // Variables
    string fName;
    string lName;
    string streetAddress;
    string city;
    string state;
    string email;
    double zipCode;
    string phoneNumber;
    long appointmentID;
    long employeeID;
    Account employeeAccount;

    cout << "Doctor First Name: " << endl;
    cin >> fName;
    currDoc.fnameSetter(fName);

    cout << "Doctor Last Name: " << endl;
    cin >> lName;
    currDoc.lnameSetter(lName);

    cout << "Doctor Street Address: " << endl;
    cin >> streetAddress;
    currDoc.streetAddressSetter(streetAddress);

    cout << "Doctor City: " << endl;
    cin >> city;
    currDoc.citySetter(city);

    cout << "Doctor State: " << endl;
    cin >> state;
    currDoc.stateSetter(state);

    // Consider special input parameters for this
    cout << "Doctor Email: " << endl;
    cin >> email;

    currDoc.emailSetter(email);

    cout << "Doctor Zip Code: " << endl;
    cin >> zipCode;
    currDoc.zipCodeSetter(zipCode);

    cout << "Doctor Phone Number: " << endl;
    cin >> phoneNumber;
    currDoc.phoneNumberSetter(phoneNumber);

    cout << "Doctor Appointment ID: " << endl;
    cin >> appointmentID;
    currDoc.appointmentIDSetter(appointmentID);

    cout << "Doctor ID: " << endl;
    cin >> employeeID;
    currDoc.employeeIDSetter(employeeID);

    currDoc.employeeAccountSetter(employeeID, 0);

    doctorAvailability.insert(make_pair(currDoc, true));
    return currDoc;
}

void readIn(vector<Doctor>& doctors, vector<Patient>& patients,
            vector<double>& rooms) {
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
    string placeholder;
    double doublePlaceholder;

    while (getline(inFile, line)) {
        if (line.empty()) {
            continue;
        }

        if (line == "Doctors") {
            // Repeats for each doctor
            for (int i = 0; i < 3; i++) {
                // Make a new doc object
                doctor = Doctor();

                // Read in the string and non string doc data
                getline(inFile >> ws, placeholder);
                doctor.fnameSetter(placeholder);

                getline(inFile, placeholder);
                doctor.lnameSetter(placeholder);

                getline(inFile, placeholder);
                doctor.streetAddressSetter(placeholder);

                getline(inFile, placeholder);
                doctor.citySetter(placeholder);

                getline(inFile, placeholder);
                doctor.stateSetter(placeholder);

                inFile >> placeholder;
                doctor.zipCodeSetter(doublePlaceholder);
                inFile.ignore();
                getline(inFile, placeholder);
                doctor.phoneNumberSetter(placeholder);

                getline(inFile, placeholder);
                doctor.emailSetter(placeholder);

                inFile >> doublePlaceholder;
                doctor.employeeIDSetter(doublePlaceholder);
                inFile.ignore();

                // Add doc to the vector
                doctors.push_back(doctor);
            }

        }

        else if (line == "Patients") {
            for (int i = 0; i < 5; i++) {
                // new patient object
                patient = Patient();

                // Read in the string patient data
                getline(inFile >> ws,
                        placeholder);  // skip whitespace or else everything
                                       // will be displaced by one
                patient.arrivalTimeSetter(placeholder);

                getline(inFile, placeholder);
                patient.fNameSetter(placeholder);

                getline(inFile, placeholder);
                patient.lNameSetter(placeholder);

                getline(inFile, placeholder);
                patient.streetAddressSetter(placeholder);

                getline(inFile, placeholder);
                patient.citySetter(placeholder);

                getline(inFile, placeholder);
                patient.stateSetter(placeholder);

                inFile >> placeholder;
                patient.zipCodeSetter(doublePlaceholder);

                inFile.ignore();
                getline(inFile, placeholder);
                patient.phoneNumberSetter(placeholder);

                getline(inFile, placeholder);
                patient.emailSetter(placeholder);

                getline(inFile, placeholder);
                patient.DoBSetter(placeholder);

                getline(inFile, placeholder);
                patient.insuranceCompanySetter(placeholder);

                inFile >> doublePlaceholder;
                patient.patientIDSetter(doublePlaceholder);

                inFile.ignore();

                patients.push_back(patient);
            }
        }

        else if (line == "Rooms") {
            for (int i = 0; i < 5; i++) {
                inFile >> room;
                rooms.push_back(room);
                officeRooms.insert(make_pair(rooms[i], false));
            }
        }
    }

    inFile.close();
}

string getAppointmentType() {
    string appointmentType;
    int appointmentChoice = 0;
    bool isValid;
    ofstream officeLogs;
    officeLogs.open("logs.txt");

    if (appointmentChoice != 1 || appointmentChoice != 2) {
        isValid = false;
    }
    do {
        cout << "Please select an appointment type from the list below:"
             << endl;
        cout << "1. Preventative" << endl;
        cout << "2. Sick" << endl;

    } while (isValid == false);

    switch (appointmentChoice) {
        case 1:
            appointmentType = "Preventative";
            officeLogs << "Preventative Visit" << endl;
            break;
        case 2:
            appointmentType = "Sick";
            officeLogs << "Sick Visit" << endl;
            break;
        default:
            appointmentType = "Invalid: ERROR";
            officeLogs << "Invalid: ERROR" << endl;
            break;
    }

    officeLogs.close();

    return appointmentType;
}

// CREATING FUNCTIONS

void addPatient() {
    // Opening the logs file to output patient logs
    ofstream officeLogs;
    officeLogs.open("logs.txt");

    string arrivalTime;

    // Getting arrival time
    // Curr time won't update until recompilation
    // Tried different methods
    // auto arrivalTime = std::chrono::system_clock::now();

    // Getting arrival time
    cout << "Patient Arrival Time " << endl;
    cin >> arrivalTime;

    // Logging Patient data
    officeLogs << "Patient Arrival Time: " << arrivalTime << endl;

    // Getting patient data and adding patient to queue
    Patient currPatient = setPatientData();
    currPatient.arrivalTimeSetter(arrivalTime);

    // Adding patient into the queue
    patientQueue.push(currPatient);

    //Adding patient to their ID Map
    patientsMap.insert(make_pair(currPatient.patientIDGetter(), currPatient));

    // Creating their appointment
    createAppointment(currPatient);

}

void addDoctor() {
    /*
    Your code should prompt the office manager to enter doctor details and the
    doctor should become available to assign to patients.
    */
    ofstream officeLogs;
    officeLogs.open("logs.txt");

    Doctor currDoc = setDoctorData();

    // Logging Patient data
    officeLogs << "Doctor Added: " << currDoc.fNameGetter() << " "
               << currDoc.lNameGetter() << endl;
}

void createAppointment(Patient myPatient) {
    // Getting the date
    string date;
    cout << "What is the current date in MM/DD/YYYY format?" << endl;
    cin >> date;

    // Creating current appointment
    Appointment currAppointment(
        myPatient.fNameGetter(), myPatient.lNameGetter(),
        myPatient.patientIDGetter(), date, getAppointmentType(),
        myPatient.arrivalTimeGetter());

    // Adding appointment to map
    myPatient.appointmentSetter(currAppointment);
}

// OTHER FUNCTIONS

float calculateBill(string appointmentType, bool isInsured) {
    float bill = 0.0;
    ofstream officeLogs;
    officeLogs.open("logs.txt");

    if (isInsured) {
        if (appointmentType == "Preventative") {
            bill = 0.0;
            cout << "Your insurance covers this visit! You will not be billed!"
                 << endl;

        } else if (appointmentType == "Sick") {
            bill = 50.95;
            cout << "Your insurance covers part of this visit. You owe $50.95"
                 << endl;
        } else {
            cout << "ERROR: Invalid appointment type" << endl;
        }
    } else if (!isInsured) {
        if (appointmentType == "Preventative") {
            bill = 29.95;
            cout << "You do not have insurance. You owe $29.95" << endl;
        } else if (appointmentType == "Sick") {
            bill = 150.95;
            cout << "You do not have insurance. You owe $150.95" << endl;
        } else {
            cout << "ERROR: Invalid appointment type" << endl;
        }
    } else {
        cout << "ERROR: INVALID INSURANCE" << endl;
    }

    officeLogs << "Billed Amount: " << bill << endl;
    officeLogs.close();
    return bill;
}

void patientQueueSummary(vector<double>& rooms) {

    Patient person;
    Patient firstPatient;

    cout << "Patient Queue Summary:" << endl;

    // Displaying the patient queue
    for (auto& pair : appointments) {
        person = pair.first;
        cout << "Patient Name: " << person.fNameGetter() << " "
             << person.lNameGetter()
             << " Patient Arrival Time: " << person.arrivalTimeGetter() << endl;
    }

    // Asking if they want to assign a patient
    char choice;
    bool isValid = false;

    cout << "Would you like to assign a patient? Please type Y or N." << endl;
    cin >> choice;

    // Choice Validation
    while (!isValid) {
        if (choice != 'Y' || choice != 'N' || choice != 'y' || choice != 'n') {
            cout << "Invalid Choice. Please try again." << endl;
            cin >> choice;
        } else {
            isValid = true;
        }
    }

    int roomCount = 0;
    double patientID;

    if (choice == 'Y' || choice == 'y') {
        // Displaying rooms
        for (auto& pair : officeRooms) {
            if (pair.second == false) {
                cout << "Room Number: " << pair.first << endl;
                roomCount++;
            }
        }
        if (roomCount == 0) {
            cout << "Sorry, there are no rooms available!" << endl;
        } else {
            cout << "Please enter the room number you would like to assign the "
                    "patient to."
                 << endl;
            int roomNumber;
            cin >> roomNumber;

            //find the first available person 
            firstPatient = patientQueue.front();
            
            //Assign the patient their own room number
            firstPatient.appointmentRoomNumberSetter(roomNumber);

            //Remove patient from the line
            patientQueue.pop();


        }
    }
    else{
        cout << "Exiting" << endl;
        return;
    }

}


// TEST MAIN


int main() {
    vector<Doctor> doctors;
    vector<Patient> patients;
    vector<double> rooms;

    // TEST 1 CODE
    readIn(doctors, patients, rooms);

    for (int i = 0; i < doctors.size(); i++) {
        cout << doctors[i].fNameGetter() << endl;
        cout << doctors[i].lNameGetter() << endl;
        cout << doctors[i].streetAddressGetter() << endl;
        cout << doctors[i].cityGetter() << endl;
        cout << doctors[i].stateGetter() << endl;
        cout << doctors[i].zipCodeGetter() << endl;
        cout << doctors[i].phoneNumberGetter() << endl;
        cout << doctors[i].emailGetter() << endl;
        cout << doctors[i].employeeIDGetter() << endl;
    }

    for (int j = 0; j < patients.size(); j++) {
        cout << patients[j].arrivalTimeGetter() << endl;
        cout << patients[j].fNameGetter() << endl;
        cout << patients[j].lNameGetter() << endl;
        cout << patients[j].streetAddressGetter() << endl;
        cout << patients[j].cityGetter() << endl;
        cout << patients[j].stateGetter() << endl;
        cout << patients[j].emailGetter() << endl;
        cout << patients[j].insuranceCompanyGetter() << endl;
        cout << patients[j].DoBGetter() << endl;
        cout << patients[j].zipCodeGetter() << endl;
        cout << patients[j].phoneNumberGetter() << endl;
        cout << patients[j].patientIDGetter() << endl;
    }

    for (int k = 0; k < rooms.size(); k++) {
        cout << rooms[k] << endl;
    }

    return 0;
}