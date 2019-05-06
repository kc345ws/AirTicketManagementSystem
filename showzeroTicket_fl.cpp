#include"Flight.h"
#include"User.h"
#include"UserTicket.h"
#include<iostream>
#include<iomanip>

void Flight::showzeroTicket_fl() {
	User U_AI;

	system("cls");
	U_AI.print_item(24);
	if ((flight_num = load_fn()) == 0)		//判断航班信息是否为空
	{
		cout << "无航班信息可供显示!" << endl;
		Sleep(2000);
	}
	else	//当航班信息不为空时，继续执行以下操作
	{
		cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  余票数  票价  中转地\t中转时间" << endl;
		load_fil();
		fi = flight->next;
		while (fi != NULL)
		{
			if (fi->count == 0) {
				cout.setf(ios::left);
				cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
					setw(11) << fi->time << "\t" << setw(3) << fi->at << "分钟" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
					<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "分钟" << endl;
			}
			fi = fi->next;
		}
	}
}