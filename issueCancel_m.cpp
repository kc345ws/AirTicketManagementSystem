#include"User.h"
#include"Flight.h"
#include"User.h"
#include"UserTicket.h"
#include<iostream>

//����Ա��������ȡ��֪ͨ
void User::issueCancel_m() {
	system("CLS");
	User UI;
	Flight F;
	UserTicket* userticket = new UserTicket();
	F.browse_fi(false);
	UI.print_item(21);
	load_un();
	load_list();
	string flightnum;
	string flighttime;
	string flightdata;
	cout << "������Ҫ����ȡ��֪ͨ�ĺ�������" << endl;
	cin >> flightdata;
	cout << "������Ҫ����ȡ��֪ͨ�ĺ����" << endl;
	cin >> flightnum;
	cout << "������Ҫ����ȡ��֪ͨ�ĺ�����ʱ��" << endl;
	cin >> flighttime;

	string userfilename;
	string userid;
	User::UserInfo* tempinfo;//�����û���Ϣ

	tempinfo = user->next;

	UserTicket::Ticket* tempticket = nullptr;
	bool isfound = false;//�ж��û��Ƿ����������Ļ�Ʊ
	bool issucced = false;
	for (int i = 0; i < user_num; i++) {
		//userticket->load_ut(tempinfo->id);
		LoginedUser->allus = new UserInfo();
		LoginedUser->allus->userTicket = new UserTicket();
		LoginedUser->allus->userTicket->load_ut(tempinfo->id);//���ػ�Ʊ��Ϣ
		if (LoginedUser->allus->userTicket) {
			tempticket = LoginedUser->allus->userTicket->sentine;
			LoginedUser->allus->userTicket->temp = LoginedUser->allus->userTicket->sentine;
			while (tempticket) {
				if (tempticket->data == flightdata && tempticket->num == flightnum && tempticket->time == flighttime) {
					isfound = true;
					//tempticket->isDelay = true;
					tempticket->isCancel = true;
					issucced = true;
					break;
				}
				tempticket = tempticket->next;
				LoginedUser->allus->userTicket->temp = LoginedUser->allus->userTicket->temp->next;
			}
		}
		if (isfound) {
			UserTicket* Temput = new UserTicket();
			string tempid = tempinfo->id;
			Temput->change_ut(tempid, true);
			delete Temput;

			F.delete_fi(tempticket->data, tempticket->num, tempticket->start, tempticket->end);//ɾ���ú�����Ϣ
		}
		tempinfo = tempinfo->next;
		isfound = false;
	}

	if (issucced) {
		cout << "����ȡ��֪ͨ�ɹ�" << endl;
	}
	else {
		cout << "û�иüܺ����û���û�����ú����Ʊ" << endl;
	}
	delete userticket;


	cout << "�����������������" << endl;
	getchar();
	getchar();
	login_mf();
}