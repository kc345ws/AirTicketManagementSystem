#include"City.h"
#include<iostream>
#include<fstream>
#include"User.h"
using namespace std;

City::City()
{
	sentine = new CityInfo();
	last = sentine;
	newcity = sentine;
	sentine  -> next = nullptr;

	citynumber = 0;
	citycount = 0;

	cnsentine = new CityName();
	cnsentine -> next = nullptr;
}

City::~City()
{
	tempcityinfo = sentine;
	CityInfo* temp = tempcityinfo;
	while (tempcityinfo) {
		tempcityinfo = tempcityinfo->next;
		delete temp;
		temp = tempcityinfo;
	}
}

void City::add_city() {
	User UI;
	system("CLS");
	newcity = last;
	newcity->next = new CityInfo();
	newcity = newcity->next;
	cout << "请输入起飞城市" << endl;
	cin >> newcity->start;
	cout << "请输入降落城市" << endl;
	cin >> newcity->end;
	cout << "请输入两城市之间的距离" << endl;
	cin >> newcity->distance;
	newcity->next = nullptr;
	cout << "添加成功" << endl;

	last = newcity;
	citynumber++;

	save_city();
	save_citynum();
	getallcityname();
	getcitycount();
	
	GLCT = new Graph_List_City();

	cout << "按任意键返回" << endl;
	getchar();
	getchar();
	UI.login_mf();
}

void City::save_city() {
	string filename = "city.txt";
	fstream cityfile;
	cityfile.open(filename, ios::out);

	tempcityinfo = sentine->next;
	while (tempcityinfo) {
		cityfile << tempcityinfo->start << " " << tempcityinfo->end << " " << tempcityinfo->distance << endl;

		tempcityinfo = tempcityinfo->next;
	}
	cityfile.close();
}

void City::load_city() {
	load_citynum();

	string filename = "city.txt";
	fstream cityfile;
	cityfile.open(filename, ios::in);

	tempcityinfo = sentine;
	if (!cityfile) {
		cityfile.close();
		cityfile.open(filename, ios::out);
		cityfile.close();
		cityfile.open(filename, ios::in);
	}

	for (int i = 0; i < citynumber; i++) {
		tempcityinfo->next = new CityInfo();
		tempcityinfo = tempcityinfo->next;
		cityfile >> tempcityinfo->start >> tempcityinfo->end >> tempcityinfo->distance;
	}
	cityfile.close();
	last = tempcityinfo;

	getallcityname();
	getcitycount();
}

void City::save_citynum() {
	string filename = "citynumber.txt";
	fstream citynumberfile;
	citynumberfile.open(filename, ios::out);
	citynumberfile << citynumber;
	citynumberfile.close();
}

void City::load_citynum() {
	string filename = "citynumber.txt";
	fstream citynumberfile;
	citynumberfile.open(filename, ios::in);
	if (!citynumberfile) {
		citynumberfile.close();
		citynumberfile.open(filename, ios::out);
		citynumberfile << 0;
		citynumberfile.close();
		citynumberfile.open(filename, ios::in);
	}
	citynumberfile >> citynumber;
	citynumberfile.close();
}

void City::getallcityname()
{
	//load_city();

	tempcityinfo = sentine->next;
	cntp = cnsentine;
	//CityInfo* temp = sentine->next;
	bool isrepeat = false;//是否重复
	//int count = 0;
	while (tempcityinfo) {
		cntp->next = new CityName();
		cntp = cntp->next;
		cntp->name = tempcityinfo->start;
		cntp->next = new CityName();
		cntp = cntp->next;
		cntp->name = tempcityinfo->end;
		cntp->next = nullptr;

		tempcityinfo = tempcityinfo->next;
	}

	cntp = cnsentine->next;
	CityName* temp;
	CityName* front;
	while (cntp) {//删除重复名称
		temp = cntp->next;
		front = cntp;
		while (temp) {
			if (temp->name == cntp->name) {
				front->next = temp->next;
				delete temp;
				temp = front->next;
			}
			else {
				front = temp;
				if (temp) {
					temp = temp->next;
				}
				else {
					temp = nullptr;
				}
			}
		}
		cntp = cntp->next;
	}
}

void City::getcitycount()
{
	citycount = 0;
	cntp = cnsentine->next;
	while (cntp)
	{
		citycount++;
		cntp = cntp->next;
	}
}