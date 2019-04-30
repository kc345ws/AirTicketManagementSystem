#include "Ticket.h"
#include "Ticket1.h"
#include <iostream>

using namespace std;

void User::home() 					//主界面
{	
	system("cls");
	print_item(1);	
	switch(choose())
	{
	case '1':identify();
		break;
	case '2':create_uif();
		break;
	case '0':cout<<"即将退出..."<<endl;
		Sleep(1000);
		system("cls");
		End_screen();
		break;
	default:cout<<"输入错误!请重新输入!"<<endl;
		Sleep(1000);
		home();
	}
}
