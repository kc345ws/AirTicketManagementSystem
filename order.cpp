#include "Ticket.h"
#include "Ticket1.h"
#include <iostream>

using namespace std;

void Flight::order()		//订票
{
	User U_AI;
	int success=0;
	bool exist = false;

	system("cls");
	U_AI.print_item(14);
	current_time();
	if((flight_num=load_fn())==0)	//没有航班信息可供预定
	{
		cout<<"没有航班信息!无法提供预定服务!"<<endl;
		cout<<"即将跳转至机票管理系统主页..."<<endl;
		Sleep(1000);
		goto loop2;
	}
	else					//存在航班信息时，继续进行以下操作
	{
		input_sfi(1,0,0);
		load_fil();
		cout<<"航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间\t余票数\t票价"<<endl;
		for(fi=flight->next;fi!=NULL;fi=fi->next)
		{
			if(strcmp(fi->start,fn->start)==0 && strcmp(fi->end,fn->end)==0)
			{
				exist = true;
				cout<<fi->data<<" "<<fi->num<<"\t"<<fi->start<<"\t"<<fi->end<<"\t"<<fi->time<<"\t"<<fi->at<<"\t\t"<<fi->count<<"\t"<<fi->price<<endl;
			}
		}
		if(!exist)
			goto Nofind;
		input_sfi(0,1,0);
		for(fi=flight->next;fi!=NULL;fi=fi->next)
		{
			if(strcmp(fi->num,fn->num)==0)
			{
				if(fn->count<=0)
				{
					cout<<"输入订票数无效!"<<endl;
					Sleep(1000);
					order();
					break;
				}
				else if(fi->count>=fn->count)
				{
					success = 1;
					fi->count = fi->count - fn->count;
					cout<<"订票成功!"<<endl;
					Sleep(2000);
					system("cls");
					cout<<"航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间\t余票数\t票价"<<endl;
					cout<<fi->data<<" "<<fi->num<<"\t"<<fi->start<<"\t"<<fi->end<<"\t"<<fi->time<<"\t"<<fi->at<<"\t\t"<<fi->count<<"\t"<<fi->price<<endl;
					if(fi->count==0)
					{
						fi->prior->next = fi->next;
						fi->next->prior = fi->prior;
						delete fi;
						--flight_num;
						save_fn();
					}
					break;
				}
				else if(fi->count>0 && fi->count<fn->count)
				{
					cout<<"余票不足!无法完成订票!"<<endl;
					cout<<"请重新订票!"<<endl;
					Sleep(2000);
					order();
					break;
				}
				else if(fi->count==0)
				{
					cout<<"该航班票已售空!请改换航班订购!"<<endl;
					Sleep(2000);
					order();
					break;
				}
			}
		}
Nofind:	if(success==0)
		{
			system("cls");
			cout<<"没有航班信息或已售空!"<<endl;
			Sleep(2000);
			order();
		}
		save_fil();
loop2:	Sleep(2000);
		if((U_AI.mode=U_AI.load_mode())==1)
			U_AI.login_mf();
		else if(U_AI.mode==0)
			U_AI.login_uf();
	}
}