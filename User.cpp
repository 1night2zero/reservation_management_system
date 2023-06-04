
#include <fstream>
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

    cout << "景区名称\t日期\t\t时间段\t最大容量\t已预约人数" << endl;
    for (auto &vAttraction: vAttractions) {
        cout << vAttraction.attractionsName << "\t\t"
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
}

//删除景区信息

void User::deleteAttraction() {
    string attractionsName;
    cout << "请输入要删除的景区名称：";
    cin >> attractionsName;
    for (auto it = vAttractions.begin(); it != vAttractions.end(); it++) {
        if (it->attractionsName == attractionsName) {
            vAttractions.erase(it);
            cout << "删除成功" << endl;
            return;
        }
    }
    cout << "未找到该景区" << endl;
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
    int state;
    while (in2 >> attractionsName >> name >> phoneNum >> serial >> state) {
        vForm.emplace_back(attractionsName, name, phoneNum, serial, state);
    }
    in2.close();
}