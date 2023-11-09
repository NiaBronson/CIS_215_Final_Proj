using namespace std;
#include <iostream>
#include "Account.h"




class Patient{

    private:
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
    Account patientAccount;
    int arrivalHour, arrivalMinute, arrivalSecond;


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
    string insuranceCompanyGetter(){
        return insuranceCompany;
    }
    double zipCodeGetter(){
        return zipCode;
    }
    double phoneNumberGetter(){
        return phoneNumber;
    }
    double DoBGetter(){
        return DoB;
    }
    double appointmentIDGetter(){
        return appointmentID;
    }
    double patientIDGetter(){
        return patientID;
    }
    Account patientAccountGetter(){
        return patientAccount;
    }
    float patientBalanceGetter(){
        return patientAccount.balanceGetter();
    }
    int arrivalHourGetter(){
        return arrivalHour;
    }
    int arrivalMinuteGetter(){
        return arrivalMinute;
    }
    int arrivalSecondGetter(){
        return arrivalSecond;
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
    void insuranceCompanySetter(string newInsuranceCompany){
        insuranceCompany = newInsuranceCompany;
    }
    void zipCodeSetter(double newZipCode){
        zipCode = newZipCode;
    }
    void phoneNumberSetter(double newPhoneNumber){
        phoneNumber = newPhoneNumber;
    }
    void DoBSetter(double newDoB){
        DoB = newDoB;
    }
    void appointmentIDSetter(long newAppointmentID){
        appointmentID = newAppointmentID;
    }
    void patientIDSetter(long newPatientID){
        patientID = newPatientID;
    }
    void patientAccountSetter(long patientID, float balance = 0);
    void patientBalanceSetter(float newBalance){
        patientAccount.balanceSetter(newBalance);
    }
    void arrivalHourSetter(int newHour){
        arrivalHour = newHour;
    }
    void arrivalMinuteSetter(int newMinute){
        arrivalMinute = newMinute;
    }
    void arrivalSecondSetter(int newSecond){
        arrivalSecond = newSecond;
    }

};