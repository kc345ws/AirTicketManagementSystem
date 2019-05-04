#include"Flight.h"
#include"User.h"
#include<iostream>

void isContinue(char ch);
char issucced();
void isWrong();
void changechar(char ch[], int changeobjID, Flight::FlightInfo* info);
//修改航班信息
void Flight::change_fi() {
	system("cls");
	User U_AI;
	browse_fi(false);
	char data_del[9];//修改航班的日期
	char num_del[10];//修改航班的航班号
	char start_del[12];//修改航班的起始时间
	char end_del[12];//修改航班的结束时间

	U_AI.print_item(16);//打印航班修改标题
	cout << "请输入要修改航班的日期(如:20190430)" << endl;
	cin >> data_del;
	cout << "请输入要修改航班的航班号(如:MU5235)" << endl;
	cin >> num_del;
	cout << "请输入要修改航班的起飞地点(如:长春)" << endl;
	cin >> start_del;
	cout << "请输入要修改航班的降落地点(如:北京)" << endl;
	cin >> end_del;

	fi = flight;//赋值哨兵结点
	FlightInfo* tail = flight;//中间变量
	bool ischange = false;//是否成功修改

	char changedinfo[20];
	int changedcount;
	double changeprice;
	FlightInfo* saveinfo = fi;//用于执行完save_fil()后恢复fi指针
	while (fi) {

		if (strcmp(data_del, fi->data) == 0 && strcmp(num_del, fi->num) == 0
			&& strcmp(start_del, fi->start) == 0 && strcmp(end_del, fi->end) == 0) {

			ischange = true;
			int choice;
			char yorno;
			while (1) {
				U_AI.print_item(17);//打印航班修改操作界面
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "请输入要修改的航班日期" << endl;
					cin >> changedinfo;
					if (changedinfo != nullptr) {
						changechar(changedinfo, 1,fi);
						save_fil();
						fi = saveinfo;
						yorno = issucced();
						isContinue(yorno);
					}
					else {
						isWrong();
					}
					break;
				case 2:
					cout << "请输入要修改的航班号" << endl;
					cin >> changedinfo;
					if (changedinfo != nullptr) {
						changechar(changedinfo, 2, fi);
						save_fil();
						fi = saveinfo;
						yorno = issucced();
						isContinue(yorno);
					}
					else {
						isWrong();
					}
					break;
				case 3:
					cout << "请输入要修改的起飞地点" << endl;
					cin >> changedinfo;
					if (changedinfo != nullptr) {
						changechar(changedinfo, 3, fi);
						save_fil();
						fi = saveinfo;
						yorno = issucced();
						isContinue(yorno);
					}
					else {
						isWrong();
					}
					break;
				case 4:
					cout << "请输入要修改的降落地点" << endl;
					cin >> changedinfo;
					if (changedinfo != nullptr) {
						changechar(changedinfo, 4, fi);
						save_fil();
						fi = saveinfo;
						yorno = issucced();
						isContinue(yorno);
					}
					else {
						isWrong();
					}
					break;
				case 5:
					cout << "请输入要修改的起降时间" << endl;
					cin >> changedinfo;
					if (changedinfo != nullptr) {
						changechar(changedinfo, 5, fi);
						save_fil();
						fi = saveinfo;
						yorno = issucced();
						isContinue(yorno);
					}
					else {
						isWrong();
					}
					break;
				case 6:
					cout << "请输入要修改的预计飞行时间" << endl;
					cin >> changedinfo;
					if (changedinfo != nullptr) {
						changechar(changedinfo, 6, fi);
						save_fil();
						fi = saveinfo;
						yorno = issucced();
						isContinue(yorno);
					}
					else {
						isWrong();
					}
					break;
				case 7:
					cout << "请输入要修改的预计剩余票数" << endl;
					cin >> changedcount;
					if (changedinfo != nullptr) {
						fi->count = changedcount;
						save_fil();
						fi = saveinfo;
						yorno = issucced();
						isContinue(yorno);
					}
					else {
						isWrong();
					}
					break;
				case 8:
					cout << "请输入要修改的票价" << endl;
					cin >> changeprice;
					if (changedinfo != nullptr) {
						fi->price = changeprice;
						save_fil();
						fi = saveinfo;
						yorno = issucced();
						isContinue(yorno);
					}
					else {
						isWrong();
					}
					break;
				case 0:
					U_AI.login_mf();
					break;
				default:
					isWrong();
				}
			}
			break;
		}
		tail = fi;
		fi = fi->next;
		saveinfo = fi;
	}

	if (ischange) {//如果修改成功
		save_fil();				//把新航班信息链表保存到文件

		cout << "\n正在进行航班信息修改..." << endl;
		Sleep(2000);
		system("cls");
		cout << "航班信息修改成功!" << endl;
		cout << "即将跳转至信息管理系统主页..." << endl;
		Sleep(2000);
		system("cls");
		U_AI.login_mf();
	}
	else {
		cout << "没有查询到相应航班修改失败，是否继续修改?(y/n)" << endl;
		char choice;
		cin >> choice;
		switch (choice)
		{
		case 'y':
			change_fi();
			cout << "即将重新开始修改..." << endl;
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

void isContinue(char ch) {//是否继续修改
	User U_AI;
	switch (ch) {
	case 'y':
		break;
	default:
		cout << "即将返回信息管理界面..." << endl;
		Sleep(2000);
		U_AI.login_mf();
		break;
	}
}

void isWrong() {//如果修改失败
	cout << "输入信息错误" << endl;
	cout << "是否继续修改?(y/n)" << endl;
	char yorno;
	cin >> yorno;
	isContinue(yorno);
}

char issucced() {//如果修改成功
	char yorno;
	cout << "修改成功" << endl;
	cout << "是否继续修改?(y/n)" << endl;
	cin >> yorno;
	return yorno;
}

void changechar(char ch[],int changeobjID, Flight::FlightInfo* info) {//修改char类型的数据

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
}

void Flight::change_finum(int num, char data_ch[], char num_ch[], char time_ch[]) {
	system("cls");
	load_fil();
	fi = flight->next;//赋值哨兵结点
	FlightInfo* tail = flight;//中间变量
	bool ischange = false;//是否成功修改

	char changedinfo[20];
	int changedcount;
	double changeprice;
	FlightInfo* saveinfo = fi;//用于执行完save_fil()后恢复fi指针


	while (fi) {

		if (strcmp(data_ch, fi->data) == 0 && strcmp(num_ch, fi->num) == 0
			&& strcmp(time_ch, fi->time) == 0) {
			ischange = true;
			fi->count += num;//增加用户退票的数量
			break;
		}
		tail = fi;
		fi = fi->next;
		saveinfo = fi;
	}

	if (ischange) {//如果修改成功
		save_fil();	//把新航班信息链表保存到文件
	}
}
