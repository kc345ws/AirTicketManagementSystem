#include"UserTicket.h"
#include<iostream>
#include <shlwapi.h>
#include<Windows.h>
extern UserTicket* ZeroTicket = nullptr;
extern UserTicket* MyTickets  = nullptr;

void changechar(char ch[], int changeobjID, UserTicket::Ticket* info);//�޸�char���͵�����

UserTicket::UserTicket() {
	
	Ticketnum = 0;				//��Ʊ������Ϊ0
	sentine = new Ticket();		//�ڱ��ڵ�
	lastticket = sentine;
	sentine->next = nullptr;
	sentine->prior = nullptr;

	temp = nullptr;
}

UserTicket::~UserTicket() {
	Destroy();
}

void UserTicket :: Destroy() {
	//MyTickets = ZeroTicket->next;
	Ticket* T1, * T2;
	//UserTicket* Temp = ZeroTicket;
	T1 = sentine;
	T2 = sentine->next;
	while (T2) {
		delete T1;
		T1 = T2;
		T2 = T2->next;
	}
	delete T1;
}

void UserTicket::addTicket(Flight::FlightInfo* info ,int ticnum) {//ticnumΪ��Ʊ��������
	//***********************************************
					//����Ʊ��Ϣ��ӵ��û���Ʊ��
					//LoginedUser->userTicket->next;
	UserTicket* TempUT = nullptr;
	UserTicket::Ticket* TempPorior;
	//TempUT->temp =LoginedUser->userTicket->sentine;
	TempUT = LoginedUser->mg->userTicket;
	TempUT->temp = LoginedUser->mg->userTicket->sentine;
	while (TempUT->temp->next) {
		TempUT->temp = TempUT->temp->next;
	}
	TempUT->temp->next = new UserTicket::Ticket();
	TempPorior = TempUT->temp;
	TempUT->temp = TempUT->temp->next;
	changechar(info->data, 1, TempUT->temp);
	changechar(info->num, 2, TempUT->temp);
	changechar(info->start, 3, TempUT->temp);
	changechar(info->end, 4, TempUT->temp);
	changechar(info->time, 5, TempUT->temp);
	changechar(info->at, 6, TempUT->temp);
	TempUT->temp->price = info->price;
	TempUT->temp->Ticketcount = ticnum;
	//��ӹ���ʱ��
	time_t  t;
	t = time(NULL);
	struct tm* local;
	local = localtime(&t);
	t = time(NULL);
	local = localtime(&t);
	string currenttime = std::to_string(local->tm_year + 1900)+ "-"+std::to_string(local->tm_mon + 1)
		+"-"+to_string(local->tm_mday)+"/"+to_string(local->tm_hour)+":"+to_string(local->tm_min)+
		":"+ to_string(local->tm_sec);
	for (int i = 0; i < currenttime.length(); i++) {
		TempUT->temp->buytime[i] = currenttime[i];
	}
	
	TempUT->temp->isDelay = false;
	TempUT->temp->isCancel = false;
	TempUT->temp->transit = info->transit;
	TempUT->temp->transittime = info->transittime;//�����תʱ��
	load_num();
	Ticketnum ++;//���»�Ʊ�������

	lastticket = TempUT->temp;//�������һ�Ż�Ʊ
	TempUT->temp->prior = TempPorior;//����ǰ�̽��
	TempUT->temp->next = nullptr;
	//***********************************************
	save_ut();//���浽�ļ���
}

void UserTicket::init_ut() {//��ʼ��
	string userid = LoginedUser->ui->id;
	string filename = "Users\\" + userid+"\\mytickets.txt";
	fstream myticketsfile;
	myticketsfile.open(filename, ios::out);//������Ʊ�ļ�
	myticketsfile.close();

	filename = "Users\\" + userid + "\\tickets_num.txt";
	myticketsfile.open(filename, ios::out);
	myticketsfile << 0;//�����û���Ʊ����
	myticketsfile.close();
}

