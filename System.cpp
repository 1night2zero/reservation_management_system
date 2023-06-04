#include "System.h"
#include "User.h"
#include "Visitor.h"
#include "Admin.h"

//判断用户信息是否存在
bool isInfoExist(string myName, string idNum = "", string phoneNum = "") {
    ifstream in(VISITOR_FILE, ios::in);
    if (!in.is_open()) {
        cout << "文件不存在" << endl;
        in.close();
        return false;
    }
    string username, name, id, phone, passwd;
    while (in >> username >> name >> id >> phone >> passwd) {
        if (myName == name || idNum == id || phoneNum == phone) {
            in.close();
            return true;
        }
    }
    in.close();
    return false;
}


//检验身份证号正确性
bool isIdNum(string idNum) {
    regex pattern("[0-9]{17}[0-9X]");
    return regex_match(idNum, pattern);
}

//计算身份证校验码
char getCheckCode(string idNum) {
    int sum = 0;
    int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6,
                      3, 7, 9, 10, 5, 8, 4, 2};
    char checkCode[11] = {'1', '0', 'X', '9', '8', '7', '6', '5',
                          '4', '3', '2'};
    for (int i = 0; i < 17; i++) {
        sum += (idNum[i] - '0') * weight[i];
    }
    return checkCode[sum % 11];
}

// 检验身份证中的日期
bool isDateValid(string idNum) {
    int year = stoi(idNum.substr(6, 4));
    int month = stoi(idNum.substr(10, 2));
    int day = stoi(idNum.substr(12, 2));
    if (year < 1900 || year > 2023) {
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > 31) {
        return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }
    if (month == 2) {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            if (day > 29) {
                return false;
            }
        } else {
            if (day > 28) {
                return false;
            }
        }
    }

    return true;
}


// 判断身份证号是否合法
bool isIdNumValid(string idNum) {
    // 长度判断
    if (!isIdNum(idNum)) {
        return false;
    }
    // 日期判断
    if (!isDateValid(idNum)) {
        return false;
    }
    // 校验码判断
    if (idNum[17] != getCheckCode(idNum)) {
        return false;
    }
    return true;
}

//校验手机号正确性
bool isPhoneNum(string phoneNum) {
    regex pattern("1[0-9]{10}");
    return regex_match(phoneNum, pattern);
}

//获取游客数量
int System::getVisitorNum() {
    ifstream in(VISITOR_FILE, ios::in);
    if (!in.is_open()) {
        cout << "文件不存在" << endl;
        in.close();
        return 0;
    }
    int num = 0;
    string username, name, idNum, phoneNum, passwd;
    while (in >> username >> name >> idNum >> phoneNum >> passwd) {
        num++;
    }
    in.close();
    return num;
}

//默认构造函数
System::System() = default;

//开始
void System::Start() {
    while (true) {
        SetConsoleTitle("景点预约系统");
        cout << "*****************************************************\n";
        cout << "*                                                   *\n";
        cout << "*                欢迎来到景点预约系统                   *\n";
        cout << "*                  请选择你的操作                      *\n";
        cout << "*                                                   *\n";
        cout << "*                                                   *\n";
        cout << "*     0.管理员登录  1.游客登录  2.注册账号   3.退出      *\n";
        cout << "*                                                   *\n";
        cout << "*                                                   *\n";
        cout << "*****************************************************\n";
        int ch;
        cin >> ch;
        switch (ch) {
            case 0:
                login(0);
                break;
            case 1:
                login(1);
                break;
            case 2:
                visitorRegister();
                break;
            case 3:
                cout << "欢迎下次使用！\n";
                exit(0);
            default:
                cout << "请选择正确的选项!\n";
                break;
        }
    }
}


