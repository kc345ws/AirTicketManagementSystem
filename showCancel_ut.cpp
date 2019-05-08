#include"UserTicket.h"
#include<iostream>
#include<iomanip>

void UserTicket::showCancel_ut() {
	User UI;
	system("CLS");
	UI.print_item(22);
	LoginedUser->mg->userTicket->load_ut();
	UserTicket::Ticket* tempticket = LoginedUser->mg->userTicket->sentine->next;
	bool isfound = false;
	cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  票价\t数量\t购买时间\t 延误 取消 中转地 中转时间" << endl;
	while (tempticket) {
		if (tempticket->isCancel) {
			isfound = true;
			cout.setf(ios::left);
			cout << setw(8) << tempticket->data << " " << setw(7) << tempticket->num << " " << setw(5) << tempticket->start << "\t" << setw(5) << tempticket->end << "\t"
				<< setw(11) << tempticket->time << "\t" << setw(3) << tempticket->at << "分钟" << "  " << setw(5) << tempticket->price << "  " << tempticket->Ticketcount << "\t"
				<< setw(17) << tempticket->buytime << "  ";

			if (!tempticket->isDelay) {//如果不延误
				cout << "否" << " ";
			}
			else {
				cout << "是" << " ";
			}
			if (!tempticket->isCancel) {//如果没有取消
				cout << "否   ";
			}
			else {
				cout << "是   ";
			}
			if (tempticket->transit == "无") {//如果没有中转
				cout.setf(ios::left);
				cout << setw(10) << "无" << setw(8) << "无" << endl;
			}
			else {
				cout.setf(ios::left);
				cout << setw(8) << tempticket->transit << " " << setw(3) << tempticket->transittime << "分钟" << endl;
			}
			//temp = temp->next;
		}
		tempticket = tempticket->next;
	}

	if (!isfound) {
		cout << "没有任何发生航班取消的机票" << endl;
	}
	cout << "按任意键返回主界面" << endl;
	getchar();
	getchar();
	UI.login_uf();
}