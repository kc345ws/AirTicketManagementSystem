#include "Flight.h"
#include "User.h"
#include"City.h"
#include <iostream>
#include<Windows.h>
extern User* LoginedUser = new User();
extern Flight* FLIGHT_WAIT = new Flight();
extern City* ALLCITY = new City();
extern Graph_List_City* GLCT = new Graph_List_City();
using namespace std;

int main()
{
	SetConsoleTitle("机票信息管理系统");
	CreateDirectory("Users", NULL);//创建用户机票信息文件夹
	CreateDirectory("FlightWaitOrder", NULL);//创建机票抢购队列文件夹
	ALLCITY->load_city();
	User u;
	u.Start_screen();
}
