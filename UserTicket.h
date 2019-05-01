#pragma once
#include"Flight.h"
#include"User.h"
//用户机票类
class UserTicket {
public:
	struct Ticket {
		char data[9];				//航班日期
		char num[10];				//航班号
		char start[12];				//起始地
		char end[12];				//目的地
		char time[16];				//起降时间
		char at[6];					//飞行时间

		char buytime[128];			//购买机票的时间
		double price;				//票价
		bool isDelay;               //是否延误
		bool isCancel;              //是否取消航班
		Flight recommendFlight;		//延误或者取消后推荐的航班
		Ticket* next;			//指向下一张机票信息
		Ticket* prior;			//指向前一张机票信息
	}*sentine,*temp;
	//sentine哨兵节点 temp用来遍历
	int Ticketnum;				//机票总数
public:
	//int static Tickernum;		//机票总数

	UserTicket();
	~UserTicket();
	void Destroy();
	void addTicket();
	friend class Flight;
	friend class User;

};

extern UserTicket* ZeroTicket;
extern UserTicket* MyTickets;
//变量只能被定义(赋值)一次，但能被声明多次
//全局变量应该在头文件声明 原文件定义
//因为在头文件定义全局变量，在引用头文件时会再次定义全局变量