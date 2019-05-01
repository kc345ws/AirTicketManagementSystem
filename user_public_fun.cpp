#include "Flight.h"
#include "User.h"
#include <iostream>

using namespace std;

User::User()				//���캯��
{
	user=new UserInfo;
	user->next=NULL;
	ui=NULL;
	mi=NULL;
	mg=NULL;
	ug=NULL;
	user_num=0;//�û�����
	judge=0;//����Ա�״ε�½
	mode=-1;//��½ģʽ

	userTicket = new UserTicket();//�����û���Ʊ
}
User::~User()				//��������
{
	Destroy(user);
}
void User::Destroy(UserInfo *&U)	//�ͷ�����
{
	UserInfo *p=U->next,*q=U;
	while(p!=NULL)
	{
		delete q;
		q=p;
		p=q->next;
	}
	delete q;
}

void User::init_file()		//��ʼ���ļ�
{
	fstream u_file,u_file1;
	if((user_num=load_un())==0)		//��ʼ����¼�������ļ�user_num.txt
	{
		u_file.open("user_num.txt",ios::out);
		u_file<<"0"<<endl;
		u_file.close();
	}
	u_file1.open("mode.txt",ios::out);	//��ʼ����½ģʽ�ļ�mode.txt
	u_file1<<"-1"<<endl;
	u_file1.close();

	if((judge=load_judge())==0)
	{
		u_file.open("judge.txt",ios::out);	//��ʼ���жϹ���Ա�Ƿ����״ε�½�ļ�judge.txt
		u_file<<"0"<<endl;
		u_file.close();
	}
}

char User::choose()			//����ѡ��
{
	char item;
	cin.sync();
	cout<<"������ѡ��:";
	cin>>item;
	return item;
}

void User::input_linfo()	//�����¼��Ϣ
{
	mg=new UserInfo;
	cin.sync();
	cout<<"\n�������û���:";
	cin>>mg->name;
	cin.sync();
	cout<<"\n�������û�����:";
	cin>>mg->passport;

	LoginedUser->ug = mg;
//	return mg;
//	delete mg;
}

void User::input_uinfo()		//�����û���Ϣ
{
	fstream u_file;
	ui=new UserInfo;
	cin.sync();
	cout<<"\n�������û�����:";
	cin>>ui->name;
	cin.sync();
	cout<<"\n���������û����֤��:";
	cin>>ui->id;
	if((user_num=load_un())!=0)
	{
		int j=0;
		u_file.open("user.txt",ios::in);	//���Ѵ����û��ļ������Զ�ȡ��ʽ�򿪽����ж��Ƿ��Ѿ�ע��
		while(j<user_num)					//�ж��Ƿ�����֤���ѱ�����ע���
		{
			mg=new UserInfo;
			u_file>>mg->name>>mg->passport>>mg->sex>>mg->age>>mg->id;
			if(strcmp(ui->id,mg->id)==0)
			{
				cout<<"\n�����֤���ѱ�ʹ�ù�!"<<endl;
				cout<<"������ע���û���Ϣ!"<<endl;
				Sleep(2000);
				system("cls");
			//	input_uinfo();
				create_uif();
			}
			j++;
		}
		u_file.close();
	}
	cin.sync();
	cout<<"\n�������û�����:";
	cin>>ui->passport;
	cin.sync();
	cout<<"\n�������û��Ա�:";
	cin>>ui->sex;
	cin.sync();
	cout<<"\n�������û�����:";
	cin>>ui->age;
//	return ui;
//	delete ui;
}

void User::load_list()				//���ļ���Ϣװ�ص�����
{
	int i;
	fstream u_file;
	UserInfo *tail;
	u_file.open("user.txt",ios::in);
	if(!u_file)
	{
		cerr<<"��ȡ�û���Ϣʧ��!"<<endl;
		return ;
	}
	tail=user;
	for(i=0;i<(user_num=load_un());i++)	//ѭ�����Ҳ��ж��Ƿ���ڸ��û���Ϣ
	{
		ui=new UserInfo;
		u_file>>ui->name>>ui->passport>>ui->sex>>ui->age>>ui->id;	
		tail->next=ui;
		tail=ui;
	}
	tail->next=NULL;
	u_file.close();
}

