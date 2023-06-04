#pragma once

#include "Attraction.h"

class Form : public Attraction {
    string name;      //预约人姓名
    string phoneNum;    //手机号
    string serial;      //预约序号
    int state = 0;    //0未处理 1已预约 -1已取消

public:
    Form();
    Form(string attractionName,string name, string phoneNum, string serial, int state);
};


