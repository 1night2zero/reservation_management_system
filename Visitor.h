#pragma once

#include <vector>
#include <fstream>

#include "File.h"
#include "User.h"

class Visitor : public User {

    string idNum;   //身份证号
    string phoneNum;    //手机号
    string name;    //姓名
public:
    //默认构造函数
    Visitor();

    //有参构造
    Visitor(string username, string name, string idNum, string phoneNum, string password);

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


    //获取游客列表
    void getVisitorList();

    //游客容器
    vector<Visitor> vVisitor;

    //游客数量
    int vNum = 0;

    //添加游客
    void addVisitor();

    //删除游客
    void deleteVisitor();

    //修改游客信息
    void changeVisitorInfo();
};

