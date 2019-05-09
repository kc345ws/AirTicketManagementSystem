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

/*void Flight::browse_fi_priceLTH() {//按机票从高到低排序
	User U_AI;

	system("cls");
	U_AI.print_item(11);
	if ((flight_num = load_fn()) == 0)		//判断航班信息是否为空
	{
		cout << "无航班信息可供显示!" << endl;
		Sleep(2000);
	}
	else	//当航班信息不为空时，继续执行以下操作
	{
		cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  余票数  票价  中转地\t中转时间 延误" << endl;
		load_fil();
		Flight::FlightInfo* LTHPrice = new Flight::FlightInfo();
		Flight::FlightInfo* Tempinfo = flight->next;
		Flight::FlightInfo* frontLTH = LTHPrice;
		Flight::FlightInfo* firstLTH = LTHPrice;
		//LTHPrice->next = new Flight::FlightInfo();
		//LTHPrice = LTHPrice->next;
		LTHPrice->price = 0;
		while (Tempinfo) {
			if (Tempinfo->price > LTHPrice->price) {
				//LTHPrice->next = Tempinfo;
				LTHPrice->next = new Flight::FlightInfo();
				LTHPrice = LTHPrice->next;
				for (int i = 0; i < size(Tempinfo->data); i++) {
					LTHPrice->data[i] = Tempinfo->data[i];
				}
				for (int i = 0; i < size(Tempinfo->num);i++) {
					LTHPrice->num[i] = Tempinfo->num[i];
				}
				for (int i = 0; i < size(Tempinfo->start); i++) {
					LTHPrice->start[i] = Tempinfo->start[i];
				}
				for (int i = 0; i < size(Tempinfo->end); i++) {
					LTHPrice->end[i] = Tempinfo->end[i];
				}
				for (int i = 0; i < size(Tempinfo->time); i++) {
					LTHPrice->time[i] = Tempinfo->time[i];
				}
				for (int i = 0; i < size(Tempinfo->at); i++) {
					LTHPrice->at[i] = Tempinfo->at[i];
				}
				LTHPrice->count = Tempinfo->count;
				LTHPrice->price = Tempinfo->price;
				LTHPrice->transit = Tempinfo->transit;
				LTHPrice->transittime = Tempinfo->transittime;
				LTHPrice->isDelay = Tempinfo->isDelay;
			}
			else {
				frontLTH->next = new Flight::FlightInfo();
				frontLTH = frontLTH->next;
				frontLTH->next = LTHPrice;

				for (int i = 0; i < size(Tempinfo->data); i++) {
					frontLTH->data[i] = Tempinfo->data[i];
				}
				for (int i = 0; i < size(Tempinfo->num); i++) {
					frontLTH->num[i] = Tempinfo->num[i];
				}
				for (int i = 0; i < size(Tempinfo->start); i++) {
					frontLTH->start[i] = Tempinfo->start[i];
				}
				for (int i = 0; i < size(Tempinfo->end); i++) {
					frontLTH->end[i] = Tempinfo->end[i];
				}
				for (int i = 0; i < size(Tempinfo->time); i++) {
					frontLTH->time[i] = Tempinfo->time[i];
				}
				for (int i = 0; i < size(Tempinfo->at); i++) {
					frontLTH->at[i] = Tempinfo->at[i];
				}
				frontLTH->count = Tempinfo->count;
				frontLTH->price = Tempinfo->price;
				frontLTH->transit = Tempinfo->transit;
				frontLTH->transittime = Tempinfo->transittime;
				frontLTH->isDelay = Tempinfo->isDelay;
			}
			Tempinfo = Tempinfo->next;
		}
		//f_file >> fi->data >> fi->num >> fi->start >> fi->end >> fi->time >> fi->at >> fi->count >> fi->price >> fi->transit >> fi->transittime >> fi->isDelay;

		//fi = flight->next;
		firstLTH = firstLTH->next;
		while (firstLTH)
		{
			cout.setf(ios::left);
			cout << setw(8) << firstLTH->data << " " << setw(7) << firstLTH->num << " " << setw(5) << firstLTH->start << "\t" << setw(5) << firstLTH->end << "\t" <<
				setw(11) << firstLTH->time << "\t" << setw(3) << firstLTH->at << "分钟" << "    " << setw(4) << firstLTH->count << "  " << setw(5) << firstLTH->price << "  "
				<< setw(5) << firstLTH->transit << "\t" << setw(3) << firstLTH->transittime << "分钟" << "   ";
			if (firstLTH->isDelay) {
				cout << "是" << endl;
			}
			else {
				cout << "否" << endl;
			}
			firstLTH = firstLTH->next;
		}	
	}
		
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
}*/


