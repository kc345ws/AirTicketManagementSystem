#include"UserTicket.h"
#include<iostream>
#include <shlwapi.h>
#include<Windows.h>
extern UserTicket* ZeroTicket = nullptr;
extern UserTicket* MyTickets  = nullptr;

void changechar(char ch[], int changeobjID, UserTicket::Ticket* info);//修改char类型的数据

UserTicket::UserTicket() {
	
	Ticketnum = 0;				//机票总数设为0
	sentine = new Ticket();		//哨兵节点
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

void UserTicket::addTicket(Flight::FlightInfo* info ,int ticnum) {//ticnum为机票购买数量
	//***********************************************
					//将购票信息添加到用户机票中
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
	//添加购买时间
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
	TempUT->temp->transittime = info->transittime;//添加中转时间
	load_num();
	Ticketnum ++;//更新机票购买次数

	lastticket = TempUT->temp;//设置最后一张机票
	TempUT->temp->prior = TempPorior;//设置前继结点
	TempUT->temp->next = nullptr;
	//***********************************************
	save_ut();//保存到文件中
}

void UserTicket::init_ut() {//初始化
	string userid = LoginedUser->ui->id;
	string filename = "Users\\" + userid+"\\mytickets.txt";
	fstream myticketsfile;
	myticketsfile.open(filename, ios::out);//创建机票文件
	myticketsfile.close();

	filename = "Users\\" + userid + "\\tickets_num.txt";
	myticketsfile.open(filename, ios::out);
	myticketsfile << 0;//创建用户机票总数
	myticketsfile.close();
}

void UserTicket::load_num() {//加载机票购买次数
	string userid = LoginedUser->mg->id;
	string filename = "Users\\" + userid + "\\tickets_num.txt";
	fstream myticketsfile;

	myticketsfile.open(filename, ios::in);
	if (!myticketsfile) {//如果文件不存在
		myticketsfile.close();
		myticketsfile.open(filename, ios::out);
		myticketsfile << 0;//创建用户机票总数
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
	if (!myticketsfile) {//如果文件不存在
		myticketsfile.close();
		myticketsfile.open(filename, ios::out);
		myticketsfile << 0;//创建用户机票总数
		myticketsfile.close();
		Ticketnum = 0;
	}
	else {
		myticketsfile >> Ticketnum;
		myticketsfile.close();
	}
}

void UserTicket::load_ut(string id) {
	load_num(id);//加载机票购买次数
	//User US;
	string userid = id;
	string filename = "Users\\" + userid + "\\mytickets.txt";
	fstream myticketsfile;
	string testisEmpty;
	//User::UserInfo* tempinfo;
	//tempinfo = US.findUser(id);
	//tempinfo->userTicket = new UserTicket();
	myticketsfile.open(filename, ios::in);
	if (!myticketsfile) {//文件如果不存在
		myticketsfile.close();
		myticketsfile.open(filename, ios::out);
		myticketsfile.close();
	}
	else {//如果用户存在
		myticketsfile >> testisEmpty;
		myticketsfile.seekg(0);//重定向文件头部
		if (!testisEmpty.empty()) {//如果文件存在且不为空
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

void UserTicket::load_ut() {//把机票信息装载到链表中
	load_num();//加载机票购买次数
	string userid = LoginedUser->mg->id;
	string filename = "Users\\" + userid + "\\mytickets.txt";
	fstream myticketsfile;
	string testisEmpty;

	myticketsfile.open(filename, ios::in);
	if (!myticketsfile) {//文件如果不存在
		myticketsfile.close();
		myticketsfile.open(filename, ios::out);
		myticketsfile.close();
	}
	else {
		myticketsfile >> testisEmpty;
		myticketsfile.seekg(0);//重定向文件头部
		if (!testisEmpty.empty()) {//如果文件存在且不为空
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

	//更新机票购买次数
	filename = "Users\\" + userid + "\\tickets_num.txt";
	myticketsfile.open(filename, ios::out);
	myticketsfile << Ticketnum;//创建用户机票总数
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

	//更新机票购买次数
	filename = "Users\\" + userid + "\\tickets_num.txt";
	myticketsfile.open(filename, ios::out);
	myticketsfile << Ticketnum;//创建用户机票总数
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

	//更新机票购买次数
	filename = "Users\\" + userid + "\\tickets_num.txt";
	myticketsfile.open(filename, ios::out);
	myticketsfile << Ticketnum;//创建用户机票总数
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

	//更新机票购买次数
	filename = "Users\\" + userid + "\\tickets_num.txt";
	myticketsfile.open(filename, ios::out);
	myticketsfile << Ticketnum;//创建用户机票总数
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

	//更新机票购买次数
	/*filename = "Users\\" + id + "\\tickets_num.txt";
	myticketsfile.open(filename, ios::out);
	myticketsfile << Ticketnum;//创建用户机票总数
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
