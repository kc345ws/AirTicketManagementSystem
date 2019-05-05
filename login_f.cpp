//登陆成功后的操作界面
#include "Flight.h"
#include "User.h"
#include"UserTicket.h"
#include <iostream>

using namespace std;

void User::login_mf()	//管理员登陆机票管理系统
{
	Flight F;
	User US;

	system("cls");
	print_item(8);//打印管理员操作界面
	do
	{
		switch(choose())
		{
		case '1':F.add_fi();//添加航班信息
			break;
		case '2':F.browse_fi(true);
			break;
		case '3':F.search_fi();
			break;
		case '4':F.sort_byfp();
			break;
		//case '5':F.order();
			//break;
		case '5':F.delete_fi();//删除航班信息
			break;
		case '6':F.change_fi();//修改航班信息
			break;
		case '7':US.issueDelay_m();//发布航班延误
			break;
		case '8':US.issueCancel_m();//发布航班取消
			break;
		case '0':cout<<"即将退出'机票管理系统',并跳转到主界面..."<<endl;
			Sleep(1000);
			system("cls");
			home();
			break;                          
		default:cout<<"输入有误!请重新输入!"<<endl;
			Sleep(1000);
			system("cls");
			login_mf();
		}
	}while(choose()!=0);
}

void User::login_uf()	//用户登陆机票管理系统
{
	Flight F;

	system("cls");
	print_item(9);
	do
	{
		switch(choose())
		{
		case '1':F.browse_fi(true);
			break;
		case '2':F.search_fi();
			break;
		case '3':F.sort_byfp();
			break;
		case '4':F.order();
			break;
		case '5':LoginedUser->mg->userTicket->showTickets(false);
			break;
		case '6':LoginedUser->mg->userTicket->showDelay_ut();
			break;
		case '7':LoginedUser->mg->userTicket->showCancel_ut();
			break;
		case '8':refundTicket_us();//退票
			break;
		case '0':cout<<"即将退出'机票管理系统',并跳转到主界面..."<<endl;
			Sleep(1000);
			system("cls");
			home();
			break;
		default:cout<<"输入有误!请重新输入!"<<endl;
			Sleep(1000);
			system("cls");
			login_uf();
		}
	}while(choose()!=0);
}