#pragma once

#include <vector>
#include "User.h"

class Visitor : public User {

    string idNum;   //身份证号
    string phoneNum;    //手机号
    string name;    //姓名
public:
    //默认构造函数
    Visitor();

    //有参构造
    Visitor(string username, string name, string idNum, string phoneNum,string password);

    //界面
    virtual void page();

    //操作
    void operate();

    //预约
    void makeAppointment();

    //查看预约
    void showAppointment();

    //*取消预约
    void cancelAppointment();

    //代理预约
    void proxyAppointment();

};

