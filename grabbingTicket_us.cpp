#include"Flight.h"
#include"User.h"
#include"UserTicket.h"
#include<iostream>
#include<iomanip>
extern Flight* FLIGHT_WAIT;
void User::grabbingTicket_us() {//用户抢票
	User UI;
	Flight F;
	string grab_data;//要抢票航班的日期
	string grab_num;//要抢票航班的航班号
	string grab_time;//要抢票航班的起降时间
	string grab_count;//抢票数量
	bool isfound = false;
	F.load_fil();
	Flight::FlightInfo* tempinfo = F.flight->next;
	system("cls");
	UI.print_item(24);
	F.showzeroTicket_fl();//显示所有售罄航班信息
	cout << "请输入要抢票航班的日期" << endl;
	cin >> grab_data;
	cout << "请输入要抢票航班的航班号" << endl;
	cin >> grab_num;
	cout << "请输入要抢票航班的起降时间" << endl;
	cin >> grab_time;

	while (tempinfo) {
		if (tempinfo->data == grab_data && tempinfo->num == grab_num && tempinfo->time == grab_time &&tempinfo->count==0) {
			cout << "请输入抢票数量" << endl;
			cin >> grab_count;
			fstream flightwait;//向抢票等待队列写入信息
			string userid = LoginedUser->mg->id;
			string filename = "FlightWaitOrder\\" + grab_data + "-" + grab_num + "-" + grab_time + ".txt";
			string filenumname = "FlightWaitOrder\\" + grab_data + "-" + grab_num + "-" + grab_time + "_num.txt";
			flightwait.open(filename, ios::app);//追加写入
			flightwait << LoginedUser->mg->id << " " << grab_count << endl;//写入用户的身份证号和数量
			flightwait.close();
			isfound = true;

			FLIGHT_WAIT->load_waitnum(filenumname);//增加抢票用户数量
			FLIGHT_WAIT->wait_num++;
			FLIGHT_WAIT->save_waitnum(filenumname);
			break;
		}
		tempinfo = tempinfo->next;
	}

	if (isfound) {
		cout << "抢票成功，当有余票时将自动购买" << endl;
		cout << "按任意键返回主界面" << endl;
		getchar();
		getchar();
		UI.login_uf();
	}
	else {
		cout << "抢票失败，没有此航班或此航班有余票" << endl;
		cout << "按任意键返回主界面" << endl;
		getchar();
		getchar();
		UI.login_uf();
	}
}	