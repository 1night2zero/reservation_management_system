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
    cout << "\t\t|          9.修改预约信息           |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          10.添加游客              |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          11.删除游客             |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          12.修改游客信息          |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.注销登录            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

//操作
void Admin::operate() {
    this->page();

    string in;
    int ch;

    while (cin >> in) {
        try {
            ch = stoi(in);
        } catch (exception &e) {
            cout << "请输入正确的选项!\n";
            continue;
        }
        switch (ch) {
            case 1:
                this->getVisitorList(); // TODO 根据需求实现所需的功能，还可以加用户的CRUD操作
                break;
            case 2:
                this->showAttractions();
                break;
            case 3:
                this->getFormList();
                break;
            case 4:
                this->addAttraction();
                break;
            case 5:
                this->deleteAttraction();
                break;
            case 6:
                this->changeAttraction();
                break;
            case 7:
                this->makeAppointment();
                break;
            case 8:
                this->deleteForm();
                break;
            case 9:
                this->changeForm();
                break;
            case 10:
                this->addVisitor();
                break;
            case 11:
                this->deleteVisitor();
                break;
            case 12:
                this->changeVisitorInfo();
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

//获取游客列表
void Admin::getVisitorList() {
    Visitor v;
    v.getVisitorList();
}

//添加游客
void Admin::addVisitor() {
    Visitor v;
    v.addVisitor();
}

//删除游客
void Admin::deleteVisitor() {
    Visitor v;
    v.deleteVisitor();
}

//修改游客信息
void Admin::changeVisitorInfo() {
    Visitor v;
    v.changeVisitorInfo();
}