void UserTicket::load_num() {//���ػ�Ʊ�������
	string userid = LoginedUser->mg->id;
	string filename = "Users\\" + userid + "\\tickets_num.txt";
	fstream myticketsfile;

	myticketsfile.open(filename, ios::in);
	if (!myticketsfile) {//����ļ�������
		myticketsfile.close();
		myticketsfile.open(filename, ios::out);
		myticketsfile << 0;//�����û���Ʊ����
		myticketsfile.close();
		Ticketnum = 0;
	}
	else {
		myticketsfile >> Ticketnum;
		myticketsfile.close();
	}
}

void UserTicket::load_num(string id) {
	string userid = id;
	string filename = "Users\\" + userid + "\\tickets_num.txt";
	fstream myticketsfile;

	myticketsfile.open(filename, ios::in);
	if (!myticketsfile) {//����ļ�������
		myticketsfile.close();
		myticketsfile.open(filename, ios::out);
		myticketsfile << 0;//�����û���Ʊ����
		myticketsfile.close();
		Ticketnum = 0;
	}
	else {
		myticketsfile >> Ticketnum;
		myticketsfile.close();
	}
}

void UserTicket::load_ut(string id) {
	load_num(id);//���ػ�Ʊ�������
	//User US;
	string userid = id;
	string filename = "Users\\" + userid + "\\mytickets.txt";
	fstream myticketsfile;
	string testisEmpty;
	//User::UserInfo* tempinfo;
	//tempinfo = US.findUser(id);
	//tempinfo->userTicket = new UserTicket();
	myticketsfile.open(filename, ios::in);
	if (!myticketsfile) {//�ļ����������
		myticketsfile.close();
		myticketsfile.open(filename, ios::out);
		myticketsfile.close();
	}
	else {//����û�����
		myticketsfile >> testisEmpty;
		myticketsfile.seekg(0);//�ض����ļ�ͷ��
		if (!testisEmpty.empty()) {//����ļ������Ҳ�Ϊ��
			UserTicket::Ticket* tempticket = LoginedUser->allus->userTicket->sentine;
			//UserTicket::Ticket* tempticket = tempinfo->userTicket->sentine;
			for (int i = 0; i < Ticketnum; i++) {
				tempticket->next = new UserTicket::Ticket();
				temp = tempticket;
				tempticket = tempticket->next;
				tempticket->prior = temp;
				tempticket->next = nullptr;
				myticketsfile >> tempticket->data >> tempticket->num >> tempticket->start >> tempticket->end
					>> tempticket->time >> tempticket->at >> tempticket->price >> tempticket->Ticketcount >>
					tempticket->buytime >> tempticket->isDelay >> tempticket->isCancel >> tempticket->transit >> tempticket->transittime;
			}
		}
		myticketsfile.close();
	}
}

void UserTicket::load_ut() {//�ѻ�Ʊ��Ϣװ�ص�������
	load_num();//���ػ�Ʊ�������
	string userid = LoginedUser->mg->id;
	string filename = "Users\\" + userid + "\\mytickets.txt";
	fstream myticketsfile;
	string testisEmpty;

	myticketsfile.open(filename, ios::in);
	if (!myticketsfile) {//�ļ����������
		myticketsfile.close();
		myticketsfile.open(filename, ios::out);
		myticketsfile.close();
	}
	else {
		myticketsfile >> testisEmpty;
		myticketsfile.seekg(0);//�ض����ļ�ͷ��
		if (!testisEmpty.empty()) {//����ļ������Ҳ�Ϊ��
			UserTicket::Ticket* tempticket = LoginedUser->mg->userTicket->sentine;
			for (int i = 0; i < Ticketnum; i++) {
				tempticket->next = new UserTicket::Ticket();
				temp = tempticket;
				tempticket = tempticket->next;
				tempticket->prior = temp;
				tempticket->next = nullptr;
				myticketsfile >> tempticket->data >> tempticket->num >> tempticket->start >> tempticket->end
					>> tempticket->time >> tempticket->at >> tempticket->price >> tempticket->Ticketcount >>
					tempticket->buytime >> tempticket->isDelay >> tempticket->isCancel>>tempticket->transit>>tempticket->transittime;
			}
		}
		myticketsfile.close();
	}
}

