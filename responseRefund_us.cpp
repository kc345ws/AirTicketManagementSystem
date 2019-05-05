#include"Flight.h"
#include"User.h"
#include"UserTicket.h"
#include<iostream>
#include<iomanip>

//响应用户抢票
void User::responseRefund_us(string grab_data, string grab_num, string grab_time) {
	string filename = "FlightWaitOrder\\" + grab_data + "-" + grab_num + "-" + grab_time + ".txt";
	string filenumname = "FlightWaitOrder\\" + grab_data + "-" + grab_num + "-" + grab_time + "_num.txt";
	FLIGHT_WAIT->loadall_wait(filename);
	string userid = FLIGHT_WAIT->waituser->next->id;
	User::UserInfo* tempuser = FLIGHT_WAIT->waituser->next;
	FLIGHT_WAIT->waituser->next = tempuser->next;
	delete tempuser;
	FLIGHT_WAIT->saveall_wait(filename);
	FLIGHT_WAIT->load_waitnum(filenumname);
	FLIGHT_WAIT->wait_num--;
	FLIGHT_WAIT->save_waitnum(filenumname);

	LoginedUser->allus = new UserInfo();
	LoginedUser->allus->userTicket = new UserTicket();
	LoginedUser->allus->userTicket->load_num(userid);
	LoginedUser->allus->userTicket->load_ut(userid);//加载机票信息

	//LoginedUser->allus->userTicket->addTicket();

}