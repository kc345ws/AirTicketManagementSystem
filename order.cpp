//订票
#include "Flight.h"
#include "User.h"
#include"UserTicket.h"
#include <iostream>
#include<iomanip>

using namespace std;
void changechar(char ch[], int changeobjID, UserTicket::Ticket* info);//修改char类型的数据

void Flight::order()		//订票
{
	User U_AI;
	Flight F;
	int success=0;
	bool exist = false;

	system("cls");
	string choice;
	//U_AI.print_item(14);
	//current_time();
	if((flight_num=load_fn())==0)	//没有航班信息可供预定
	{
		cout<<"没有航班信息!无法提供预定服务!"<<endl;
		cout<<"即将跳转至机票管理系统主页..."<<endl;
		Sleep(1000);
		goto loop2;
	}
	else					//存在航班信息时，继续进行以下操作
	{
		Sleep(2000);
		browse_fi(false);
		U_AI.print_item(14);
		current_time();
		input_sfi(1,0,0);
		load_fil();
		//cout<<"航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间\t余票数\t票价 中转地 中转时间"<<endl;
		cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  余票数  票价  中转地\t中转时间 延误" << endl;
		for(fi=flight->next;fi!=NULL;fi=fi->next)
		{
			if(strcmp(fi->start,fn->start)==0 && strcmp(fi->end,fn->end)==0)
			{
				exist = true;
				//cout<<fi->data<<" "<<fi->num<<"\t"<<fi->start<<"\t"<<fi->end<<"\t"<<fi->time<<"\t"<<fi->at<<"\t\t"<<fi->count<<"\t"<<fi->price<<" "<<fi->transit<<" "<< fi->transittime<<endl;
				cout.setf(ios::left);
				cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
					setw(11) << fi->time << "\t" << setw(3) << fi->at << "分钟" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
					<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "分钟" <<"  " ;
				if (fi->isDelay) {
					cout << "是" << endl;
				}
				else {
					cout << "否" << endl;
				}
			}
		}
		if(!exist)
			goto Nofind;
		input_sfi(0,1,0);
		for(fi=flight->next;fi!=NULL;fi=fi->next)
		{
			if(strcmp(fi->num,fn->num)==0 && strcmp(fi->data,fn->data) == 0)
			{
				if(fn->count<=0)//输入的定票数小于等于0
				{
					cout<<"输入订票数无效!"<<endl;
					cout << "是否继续订票(y/n)?" << endl;
					cin >> choice;
					if (choice == "y" || choice == "Y") {
						order();
					}
					else {
						U_AI.login_uf();
					}
					break;
				}
				else if(fi->count>=fn->count)
				{
					success = 1;
					fi->count = fi->count - fn->count;
					cout<<"订票成功!"<<endl;
					Sleep(2000);
					system("cls");
					cout<<"航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间\t余票数\t票价 延误"<<endl;
					
					cout<<fi->data<<" "<<fi->num<<"\t"<<fi->start<<"\t"<<fi->end<<"\t"<<fi->time<<"\t"<<fi->at<<"\t\t"<<fi->count<<"\t"<<fi->price<<"  "<<endl;
					if (fi->isDelay) {
						cout << "是" << endl;
					}
					else {
						cout << "否" << endl;
					}

					/*if(fi->count==0)//如果购票后剩余票数为0
					{
						fi->prior->next = fi->next;//将该航班的前一个航班的下一个航班设为该航班的下一个航班
						fi->next->prior = fi->prior;//该航班的下一个航班的前一个航班设为该航班的前一个航班
						delete fi;
						--flight_num;//航班总数减1
						save_fn();
					}*/

					//***********************************************
					//将购票信息添加到用户机票中
					LoginedUser->mg->userTicket->addTicket(fi,fn->count);

					//************************************************/
					save_fil();
					cout << "是否继续订票(y/n)?" << endl;
					cin >> choice;
					if (choice == "y" || choice == "Y") {
						order();
					}
					else {
						U_AI.login_uf();
					}

					break;
				}
				else if(fi->count>0 && fi->count<fn->count)
				{
					cout<<"余票不足!无法完成订票!"<<endl;
					cout<<"请重新订票!"<<endl;
					cout << "是否继续订票(y/n)?" << endl;
					cin >> choice;
					if (choice == "y" || choice == "Y") {
						order();
					}
					else {
						U_AI.login_uf();
					}
					break;
				}
				else if(fi->count==0)//要预定航班的剩余票数
				{
					cout<<"该航班票已售空!请改换航班订购!"<<endl;
					cout << "是否继续订票(y/n)?" << endl;
					cin >> choice;
					if (choice == "y" || choice == "Y") {
						order();
					}
					else {
						U_AI.login_uf();
					}
					break;
				}
			}
		}

		cout << "输入的信息有误" << endl;
		cout << "是否继续订票(y/n)?" << endl;
		cin >> choice;
		if (choice == "y" || choice == "Y") {
			order();
		}
		else {
			U_AI.login_uf();
		}
		


Nofind:	if(success==0)
		{//无直达航班
			system("cls");
			F.recommendTransit(fn->start, fn->end);
			//cout<<"没有航班信息或已售空!"<<endl;
			cout << "是否继续订票(y/n)?" << endl;
			cin >> choice;
			if (choice == "y" || choice == "Y") {
				order();
			}
			else {
				U_AI.login_uf();
			}
		}
		save_fil();
loop2:	Sleep(2000);
		if((U_AI.mode=U_AI.load_mode())==1)
			U_AI.login_mf();
		else if(U_AI.mode==0)
			U_AI.login_uf();
	}
}

void changechar(char ch[], int changeobjID, UserTicket::Ticket* info) {//修改char类型的数据

	if (changeobjID == 1) {//如果要修改航班日期
		for (int i = 0; i < strlen(ch); i++) {
			info->data[i] = ch[i];
		}
	}
	else if (changeobjID == 2) {
		for (int i = 0; i < strlen(ch); i++) {
			info->num[i] = ch[i];
		}
	}
	else if (changeobjID == 3) {
		for (int i = 0; i < strlen(ch); i++) {
			info->start[i] = ch[i];
		}
	}
	else if (changeobjID == 4) {
		for (int i = 0; i < strlen(ch); i++) {
			info->end[i] = ch[i];
		}
	}
	else if (changeobjID == 5) {
		for (int i = 0; i < strlen(ch); i++) {
			info->time[i] = ch[i];
		}
	}
	else if (changeobjID == 6) {
		for (int i = 0; i < strlen(ch); i++) {
			info->at[i] = ch[i];
		}
	}
	else if (changeobjID == 7) {
		for (int i = 0; i < strlen(ch); i++) {
			info->buytime[i] = ch[i];
		}
	}
}