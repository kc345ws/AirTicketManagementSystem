//管理员删除航班信息
#include "Flight.h"
#include "User.h"
#include <iostream>

void Flight::delete_fi() {
	int i = 0;
	User U_AI;

	system("cls");

	load_fil();				//把文件中航班信息装载到链表
	//input_fi();				//输入要添加的航班信息
	//Inser_fi();				//把航班信息按日期顺序插入链表
	browse_fi(false);
	char data_del[9];//删除航班的日期
	char num_del[10];//删除航班的航班号
	char start_del[12];//删除航班的起始时间
	char end_del[12];//删除航班的结束时间
	U_AI.print_item(15);//打印航班删除标题
	cout << "请输入要删除航班的日期(如:20190430)" << endl;
	cin >> data_del;
	cout << "请输入要删除航班的航班号(如:MU5235)" << endl;
	cin >> num_del;
	cout << "请输入要删除航班的起飞地点(如:长春)" << endl;
	cin >> start_del;
	cout << "请输入要删除航班的降落地点(如:北京)" << endl;
	cin >> end_del;

	fi = flight;//赋值哨兵结点
	FlightInfo* tail= flight;//中间变量
	//fstream f_file;
	bool isdel = false;//是否成功删除
	/*f_file.open("flight.txt", ios::in);
	if (!f_file) {
		cout << "读取航班信息失败" << endl;
		return;
	}*/
	while (fi) {
		//f_file >> fi->data >> fi->num >> fi->start >> fi->end >> fi->time >> fi->at >> fi->count >> fi->price;

		if (strcmp(data_del, fi->data) == 0 && strcmp(num_del, fi->num) == 0
			&& strcmp(start_del, fi->start) == 0 && strcmp(end_del, fi->end) == 0) {

			tail->next = fi->next;
			delete fi;
			cout << "删除成功" << endl;
			isdel = true;
			break;
		}
		tail = fi;
		fi = fi->next;
		i++;
	}

	//f_file.close();

	if (isdel) {//如果删除成功
		save_fil();				//把新航班信息链表保存到文件

		--flight_num;			//航班数减1
		save_fn();				//保存航班总数

		cout << "\n正在进行航班信息删除..." << endl;
		Sleep(2000);
		system("cls");
		cout << "航班信息删除成功!" << endl;
		cout << "即将跳转至信息管理系统主页..." << endl;
		Sleep(2000);
		system("cls");
		U_AI.login_mf();
	}
	else {
		cout << "没有查询到相应航班删除失败，是否继续删除?(y/n)" << endl;
		char choice;
		cin >> choice;
		switch (choice)
		{
		case 'y':
			delete_fi();
			cout << "即将重新开始删除..." << endl;
			Sleep(2000);
			system("cls");
			break;
		default:
			cout << "即将跳转至信息管理系统主页..." << endl;
			Sleep(2000);
			system("cls");
			U_AI.login_mf();
			break;
		}
	}
}