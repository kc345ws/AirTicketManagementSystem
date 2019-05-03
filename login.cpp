//用户和管理员登陆
#include "Flight.h"
#include "User.h"
#include <iostream>

using namespace std;

void User::print_login()	//打印登陆成功界面
{
	system("cls");
	cout<<"登陆成功!"<<endl;
	cout<<"即将进入机票管理系统,请稍后..."<<endl;
	Sleep(1000);
	if((mode=load_mode())==1)
		login_mf();
	else if(mode==0)
		login_uf();
}

void User::input_loop()		//循环选项函数
{
	char relogin;			//用于判断是否重新输入
	cout<<"是否重新输入!(y(是),n(否))!"<<endl;
	cin>>relogin;
	if(relogin!='Y' && relogin!='y' && relogin!='N' && relogin!='n')
	{
		cout<<"输入有误!请重新输入!"<<endl;
		Sleep(1000);
		system("cls");
		input_loop();
	}
	else if(relogin=='Y' || relogin=='y')
	{		
		system("cls");
		if((mode=load_mode())==1)
			login_m();  
		else if(mode==0)
			login_u();
	}
	else if(relogin=='N' || relogin=='n')
	{
		system("cls");
		mode=-1;
		save_mode();
		identify();
	}	
}

void User::login_m() 		//管理员登陆
{
	int success=0;				//用于判断是否登陆成功的全局变量

	system("cls");
	mode=1;
	save_mode();
	if((judge=load_judge())==0)	//判断是否是首次使用该系统
	{
		print_item(3);
		input_linfo();
	}
	else		/*如果不是首次登录该系统，直接输入管理员姓名和密码即可*/
	{
		print_item(4);
		input_linfo();
	}
	if(strcmp(mg->id,"admin")==0 && strcmp(mg->passport,"admin")==0)
	{
		success = 1;
		++judge;
		save_judge();
//		save_lfui();
		print_login();
	}
	if(success==0)	//登录失败
	{
		system("cls");
		cout<<"输入用户名或密码有误!"<<endl;
		input_loop();
	}
}
	   
void User::login_u()		//用户登录
{
	int success=0;			//用于判断是否登陆成功的全局变量
	system("cls");
	mode=0;
	save_mode();
	if((user_num=load_un())==0)	//判断是否有用户信息
	{
		print_item(5);
		Sleep(1000);
		system("cls");
		cout<<"即将跳转至主菜单进行注册..."<<endl;
		Sleep(1000);
		home();
	}
	else		//有用户信息时，继续以下操作
	{
		print_item(6);
		input_linfo();
		load_list();
		ui=user->next;
		while(ui!=NULL)
		{
			if(strcmp(mg->id,ui->id)==0 && strcmp(mg->passport,ui->passport)==0)	//存在该用户的信息时，把success置1
			{
				success=1;

				//登陆帐号设置输入的账号
				LoginedUser->mg = mg;
				//LoginedUser->mg->userTicket = mg->userTicket;
				break;
			}
			ui=ui->next;
		}
	}
	if(success==1)	//success为1时,跳转至机票管理系统
	{
		print_login();
	}
	else			//success为0时的相应操作
	{
		system("cls");
		cout<<"输入用户名或密码有误!"<<endl;
		Sleep(1000);
		input_loop();
	}
}