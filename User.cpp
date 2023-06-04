
#include <fstream>
#include <cstdlib>
#include "User.h"
#include "File.h"

User::User() {
    //初始化景区容器
    initVAttractions();
    //初始化预约单容器
    initVForm();
}

//输出景区信息
void User::showAttractions() {
    cout << "景区列表如下：" << endl;
    cout << "景区名称\t日期\t\t时间段\t最大容量\t已预约人数" << endl;
    for (auto &vAttraction: vAttractions) {
        cout << vAttraction.attractionName << "\t\t"
             << (vAttraction.day == 0 ? "今天" : "明天") << "\t\t"
             << (vAttraction.aorp == 0 ? "上午" : "下午") << "\t\t"
             << vAttraction.maxNum << "\t\t"
             << vAttraction.Had[vAttraction.day][vAttraction.aorp] << endl;
    }
}

//添加景区信息
void User::addAttraction() {
    string attractionsName;
    int day, aorp, maxNum, Had[2][2];
    cout << "请输入景区名称：";
    cin >> attractionsName;
    cout << "请输入日期（0为今天，1为明天）：";
    cin >> day;
    cout << "请输入时间段（0为上午，1为下午）：";
    cin >> aorp;
    cout << "请输入最大容量：";
    cin >> maxNum;
    cout << "请输入已预约人数（上午，下午）：";
    cin >> Had[0][0] >> Had[0][1] >> Had[1][0] >> Had[1][1];
    Attraction attraction(attractionsName, day, aorp, maxNum, Had);
    vAttractions.push_back(attraction);
    cout << "添加成功" << endl;
    //刷新文件
    updateAttractionsFile();
}

//删除景区信息
void User::deleteAttraction() {
    string attractionsName;
    cout << "请输入要删除的景区名称：";
    cin >> attractionsName;
    for (auto it = vAttractions.begin(); it != vAttractions.end(); it++) {
        if (it->attractionName == attractionsName) {
            vAttractions.erase(it);
            cout << "删除成功" << endl;
            //刷新文件
            updateAttractionsFile();
            return;
        }
    }
    cout << "未找到该景区" << endl;
}

//修改景区信息
void User::changeAttraction() {
    string attractionsName;
    cout << "请输入要修改的景区名称：";
    cin >> attractionsName;
    for (auto &vAttraction: vAttractions) {
        if (vAttraction.attractionName == attractionsName) {
            cout << "请输入新的景区名称：";
            cin >> vAttraction.attractionName;
            cout << "请输入新的日期（0为今天，1为明天）：";
            cin >> vAttraction.day;
            cout << "请输入新的时间段（0为上午，1为下午）：";
            cin >> vAttraction.aorp;
            cout << "请输入新的最大容量：";
            cin >> vAttraction.maxNum;
            cout << "请输入新的已预约人数（上午，下午）：";
            cin >> vAttraction.Had[0][0] >> vAttraction.Had[0][1] >> vAttraction.Had[1][0] >> vAttraction.Had[1][1];
            cout << "修改成功" << endl;
            //更新文件内容
            updateAttractionsFile();
            return;
        }
    }
    cout << "未找到该景区" << endl;
}


//获取预约单列表
void User::getFormList() {
    cout << "景区名称\t姓名\t手机号\t预约码\t状态" << endl;
    for (auto &form: vForm) {
        cout << form.attractionName << "\t\t"
             << form.name << "\t\t"
             << form.phoneNum << "\t\t"
             << form.serial << "\t\t"
             << (form.day == 0 ? "今天" : "明天") << "\t\t"
             << (form.aorp == 0 ? "上午" : "下午") << "\t\t"
             << (form.state == 1 ? "已预约" : form.state == -1 ? "已取消" : "未处理")
             << endl;
    }
    return;
}

//添加预约单
void User::addForm() {      //makeAppointment和两个能用一个就行
    string attractionsName, name, phoneNum, serial;
    int day, aorp, state;
    cout << "请输入景区名称：";
    cin >> attractionsName;
    cout << "请输入姓名：";
    cin >> name;
    cout << "请输入手机号：";
    cin >> phoneNum;
    cout << "请输入预约码：";
    cin >> serial;
    cout << "请输入日期（0为今天，1为明天）：";
    cin >> day;
    cout << "请输入时间段（0为上午，1为下午）：";
    cin >> aorp;
    cout << "请输入状态（0未处理 1已预约 -1已取消）：";
    cin >> state;
    Form form(attractionsName, name, phoneNum, serial, day, aorp, state);
    vForm.push_back(form);
    cout << "添加成功" << endl;
    //刷新文件
    updateFormFile();
}

