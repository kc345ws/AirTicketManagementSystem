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
	SetConsoleTitle("��Ʊ��Ϣ����ϵͳ");
	CreateDirectory("Users", NULL);//�����û���Ʊ��Ϣ�ļ���
	CreateDirectory("FlightWaitOrder", NULL);//������Ʊ���������ļ���
	ALLCITY->load_city();
	User u;
	u.Start_screen();
}
