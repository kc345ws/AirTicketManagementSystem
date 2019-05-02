#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include"UserTicket.h"
using namespace std;


//LoginedUserΪ��½���û�

class User
{
//public:
public:
	//ÿһ���û�����Ϣ
	struct UserInfo				//�û���Ϣ
	{
		char name[32];			//�û�����
		char passport[16];		//�û���¼����
		char sex[6];			//�û��Ա�
		int age;				//�û�����
		char id[19];			//�û����֤��
		struct UserInfo *next;	//ָ����һ���û���Ϣ

		class UserTicket* userTicket;		//�û���Ʊ
	}*user,*ui,*mi,*mg,*ug;
	//userΪ�����ڱ��ڵ� mg�û���½ʱ���� ui����������ע��ʱ

	//class UserTicket* userTicket;		//�û���Ʊ
public:
	int user_num;				//��¼���û���
	int mode;					//��½ģʽ��¼
	int judge;					//�����ж��Ƿ����Ա�״ε�½ (��½����)

public:
		User();									//���캯��
		~User();								//��������
		void Destroy(UserInfo *&U);				//�ͷ�����

		void init_file();						//��ʼ���ļ�
		void Start_screen();					//��ʼ����
		void End_screen();						//��������
		char choose();							//����ѡ��
		void print_item(int k);					//��ӡ��������
		void input_linfo();						//�����¼��Ϣ
		void input_uinfo();						//�����û���Ϣ

		void input_loop();						//ѭ��ѡ���
		void load_list();						//���ļ���Ϣװ�ص�����
		void save_list();						//����������Ϣ���ļ�
		void save_uitf();						//�����û���Ϣ���ļ�

		void home(); 			//������
		void identify(); 		//�û�������Ա��¼ѡ��
		void login_m(); 		//����Ա��½
		void login_u();			//�û���¼
		void print_login();		//��ӡ��½�ɹ�����
		void login_mf();		//����Ա��½��Ʊ����ϵͳ
		void login_uf();		//�û���½��Ʊ����ϵͳ
		void create_uif();		//�����û���Ϣ�ļ�

		void save_mode();		//�����¼ģʽ�͵�½����
		int load_mode();		//��ȡ��½ģʽ�͵�½����
		void save_un();			//�����û�������
		int load_un();			//��ȡ�û�������
		void save_judge();		//�����½����
		int load_judge();		//��ȡ��½����
//		void save_lfui();		//�����¼ϵͳ���û���Ϣ
//		int load_lfui();		//��ȡ��¼ϵͳ���û���Ϣ
		friend class Flight;	
		friend class UserTicket;

		
};
extern User* LoginedUser;
//LoginedUserΪ��½���û�
