#include"Flight.h"
#include"User.h"
#include"UserTicket.h"
#include<iostream>
#include<iomanip>

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
		cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  票价\t数量\t购买时间\t 延误 取消 中转地 中转时间" << endl;
		while (temp) {
			cout.setf(ios::left);
			cout << setw(8) << temp->data << " " << setw(7) <<temp->num << " " << setw(5) <<temp->start << "\t" << setw(5) <<temp->end << "\t" 
				<<setw(11) << temp->time << "\t" <<setw(3) << temp->at << "分钟"<< "  "<<setw(5)<<temp->price << "  " << temp->Ticketcount << "\t"
				<< setw(12) <<temp->buytime<<"  ";

			/*cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "分钟" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "分钟" << endl;*/
			if (!temp->isDelay) {//如果不延误
				cout << "否"<<" ";
			}
			else {
				cout << "是"<<" ";
			}
			if (!temp->isCancel) {//如果没有取消
				cout << "否   ";
			}
			else{
				cout << "是   ";
			}
			if(temp->transit=="无") {//如果没有中转
				cout.setf(ios::left);
				cout << setw(8) << "无" << setw(5) <<"无"<<endl;
			}
			else {
				cout.setf(ios::left);
				cout << setw(8) << temp->transit << " " << setw(3) <<temp->transittime << "分钟"<<endl;
			}
			temp = temp->next;
		}
	}
	cout << "按任意键返回主界面" << endl;
	getchar();
	getchar();
	ui.login_uf();
}