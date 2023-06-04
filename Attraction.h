#pragma once

#include <string>

using std::string;

class Attraction {

public:
    string attractionsName;    //景点名称
    Attraction();

    Attraction(string name, int day, int aorp, int maxNum, int Had[2][2]);

    //日期 0-1 今天明天
    int day;
    //时间段、0上午1下午
    int aorp;
    //上午最大容量
    int maxNum = 30;
    //今天上午、今天下午、明天上午、明天下午已预约量
    int Had[2][2] = {0, 0, 0, 0};

};