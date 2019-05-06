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
		char data[9];				//��������
		char num[10];				//�����
		char start[12];				//��ʼ��
		char end[12];				//Ŀ�ĵ�
		char time[16];				//��ʱ��
		char at[6];					//����ʱ��
		int count;					//Ʊ��
		double price;				//Ʊ��

		string transit;				//��ת��
		int transittime;			//��תʱ��
		struct FlightInfo *next;	//ָ����һ��������Ϣ
		struct FlightInfo *prior;	//ָ��ǰһ��������Ϣ

	}*flight,*fi,*fn,*fg;

	struct WaitUsers {
		int id;
		int count;
		WaitUsers* next;
	};
//flight��ʼ���ڱ���� fi���ļ���ȡʱ������ fn���뺽����Ϣʱ������ 
public:	
	int flight_num;					//���к�����
	//User::UserInfo* waituser;		//��Ʊ���û�����
	WaitUsers* waitUS;				//��Ʊ���û�����
	int wait_num;					//�ú�����Ʊ�û�����
	//int first_count;				//��һ���û���Ʊ������
	//int* grabnum;					//��Ʊ����

	public:
		friend class UserTicket;
		Flight();
		~Flight();
		void destroy(FlightInfo *&F);					//�ͷ�����

		void init_fnf();								//��ʼ����¼�������ļ�user_num.txt
		void current_time();							//��ǰʱ��
		void input_fi();								//���뺽����Ϣ
		void input_sfi(int note,int note1,int note2);	//��������ҵĺ�����Ϣ
	//	void save_fitf(FlightInfo *userinfo);			//���溽����Ϣ���ļ�
		void load_fil();								//���ļ��к�����Ϣװ�ص�����
		void save_fil();								//���������к�����Ϣ���ļ���
		void Inser_fi();								//�Ѻ�����Ϣ������˳���������

		void add_fi();			//��Ӻ�����Ϣ
		//void browse_fi(); 		//���������Ϣ
		void browse_fi(bool isback); 		//���������Ϣ
		//	void save_fi();		//����������Ϣ,��ֹ��Ϣ��ʧ
		//	bool load_fi();		//��ȡ������Ϣ
		void sort_byfp();		//ȫ�����ఴƱ�۽�����ʾ
		void search_fi();		//������Ų��Һ�����Ϣ
		FlightInfo *getrefund_fi(string data_re,string num_re, string time_re);	//�����Ʊ������Ϣ
		void order();			//��Ʊ

		void delete_fi();//ɾ��������Ϣ
		void delete_fi(char data_del[], char num_del[], char start_del[], char end_del[]);
		void change_fi();//�޸ĺ�����Ϣ
		void change_finum(int num, char data_ch[], char num_ch[], char time_ch[]);//�û���Ʊʱ�޸Ļ�Ʊ����

		void save_fn();			//���溽������
		int load_fn();			//��ȡ��������
		//void save_lfui1();		//�����¼ϵͳ���û���Ϣ
		//int load_lfui1();		//��ȡ��¼ϵͳ���û���Ϣ
		//	void load_bfi();	//��ȡ��������ʽ����ĺ�����Ϣ�ļ�����


		FlightInfo*getFlightinfo() { return fi; };
		void showzeroTicket_fl();				//��ʾ�Ѿ������ĺ�����Ϣ��Ϣ
		void loadall_wait(string filename);			//��ȡĳ���������Ʊ������Ϣ
		void saveall_wait(string filename);			//����ĳ���������Ʊ������Ϣ
		void load_waitnum(string filename);			//���صȴ���Ʊ���û�����
		void save_waitnum(string filename);			//����ȴ���Ʊ���û�����
};
#endif // !1
extern Flight* FLIGHT_WAIT;