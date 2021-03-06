#include"User.h"
#include"Flight.h"
#include"User.h"
#include"UserTicket.h"
#include<iostream>

//管理员发布航班取消通知
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
	cout << "请输入要发布取消通知的航班日期" << endl;
	cin >> flightdata;
	cout << "请输入要发布取消通知的航班号" << endl;
	cin >> flightnum;
	cout << "请输入要发布取消通知的航班起降时间" << endl;
	cin >> flighttime;

	string userfilename;
	string userid;
	User::UserInfo* tempinfo;//遍历用户信息

	tempinfo = user->next;

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

			F.delete_fi(tempticket->data, tempticket->num, tempticket->start, tempticket->end);//删除该航班信息
		}
		tempinfo = tempinfo->next;
		isfound = false;
	}

	if (issucced) {
		cout << "发布取消通知成功" << endl;
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