using namespace std;
#include <iostream> 
#include <vector>
#include <fstream>
#include "doctors_office.h"
#include "doctors_office.cpp"

int main(){
   
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<double> rooms;
    vector<Appointment> appointments;

    queue<Patient> patientQueue;
    // Map of doctors and their availability
    // True indicates available, false indicates unavailable
    std::map<Doctor, bool> doctorAvailability;
    std::map<Patient, Appointment> appointmentMap;
    std::map<double, bool> officeRooms;
    std::map<long, Patient> patientsMap;


    showMenu();


    // switch(choice){
    //     case 1:
    //             loadData();
    //             break;
    //     case 2:
    //             cout << "You chose to add a new doctor" << endl;
    //             officeLogs << "Added New Doctor" << endl;
    //             break;
    //     case 3:
    //             cout << "You chose to add a new patient" << endl;
    //             officeLogs << "Added New Patient" << endl;
    //             break;
    //     case 4:
    //             cout << "You chose to view the patient queue summary" << endl;
    //             officeLogs << "Viewed Patient Queue Summary" << endl;
    //             break;
    //     case 5:
    //             cout << "You chose to view the doctor summary" << endl;
    //             officeLogs << "Viewed Doctor Summary" << endl;
    //             break;
    //     case 6:
    //             cout << "You chose to check out a patient" << endl;
    //             officeLogs << "Checked Patient Out" << endl;
    //             break;
    //     case 7:
    //             cout << "You chose to close the office" << endl;
    //             officeLogs << "Closing Office" << endl;
    //             break;
    //     default:
    //             cout << "Invalid Choice" << endl;
    //             officeLogs << "Invalid Choice" << endl;
    //             break;
    // }



    return 0;
}


