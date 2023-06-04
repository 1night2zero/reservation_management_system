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
    int ch;
    string in;
    while (cin >> in) {
        try {
            ch = stoi(in);
        } catch (exception &e) {
            cout << "请输入正确的选项!\n";
            continue;
        }
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

void Visitor::addVisitor() {
    string username, name, idNum, phoneNum, password;
    cout << "请输入用户名：" << endl;
    cin >> username;
    cout << "请输入姓名： " << endl;
    cin >> name;
    cout << "请输入身份证号： " << endl;
    cin >> idNum;
    cout << "请输入手机号： " << endl;
    cin >> phoneNum;
    //检测用户是否存在
    for (int i = 0; i < vNum; i++) {
        if (vVisitor[i].username == username) {
            cout << "该用户已存在！" << endl;
            return;
        }
        if (vVisitor[i].phoneNum == phoneNum) {
            cout << "该手机号已被注册！" << endl;
            return;
        }
        if (vVisitor[i].idNum == idNum) {
            cout << "该身份证号已被注册！" << endl;
            return;
        }
    }
    password = idNum.substr(idNum.length() - 6, 6);
    vVisitor.emplace_back(username, name, idNum, phoneNum, password);
    vNum++;
    cout << "添加成功！默认密码为身份证后六位" << endl;
    //刷新文件
    ofstream out(VISITOR_FILE, ios::trunc);
    for (int i = 0; i < vNum; ++i) {
        out << vVisitor[i].username << "\t" << vVisitor[i].name << "\t" << vVisitor[i].idNum << "\t"
            << vVisitor[i].phoneNum << "\t" << vVisitor[i].password << endl;
    }
    out.close();
}

void Visitor::deleteVisitor() {
    string name;
    cout << "请输入要删除的游客姓名： " << endl;
    cin >> name;
    for (int i = 0; i < vNum; i++) {
        if (vVisitor[i].name == name) {
            vVisitor.erase(vVisitor.begin() + i);
            vNum--;
            cout << "删除成功！" << endl;
            //刷新文件
            ofstream out(VISITOR_FILE, ios::trunc);
            for (int i = 0; i < vNum; ++i) {
                out << vVisitor[i].username << "\t" << vVisitor[i].name << "\t" << vVisitor[i].idNum << "\t"
                    << vVisitor[i].phoneNum << "\t" << vVisitor[i].password << endl;
            }
            out.close();
            return;
        }
    }
    cout << "未找到该游客！" << endl;
}

void Visitor::changeVisitorInfo() {
    string username, name, idNum, phoneNum, password;
    cout << "提示：直接输入回车不会修改信息" << endl;
    cout << "请输入要修改的游客用户名： " << endl;
    cin >> username;
    for (int i = 0; i < vNum; i++) {
        if (vVisitor[i].username == username) {
            //回车不修改
            cout << "请输入新的用户名： " << endl;
            cin >> username;
            cout << "请输入新的姓名： " << endl;
            cin >> name;
            cout << "请输入新的身份证号： " << endl;
            cin >> idNum;
            cout << "请输入新的手机号： " << endl;
            cin >> phoneNum;


            //检测是否已存在
            for (int i = 0; i < vNum; i++) {
                if (vVisitor[i].username == username) {
                    cout << "该用户已存在！" << endl;
                    return;
                }
                if (vVisitor[i].phoneNum == phoneNum) {
                    cout << "该手机号已被注册！" << endl;
                    return;
                }
                if (vVisitor[i].idNum == idNum) {
                    cout << "该身份证号已被注册！" << endl;
                    return;
                }
                if (username != "\\")
                    vVisitor[i].username = username;
                if (username != "\\")
                    vVisitor[i].name = name;
                if (username != "\\")
                    vVisitor[i].idNum = idNum;
                if (username != "\\")
                    vVisitor[i].phoneNum = phoneNum;
            }
            cout << "修改成功！" << endl;


            //刷新文件
            ofstream out(VISITOR_FILE, ios::trunc);
            for (int i = 0; i < vNum; ++i) {
                out << vVisitor[i].username << "\t" << vVisitor[i].name << "\t" << vVisitor[i].idNum << "\t"
                    << vVisitor[i].phoneNum << "\t" << vVisitor[i].password << endl;
            }
            out.close();
            return;
        }
    }
    cout << "未找到该游客！" << endl;
}


