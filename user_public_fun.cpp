#include "Flight.h"
#include "User.h"
#include <iostream>

using namespace std;

User::User()				//构造函数
{
	user=new UserInfo;
	user->next=NULL;
	ui=NULL;
	mi=NULL;
	mg=NULL;
	ug=NULL;
	user_num=0;//用户数量
	judge=0;//管理员首次登陆
	mode=-1;//登陆模式

	userTicket = new UserTicket();//创建用户机票
}
User::~User()				//析构函数
{
	Destroy(user);
}
void User::Destroy(UserInfo *&U)	//释放链表
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

void User::init_file()		//初始化文件
{
	fstream u_file,u_file1;
	if((user_num=load_un())==0)		//初始化记录数量的文件user_num.txt
	{
		u_file.open("user_num.txt",ios::out);
		u_file<<"0"<<endl;
		u_file.close();
	}
	u_file1.open("mode.txt",ios::out);	//初始化登陆模式文件mode.txt
	u_file1<<"-1"<<endl;
	u_file1.close();

	if((judge=load_judge())==0)
	{
		u_file.open("judge.txt",ios::out);	//初始化判断管理员是否是首次登陆文件judge.txt
		u_file<<"0"<<endl;
		u_file.close();
	}
}

char User::choose()			//输入选项
{
	char item;
	cin.sync();
	cout<<"请输入选项:";
	cin>>item;
	return item;
}

void User::input_linfo()	//输入登录信息
{
	mg=new UserInfo;
	cin.sync();
	cout<<"\n请输入用户名:";
	cin>>mg->name;
	cin.sync();
	cout<<"\n请输入用户密码:";
	cin>>mg->passport;

	LoginedUser->ug = mg;
//	return mg;
//	delete mg;
}

void User::input_uinfo()		//输入用户信息
{
	fstream u_file;
	ui=new UserInfo;
	cin.sync();
	cout<<"\n请输入用户姓名:";
	cin>>ui->name;
	cin.sync();
	cout<<"\n请输入用用户身份证号:";
	cin>>ui->id;
	if((user_num=load_un())!=0)
	{
		int j=0;
		u_file.open("user.txt",ios::in);	//若已存在用户文件，则以读取方式打开进行判断是否已经注册
		while(j<user_num)					//判断是否此身份证号已被用于注册过
		{
			mg=new UserInfo;
			u_file>>mg->name>>mg->passport>>mg->sex>>mg->age>>mg->id;
			if(strcmp(ui->id,mg->id)==0)
			{
				cout<<"\n此身份证号已被使用过!"<<endl;
				cout<<"请重新注册用户信息!"<<endl;
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
	cout<<"\n请输入用户密码:";
	cin>>ui->passport;
	cin.sync();
	cout<<"\n请输入用户性别:";
	cin>>ui->sex;
	cin.sync();
	cout<<"\n请输入用户年龄:";
	cin>>ui->age;
//	return ui;
//	delete ui;
}

void User::load_list()				//把文件信息装载到链表
{
	int i;
	fstream u_file;
	UserInfo *tail;
	u_file.open("user.txt",ios::in);
	if(!u_file)
	{
		cerr<<"读取用户信息失败!"<<endl;
		return ;
	}
	tail=user;
	for(i=0;i<(user_num=load_un());i++)	//循环查找并判断是否存在该用户信息
	{
		ui=new UserInfo;
		u_file>>ui->name>>ui->passport>>ui->sex>>ui->age>>ui->id;	
		tail->next=ui;
		tail=ui;
	}
	tail->next=NULL;
	u_file.close();
}

void User::save_list()			//保存链表信息到文件
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

void User::save_uitf()			//保存用户信息到文件
{
	fstream u_file,u_file1;
	if((user_num=load_un())==0)	//判断是否存在用户信息
	{
		u_file.open("user.txt",ios::out);
		u_file<<ui->name<<"\t"<<ui->passport<<"\t"<<ui->sex<<"\t"<<ui->age<<"\t"<<ui->id<<endl;
		u_file.close();
	}
	else	//存在时，直接以追加方式打开文件进行写入
	{
		u_file1.open("user.txt",ios::app|ios::out);
		if(!u_file1)
		{
			cerr<<"保存用户信息失败!"<<endl;
			return ;
		}
		u_file1<<ui->name<<"\t"<<ui->passport<<"\t"<<ui->sex<<"\t"<<ui->age<<"\t"<<ui->id<<endl;
		u_file1.close();
	}
}

void User::save_un()			//保存用户总人数
{
	fstream u_file;
	u_file.open("user_num.txt",ios::out);
	if(!u_file)
	{
		cerr<<"保存用户总人数信息失败!"<<endl;
		return ;
	}
	u_file<<user_num;
	u_file.close();
}

int User::load_un()				//读取用户总人数
{
	fstream u_file;
	u_file.open("user_num.txt",ios::in);
	if(!u_file)
	{
		cerr<<"读取用户总人数信息失败!"<<endl;
		return 0;
	}
	u_file>>user_num;
	u_file.close();
	return user_num;
}

void User::save_mode()			//保存登录模式
{
	fstream u_file;
	u_file.open("mode.txt",ios::out);
	if(!u_file)
	{
		cerr<<"保存登陆模式信息失败!"<<endl;
		return ;
	}
	u_file<<mode<<endl;
	u_file.close();
}

int User::load_mode()			//读取登陆模式
{
	fstream u_file1;
	u_file1.open("mode.txt",ios::in);
	if(!u_file1)
	{
		cerr<<"读取登陆模式信息失败!"<<endl;
		return -1;
	}
	u_file1>>mode;
	u_file1.close();
	return mode;
}

void User::save_judge()			//保存登陆次数
{
	fstream u_file;
	u_file.open("judge.txt",ios::out);
	if(!u_file)
	{
		cerr<<"保存登陆次数信息失败!"<<endl;
		return ;
	}
	u_file<<judge<<endl;
	u_file.close();
}

int User::load_judge()			//读取登陆次数
{
	fstream u_file1;
	u_file1.open("judge.txt",ios::in);
	if(!u_file1)
	{
		cerr<<"读取登陆次数信息失败"<<endl;
		return 0;
	}
	u_file1>>judge;
	u_file1.close();
	return judge;
}
/*
void User::save_lfui()		//保存登录系统的用户信息
{
	fstream order;
	order.open("order.txt",ios::app|ios::out);
	order<<mg->name<<"\t";
	order.close();
}*/
/*
int User::load_lfui()		   //读取登录系统的用户信息
{
	char name[32];
	char id[19];
*/