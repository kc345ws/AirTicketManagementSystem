#pragma once
#ifndef USERTICKET
#define USERTICKET

#include"Flight.h"
#include"User.h"
class UserTicket {
public:
	//�û�ÿһ�Ż�Ʊ����Ϣ
	struct Ticket {
		char data[9];				//��������
		char num[10];				//�����
		char start[12];				//��ʼ��
		char end[12];				//Ŀ�ĵ�
		char time[16];				//��ʱ��
		char at[6];					//����ʱ��

		char buytime[128];			//�����Ʊ��ʱ��
		double price;				//Ʊ��
		int Ticketcount;			//�û�Ʊ�Ĺ�������
		bool isDelay;               //�Ƿ�����
		bool isCancel;              //�Ƿ�ȡ������
		string transit;				//��ת��
		int transittime;			//��תʱ��
		Flight* recommendFlight;		//�������ȡ�����Ƽ��ĺ���
		Ticket* next;				//ָ����һ�Ż�Ʊ��Ϣ
		Ticket* prior;				//ָ��ǰһ�Ż�Ʊ��Ϣ
	}*sentine, * temp, * lastticket;
	//sentine�ڱ��ڵ� temp�������� lastticket���һ�Ż�Ʊ
	int Ticketnum;					//��Ʊ�������
public:
	//friend class Flight;
	//int static Tickernum;			//��Ʊ����
	UserTicket();
	~UserTicket();
	void Destroy();					//����ʱ�ͷ���������
	void addTicket(Flight::FlightInfo* info, int ticnum);//��Ʊʱ�Զ�����Ʊ��Ϣ��ӵ��û���Ʊ����
	void init_ut();					//��ʼ���û���Ʊ��Ϣ
	void load_ut();					//�����û���Ʊ��Ϣ
	void load_ut(string id);		//�����û���Ʊ��Ϣ
	void save_ut();					//�����û���Ʊ��Ϣ
	void save_ut(string id);		//�����û���Ʊ��Ϣ
	void saveall_ut();				//���������û���Ϣ
	void load_num();				//���ع������
	void load_num(string id);		//�����û���Ʊ
	void showTickets(bool isback);	//��ʾ�����Ʊ��Ϣ
	void change_ut(bool info);	//�����û���Ʊ����ȡ����Ϣ
	void change_ut(string id, bool info);	//�����û���Ʊ��Ϣ
	bool delete_ut(char del_data[], char del_num[], char del_time[]);//ɾ���û���Ʊ��Ϣ
	void showDelay_ut();				//��ʾ���󺽰��Ʊ
	void showCancel_ut();				//��ʾȡ�������Ʊ

};
//extern UserTicket* ZeroTicket;
//extern UserTicket* MyTickets;
//����ֻ�ܱ�����(��ֵ)һ�Σ����ܱ��������
//ȫ�ֱ���Ӧ����ͷ�ļ����� ԭ�ļ�����
//��Ϊ��ͷ�ļ�����ȫ�ֱ�����������ͷ�ļ�ʱ���ٴζ���ȫ�ֱ���
#endif

