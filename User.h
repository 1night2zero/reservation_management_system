#pragma once

#include <iostream>
#include <vector>
#include "Attraction.h"
#include "Form.h"

using namespace std;

class User {

public:
    string username; //用户名
    string password; //密码

    //构造函数
    User();

    virtual void page() = 0;

    //旅游景点信息的容器
    vector<Attraction> vAttractions;

    //预约订单容器 TODO
    vector<Form> vForm;

    //显示景区列表
    void showAttractions();

    //添加景区
    void addAttraction();

    //删除景区
    void deleteAttraction();

    //初始化容器
    void initVAttractions();

    void initVForm();

    void changeAttraction();

    void getFormList();

    void addForm();

    void deleteForm();

    void changeForm();

    static string generateCode();

    void makeAppointment();

    void updateAttractionsFile();

    void updateFormFile();

    string makeSerialCode();
};


