//��½�ɹ���Ĳ�������
#include "Flight.h"
#include "User.h"
#include"UserTicket.h"
#include <iostream>

using namespace std;
void browseMenu();

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
	//User* temp = new User();

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
			//temp->refundTicket_us();
			break;
		case '9':grabbingTicket_us();//��Ʊ
			//temp->grabbingTicket_us();
			break;
		case 'Q':browseMenu();
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

void browseMenu() {
	User UI;
	Flight F;
	cout << "������ѡ��" << endl;
	cout << "1.����Ʊ�����������" << endl;
	cout << "2.����Ʊ�����������" << endl;
	cout << "3.������ʱ�������������" << endl;
	cout << "4.������ʱ�併���������" << endl;
	cout << "5.����Ʊ���������������" << endl;
	cout << "6.����Ʊ���������������" << endl;
	cout << "7.����תʱ�������������" << endl;
	cout << "8.����תʱ�併���������" << endl;
	cout << "9.���������������������" << endl;
	cout << "10.���������ڽ����������" << endl;
	cout << "0.������һ���˵�" << endl;
	getchar();
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		F.browse_fi_priceLTH();
		break;
	case 2:
		F.sort_byfp();
		break;
	case 3:
		F.browse_fi_atLTH();
		break;
	case 4:
		F.browse_fi_atHTL();
		break;
	case 5:
		F.browse_fi_countLTH();
		break;
	case 6:
		F.browse_fi_countHTL();
		break;
	case 7:
		F.browse_fi_transtimeLTH();
		break;
	case 8:
		F.browse_fi_transtimeHTL();
		break;
	case 9:
		F.browse_fi_dateLTH();
		break;
	case 10:
		F.browse_fi_dateHTL();
		break;
	default:
		UI.login_uf();
		break;
	}
}