void Flight::browse_fi_priceLTH()	//票价升序
{
	User U_AI;
	FlightInfo* temp;

	system("cls");
	//U_AI.print_item(13);
	cout << "#===========================================================================#" << endl;
	cout << "#                              航班按票价升序显示                           #" << endl;
	cout << "#===========================================================================#" << endl;
	if ((flight_num = load_fn()) != 0)
	{
		load_fil();
		FlightInfo* f_ai;
		/*对航班信息按票价进行排序*/
		f_ai = new FlightInfo;
		f_ai = flight;//哨兵节点
		fi = f_ai->next->next;//第二个有效结点
		f_ai->next->next = NULL;
		while (fi != NULL)
		{
			temp = fi->next;//首先赋值第一个有效结点
			fn = f_ai;//哨兵节点
			while (fn->next != NULL && fn->next->price < fi->price)//找到一个比fi->price大的结点
				fn = fn->next;
			fi->next = fn->next;
			fn->next = fi;
			fi = temp;
		}
		/*排序完成*/
		//cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间\t余票数\t票价" << endl;
		cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  余票数  票价  中转地\t中转时间 延误" << endl;
		fi = f_ai->next;
		while (fi != NULL)
		{
			cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "分钟" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "分钟" << "   ";
			if (fi->isDelay) {
				cout << "是" << endl;
			}
			else {
				cout << "否" << endl;
			}
			fi = fi->next;
		}
		cin.sync();
		cout << "\n按任意键返回机票管理系统主页." << endl;
		getchar();
		getchar();
	}
	else
	{
		cout << "没有航班信息!" << endl;
		Sleep(2000);
	}
	system("cls");
	if ((U_AI.mode = U_AI.load_mode()) == 1)
		U_AI.login_mf();
	else if (U_AI.mode == 0)
		U_AI.login_uf();
}

void Flight::browse_fi_atLTH()
{
	User U_AI;
	FlightInfo* temp;

	system("cls");
	//U_AI.print_item(13);
	cout << "#===========================================================================#" << endl;
	cout << "#                              航班按飞行时间升序显示                       #" << endl;
	cout << "#===========================================================================#" << endl;
	if ((flight_num = load_fn()) != 0)
	{
		load_fil();
		FlightInfo* f_ai;
		/*对航班信息按票价进行排序*/
		f_ai = new FlightInfo;
		f_ai = flight;//哨兵节点
		fi = f_ai->next->next;//第二个有效结点
		f_ai->next->next = NULL;
		while (fi != NULL)
		{
			temp = fi->next;//首先赋值第一个有效结点
			fn = f_ai;//哨兵节点
			int tempa = atoi(fn->next->at);
			int tempb = atoi(fi->at);
			while (fn->next != NULL && tempa < tempb) {
				fn = fn->next;
				if (fn->next) {
					tempa = atoi(fn->next->at);
					tempb = atoi(fi->at);
				}
			}
				
			fi->next = fn->next;
			fn->next = fi;
			fi = temp;
		}
		/*排序完成*/
		cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  余票数  票价  中转地\t中转时间 延误" << endl;
		fi = f_ai->next;
		while (fi != NULL)
		{
			cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "分钟" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "分钟" << "   ";
			if (fi->isDelay) {
				cout << "是" << endl;
			}
			else {
				cout << "否" << endl;
			}
			fi = fi->next;
		}
		cin.sync();
		cout << "\n按任意键返回机票管理系统主页." << endl;
		getchar();
		getchar();
	}
	else
	{
		cout << "没有航班信息!" << endl;
		Sleep(2000);
	}
	system("cls");
	if ((U_AI.mode = U_AI.load_mode()) == 1)
		U_AI.login_mf();
	else if (U_AI.mode == 0)
		U_AI.login_uf();
}

