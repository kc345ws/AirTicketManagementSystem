#include"User.h"
#include<iostream>

//����Ա������������֪ͨ
void User::issueDelay_m() {
	system("CLS");
	User UI;
	Flight F;
	UserTicket* userticket= new UserTicket();
	F.browse_fi(false);
	UI.print_item(20);
	load_un();
	load_list();
	string flightnum;
	string flighttime;
	string flightdata;
	cout << "������Ҫ��������֪ͨ�ĺ�������" << endl;
	cin >> flightdata;
	cout << "������Ҫ��������֪ͨ�ĺ����" << endl;
	cin >> flightnum;
	cout << "������Ҫ��������֪ͨ�ĺ�����ʱ��" << endl;
	cin >> flighttime;

	string userfilename;
	string userid;
	User::UserInfo* tempinfo;//�����û���Ϣ
	//LoginedUser->allus = new UserInfo();
	//LoginedUser->allus->userTicket = new UserTicket();
	//LoginedUser->allus->userTicket->load_ut(user->next->id);//���ػ�Ʊ��Ϣ
	//tempinfo�ܻ�ȡ tempinfo->userticketΪ��
	tempinfo = user->next;
	//tempinfo->userTicket = LoginedUser->allus->userTicket;
	//user->next->userticketΪ��
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
					tempticket->isDelay = true;
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
		}
		tempinfo = tempinfo->next;
		isfound = false;
	}
	if (issucced) {
		cout << "��������֪ͨ�ɹ�" << endl;
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