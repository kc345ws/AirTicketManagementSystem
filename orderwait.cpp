#include"User.h"
#include"Flight.h"
#include"UserTicket.h"
#include<iostream>
#include<iomanip>
extern Flight* FLIGHT_WAIT;
//��Ʊʱ�ĵȴ���Ϣ��ز���
void Flight::loadall_wait(string filename) {
	fstream waitfile;
	waitfile.open(filename,ios::in);
	FLIGHT_WAIT->waituser->next = new User::UserInfo();
	User::UserInfo* tempuser = FLIGHT_WAIT->waituser->next;

	if (!waitfile) {
		waitfile.close();
		waitfile.open(filename, ios::out);
		waitfile.close();
	}
	else {
		for (int i = 0; i < wait_num; i++) {
			waitfile >> tempuser->id;//���ڱ��ڵ�
			tempuser->next = new User::UserInfo();
			tempuser = tempuser->next;
		}
		waitfile.close();
	}
}

void Flight::saveall_wait(string filename) {
	fstream waitfile;
	waitfile.open(filename, ios::out);
	User::UserInfo* tempuser = FLIGHT_WAIT->waituser->next;
	while (tempuser) {
		waitfile << tempuser->id;
		tempuser = tempuser->next;
	}
	waitfile.close();
	//FLIGHT_WAIT = new Flight();
	FLIGHT_WAIT->waituser = new User::UserInfo();
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