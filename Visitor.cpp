#include "Visitor.h"

Visitor::Visitor() {
    cout << "欢迎：" << this->name << "登录！" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          1.预约景点             |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          2.查看预约记录         |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          3.取消预约             |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          0.注销登录             |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

Visitor::Visitor(string username, string name, string idNum, string phoneNum,string password) {
    this->username = username;
    this->name = name;
    this->idNum = idNum;
    this->phoneNum = phoneNum;
    this->password = password;
}

void Visitor::page() {
    cout << "欢迎：" << this->name << "登录！" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          1.预约景点             |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          2.查看预约记录         |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          3.取消预约             |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          4.代理预约             |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          0.注销登录             |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

void Visitor::operate() {
    this->page();
    int ch = 0;
    while (cin >> ch) {
        switch (ch) {
            case 1:
                this->makeAppointment();
                break;
            case 2:
                this->showAppointment();
                break;
            case 3:
                this->cancelAppointment();
                break;
            case 4:
                this->proxyAppointment();
                break;
            case 0:
                return;
            default:
                cout << "请输入正确选项！" << endl;
                system("pause");
                this->operate();
                break;
        }
        cout << "请选择您的操作： " << endl;
    }
}

void Visitor::makeAppointment() {

}

void Visitor::showAppointment() {

}

void Visitor::cancelAppointment() {

}

void Visitor::proxyAppointment() {

}


