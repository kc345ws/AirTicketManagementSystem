#include "Flight.h"
#include "User.h"
#include <iostream>
#include<Windows.h>
extern User* LoginedUser = new User();
using namespace std;

int main()
{
	SetConsoleTitle("��Ʊ��Ϣ����ϵͳ");
	CreateDirectory("Users", NULL);//�����ļ���
	User u;
	u.Start_screen();
}
