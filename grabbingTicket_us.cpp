#include"Flight.h"
#include"User.h"
#include"UserTicket.h"
#include<iostream>
#include<iomanip>
#include<vector>
extern Flight* FLIGHT_WAIT;
void User::grabbingTicket_us() {//�û���Ʊ
	User UI;
	Flight F;
	string grab_data;//Ҫ��Ʊ���������
	string grab_num;//Ҫ��Ʊ����ĺ����
	string grab_time;//Ҫ��Ʊ�������ʱ��
	string grab_count;//��Ʊ����
	bool isfound = false;
	F.load_fil();
	Flight::FlightInfo* tempinfo = F.flight->next;
	system("cls");
	UI.print_item(24);
	F.showzeroTicket_fl();//��ʾ��������������Ϣ
	cout << "������Ҫ��Ʊ���������" << endl;
	cin >> grab_data;
	cout << "������Ҫ��Ʊ����ĺ����" << endl;
	cin >> grab_num;
	cout << "������Ҫ��Ʊ�������ʱ��" << endl;
	cin >> grab_time;

	while (tempinfo) {
		if (tempinfo->data == grab_data && tempinfo->num == grab_num && tempinfo->time == grab_time &&tempinfo->count==0) {
			cout << "��������Ʊ����" << endl;
			cin >> grab_count;
			//string filename = "Users\\" + id + "\\mytickets.txt";
			
			string::iterator it = grab_time.begin();
			for (it; it != grab_time.end(); it++) {
				if (*it == ':') {
					grab_time.erase(it);
				}
			}
			fstream flightwait;//����Ʊ�ȴ�����д����Ϣ
			string userid = LoginedUser->mg->id;
			string filename = "FlightWaitOrder\\" + grab_data + "_" + grab_num + "_" + grab_time + ".txt";
			string filenumname = "FlightWaitOrder\\" + grab_data + "_" + grab_num + "_" + grab_time + "_num.txt";
			flightwait.open(filename, ios::app);//׷��д��
			//flightwait.open(filename, ios::out);
			if (!flightwait) {
				flightwait.close();
				flightwait.open(filename, ios::out);
				flightwait.close();
				flightwait.open(filename, ios::app);
			}
			flightwait << LoginedUser->mg->id << " " << grab_count << endl;//д���û������֤�ź�����
			flightwait.close();
			isfound = true;

			FLIGHT_WAIT->load_waitnum(filenumname);//������Ʊ�û�����
			FLIGHT_WAIT->wait_num++;
			FLIGHT_WAIT->save_waitnum(filenumname);
			break;
		}
		tempinfo = tempinfo->next;
	}

	if (isfound) {
		cout << "��Ʊ�ɹ���������Ʊʱ���Զ�����" << endl;
		cout << "�����������������" << endl;
		getchar();
		getchar();
		UI.login_uf();
	}
	else {
		cout << "��Ʊʧ�ܣ�û�д˺����˺�������Ʊ" << endl;
		cout << "�����������������" << endl;
		getchar();
		getchar();
		UI.login_uf();
	}
}	