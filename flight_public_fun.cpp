//Flight类的各种操作
#include "Ticket.h"
#include "Ticket1.h"
#include <iostream>

using namespace std;

Flight::Flight()
{
	//初始化航班信息
	flight=new FlightInfo;//哨兵节点
	flight->next=NULL;
	flight->prior=NULL;
	fi=NULL;
	fn=NULL;
	fg=NULL;
	flight_num=load_fn();//读取航班总数
}

Flight::~Flight()
{
	destroy(flight);
}

void Flight::destroy(FlightInfo *&F)	//释放链表
{
	FlightInfo *p=F->next,*q=F;
	while(p!=NULL)
	{
		delete q;
		q=p;
		p=q->next;
	}
	delete q;
}

void Flight::init_fnf()					//初始化记录数量的文件flight_num.txt
{
	fstream f_file;
	if((flight_num=load_fn())==0)//读取航班总数信息成功
	{
		f_file.open("flight_num.txt",ios::out);
		f_file<<"0"<<endl;
		f_file.close();
	}
}

void Flight::current_time()						//当前时间
{       
	time_t  t;      
	t = time(NULL);      
//	cout<<"The Calendar Time now is:\n"; //显示从1970年1月1日0时0分0秒到此时的秒数。      
	struct tm *local;      
	local = localtime(&t);     
//	while(1)  //每隔1000毫米，更新显示时间 
//	{          
	//	Sleep(1000);        
		t = time(NULL);         
		local = localtime(&t);          
		cout<<"当前时间:"<< local->tm_year+1900 <<"-"<< local->tm_mon+1 <<"-"<< local->tm_mday 
			<<" "<< local->tm_hour <<":"<< local->tm_min <<":"<< local->tm_sec <<endl;  
		Sleep(1000);
	//	system("cls");
//	}  
}

void Flight::input_fi()					//输入航班信息
{
	int i=0;
	fstream f_file;
	fi=new FlightInfo;
	cin.sync();
	cout<<"\n请输入航班日期:";
	cin>>fi->data;
	cin.sync();
	cout<<"\n请输入航班号:";
	cin>>fi->num;
	cin.sync();
	cout<<"\n请输入起始地:";
	cin>>fi->start;
	cin.sync();
	cout<<"\n请输入目的地:";
	cin>>fi->end;
	cin.sync();
	cout<<"\n请输入起降时间:";
	cin>>fi->time;
	cin.sync();
	cout<<"\n请输入飞行时间:";
	cin>>fi->at;
	cin.sync();
	cout<<"\n请输入机票数:";
	cin>>fi->count;
	cin.sync();
	cout<<"\n请输入票价:";
	cin>>fi->price;
	fi->next = NULL;
	if((flight_num=load_fn())!=0)
	{
		f_file.open("flight.txt",ios::in);
		if(!f_file)
		{
			cerr<<"打开航班信息失败!"<<endl;
			return ;
		}
		while(i<flight_num)				//判断该航班号是否已经存在
		{
			fn=new FlightInfo;
			f_file>>fn->data>>fn->num>>fn->start>>fn->end>>fn->time;
			if(strcmp(fi->data,fn->data)==0 && 
				strcmp(fi->num,fn->num)==0 && 
				strcmp(fi->start,fn->start)==0 && 
				strcmp(fi->end,fn->end)==0 && strcmp(fi->time,fn->time)==0)
			{
				cout<<"\n该航班信息已经存在!"<<endl;
				cout<<"请重新输入航班信息!"<<endl;
				Sleep(1000);
				system("cls");
				input_fi();
			}
			i++;
		}
		f_file.close();
	}
}


void Flight::input_sfi(int note,int note1,int note2)	//输入需查找的航班信息
{
	if(note==1)
	{
		fn=new FlightInfo;
		cin.sync();
		cout<<"\n请输入航班的起始地:";
		cin>>fn->start;
		cin.sync();
		cout<<"请输入航班的目的地:";
		cin>>fn->end;
	}
	if(note1==1)
	{
		cin.sync();
		cout<<"\n请输入要订票的航班号:";
		cin>>fn->num;
		cin.sync();
		cout<<"请输入订票数:";
		cin>>fn->count;
	}
	if(note2==1)
	{
		cin.sync();
		cout<<"请输入要查找的时间段:";
		cin>>fn->time;
	}
}

/*
void Flight::save_fitf(FlightInfo *finfo)				//保存航班信息到文件
{
	if((F_AI.flight_num=F_AI.load_fn())==0)				//判断是否存在航班信息
	{
		f_file.open("flight.txt",ios::out);				//若不存在航班信息文件，则新建
		f_file<<finfo->data<<"\t"<<finfo->num<<"\t"<<finfo->start<<"\t"<<finfo->end<<"\t"<<finfo->time<<"\t"<<finfo->at<<"\t"<<finfo->count<<"\t"<<finfo->price<<endl;
		f_file.close();
	}
	else
	{
		f_file1.open("flight.txt",ios::app|ios::out);	//若已存在航班信息文件，则以追加方式打开
		if(!f_file1)
		{
			cerr<<"Open flight.txt error!"<<endl;
			return ;
		}
		f_file1<<finfo->data<<"\t"<<finfo->num<<"\t"<<finfo->start<<"\t"<<finfo->end<<"\t"<<finfo->time<<"\t"<<finfo->at<<"\t"<<finfo->count<<"\t"<<finfo->price<<endl;
		f_file1.close();
	}
	++F_AI.flight_num;		//航班数加1
	F_AI.save_fn();			//保存航班总数
}													*/