//删除预约单
void User::deleteForm() {
    string serial;
    cout << "请输入要删除的预约码：";
    cin >> serial;
    for (auto it = vForm.begin(); it != vForm.end(); it++) {
        if (it->serial == serial) {
            vForm.erase(it);
            cout << "删除成功" << endl;
            //刷新文件
            updateFormFile();
            return;
        }
    }
    cout << "未找到该预约单" << endl;
}

//修改预约单
void User::changeForm() {
    string serial;
    cout << "请输入要修改的预约码：";
    cin >> serial;
    for (auto &form: vForm) {
        if (form.serial == serial) {
            cout << "请输入新的景区名称：";
            cin >> form.attractionName;
            cout << "请输入新的姓名：";
            cin >> form.name;
            cout << "请输入新的手机号：";
            cin >> form.phoneNum;
            cout << "请输入新的预约码：";
            cin >> form.serial;
            cout << "请输入新的日期（0为今天，1为明天）：";
            cin >> form.day;
            cout << "请输入新的时间段（0为上午，1为下午）：";
            cin >> form.aorp;
            cout << "请输入新的状态（0未处理 1已预约 -1已取消）：";
            cin >> form.state;
            cout << "修改成功" << endl;
            //更新文件内容
            updateFormFile();
            return;
        }
    }
    cout << "未找到该预约单" << endl;
}

//预约景区并生成预约码
void User::makeAppointment() {
    string attractionsName, name, phoneNum, serial;
    int day, aorp;
    cout << "请输入景区名称：";
    cin >> attractionsName;
    cout << "请输入姓名：";
    cin >> name;
    cout << "请输入手机号：";
    cin >> phoneNum;
    cout << "请输入日期（0为今天，1为明天）：";
    cin >> day;
    cout << "请输入时间段（0为上午，1为下午）：";
    cin >> aorp;
    for (auto &vAttraction: vAttractions) {
        if (vAttraction.attractionName == attractionsName && vAttraction.day == day && vAttraction.aorp == aorp) {
            if (vAttraction.Had[day][aorp] < vAttraction.maxNum) {
                vAttraction.Had[day][aorp]++;
                serial = attractionsName + to_string(day) + to_string(aorp) + to_string(vAttraction.Had[day][aorp]);
                Form form(attractionsName, name, phoneNum, serial, day, aorp, 0);
                vForm.push_back(form);
                cout << "预约成功，您的预约码为：" << serial << endl;
                //更新文件内容
                updateAttractionsFile();
                updateFormFile();
                return;
            } else {
                cout << "该时间段已满" << endl;
                return;
            }
        }
    }
    cout << "未找到该景区或该时间段不可用" << endl;
}


//初始化
void User::initVAttractions() {
    vAttractions.clear();
    //初始化景区容器
    ifstream in1(COMMON_FILE, ios::in);
    if (!in1.is_open()) {
        cout << "文件不存在" << endl;
        in1.close();
        return;
    }
    string attractionsName;
    int day, aorp, maxNum, Had[2][2];
    while (in1 >> attractionsName >> day >> aorp >> maxNum >> Had[0][0] >> Had[0][1] >> Had[1][0]
               >> Had[1][1]) {
        vAttractions.emplace_back(attractionsName, day, aorp, maxNum, Had);
    }
    in1.close();
}


//初始化预约单容器
void User::initVForm() {
    ifstream in2(FORM_FILE, ios::in);
    if (!in2.is_open()) {
        cout << "文件不存在" << endl;
        in2.close();
        return;
    }
    string name, phoneNum, attractionsName, serial;
    int day, aorp, state;
    while (in2 >> attractionsName >> name >> phoneNum >> serial >> day >> aorp >> state) {
        vForm.emplace_back(attractionsName, name, phoneNum, serial, day, aorp, state);
    }
    in2.close();
}

void User::updateAttractionsFile() {
    ofstream out1(COMMON_FILE, ios::out);
    if (!out1.is_open()) {
        cout << "文件不存在" << endl;
        out1.close();
        return;
    }
    for (auto &vAttraction: vAttractions) {
        out1 << vAttraction.attractionName << "\t\t"
             << vAttraction.day << "\t\t"
             << vAttraction.aorp << "\t\t"
             << vAttraction.maxNum << "\t\t"
             << vAttraction.Had[0][0] << "\t\t"
             << vAttraction.Had[0][1] << "\t\t"
             << vAttraction.Had[1][0] << "\t\t"
             << vAttraction.Had[1][1] << endl;
    }
    out1.close();
}

void User::updateFormFile() {
    ofstream out2(FORM_FILE, ios::out);
    if (!out2.is_open()) {
        cout << "文件不存在" << endl;
        out2.close();
        return;
    }
    for (auto &form: vForm) {
        out2 << form.attractionName << "\t\t"
             << form.name << "\t\t"
             << form.phoneNum << "\t\t"
             << form.serial << "\t\t"
             << form.day << "\t\t"
             << form.aorp << "\t\t"
             << form.state << endl;
    }
    out2.close();
}

