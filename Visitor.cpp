//
// Created by asus on 2023/6/4.
//

#include "Visitor.h"

Visitor::Visitor() {

}

Visitor::Visitor(string username, string name, string idNum, string phoneNum,string password) {
    this->username = username;
    this->name = name;
    this->idNum = idNum;
    this->phoneNum = phoneNum;
    this->password = password;
}

void Visitor::page() {

}

void Visitor::operate() {

}

void Visitor::makeAppointment() {

}

void Visitor::showAppointment() {

}

void Visitor::cancelAppointment() {

}

void Visitor::proxyAppointment() {

}


