#pragma once
#ifndef USERTICKET
#define USERTICKET

#include"Flight.h"
#include"User.h"
class UserTicket {
public:
	//用户每一张机票的信息
	struct Ticket {
		char data[9];				//航班日期
		char num[10];				//航班号
		char start[12];				//起始地
		char end[12];				//目的地
		char time[16];				//起降时间
		char at[6];					//飞行时间

		char buytime[128];			//购买机票的时间
		double price;				//票价
		int Ticketcount;			//该机票的购买张数
		bool isDelay;               //是否延误
		bool isCancel;              //是否取消航班
		string transit;				//中转地
		int transittime;			//中转时间
		Flight* recommendFlight;		//延误或者取消后推荐的航班
		Ticket* next;				//指向下一张机票信息
		Ticket* prior;				//指向前一张机票信息
	}*sentine, * temp, * lastticket;
	//sentine哨兵节点 temp用来遍历 lastticket最后一张机票
	int Ticketnum;					//机票购买次数
public:
	//friend class Flight;
	//int static Tickernum;			//机票总数
	UserTicket();
	~UserTicket();
	void Destroy();					//析构时释放整个链表
	void addTicket(Flight::FlightInfo* info, int ticnum);//订票时自动将机票信息添加到用户机票类中
	void init_ut();					//初始化用户机票信息
	void load_ut();					//加载用户机票信息
	void load_ut(string id);		//加载用户机票信息
	void save_ut();					//保存用户机票信息
	void save_ut(string id);		//保存用户机票信息
	void saveall_ut();				//保存所有用户信息
	void load_num();				//加载购买次数
	void load_num(string id);		//加载用户机票
	void showTickets(bool isback);	//显示购买机票信息
	void change_ut(bool info);	//更改用户机票延误取消信息
	void change_ut(string id, bool info);	//更改用户机票信息
	bool delete_ut(char del_data[], char del_num[], char del_time[]);//删除用户机票信息
	void showDelay_ut();				//显示延误航班机票
	void showCancel_ut();				//显示取消航班机票

};
//extern UserTicket* ZeroTicket;
//extern UserTicket* MyTickets;
//变量只能被定义(赋值)一次，但能被声明多次
//全局变量应该在头文件声明 原文件定义
//因为在头文件定义全局变量，在引用头文件时会再次定义全局变量
#endif

