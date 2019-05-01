#include "Flight.h"
#include "User.h"
#include <iostream>

using namespace std;

void Flight::sort_byfp()	//对全部航班按票价排序并显示
{
	User U_AI;
	FlightInfo *temp;

	system("cls");
	U_AI.print_item(13);
	if((flight_num=load_fn())!=0)
	{	
		load_fil();
		FlightInfo *f_ai;
		/*对航班信息按票价进行排序*/
		f_ai = new FlightInfo;
		f_ai = flight;
		fi = f_ai->next->next;
		f_ai->next->next = NULL;
		while(fi!=NULL)
		{
			temp=fi->next;
			fn=f_ai;
			while(fn->next!=NULL && fn->next->price>fi->price)
				fn=fn->next;
			fi->next=fn->next;
			fn->next=fi;
			fi=temp;
		}
		/*排序完成*/
		cout<<"航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间\t余票数\t票价"<<endl;
		fi=f_ai->next;
		while(fi!=NULL)
		{
			cout<<fi->data<<" "<<fi->num<<"\t"<<fi->start<<"\t"<<fi->end<<"\t"<<fi->time<<"\t"<<fi->at<<"\t\t"<<fi->count<<"\t"<<fi->price<<endl;
			fi=fi->next;
		}
		cin.sync();
		cout<<"\n按任意键返回机票管理系统主页."<<endl;
		getchar();
		getchar();
	}
	else
	{
		cout<<"没有航班信息!"<<endl;
		Sleep(2000);
	}
	system("cls");
	if((U_AI.mode=U_AI.load_mode())==1)
		U_AI.login_mf();
	else if(U_AI.mode==0)
		U_AI.login_uf();
}