#include "Flight.h"
#include "User.h"
#include <iostream>
#include<iomanip>

using namespace std;

void Flight::browse_fi(bool isback) 	//输出航班信息
{
	User U_AI;
	
	system("cls");
	U_AI.print_item(11);
	if((flight_num=load_fn())==0)		//判断航班信息是否为空
	{
		cout<<"无航班信息可供显示!"<<endl;
		Sleep(2000);
	}
	else	//当航班信息不为空时，继续执行以下操作
	{
		cout<<"航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  余票数  票价  中转地\t中转时间 延误"<<endl;
		load_fil();
		fi=flight->next;
		while(fi!=NULL)
		{
			cout.setf(ios::left);
			cout<< setw(8) <<fi->data<<" "<< setw(7) <<fi->num<<" "<< setw(5) <<fi->start<<"\t"<< setw(5) <<fi->end<<"\t"<< 
				setw(11) <<fi->time<<"\t"<< setw(3) <<fi->at << "分钟" <<"    "<< setw(4) <<fi->count<<"  "<< setw(5) <<fi->price<<"  "
				<< setw(5) <<fi->transit<< "\t"<<setw(3) <<fi->transittime<<"分钟"<<"   ";
			if (fi->isDelay) {
				cout << "是" << endl;
			}
			else {
				cout << "否" << endl;
			}
			fi=fi->next;
		}
		
	}

	if (isback) {
		cin.sync();
		cout << "\n\n按任意键键返回机票管理系统主页\n";
		getchar();
		getchar();
		system("cls");
		U_AI.mode = U_AI.load_mode();
		if (U_AI.mode == 1)
			U_AI.login_mf();
		else if (U_AI.mode == 0)
			U_AI.login_uf();
	}
}
