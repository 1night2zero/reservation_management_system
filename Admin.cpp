//
// Created by asus on 2023/6/4.
//

#include "Admin.h"

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
    cout << "\t\t|          1.展示信息            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.添加信息            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          3.修改信息            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          4.删除信息            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          5.添加景点            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          6.修改景点            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          7.删除景点            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          8.查看预约            |\n";
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
                this->showInfo();
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