void Flight::browse_fi_atHTL() {
	User U_AI;
	FlightInfo* temp;

	system("cls");
	//U_AI.print_item(13);
	cout << "#===========================================================================#" << endl;
	cout << "#                              航班按飞行时间降序显示                       #" << endl;
	cout << "#===========================================================================#" << endl;
	if ((flight_num = load_fn()) != 0)
	{
		load_fil();
		FlightInfo* f_ai;
		/*对航班信息按票价进行排序*/
		f_ai = new FlightInfo;
		f_ai = flight;//哨兵节点
		fi = f_ai->next->next;//第二个有效结点
		f_ai->next->next = NULL;
		while (fi != NULL)
		{
			temp = fi->next;//首先赋值第一个有效结点
			fn = f_ai;//哨兵节点
			int tempa = atoi(fn->next->at);
			int tempb = atoi(fi->at);
			while (fn->next != NULL && tempa > tempb)
			{
				fn = fn->next;
				if (fn->next) {
					tempa = atoi(fn->next->at);
					tempb = atoi(fi->at);
				}
			}
			fi->next = fn->next;
			fn->next = fi;
			fi = temp;
		}
		/*排序完成*/
		cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  余票数  票价  中转地\t中转时间 延误" << endl;
		fi = f_ai->next;
		while (fi != NULL)
		{
			cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "分钟" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "分钟" << "   ";
			if (fi->isDelay) {
				cout << "是" << endl;
			}
			else {
				cout << "否" << endl;
			}
			fi = fi->next;
		}
		cin.sync();
		cout << "\n按任意键返回机票管理系统主页." << endl;
		getchar();
		getchar();
	}
	else
	{
		cout << "没有航班信息!" << endl;
		Sleep(2000);
	}
	system("cls");
	if ((U_AI.mode = U_AI.load_mode()) == 1)
		U_AI.login_mf();
	else if (U_AI.mode == 0)
		U_AI.login_uf();
}

void Flight::browse_fi_countLTH()
{
	User U_AI;
	FlightInfo* temp;

	system("cls");
	//U_AI.print_item(13);
	cout << "#===========================================================================#" << endl;
	cout << "#                              航班按余票数升序显示                         #" << endl;
	cout << "#===========================================================================#" << endl;
	if ((flight_num = load_fn()) != 0)
	{
		load_fil();
		FlightInfo* f_ai;
		/*对航班信息按票价进行排序*/
		f_ai = new FlightInfo;
		f_ai = flight;//哨兵节点
		fi = f_ai->next->next;//第二个有效结点
		f_ai->next->next = NULL;
		while (fi != NULL)
		{
			temp = fi->next;//首先赋值第一个有效结点
			fn = f_ai;//哨兵节点
			while (fn->next != NULL && fn->next->count < fi->count)
				fn = fn->next;
			fi->next = fn->next;
			fn->next = fi;
			fi = temp;
		}
		/*排序完成*/
		cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  余票数  票价  中转地\t中转时间 延误" << endl;
		fi = f_ai->next;
		while (fi != NULL)
		{
			cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "分钟" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "分钟" << "   ";
			if (fi->isDelay) {
				cout << "是" << endl;
			}
			else {
				cout << "否" << endl;
			}
			fi = fi->next;
		}
		cin.sync();
		cout << "\n按任意键返回机票管理系统主页." << endl;
		getchar();
		getchar();
	}
	else
	{
		cout << "没有航班信息!" << endl;
		Sleep(2000);
	}
	system("cls");
	if ((U_AI.mode = U_AI.load_mode()) == 1)
		U_AI.login_mf();
	else if (U_AI.mode == 0)
		U_AI.login_uf();
}

