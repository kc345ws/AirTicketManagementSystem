#include "Flight.h"
#include "User.h"
#include <iostream>
#include<Windows.h>
extern User* LoginedUser = new User();
extern Flight* FLIGHT_WAIT = new Flight();
using namespace std;

int main()
{
	SetConsoleTitle("��Ʊ��Ϣ����ϵͳ");
	CreateDirectory("Users", NULL);//�����û���Ʊ��Ϣ�ļ���
	CreateDirectory("FlightWaitOrder", NULL);//������Ʊ���������ļ���
	User u;
	u.Start_screen();
}
