//����Ա��½��Ʊ����ϵͳ
#include "Ticket.h"
#include "Ticket1.h"
#include <iostream>

using namespace std;

void User::login_mf()	//����Ա��½��Ʊ����ϵͳ
{
	Flight F;

	system("cls");
	print_item(8);//��ӡ����Ա��������
	do
	{
		switch(choose())
		{
		case '1':F.add_fi();//���Ӻ�����Ϣ
			break;
		case '2':F.browse_fi(true);
			break;
		case '3':F.search_fi();
			break;
		case '4':F.sort_byfp();
			break;
		case '5':F.order();
			break;
		case '6':F.delete_fi();//ɾ��������Ϣ
			break;
		case '7':F.change_fi();//�޸ĺ�����Ϣ
			break;
		case '0':cout<<"�����˳�'��Ʊ����ϵͳ',����ת��������..."<<endl;
			Sleep(1000);
			system("cls");
			home();
			break;                          
		default:cout<<"��������!����������!"<<endl;
			Sleep(1000);
			system("cls");
			login_mf();
		}
	}while(choose()!=0);
}

void User::login_uf()	//�û���½��Ʊ����ϵͳ
{
	Flight F;

	system("cls");
	print_item(9);
	do
	{
		switch(choose())
		{
		case '1':F.browse_fi(true);
			break;
		case '2':F.search_fi();
			break;
		case '3':F.sort_byfp();
			break;
		case '4':F.order();
			break;
		case '0':cout<<"�����˳�'��Ʊ����ϵͳ',����ת��������..."<<endl;
			Sleep(1000);
			system("cls");
			home();
			break;
		default:cout<<"��������!����������!"<<endl;
			Sleep(1000);
			system("cls");
			login_uf();
		}
	}while(choose()!=0);
}