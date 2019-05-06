#include"User.h"
#include"Flight.h"
#include"UserTicket.h"
#include<iostream>
#include<iomanip>
extern Flight* FLIGHT_WAIT;
//抢票时的等待信息相关操作
void Flight::loadall_wait(string filename) {
	fstream waitfile;
	waitfile.open(filename,ios::in);
	//FLIGHT_WAIT->waituser->next = new User::UserInfo();
	FLIGHT_WAIT->waitUS->next = new WaitUsers();
	//User::UserInfo* tempuser = FLIGHT_WAIT->waituser->next;
	Flight::WaitUsers* tempuser = FLIGHT_WAIT->waitUS->next;
	//waitfile >> seek;//跳过第一个用户的身份证
	//waitfile >> FLIGHT_WAIT->first_count;
	//waitfile.seekg(0);//文件重定向头部
	if (!waitfile) {
		waitfile.close();
		waitfile.open(filename, ios::out);
		waitfile.close();
	}
	else {
		for (int i = 0; i < wait_num; i++) {
			waitfile >> tempuser->id;//有哨兵节点
			waitfile >> tempuser->count;
			//tempuser->next = new User::UserInfo();
			tempuser->next = new Flight::WaitUsers();
			tempuser = tempuser->next;
		}
		waitfile.close();
	}
}

void Flight::saveall_wait(string filename) {
	fstream waitfile;
	waitfile.open(filename, ios::out);
	//User::UserInfo* tempuser = FLIGHT_WAIT->waituser->next;
	Flight::WaitUsers* tempuser = FLIGHT_WAIT->waitUS->next;
	while (tempuser) {
		waitfile << tempuser->id << tempuser->count;
		//waitfile << tempuser->count;
		tempuser = tempuser->next;
	}
	waitfile.close();
	//FLIGHT_WAIT = new Flight();
	//FLIGHT_WAIT->waituser = new User::UserInfo();
	FLIGHT_WAIT->waitUS = new Flight::WaitUsers();
}

void Flight::save_waitnum(string filename) {
	fstream waitfile;
	waitfile.open(filename, ios::out);
	waitfile << FLIGHT_WAIT->wait_num;
	waitfile.close();
	FLIGHT_WAIT->wait_num = 0;
}

void Flight::load_waitnum(string filename) {
	fstream waitfile;
	waitfile.open(filename, ios::in);
	if (!waitfile) {
		waitfile.close();
		waitfile.open(filename, ios::out);
		waitfile << 0;
		waitfile.close();
		waitfile.open(filename, ios::in);
	}
	waitfile >> FLIGHT_WAIT->wait_num;
	waitfile.close();
}