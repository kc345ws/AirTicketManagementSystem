#include "Ticket.h"
#include "Ticket1.h"
#include <iostream>

using namespace std;

void User::home() 					//������
{	
	system("cls");
	print_item(1);	
	switch(choose())
	{
	case '1':identify();
		break;
	case '2':create_uif();
		break;
	case '0':cout<<"�����˳�..."<<endl;
		Sleep(1000);
		system("cls");
		End_screen();
		break;
	default:cout<<"�������!����������!"<<endl;
		Sleep(1000);
		home();
	}
}
