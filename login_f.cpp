//��½�ɹ���Ĳ�������
#include "Flight.h"
#include "User.h"
#include"UserTicket.h"
#include <iostream>

using namespace std;

void User::login_mf()	//����Ա��½��Ʊ����ϵͳ
{
	Flight F;
	User US;

	system("cls");
	print_item(8);//��ӡ����Ա��������
	do
	{
		switch(choose())
		{
		case '1':F.add_fi();//��Ӻ�����Ϣ
			break;
		case '2':F.browse_fi(true);
			break;
		case '3':F.search_fi();
			break;
		case '4':F.sort_byfp();
			break;
		//case '5':F.order();
			//break;
		case '5':F.delete_fi();//ɾ��������Ϣ
			break;
		case '6':F.change_fi();//�޸ĺ�����Ϣ
			break;
		case '7':US.issueDelay_m();//������������
			break;
		case '8':US.issueCancel_m();//��������ȡ��
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
		case '5':LoginedUser->mg->userTicket->showTickets(false);
			break;
		case '6':LoginedUser->mg->userTicket->showDelay_ut();
			break;
		case '7':LoginedUser->mg->userTicket->showCancel_ut();
			break;
		case '8':refundTicket_us();//��Ʊ
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