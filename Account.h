using namespace std;
#include <iostream>

class Account{

    private:
    long ownerID;
    float balance;

    public:
    //Getters
    long ownerIDGetter(){
        return ownerID;
    }
    float balanceGetter(){
        return balance;
    }

    //Setters
    void ownerIDSetter(long newOwnerID){
        ownerID = newOwnerID;
    }
    void balanceSetter(float newBalance){
        balance = newBalance;
    }

};