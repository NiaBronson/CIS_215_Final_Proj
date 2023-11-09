using namespace std;
#include <iostream>


class Appointment{

    private:
    string patientName;
    string patientID;
    string doctorName;
    string doctorID;
    string date;
    string visitType;
    int roomNumber;
    int time;

    public:
    //Getters
    string patientNameGetter(){
        return patientName;
    }
    string patientIDGetter(){
        return patientID;
    }
    string doctorNameGetter(){
        return doctorName;
    }
    string doctorIDGetter(){
        return doctorID;
    }
    string dateGetter(){
        return date;
    }
    string visitTypeGetter(){
        return visitType;
    }
    int roomNumberGetter(){
        return roomNumber;
    }
    int timeGetter(){
        return time;
    }

    //Setters
    void patientNameSetter(string newPatientName){
        patientName = newPatientName;
    }
    void patientIDSetter(string newPatientID){
        patientID = newPatientID;
    }
    void doctorNameSetter(string newDoctorName){
        doctorName = newDoctorName;
    }
    void doctorIDSetter(string newDoctorID){
        doctorID = newDoctorID;
    }
    void dateSetter(string newDate){
        date = newDate;
    }
    void visitTypeSetter(string newVisitType){
        visitType = newVisitType;
    }
    void roomNumberSetter(int newRoomNumber){
        roomNumber = newRoomNumber;
    }
    void timeSetter(int newTime){
        time = newTime;
    }

};