void Flight::browse_fi_countHTL() {
	User U_AI;
	FlightInfo* temp;

	system("cls");
	//U_AI.print_item(13);
	cout << "#===========================================================================#" << endl;
	cout << "#                              航班按余票数降序显示                         #" << endl;
	cout << "#===========================================================================#" << endl;
	if ((flight_num = load_fn()) != 0)
	{
		load_fil();
		FlightInfo* f_ai;
		/*对航班信息按票价进行排序*/
		f_ai = new FlightInfo;
		f_ai = flight;//哨兵节点
		fi = f_ai->next->next;//第二个有效结点
		f_ai->next->next = NULL;
		while (fi != NULL)
		{
			temp = fi->next;//首先赋值第一个有效结点
			fn = f_ai;//哨兵节点
			while (fn->next != NULL && fn->next->count > fi->count)//找到一个比fi->price大的结点
				fn = fn->next;
			fi->next = fn->next;
			fn->next = fi;
			fi = temp;
		}
		/*排序完成*/
		cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  余票数  票价  中转地\t中转时间 延误" << endl;
		fi = f_ai->next;
		while (fi != NULL)
		{
			cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "分钟" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "分钟" << "   ";
			if (fi->isDelay) {
				cout << "是" << endl;
			}
			else {
				cout << "否" << endl;
			}
			fi = fi->next;
		}
		cin.sync();
		cout << "\n按任意键返回机票管理系统主页." << endl;
		getchar();
		getchar();
	}
	else
	{
		cout << "没有航班信息!" << endl;
		Sleep(2000);
	}
	system("cls");
	if ((U_AI.mode = U_AI.load_mode()) == 1)
		U_AI.login_mf();
	else if (U_AI.mode == 0)
		U_AI.login_uf();
}

void Flight::browse_fi_transtimeLTH()
{
	User U_AI;
	FlightInfo* temp;

	system("cls");
	//U_AI.print_item(13);
	cout << "#===========================================================================#" << endl;
	cout << "#                              航班按中转时间升序显示                       #" << endl;
	cout << "#===========================================================================#" << endl;
	if ((flight_num = load_fn()) != 0)
	{
		load_fil();
		FlightInfo* f_ai;
		/*对航班信息按票价进行排序*/
		f_ai = new FlightInfo;
		f_ai = flight;//哨兵节点
		fi = f_ai->next->next;//第二个有效结点
		f_ai->next->next = NULL;
		while (fi != NULL)
		{
			temp = fi->next;//首先赋值第一个有效结点
			fn = f_ai;//哨兵节点
			while (fn->next != NULL && fn->next->transittime < fi->transittime)//找到一个比fi->price大的结点
				fn = fn->next;
			fi->next = fn->next;
			fn->next = fi;
			fi = temp;
		}
		/*排序完成*/
		cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  余票数  票价  中转地\t中转时间 延误" << endl;
		fi = f_ai->next;
		while (fi != NULL)
		{
			cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "分钟" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "分钟" << "   ";
			if (fi->isDelay) {
				cout << "是" << endl;
			}
			else {
				cout << "否" << endl;
			}
			fi = fi->next;
		}
		cin.sync();
		cout << "\n按任意键返回机票管理系统主页." << endl;
		getchar();
		getchar();
	}
	else
	{
		cout << "没有航班信息!" << endl;
		Sleep(2000);
	}
	system("cls");
	if ((U_AI.mode = U_AI.load_mode()) == 1)
		U_AI.login_mf();
	else if (U_AI.mode == 0)
		U_AI.login_uf();
}

void Flight::browse_fi_transtimeHTL() {
	User U_AI;
	FlightInfo* temp;

	system("cls");
	//U_AI.print_item(13);
	cout << "#===========================================================================#" << endl;
	cout << "#                              航班按中转时间降序显示                       #" << endl;
	cout << "#===========================================================================#" << endl;
	if ((flight_num = load_fn()) != 0)
	{
		load_fil();
		FlightInfo* f_ai;
		/*对航班信息按票价进行排序*/
		f_ai = new FlightInfo;
		f_ai = flight;//哨兵节点
		fi = f_ai->next->next;//第二个有效结点
		f_ai->next->next = NULL;
		while (fi != NULL)
		{
			temp = fi->next;//首先赋值第一个有效结点
			fn = f_ai;//哨兵节点
			while (fn->next != NULL && fn->next->transittime > fi->transittime)//找到一个比fi->price大的结点
				fn = fn->next;
			fi->next = fn->next;
			fn->next = fi;
			fi = temp;
		}
		/*排序完成*/
		cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  余票数  票价  中转地\t中转时间 延误" << endl;
		fi = f_ai->next;
		while (fi != NULL)
		{
			cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "分钟" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "分钟" << "   ";
			if (fi->isDelay) {
				cout << "是" << endl;
			}
			else {
				cout << "否" << endl;
			}
			fi = fi->next;
		}
		cin.sync();
		cout << "\n按任意键返回机票管理系统主页." << endl;
		getchar();
		getchar();
	}
	else
	{
		cout << "没有航班信息!" << endl;
		Sleep(2000);
	}
	system("cls");
	if ((U_AI.mode = U_AI.load_mode()) == 1)
		U_AI.login_mf();
	else if (U_AI.mode == 0)
		U_AI.login_uf();
}

