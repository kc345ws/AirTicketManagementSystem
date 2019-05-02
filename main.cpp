#include "Flight.h"
#include "User.h"
#include <iostream>
#include<Windows.h>
extern User* LoginedUser = new User();
using namespace std;

int main()
{
	SetConsoleTitle("机票信息管理系统");
	CreateDirectory("Users", NULL);//创建文件夹
	User u;
	u.Start_screen();
}