void User::save_list()			//����������Ϣ���ļ�
{
	int i=0;
	fstream u_file;
	ui=user->next;
	u_file.open("user.txt",ios::out);
	while(i<(user_num=load_un()))
	{
		u_file<<ui->name<<"\t"<<ui->passport<<"\t"<<ui->sex<<"\t"<<ui->age<<"\t"<<ui->id<<endl;
		i++;
	}
	u_file.close();
}

void User::save_uitf()			//�����û���Ϣ���ļ�
{
	fstream u_file,u_file1;
	if((user_num=load_un())==0)	//�ж��Ƿ�����û���Ϣ
	{
		u_file.open("user.txt",ios::out);
		u_file<<ui->name<<"\t"<<ui->passport<<"\t"<<ui->sex<<"\t"<<ui->age<<"\t"<<ui->id<<endl;
		u_file.close();
	}
	else	//����ʱ��ֱ����׷�ӷ�ʽ���ļ�����д��
	{
		u_file1.open("user.txt",ios::app|ios::out);
		if(!u_file1)
		{
			cerr<<"�����û���Ϣʧ��!"<<endl;
			return ;
		}
		u_file1<<ui->name<<"\t"<<ui->passport<<"\t"<<ui->sex<<"\t"<<ui->age<<"\t"<<ui->id<<endl;
		u_file1.close();
	}
}

void User::save_un()			//�����û�������
{
	fstream u_file;
	u_file.open("user_num.txt",ios::out);
	if(!u_file)
	{
		cerr<<"�����û���������Ϣʧ��!"<<endl;
		return ;
	}
	u_file<<user_num;
	u_file.close();
}

int User::load_un()				//��ȡ�û�������
{
	fstream u_file;
	u_file.open("user_num.txt",ios::in);
	if(!u_file)
	{
		cerr<<"��ȡ�û���������Ϣʧ��!"<<endl;
		return 0;
	}
	u_file>>user_num;
	u_file.close();
	return user_num;
}

void User::save_mode()			//�����¼ģʽ
{
	fstream u_file;
	u_file.open("mode.txt",ios::out);
	if(!u_file)
	{
		cerr<<"�����½ģʽ��Ϣʧ��!"<<endl;
		return ;
	}
	u_file<<mode<<endl;
	u_file.close();
}

int User::load_mode()			//��ȡ��½ģʽ
{
	fstream u_file1;
	u_file1.open("mode.txt",ios::in);
	if(!u_file1)
	{
		cerr<<"��ȡ��½ģʽ��Ϣʧ��!"<<endl;
		return -1;
	}
	u_file1>>mode;
	u_file1.close();
	return mode;
}

void User::save_judge()			//�����½����
{
	fstream u_file;
	u_file.open("judge.txt",ios::out);
	if(!u_file)
	{
		cerr<<"�����½������Ϣʧ��!"<<endl;
		return ;
	}
	u_file<<judge<<endl;
	u_file.close();
}

int User::load_judge()			//��ȡ��½����
{
	fstream u_file1;
	u_file1.open("judge.txt",ios::in);
	if(!u_file1)
	{
		cerr<<"��ȡ��½������Ϣʧ��"<<endl;
		return 0;
	}
	u_file1>>judge;
	u_file1.close();
	return judge;
}
/*
void User::save_lfui()		//�����¼ϵͳ���û���Ϣ
{
	fstream order;
	order.open("order.txt",ios::app|ios::out);
	order<<mg->name<<"\t";
	order.close();
}*/
/*
int User::load_lfui()		   //��ȡ��¼ϵͳ���û���Ϣ
{
	char name[32];
	char id[19];
*/