void UserTicket::save_ut() {
	string userid = LoginedUser->mg->id;
	string filename = "Users\\" + userid + "\\mytickets.txt";
	fstream myticketsfile;

	myticketsfile.open(filename, ios::app);
	
	UserTicket::Ticket* tempticket = LoginedUser->mg->userTicket->lastticket;
	myticketsfile << tempticket->data << "\t" << tempticket->num << "\t" << tempticket->start << "\t" << tempticket->end << "\t"
		<< tempticket->time << "\t" << tempticket->at << "\t" << tempticket->price << "\t" << tempticket->Ticketcount << "\t" <<
		tempticket->buytime << "\t" << tempticket->isDelay << "\t" << tempticket->isCancel << "\t"<<tempticket->transit<<
		"\t"<<tempticket->transittime<<endl;

	myticketsfile.close();

	//���»�Ʊ�������
	filename = "Users\\" + userid + "\\tickets_num.txt";
	myticketsfile.open(filename, ios::out);
	myticketsfile << Ticketnum;//�����û���Ʊ����
	myticketsfile.close();
}

void UserTicket::save_ut(string tempid) {
	string userid = tempid;
	string filename = "Users\\" + userid + "\\mytickets.txt";
	fstream myticketsfile;

	myticketsfile.open(filename, ios::app);

	UserTicket::Ticket* tempticket = LoginedUser->allus->userTicket->lastticket;
	myticketsfile << tempticket->data << "\t" << tempticket->num << "\t" << tempticket->start << "\t" << tempticket->end << "\t"
		<< tempticket->time << "\t" << tempticket->at << "\t" << tempticket->price << "\t" << tempticket->Ticketcount << "\t" <<
		tempticket->buytime << "\t" << tempticket->isDelay << "\t" << tempticket->isCancel << "\t" << tempticket->transit <<
		"\t" << tempticket->transittime << endl;

	myticketsfile.close();

	//���»�Ʊ�������
	filename = "Users\\" + userid + "\\tickets_num.txt";
	myticketsfile.open(filename, ios::out);
	myticketsfile << Ticketnum;//�����û���Ʊ����
	myticketsfile.close();


}

void UserTicket::saveall_ut() {
	string userid = LoginedUser->mg->id;
	string filename = "Users\\" + userid + "\\mytickets.txt";
	fstream myticketsfile;

	myticketsfile.open(filename, ios::out);

	//UserTicket::Ticket* tempticket = LoginedUser->mg->userTicket->lastticket;
	UserTicket::Ticket* tempticket = LoginedUser->mg->userTicket->sentine->next;
	while (tempticket) {
		myticketsfile << tempticket->data << "\t" << tempticket->num << "\t" << tempticket->start << "\t" << tempticket->end << "\t"
			<< tempticket->time << "\t" << tempticket->at << "\t" << tempticket->price << "\t" << tempticket->Ticketcount << "\t" <<
			tempticket->buytime << "\t" << tempticket->isDelay << "\t" << tempticket->isCancel << "\t" << tempticket->transit <<
			"\t" << tempticket->transittime << endl;
		tempticket = tempticket->next;
	}
	myticketsfile.close();

	//���»�Ʊ�������
	filename = "Users\\" + userid + "\\tickets_num.txt";
	myticketsfile.open(filename, ios::out);
	myticketsfile << Ticketnum;//�����û���Ʊ����
	myticketsfile.close();
}

