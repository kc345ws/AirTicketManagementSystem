#pragma once
#include"Flight.h"
#include"User.h"
//�û���Ʊ��
class UserTicket {
public:
	struct Ticket {
		char data[9];				//��������
		char num[10];				//�����
		char start[12];				//��ʼ��
		char end[12];				//Ŀ�ĵ�
		char time[16];				//��ʱ��
		char at[6];					//����ʱ��

		char buytime[128];			//�����Ʊ��ʱ��
		double price;				//Ʊ��
		bool isDelay;               //�Ƿ�����
		bool isCancel;              //�Ƿ�ȡ������
		Flight recommendFlight;		//�������ȡ�����Ƽ��ĺ���
		Ticket* next;			//ָ����һ�Ż�Ʊ��Ϣ
		Ticket* prior;			//ָ��ǰһ�Ż�Ʊ��Ϣ
	}*sentine,*temp;
	//sentine�ڱ��ڵ� temp��������
	int Ticketnum;				//��Ʊ����
public:
	//int static Tickernum;		//��Ʊ����

	UserTicket();
	~UserTicket();
	void Destroy();
	void addTicket();
	friend class Flight;
	friend class User;

};

extern UserTicket* ZeroTicket;
extern UserTicket* MyTickets;
//����ֻ�ܱ�����(��ֵ)һ�Σ����ܱ��������
//ȫ�ֱ���Ӧ����ͷ�ļ����� ԭ�ļ�����
//��Ϊ��ͷ�ļ�����ȫ�ֱ�����������ͷ�ļ�ʱ���ٴζ���ȫ�ֱ���