#pragma once

#include<iostream>
#include<Windows.h>
#include <regex>
#include <fstream>


//#include "Visitor.h"
//#include "Admin.h"
//#include "GlobalUtils.h"
#include"File.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::regex;


class System {
public:
    //开始
    void Start();

    //构造函数
    System();

    //登录 TODO
    void login(int type);

    //注册游客账号
    void visitorRegister();
};

