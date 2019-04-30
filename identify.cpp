#include "Ticket.h"
#include "Ticket1.h"
#include <iostream>

using namespace std;

void User::identify() 		//用户及管理员登录选择
{
	system("cls");
	print_item(2);
	while(1)
	{
		switch(choose())
		{
		case '1':login_m();
			break;
		case '2':login_u();
			break;
		case '0':system("cls");
			home();
			break;
		default:cout<<"你的输入有误!请重新输入!"<<endl;
			Sleep(1000);
			identify();
		}
	}
}
