#include"User.h"
#include<iostream>

//管理员发布航班延误通知
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
	cout << "请输入要发布延误通知的航班日期" << endl;
	cin >> flightdata;
	cout << "请输入要发布延误通知的航班号" << endl;
	cin >> flightnum;
	cout << "请输入要发布延误通知的航班起降时间" << endl;
	cin >> flighttime;

	string userfilename;
	string userid;
	User::UserInfo* tempinfo;//遍历用户信息
	//LoginedUser->allus = new UserInfo();
	//LoginedUser->allus->userTicket = new UserTicket();
	//LoginedUser->allus->userTicket->load_ut(user->next->id);//加载机票信息
	//tempinfo能获取 tempinfo->userticket为空
	tempinfo = user->next;
	//tempinfo->userTicket = LoginedUser->allus->userTicket;
	//user->next->userticket为空
	UserTicket::Ticket* tempticket = nullptr;
	bool isfound = false;//判断用户是否有这个航班的机票
	bool issucced = false;
	for (int i = 0; i < user_num; i++) {
		//userticket->load_ut(tempinfo->id);
		LoginedUser->allus = new UserInfo();
		LoginedUser->allus->userTicket = new UserTicket();
		LoginedUser->allus->userTicket->load_ut(tempinfo->id);//加载机票信息
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
		cout << "发布延误通知成功" << endl;
	}
	else {
		cout << "没有该架航班或没有用户购买该航班机票" << endl;
	}
	delete userticket;
	cout << "按任意键返回主界面" << endl;
	getchar();
	getchar();
	login_mf();
}