#include "BankApplication.h"

void Client::Set_Name(const string & Name) {
    name = Name ;
}

void Client::Set_Address(const string & Address_) {
    Address = Address_ ;
}

void Client::Set_Phone(const string & phone_) {
    phone = phone_ ;
}

string Client::Get_Name() {
    return name ;
}

string Client::Get_Address() {
    return Address ;
}

string Client::Get_Phone() {
    return phone ;
}

int Client::Get_Number_Clients() {
    return Number_Clients;
}

Client::Client() {
    Number_Clients++  ;
}