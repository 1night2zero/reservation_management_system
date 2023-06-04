#include "Form.h"

Form::Form() = default;

Form::Form(string attractionName, string name, string phoneNum, string serial, int state) {
    this->attractionsName = attractionName;
    this->name = name;
    this->phoneNum = phoneNum;
    this->serial = serial;
    this->state = state;
}

