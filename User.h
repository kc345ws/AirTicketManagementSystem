#pragma once
#ifndef USER
#define USER



#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;


//LoginedUser为登陆的用户

class User
{
//public:
public:
	//每一个用户的信息
	struct UserInfo				//用户信息
	{
		char name[32];			//用户姓名
		char passport[16];		//用户登录密码
		char sex[6];			//用户性别
		int age;				//用户年龄
		char id[19];			//用户身份证号
		struct UserInfo* next;	//指向下一个用户信息

		class UserTicket* userTicket;		//用户机票
	}*user, * ui, * mi, * mg, * ug, *allus;
	//user为链表哨兵节点 mg用户登陆时输入 ui用来遍历和注册时 waituser等待抢票用户

	//class UserTicket* userTicket;		//用户机票
public:
	int user_num;				//记录总用户数
	int mode;					//登陆模式记录
	int judge;					//用于判断是否管理员首次登陆 (登陆次数)

public:
		User();									//构造函数
		~User();								//析构函数
		void Destroy(UserInfo *&U);				//释放链表

		void init_file();						//初始化文件
		void Start_screen();					//开始界面
		void End_screen();						//结束界面
		char choose();							//输入选项
		void print_item(int k);					//打印操作标题
		void input_linfo();						//输入登录信息
		void input_uinfo();						//输入用户信息

		void input_loop();						//循环选项函数
		void load_list();						//把文件信息装载到链表
		void save_list();						//保存链表信息到文件
		void save_uitf();						//保存用户信息到文件

		void home(); 			//主界面
		void identify(); 		//用户及管理员登录选择
		void login_m(); 		//管理员登陆
		void login_u();			//用户登录
		void print_login();		//打印登陆成功界面
		void login_mf();		//管理员登陆机票管理系统
		void login_uf();		//用户登陆机票管理系统
		void create_uif();		//创建用户信息文件

		void save_mode();		//保存登录模式和登陆次数
		int load_mode();		//读取登陆模式和登陆次数
		void save_un();			//保存用户总人数
		int load_un();			//读取用户总人数
		void save_judge();		//保存登陆次数
		int load_judge();		//读取登陆次数
//		void save_lfui();		//保存登录系统的用户信息
//		int load_lfui();		//读取登录系统的用户信息


		void issueDelay_m();	//管理员发布航班延误通知
		void issueCancel_m();	//管理员发布航班取消通知
		void RecommendFlight();//航班延误后推荐
		void RecommendFlightCancel();//航班取消后的推荐航班
		User::UserInfo *findUser(string id);		//查找某个用户
		void refundTicket_us();	//用户退票
		void grabbingTicket_us();	//用户抢票
		void responseRefund_us(string grab_data,string grab_num,string grab_time);	//当有用户退票成功时响应用户抢票
};
#endif // !USER
extern User* LoginedUser;
//LoginedUser为登陆的用户