//登录
void System::login(int type) {
//文件操作
    string fileName;
    type ? fileName = VISITOR_FILE : fileName = ADMIN_FILE;
    ifstream in(fileName, ios::in);
    if (!in.is_open()) {
        cout << "文件不存在" << endl;
        in.close();
        return;
    }

    //登录
    User *user = NULL;
    string inputUsername, password;
    cout << "请输入用户名：" << endl;
    cin >> inputUsername;
    cout << "请输入密码： " << endl;
    cin >> password;
    if (type) { //游客登录
        string username, name, idNum, phoneNum, passwd;
        while (in >> username >> name >> idNum >> phoneNum >> passwd) {
            if (inputUsername == username && password == passwd) {
                cout << "游客验证登录成功!" << endl;
                user = new Visitor(username, name, idNum, phoneNum, passwd);
                Visitor *visitor = (Visitor *) user;
                visitor->operate();
                delete visitor;
                user = NULL;
                return;
            }
        }
        cout << "没有这个用户，请检查用户名和密码！" << endl;
        int ch;
        cout << "*******************************************\n";
        cout << "*              请选择你的操作             *\n";
        cout << "*                                         *\n";
        cout << "*        1.重新登录     2.回到主页        *\n";
        cout << "*******************************************\n";
        cin >> ch;
        switch (ch) {
            case 1:
                this->login(1);
                break;
            case 2:
                this->Start();
            default:
                break;
        }
    } else if (type == 0) {   //管理员
        string usr, passwd;
        while (in >> usr >> passwd) {
            if (inputUsername == usr && password == passwd) {
                cout << "管理员验证登录成功!" << endl;
                user = new Admin(usr, passwd);
                Admin *admin = (Admin *) user;
                admin->operate();
                delete admin;
                user = NULL;
                return;
            }
        }
        cout << "没有这个管理员，请检查用户名和密码！" << endl;
        int ch;
        cout << "*******************************************\n";
        cout << "*              请选择你的操作               *\n";
        cout << "*                                         *\n";
        cout << "*        1.重新登录     2.回到主页          *\n";
        cout << "*******************************************\n";
        cin >> ch;
        switch (ch) {
            case 1:
                this->login(0);
                break;
            case 2:
                this->Start();
            default:
                break;
        }
    }
    in.close();
    return;
}

//注册游客账号
void System::visitorRegister() {
    string name, idNum, phoneNum, password;
    //姓名
    cout << "请输入你的姓名:" << endl;
    cin >> name;
    // 检测是否已存在
    if (isInfoExist(name)) {
        cout << "该用户已存在！请重新输入！" << endl;
        this->visitorRegister();
    }
    //身份证
    cout << "请输入你的身份证号：" << endl;
    while (cin >> idNum) {
        if (isIdNumValid(idNum)) { //身份证校验
            break;
        } else {
            cout << "请输入正确的身份证号：" << endl;
        }
    }
    // 检测是否已存在
    if (isInfoExist(name, idNum)) {
        cout << "该用户已存在！请重新输入！" << endl;
        this->visitorRegister();
    }
    //手机号
    cout << "请输入手机号：" << endl;
    while (cin >> phoneNum) {
        if (isPhoneNum(phoneNum)) { //手机号校验
            break;
        } else {
            cout << "请输入正确长度的手机号：" << endl;
        }
    }
    // 检测是否已存在
    if (isInfoExist(name, idNum, phoneNum)) {
        cout << "该用户已存在！请重新输入！" << endl;
        this->visitorRegister();
    }
    //密码
    cout << "请输入你的密码：" << endl;
    while (cin >> password) {
        if (password.length() >= 6) {
            regex judge("^[A-Za-z0-9]+$");
            if (regex_match(password, judge)) {
                break;
            } else {
                cout << "密码只能包含字母和数字：" << endl;
            }
        } else {
            cout << "密码长度不得小于6：" << endl;
        }
    }
    //添加用户
    ofstream out(VISITOR_FILE, ios::app);
    //预设username为VisitorXXX
    string username = "visitor" + to_string(getVisitorNum() + 1);
    out << username << "\t" << name << "\t" << idNum << "\t" << phoneNum << "\t" << password << endl;
    out.close();
    cout << "注册成功！" << endl;
    cout << "你的用户名为：" << username << endl;
    this->Start();
}


