#pragma once

#include "User.h"

class Admin : public User {
    //默认构造函数
    Admin();

    //界面
    virtual void page();

    //获取游客列表
    void getVisitorList();

    //添加游客
    void addVisitor();

    //修改游客信息
    void changeVisitorInfo();

    //删除游客
    void deleteVisitor();

    //获取景区列表
    void getAttractionsList();

    //添加景区
    void addAttractions();

    //修改景区信息
    void changeAttractionsInfo();

    //删除景区
    void deleteAttractions();

    //查看景区预约
    void showAppointment();

public:
//有参构造
Admin(string username, string password);

//操作
void operate();

    void showInfo();
};


