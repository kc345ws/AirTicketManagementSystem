#pragma once
#ifndef FLIGHT
#define FLIGHT



#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <conio.h>
#include <windows.h>

#include"User.h"
using namespace std;

class Flight
{
//public:
public :
	struct FlightInfo
	{
		char data[9];				//航班日期
		char num[10];				//航班号
		char start[12];				//起始地
		char end[12];				//目的地
		char time[16];				//起降时间
		char at[6];					//飞行时间
		int count;					//票数
		double price;				//票价

		string transit;				//中转地
		int transittime;			//中转时间
		struct FlightInfo *next;	//指向下一个航班信息
		struct FlightInfo *prior;	//指向前一个航班信息

	}*flight,*fi,*fn,*fg;

	struct WaitUsers {
		int id;
		int count;
		WaitUsers* next;
	};
//flight初始化哨兵结点 fi从文件读取时创建的 fn输入航班信息时创建的 
public:	
	int flight_num;					//所有航班数
	//User::UserInfo* waituser;		//抢票的用户队列
	WaitUsers* waitUS;				//抢票的用户队列
	int wait_num;					//该航班抢票用户数量
	//int first_count;				//第一个用户抢票的数量
	//int* grabnum;					//抢票数量

	public:
		friend class UserTicket;
		Flight();
		~Flight();
		void destroy(FlightInfo *&F);					//释放链表

		void init_fnf();								//初始化记录数量的文件user_num.txt
		void current_time();							//当前时间
		void input_fi();								//输入航班信息
		void input_sfi(int note,int note1,int note2);	//输入需查找的航班信息
	//	void save_fitf(FlightInfo *userinfo);			//保存航班信息到文件
		void load_fil();								//把文件中航班信息装载到链表
		void save_fil();								//保存链表中航班信息到文件中
		void Inser_fi();								//把航班信息按日期顺序插入链表

		void add_fi();			//添加航班信息
		//void browse_fi(); 		//浏览航班信息
		void browse_fi(bool isback); 		//浏览航班信息
		//	void save_fi();		//保护航班信息,防止信息丢失
		//	bool load_fi();		//读取航班信息
		void sort_byfp();		//全部航班按票价降序显示
		void search_fi();		//按航班号查找航班信息
		FlightInfo *getrefund_fi(string data_re,string num_re, string time_re);	//获得退票航班信息
		void order();			//订票

		void delete_fi();//删除航班信息
		void delete_fi(char data_del[], char num_del[], char start_del[], char end_del[]);
		void change_fi();//修改航班信息
		void change_finum(int num, char data_ch[], char num_ch[], char time_ch[]);//用户退票时修改机票数量

		void save_fn();			//保存航班总数
		int load_fn();			//读取航班总数
		//void save_lfui1();		//保存登录系统的用户信息
		//int load_lfui1();		//读取登录系统的用户信息
		//	void load_bfi();	//读取二进制形式保存的航班信息文件内容


		FlightInfo*getFlightinfo() { return fi; };
		void showzeroTicket_fl();				//显示已经售罄的航班信息信息
		void loadall_wait(string filename);			//读取某个航班的抢票队列信息
		void saveall_wait(string filename);			//保存某个航班的抢票队列信息
		void load_waitnum(string filename);			//加载等待抢票的用户数量
		void save_waitnum(string filename);			//保存等待抢票的用户数量
};
#endif // !1
extern Flight* FLIGHT_WAIT;