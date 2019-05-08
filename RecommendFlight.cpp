#include"User.h"
#include"UserTicket.h"
#include"Flight.h"
#include<iostream>
#include<iomanip>

void User::RecommendFlight() {
	UserTicket::Ticket *delayticket = LoginedUser->mg->userTicket->sentine->next;
	string delaystart[100];
	string delayend[100];
	int count = 0;
	while (delayticket) {
		if (delayticket->isDelay) {
			delaystart[count] = delayticket->start;
			delayend[count] = delayticket->end;
			count++;
		}
		delayticket = delayticket->next;
	}
	cout << "以下为延误航班推荐的其他未延误航班" << endl;
	cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  票价\t数量 延误  中转地 中转时间" << endl;
	
	Flight F;
	F.load_fil();
	for (int i = 0; i < count; i++) {
		//delayticket = LoginedUser->mg->userTicket->sentine->next;
		Flight::FlightInfo* tempinfo = F.flight->next;
		cout << delaystart[i] << "->" << delayend[i] << ":"<<endl;
		while (tempinfo) {
			if (tempinfo->start == delaystart[i] && tempinfo->end == delayend[i]&&!tempinfo->isDelay) {
				cout.setf(ios::left);
				cout << setw(8) << tempinfo->data << " " << setw(7) << tempinfo->num << " " << setw(5) << tempinfo->start << "\t" << setw(5) << tempinfo->end << "\t"
					<< setw(11) << tempinfo->time << "\t" << setw(3) << tempinfo->at << "分钟" << "  " << setw(5) << tempinfo->price << "  " <<setw(3) <<tempinfo->count<< " "
					<< "  ";

				if (!tempinfo->isDelay) {//如果不延误
					cout << "否" << "   ";
				}
				else {
					cout << "是" << "   ";
				}
				if (tempinfo->transit == "无") {//如果没有中转
					cout.setf(ios::left);
					cout << setw(10) << "无" << setw(8) << "无" << endl;
				}
				else {
					cout.setf(ios::left);
					cout << setw(8) << tempinfo->transit << " " << setw(3) << tempinfo->transittime << "分钟" << endl;
				}
			}
			tempinfo = tempinfo->next;
		}
	}
	
}