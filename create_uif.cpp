#include "Ticket.h"
#include "Ticket1.h"
#include <iostream>

using namespace std;

void User::create_uif()	//创建用户信息文件
{
	system("cls");
	print_item(7);
	input_uinfo();
	save_uitf();

	++user_num;
	save_un();
	cout<<"\n正在进行用户信息录入..."<<endl;
	Sleep(2000);
	system("cls");
	cout<<"注册成功!"<<endl;
	cout<<"即将跳转至主菜单进行登录,请稍后..."<<endl;
	Sleep(2000);
	home();
}