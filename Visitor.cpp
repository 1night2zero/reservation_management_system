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
    cout << "\t\t|          2.查看我的预约记录         |\n";
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
                this->showAttractions();
                this->booking();
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
                this->operate();
                break;
        }
        cout << "请选择您的操作： " << endl;
    }
}

//查看我的预约
void Visitor::showAppointment() {
    cout << "您的预约记录如下：" << endl;
    cout << "景点名\t预约日期\t时间段\t预约码\t预约状态" << endl;
    for (auto &i: vForm) {
        if (i.name == this->name) {
            cout << i.attractionName << "\t\t" << (i.day == 0 ? "今天" : "明天") << "\t\t"
                 << (i.aorp == 0 ? "上午" : "下午") << "\t\t"
                 << i.serial << "\t" << (i.state == 1 ? "已预约" : i.state == -1 ? "已取消" : "未处理") << endl;
        }
    }
}

//取消预约
void Visitor::cancelAppointment() {
    string serial;
    cout << "请输入您要取消的预约码： " << endl;
    cin >> serial;
    for (int i = 0; i < vForm.size(); i++) {
        if (vForm[i].serial == serial && vForm[i].state == 1) {
            vForm[i].state = -1;
            //更新景点预约人数
            for (int j = 0; j < vAttractions.size(); j++) {
                if (vAttractions[j].attractionName == vForm[i].attractionName) {
                    vAttractions[j].Had[vForm[i].day][vForm[i].aorp]--;
                    break;
                }
            }
            cout << "取消成功！" << endl;

            //刷新文件
            updateFormFile();
            updateAttractionsFile();
            return;
        }
    }
    cout << "未找到该预约码！" << endl;
}

//代理其他用户预约，最多可以代理2个用户
void Visitor::proxyAppointment() {
    string username;
    cout << "请输入您要代理的用户名： " << endl;
    cin >> username;
    for (int i = 0; i < vVisitor.size(); i++) {
        if (vVisitor[i].username == username) {
            if (vVisitor[i].proxyNum == 2) {
                cout << "该用户已有2个代理人，无法再代理！" << endl;
                return;
            }
            vVisitor[i].proxyNum++;
            makeAppointment();
            cout << "代理预约成功！" << endl;
            return;
        }
    }
    cout << "未找到该用户！" << endl;

}

void Visitor::getVisitorList() {
    cout << "共有" << vVisitor.size() << "个游客" << endl;
    cout << "用户名\t姓名\t身份证号\t手机号\t密码" << endl;
    for (auto &i: vVisitor) {
        cout << i.username << "\t" << i.name << "\t" << i.idNum << "\t"
             << i.phoneNum << "\t" << i.password << endl;
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
    for (int i = 0; i < vVisitor.size(); i++) {
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
    cout << "添加成功！默认密码为身份证后六位" << endl;
    //刷新文件
    ofstream out(VISITOR_FILE, ios::trunc);
    for (int i = 0; i < vVisitor.size(); ++i) {
        out << vVisitor[i].username << "\t" << vVisitor[i].name << "\t" << vVisitor[i].idNum << "\t"
            << vVisitor[i].phoneNum << "\t" << vVisitor[i].password << endl;
    }
    out.close();
}

void Visitor::deleteVisitor() {
    string name;
    cout << "请输入要删除的游客姓名： " << endl;
    cin >> name;
    for (int i = 0; i < vVisitor.size(); i++) {
        if (vVisitor[i].name == name) {
            vVisitor.erase(vVisitor.begin() + i);
            cout << "删除成功！" << endl;
            //刷新文件
            ofstream out(VISITOR_FILE, ios::trunc);
            for (int i = 0; i < vVisitor.size(); ++i) {
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
    cout << "提示：直接输入xx不会修改信息" << endl;
    cout << "请输入要修改的游客用户名： " << endl;
    cin >> username;
    for (int i = 0; i < vVisitor.size(); i++) {
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
            for (int i = 0; i < vVisitor.size(); i++) {
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
            if (username != "xx")
                vVisitor[i].username = username;
            if (username != "xx")
                vVisitor[i].name = name;
            if (username != "xx")
                vVisitor[i].idNum = idNum;
            if (username != "xx")
                vVisitor[i].phoneNum = phoneNum;
            cout << "修改成功！" << endl;

            //刷新文件
            ofstream out(VISITOR_FILE, ios::trunc);
            for (int i = 0; i < vVisitor.size(); ++i) {
                out << vVisitor[i].username << "\t" << vVisitor[i].name << "\t" << vVisitor[i].idNum << "\t"
                    << vVisitor[i].phoneNum << "\t" << vVisitor[i].password << endl;
            }
            out.close();
            return;
        }
    }
    cout << "未找到该游客！" << endl;
}

//用户自己预约景点，不需要填写个人信息，只需要填写景点名称和预约时间
void Visitor::booking() {
    string attractionName;
    int day, aorp;
    cout << "请输入要预约的景点名称： " << endl;
    cin >> attractionName;
    cout << "请输入要预约的日期： (0表示今天，1表示明天）" << endl;
    cin >> day;
    cout << "请输入要预约的时间： (0表示上午，1表示下午）" << endl;
    cin >> aorp;
    //生成预约单号码,景区名+6位随机且不会重复的数字
    string serial = attractionName;
    srand((unsigned) time(NULL));
    for (int i = 0; i < 6; i++) {
        serial += to_string(rand() % 10);
    }

    for (auto &vAttraction: vAttractions) {
        if (vAttraction.attractionName == attractionName) {
            if (vAttraction.day == day && vAttraction.aorp == aorp) {
                if (vAttraction.Had[day][aorp] < vAttraction.maxNum) {
                    vAttraction.Had[day][aorp]++;
                    //判断
                    for (int i = 0; i < vForm.size(); i++) {
                        if (vForm[i].serial == serial) {
                            cout << "该预约单号已存在！" << endl;
                            return;
                        }
                        if (vForm[i].day == day && vForm[i].aorp == aorp && vForm[i].name == name) {
                            cout << "该用户以预约过该时间段" << endl;
                            return;
                        }
                    }

                    Form form(attractionName, name, phoneNum, serial, day, aorp, 1);
                    vForm.push_back(form);
                    cout << "预约成功，您的预约码为：" << serial << endl;
                    //刷新文件
                    updateFormFile();
                    updateAttractionsFile();
                    return;
                } else {
                    cout << "该时间段已预约满" << endl;
                    return;
                }
            } else {
                continue;
            }
        }
    }
}



