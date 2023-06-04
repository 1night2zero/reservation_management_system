//
// Created by asus on 2023/6/4.
//

#include "Admin.h"
#include "Visitor.h"

Admin::Admin() = default;

Admin::Admin(string username, string password) {
    this->username = username;
    this->password = password;
}

//界面
void Admin::page() {
    cout << "欢迎管理员：" << this->username << "登录！" << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          1.查看游客列表            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.查看景区列表            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          3.查看预约单列表          |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          4.添加景区            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          5.删除景区信息           |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          6.修改景区信息          |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          7.添加预约             |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          8.删除预约             |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          9.获取游客列表          |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.注销登录            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

//操作
void Admin::operate() {
    this->page();
    int ch = 0;
    while (cin >> ch) {
        switch (ch) {
            case 1:
                this->showInfo(); // TODO 根据需求实现所需的功能，还可以加用户的CRUD操作
                break;
            case 9:
                this->getVisitorList(); // TODO 根据需求实现所需的功能，还可以加用户的CRUD操作
                break;
            case 0:
                return;
            default:
                cout << "请输入正确选项！" << endl;
                this->operate();
                break;
        }
        cout << "请选择您的操作： " << endl;
    }
}

//展示信息
void Admin::showInfo() {
    cout << "hello world" << endl;
}

void Admin::getVisitorList() {
    Visitor v;
    v.getVisitorList();
}