#pragma once

#include <iostream>

using namespace std;

class User {

public:
    string username; //用户名
    string password; //密码

    //构造函数
    User();

    virtual void page() = 0;

    //查看景点名称 预约数量 TODO

    //查看景点在该时间下是否有余量 TODO

    //旅游景点信息的容器 TODO

    //预约订单容器 TODO

    //游客信息容器 TODO


};


