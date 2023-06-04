#include "Visitor.h"

Visitor::Visitor() {
    //初始化visitor容器
    ifstream in(VISITOR_FILE, ios::in);
    string username, name, idNum, phoneNum, password;
    while (in >> username >> name >> idNum >> phoneNum >> password) {
        vVisitor.emplace_back(username, name, idNum, phoneNum, password);
        vNum++;
    }
    in.close();
}

Visitor::Visitor(string username, string name, string idNum, string phoneNum, string password) {
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

void Visitor::getVisitorList() {

    cout << "共有" << vNum << "个游客" << endl;
    cout << "用户名\t姓名\t身份证号\t手机号\t密码" << endl;
    for (int i = 0; i < vNum; i++) {
        cout << vVisitor[i].username << "\t" << vVisitor[i].name << "\t" << vVisitor[i].idNum << "\t"
             << vVisitor[i].phoneNum << "\t" << vVisitor[i].password << endl;
    }
}