void UserTicket::change_ut(bool info) {
	/*string userid = LoginedUser->mg->id;
	string filename = "Users\\" + userid + "\\mytickets.txt";
	fstream myticketsfile;

	myticketsfile.open(filename, ios::app);

	UserTicket::Ticket* tempticket = LoginedUser->mg->userTicket->lastticket;
	tempticket->isDelay = info;
	myticketsfile << tempticket->data << "\t" << tempticket->num << "\t" << tempticket->start << "\t" << tempticket->end << "\t"
		<< tempticket->time << "\t" << tempticket->at << "\t" << tempticket->price << "\t" << tempticket->Ticketcount << "\t" <<
		tempticket->buytime << "\t" << tempticket->isDelay << "\t" << tempticket->isCancel << "\t" << tempticket->transit <<
		"\t" << tempticket->transittime << endl;

	myticketsfile.close();

	//���»�Ʊ�������
	filename = "Users\\" + userid + "\\tickets_num.txt";
	myticketsfile.open(filename, ios::out);
	myticketsfile << Ticketnum;//�����û���Ʊ����
	myticketsfile.close();*/
}

void UserTicket::change_ut(string id, bool info) {
	//string userid = LoginedUser->mg->id;
	string filename = "Users\\" + id + "\\mytickets.txt";
	fstream myticketsfile;

	myticketsfile.open(filename, ios::out);

	UserTicket::Ticket* tempticket = LoginedUser->allus->userTicket->sentine->next;
	while (tempticket) {
		if (tempticket->data == LoginedUser->allus->userTicket->temp->data &&
			tempticket->num == LoginedUser->allus->userTicket->temp->num &&
			tempticket->time == LoginedUser->allus->userTicket->temp->time) {
			tempticket->isDelay = info;
			break;
		}
		tempticket = tempticket->next;
	}
	tempticket = LoginedUser->allus->userTicket->sentine->next;
	while (tempticket) {
		myticketsfile << tempticket->data << "\t" << tempticket->num << "\t" << tempticket->start << "\t" << tempticket->end << "\t"
			<< tempticket->time << "\t" << tempticket->at << "\t" << tempticket->price << "\t" << tempticket->Ticketcount << "\t" <<
			tempticket->buytime << "\t" << tempticket->isDelay << "\t" << tempticket->isCancel << "\t" << tempticket->transit <<
			"\t" << tempticket->transittime << endl;
		tempticket = tempticket->next;
	}
	myticketsfile.close();
	/*tempticket->isDelay = info;
	myticketsfile << tempticket->data << "\t" << tempticket->num << "\t" << tempticket->start << "\t" << tempticket->end << "\t"
		<< tempticket->time << "\t" << tempticket->at << "\t" << tempticket->price << "\t" << tempticket->Ticketcount << "\t" <<
		tempticket->buytime << "\t" << tempticket->isDelay << "\t" << tempticket->isCancel << "\t" << tempticket->transit <<
		"\t" << tempticket->transittime << endl;

	myticketsfile.close();*/

	//���»�Ʊ�������
	/*filename = "Users\\" + id + "\\tickets_num.txt";
	myticketsfile.open(filename, ios::out);
	myticketsfile << Ticketnum;//�����û���Ʊ����
	myticketsfile.close();*/
}


bool UserTicket::delete_ut(char del_data[], char del_num[], char del_time[]) {
	UserTicket::Ticket* tempticket = LoginedUser->mg->userTicket->sentine->next;
	UserTicket::Ticket* temp = LoginedUser->mg->userTicket->sentine;
	//LoginedUser->mg->userTicket->load_ut();
	load_ut();
	while (tempticket) {
		if (strcmp(tempticket->data , del_data)==0 && strcmp(tempticket->num ,del_num)==0 && strcmp(tempticket->time , del_time)==0) {
			temp->next = tempticket->next;
			tempticket->next->prior = temp;
			delete tempticket;
			Ticketnum--;
			saveall_ut();
			return true;
		}
		temp = tempticket;
		tempticket = tempticket->next;
	}
	return false;
}
