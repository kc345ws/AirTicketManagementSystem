#include "Ticket.h"
#include "Ticket1.h"
#include <iostream>

using namespace std;

void User::create_uif()	//�����û���Ϣ�ļ�
{
	system("cls");
	print_item(7);
	input_uinfo();
	save_uitf();

	++user_num;
	save_un();
	cout<<"\n���ڽ����û���Ϣ¼��..."<<endl;
	Sleep(2000);
	system("cls");
	cout<<"ע��ɹ�!"<<endl;
	cout<<"������ת�����˵����е�¼,���Ժ�..."<<endl;
	Sleep(2000);
	home();
}