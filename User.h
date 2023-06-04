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

    //界面
    virtual void page() = 0;

    //旅游景点信息的容器
    vector<Attraction> vAttractions;

    //预约订单容器
    vector<Form> vForm;

    //显示景区列表
    void showAttractions();

    //添加景区
    void addAttraction();

    //删除景区
    void deleteAttraction();

    //初始化容器
    void initVAttractions();

    //初始化预约单容器
    void initVForm();

    //修改景区信息
    void changeAttraction();

    //获取预约单列表
    void getFormList();

    //添加预约单
    void addForm();

    //删除预约单
    void deleteForm();

    //修改预约单
    void changeForm();


    //预约
    void makeAppointment();

    //更新景区信息文件
    void updateAttractionsFile();

    //更新预约单文件
    void updateFormFile();

};


