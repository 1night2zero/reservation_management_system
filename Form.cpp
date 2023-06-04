#include "Form.h"

Form::Form() = default;

Form::Form(string attractionName, string name, string phoneNum, string serial, int day, int aorp, int state) {
    this->attractionName = std::move(attractionName);
    this->name = std::move(name);
    this->phoneNum = std::move(phoneNum);
    this->serial = std::move(serial);
    this->day = day;
    this->aorp = aorp;
    this->state = state;
}

