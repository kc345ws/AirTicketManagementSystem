#include"Flight.h"
#include"User.h"
#include"UserTicket.h"
#include<iostream>

void UserTicket::showTickets(bool isback) {
	system("CLS");
	load_ut();//从文件中加载
	User ui;
	ui.print_item(18);//打印我的机票信息
	temp = LoginedUser->mg->userTicket->sentine;
	if (!temp->next) {
		cout << "没有购买任何机票" << endl;
	}
	else {
		temp = temp->next;
		//ui.print_item(19);
		cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  票价\t数量\t购买时间\t延误  取消" << endl;
		while (temp) {
			cout << temp->data << " " << temp->num << "\t" << temp->start << "\t" << temp->end << "\t" << temp->time << "\t" << temp->at << "\t"
				<< temp->price << "\t" << temp->Ticketcount << "\t"<<temp->buytime<<"  ";
			if (!temp->isDelay) {//如果不延误
				cout << "否"<<"  ";
			}
			else {
				cout << "是"<<"  ";
			}
			if (!temp->isCancel) {//如果没有取消
				cout << "否" << endl;
			}
			else{
				cout << "是" << endl;
			}
			temp = temp->next;
		}
	}
	cout << "按任意键返回主界面" << endl;
	getchar();
	getchar();
	ui.login_uf();
}