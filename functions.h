#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <vector>
#include <string>

using namespace std;

struct Doctor2 {
    string fname;
    string lname;
    string streetAddress;
    string city;
    string state;
    string email;
    double zipCode;
    string phoneNumber;
    long appointmentID;
    long employeeID;
};

struct Patient2 {
    string time;
    string fname;
    string lname;
    string streetAddress;
    string city;
    string state;
    string email;
    string insuranceCompany;
    string dob;
    double zipCode;
    string phoneNumber;
    long patientID;
    long appointmentID;
};

int showMenu();
void readIn(vector<Doctor2>& doctors, vector<Patient2>& patients,
            vector<double>& rooms);
bool checkMenuChoice(int menuChoice);
string getAppointmentType();

#endif  // FUNCTIONS_H
