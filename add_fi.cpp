//管理员添加航班信息
#include "Ticket.h"
#include "Ticket1.h"
#include <iostream>

using namespace std;

void Flight::add_fi()		//添加航班信息
{
	int i=0;
	User U_AI;

	system("cls");
	U_AI.print_item(10);

	load_fil();				//把文件中航班信息装载到链表
	input_fi();				//输入要添加的航班信息
	Inser_fi();				//把航班信息按日期顺序插入链表
	save_fil();				//把新航班信息链表保存到文件

	++flight_num;			//航班数加1
	save_fn();				//保存航班总数

	cout<<"\n正在进行航班信息录入..."<<endl;
	Sleep(2000);
	system("cls");
	cout<<"航班信息录入成功!"<<endl;
	cout<<"即将跳转至信息管理系统主页..."<<endl;
	Sleep(2000);
	system("cls");
	U_AI.login_mf();
}
