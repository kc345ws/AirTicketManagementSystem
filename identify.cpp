#include "Ticket.h"
#include "Ticket1.h"
#include <iostream>

using namespace std;

void User::identify() 		//�û�������Ա��¼ѡ��
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
		default:cout<<"�����������!����������!"<<endl;
			Sleep(1000);
			identify();
		}
	}
}
