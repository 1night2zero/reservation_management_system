#pragma once

#include "Attraction.h"

class Form : public Attraction {

public:
    Form();

    Form(string attractionName, string name, string phoneNum, string serial, int day, int aorp, int state);

    //预约人姓名
    string name;
    //手机号
    string phoneNum;
    //预约序号
    string serial;
    //预约状态，0未处理 1已预约 -1已取消
    int state = 0;
};