void Flight::Inser_fi()						//把航班信息按日期顺序插入链表
{
	FlightInfo *fp,*fpre,*save;
	fp = flight ->next->next;
	fpre = flight->next;
	bool success = false;
	if((flight_num=load_fn())==0)							//当没有数据结点时，直接插入链表
	{
		fi->next = NULL;
		flight->next = fi;
		fi->prior = flight;
		success = true;
	}
	else if(flight_num==1 && !success)		//如果存在一个数据节点
	{
		if(strcmp(fi->data,fpre->data)<=0)
		{
			fi->next = NULL;
			fi->prior = fpre;
			fpre->next = fi;
			success = true;		
		}
		else if(strcmp(fi->data,fpre->data)>0)
		{
			fi->next = fpre;
			fpre->prior = fi;
			fi->prior = flight;
			flight->next = fi;
			success =true;		
		}
	}
	while(fp!=NULL && !success)						//如果存在多个数据节点
	{
		if(strcmp(fi->data,fpre->data)>=0)	//如果f节点日期大于fpre,则插入到fpre前面
		{
			save = fpre->prior;
			fi->next = fpre;
			fpre->prior = fi;
			fi->prior = save;
			save->next = fi;
			break;
		}
		else if(strcmp(fi->data,fpre->data)<0 && strcmp(fi->data,fp->data)>0)
		{
			fi->next = fp;
			fp->prior = fi;
			fi->prior = fpre;
			fpre->next = fi;	
			break;
		}
		else if(strcmp(fi->data,fp->data)<=0 && fp->next!=NULL && strcmp(fi->data,fp->next->data)>=0)
		{
			fi ->next = fp->next;
			fp->next->prior = fi;
			fi->prior = fp;
			fp->next = fi;	
			break;
		}
		else if(strcmp(fi->data,fp->data)<=0 && fp->next==NULL)
		{
			fi->prior = fp;
			fp->next = fi;
			break;
		}
		fpre = fp;
		fp = fpre->next;
	}
}
/*
void Flight::Inser_fi()
{
	FlightInfo *curr = flight->next,*curr1 = flight->next->next,*prior;
	bool success = false;

	while(curr!=NULL)
	{
		if(strcmp(fi->data,curr->data)>0)
		{
			prior = curr->prior;
			fi->next = curr;
			curr->prior = fi;
			fi->prior = prior;
			prior->next = fi;
			success = true;
			break;
		}
		else if(strcmp(fi->data,curr->data)<=0 && strcmp(curr1->data
		{
			fi->next = curr->next;
			curr->next->prior = fi;
			fi->prior = curr;
			curr->next = fi;
			success = true;
			break;
		}
		curr = curr->next;
	}
	if(curr==NULL && !success)
	{
		fi->prior = flight;
		flight->next = fi;
	}
}										*/

void Flight::load_fil()		//把文件中航班信息装载到链表
{
	int i=0;
	fstream f_file;//打开fight.txt文件
	FlightInfo *tail;
	f_file.open("flight.txt",ios::in);
	if(!f_file)
	{
		cerr<<"航班信息读取失败!"<<endl;
		return ;
	}
	tail=flight;//赋值哨兵结点
	while(i<(flight_num = load_fn()))
	{
		fi = new FlightInfo;
		f_file>>fi->data>>fi->num>>fi->start>>fi->end>>fi->time>>fi->at>>fi->count>>fi->price;
		fi->next = NULL;
		tail->next = fi;
		fi->prior = tail;
		tail = fi;
		i++;
	}
	tail->next = NULL;
	f_file.close();
}

void Flight::save_fil()		//保存链表中航班信息到文件中
{
	int i=0;
	fstream f_file;
	fi=flight->next;
	f_file.open("flight.txt",ios::out);
	if(!f_file)
	{
		cerr<<"保存航班信息失败!"<<endl;
		return ;
	}
	while(fi!=NULL)
	{
		f_file<<fi->data<<"\t"<<fi->num<<"\t"<<fi->start<<"\t"<<fi->end<<"\t"<<fi->time<<"\t"<<fi->at<<"\t"<<fi->count<<"\t"<<fi->price<<endl;
		fi = fi->next;
	}
	f_file.close();
}

void Flight::save_fn()		//保存航班总数
{
	fstream f_file;
	f_file.open("flight_num.txt",ios::out);
	if(!f_file)
	{
		cerr<<"读取航班总数信息失败!"<<endl;
		return ;
	}
	f_file<<flight_num;
	f_file.close();
}

int Flight::load_fn()		//读取航班总数
{
	fstream f_file1;
	f_file1.open("flight_num.txt",ios::in);
	if(!f_file1)//如果首次初始化
	{
		cerr<<"读取航班总数信息发生错误"<<endl;
		return 0;
	}
	f_file1>>flight_num;
	f_file1.close();
	return flight_num;
}
/*
void Flight::save_lfui()	//保存登录系统的用户信息
{
	
int Flight::load_lfui()		//读取登录系统的用户信息
*/