void Flight::browse_fi_dateLTH()
{
	User U_AI;
	FlightInfo* temp;

	system("cls");
	//U_AI.print_item(13);
	cout << "#===========================================================================#" << endl;
	cout << "#                              航班按日期升序显示                           #" << endl;
	cout << "#===========================================================================#" << endl;
	if ((flight_num = load_fn()) != 0)
	{
		load_fil();
		FlightInfo* f_ai;
		/*对航班信息按票价进行排序*/
		f_ai = new FlightInfo;
		f_ai = flight;//哨兵节点
		fi = f_ai->next->next;//第二个有效结点
		f_ai->next->next = NULL;
		while (fi != NULL)
		{
			temp = fi->next;//首先赋值第一个有效结点
			fn = f_ai;//哨兵节点
			while (fn->next != NULL && strcmp(fn->next->data ,fi->data)<0)//找到一个比fi->price大的结点
				fn = fn->next;
			fi->next = fn->next;
			fn->next = fi;
			fi = temp;
		}
		/*排序完成*/
		cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  余票数  票价  中转地\t中转时间 延误" << endl;
		fi = f_ai->next;
		while (fi != NULL)
		{
			cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "分钟" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "分钟" << "   ";
			if (fi->isDelay) {
				cout << "是" << endl;
			}
			else {
				cout << "否" << endl;
			}
			fi = fi->next;
		}
		cin.sync();
		cout << "\n按任意键返回机票管理系统主页." << endl;
		getchar();
		getchar();
	}
	else
	{
		cout << "没有航班信息!" << endl;
		Sleep(2000);
	}
	system("cls");
	if ((U_AI.mode = U_AI.load_mode()) == 1)
		U_AI.login_mf();
	else if (U_AI.mode == 0)
		U_AI.login_uf();
}

void Flight::browse_fi_dateHTL() {
	User U_AI;
	FlightInfo* temp;

	system("cls");
	//U_AI.print_item(13);
	cout << "#===========================================================================#" << endl;
	cout << "#                              航班按日期降序显示                           #" << endl;
	cout << "#===========================================================================#" << endl;
	if ((flight_num = load_fn()) != 0)
	{
		load_fil();
		FlightInfo* f_ai;
		/*对航班信息按票价进行排序*/
		f_ai = new FlightInfo;
		f_ai = flight;//哨兵节点
		fi = f_ai->next->next;//第二个有效结点
		f_ai->next->next = NULL;
		while (fi != NULL)
		{
			temp = fi->next;//首先赋值第一个有效结点
			fn = f_ai;//哨兵节点
			while (fn->next != NULL && strcmp(fn->next->data, fi->data) > 0)//找到一个比fi->price大的结点
				fn = fn->next;
			fi->next = fn->next;
			fn->next = fi;
			fi = temp;
		}
		/*排序完成*/
		cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  余票数  票价  中转地\t中转时间 延误" << endl;
		fi = f_ai->next;
		while (fi != NULL)
		{
			cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "分钟" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "分钟" << "   ";
			if (fi->isDelay) {
				cout << "是" << endl;
			}
			else {
				cout << "否" << endl;
			}
			fi = fi->next;
		}
		cin.sync();
		cout << "\n按任意键返回机票管理系统主页." << endl;
		getchar();
		getchar();
	}
	else
	{
		cout << "没有航班信息!" << endl;
		Sleep(2000);
	}
	system("cls");
	if ((U_AI.mode = U_AI.load_mode()) == 1)
		U_AI.login_mf();
	else if (U_AI.mode == 0)
		U_AI.login_uf();
}


