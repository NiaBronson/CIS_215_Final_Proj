using namespace std;
#include <iostream>


class Doctor{

    private:
    string name;
    string streetAddress;
    string city;
    string state;
    string email;
    double zipCode;
    double phoneNumber;
    long appointmentID;
    long employeeID;

    public:
    //Getters
    string nameGetter(){
        return name;
    }
    string streetAddressGetter(){
        return streetAddress;
    }
    string cityGetter(){
        return city;
    }
    string stateGetter(){
        return state;
    }
    string emailGetter(){
        return email;
    }
    double zipCodeGetter(){
        return zipCode;
    }
    double phoneNumberGetter(){
        return phoneNumber;
    }
    double appointmentIDGetter(){
        return appointmentID;
    }
    double employeeIDGetter(){
        return employeeID;
    }
    

    //Setters
    void nameSetter(string newName){
        name = newName;
    }
    void streetAddressSetter(string newStreetAddress){
        streetAddress = newStreetAddress;
    }   
    void citySetter(string newCity){
        city = newCity;
    }
    void stateSetter(string newState){
        state = newState;
    }
    void emailSetter(string newEmail){
        email = newEmail;
    }
    void zipCodeSetter(double newZipCode){
        zipCode = newZipCode;
    }
    void phoneNumberSetter(double newPhoneNumber){
        phoneNumber = newPhoneNumber;
    }
    void appointmentIDSetter(double newAppointmentID){
        appointmentID = newAppointmentID;
    }
    void employeeIDSetter(double newEmployeeID){
        employeeID = newEmployeeID;
    }

};