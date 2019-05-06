#include"Flight.h"

using namespace std;

Flight::FlightInfo* Flight::getrefund_fi(string data_re, string num_re, string time_re) {//获得退票的航班信息
	int i;
	int success = 0;
	char ch;
	User U_AI;
	char str[5], des[5];
	char str1[5];

	system("cls");


	load_fil();

	

	fn = new FlightInfo;
	cin.sync();
	for (int i = 0; i < data_re.length(); i++) {
		fn->data[i] = data_re[i];
	}
	for (int i = 0; i < num_re.length(); i++) {
		fn->num[i] = num_re[i];
	}
	for (int i = 0; i < time_re.length(); i++) {
		fn->time[i] = time_re[i];
	}

	fi = flight->next;

	while (fi != NULL)
	{
		if (fi->data == data_re&&fi->num == num_re&&fi->time== time_re)
		{
			return fi;
		}
		fi = fi->next;
	}
	return nullptr;
}