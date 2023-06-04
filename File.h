#pragma once
//游客账号信息
#define VISITOR_FILE "./information/user/visitor.txt"    //文件格式：用户名	姓名	身份证号码		手机号		密码
//管理员信息
#define ADMIN_FILE "./information/user/admin.txt"        //文件格式：用户名	密码
//景点信息
#define COMMON_FILE "common.txt"    //文件格式：景点 日期(用数字表示)	上午最大预约量	(2个数据今天明天)下午最大预约量()	上下午(用数字表示)	最大预约数量(maxNum)	当前可预约号(1-maxNum)
//电子预约单
#define FORM_FILE "form.txt"        //文件格式：景点名称	游客姓名	日期	上下午	单号	预约人数