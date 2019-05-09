#include"Flight.h"
#include"User.h"
#include"UserTicket.h"
#include<iostream>
#include<iomanip>

//响应用户抢票
void User::responseRefund_us(string grab_data, string grab_num, string grab_time) {
	string filetime = grab_time;
	string::iterator it = filetime.begin();
	for (it; it != filetime.end(); it++) {
		if (*it == ':') {
			filetime.erase(it);
		}
	}
	string filename = "FlightWaitOrder\\" + grab_data + "_" + grab_num + "_" + filetime + ".txt";
	string filenumname = "FlightWaitOrder\\" + grab_data + "_" + grab_num + "_" + filetime + "_num.txt";
	Flight F;
	int grabnum;//用户抢票数量
	FLIGHT_WAIT->load_waitnum(filenumname);
	FLIGHT_WAIT->loadall_wait(filename);
	//string userid = FLIGHT_WAIT->waituser->next->id;
	string userid = to_string(FLIGHT_WAIT->waitUS->next->id);
	grabnum = FLIGHT_WAIT->waitUS->next->count;
	//User::UserInfo* tempuser = FLIGHT_WAIT->waituser->next;
	Flight::WaitUsers* tempuser = FLIGHT_WAIT->waitUS->next;
	//FLIGHT_WAIT->waituser->next = tempuser->next;
	FLIGHT_WAIT->waitUS->next = tempuser->next;
	delete tempuser;
	FLIGHT_WAIT->load_waitnum(filenumname);
	FLIGHT_WAIT->wait_num--;
	FLIGHT_WAIT->save_waitnum(filenumname);
	FLIGHT_WAIT->saveall_wait(filename);

	LoginedUser->allus = new UserInfo();
	LoginedUser->allus->userTicket = new UserTicket();
	LoginedUser->allus->userTicket->load_num(userid);
	LoginedUser->allus->userTicket->load_ut(userid);//加载机票信息

	//LoginedUser->allus->userTicket->addTicket();

	//向抢票用户的机票信息中写入退票航班的信息

	Flight::FlightInfo* refundfiinfo = F.getrefund_fi(grab_data, grab_num, grab_time);

	string userflightfilename = "Users\\" + userid + "\\" + "mytickets.txt";
	fstream userflightfile;
	userflightfile.open(userflightfilename, ios::app);
	/*myticketsfile << tempticket->data << "\t" << tempticket->num << "\t" << tempticket->start << "\t" << tempticket->end << "\t"
		<< tempticket->time << "\t" << tempticket->at << "\t" << tempticket->price << "\t" << tempticket->Ticketcount << "\t" <<
		tempticket->buytime << "\t" << tempticket->isDelay << "\t" << tempticket->isCancel << "\t" << tempticket->transit <<
		"\t" << tempticket->transittime << endl;*/
		//添加购买时间
	time_t  t;
	t = time(NULL);
	struct tm* local;
	local = localtime(&t);
	t = time(NULL);
	local = localtime(&t);
	string currenttime = std::to_string(local->tm_year + 1900) + "-" + std::to_string(local->tm_mon + 1)
		+ "-" + to_string(local->tm_mday) + "/" + to_string(local->tm_hour) + ":" + to_string(local->tm_min) +
		":" + to_string(local->tm_sec);

	userflightfile << refundfiinfo->data << "\t" << refundfiinfo->num << "\t" << refundfiinfo->start << "\t" << refundfiinfo->end << "\t" <<
		refundfiinfo->time << "\t" << refundfiinfo->at << "\t" << refundfiinfo->price << "\t" << grabnum << "\t" << currenttime << "\t"
		<< "\t" << 0 << "\t" << 0 << "\t" << refundfiinfo->transit << "\t" << refundfiinfo->transittime << endl;

		userflightfile.close();
	//更新抢票用户机票购买次数
	string userflightnumfilename = "Users\\" + userid + "\\" + "tickets_num.txt";
	fstream userflightnumfile;
	userflightnumfile.open(userflightnumfilename, ios::in);
	if (!userflightnumfile) {
		userflightnumfile.close();
		userflightnumfile.open(userflightnumfilename, ios::out);
		userflightnumfile << 0;
		userflightnumfile.close();
		userflightnumfile.open(userflightnumfilename, ios::in);
	}

	int userTicketnum = 0;
	userflightnumfile >> userTicketnum;
	userflightnumfile.close();
	userTicketnum++;

	userflightnumfile.open(userflightnumfilename, ios::out);
	userflightnumfile << userTicketnum;
	userflightnumfile.close();

	//更新航班票数
	char grab_data_ch[20];
	char grab_num_ch[20];
	char grab_time_ch[20];

	for (int i = 0; i < grab_data.length(); i++) {
		grab_data_ch[i] = grab_data[i];
	}
	grab_data_ch[grab_data.length()] = '\0';//必须手动赋值结束字符

	for (int i = 0; i < grab_num.length(); i++) {
		grab_num_ch[i] = grab_num[i];
	}
	grab_num_ch[grab_num.length()] = '\0';

	for (int i = 0; i < grab_time.length(); i++) {
		grab_time_ch[i] = grab_time[i];
	}
	grab_time_ch[grab_time.length()] = '\0';

	F.change_finum(-1, grab_data_ch, grab_num_ch, grab_time_ch);
	F.save_fil();
}