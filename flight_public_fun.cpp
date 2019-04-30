//Flight��ĸ��ֲ���
#include "Ticket.h"
#include "Ticket1.h"
#include <iostream>

using namespace std;

Flight::Flight()
{
	//��ʼ��������Ϣ
	flight=new FlightInfo;//�ڱ��ڵ�
	flight->next=NULL;
	flight->prior=NULL;
	fi=NULL;
	fn=NULL;
	fg=NULL;
	flight_num=load_fn();//��ȡ��������
}

Flight::~Flight()
{
	destroy(flight);
}

void Flight::destroy(FlightInfo *&F)	//�ͷ�����
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

void Flight::init_fnf()					//��ʼ����¼�������ļ�flight_num.txt
{
	fstream f_file;
	if((flight_num=load_fn())==0)//��ȡ����������Ϣ�ɹ�
	{
		f_file.open("flight_num.txt",ios::out);
		f_file<<"0"<<endl;
		f_file.close();
	}
}

void Flight::current_time()						//��ǰʱ��
{       
	time_t  t;      
	t = time(NULL);      
//	cout<<"The Calendar Time now is:\n"; //��ʾ��1970��1��1��0ʱ0��0�뵽��ʱ��������      
	struct tm *local;      
	local = localtime(&t);     
//	while(1)  //ÿ��1000���ף�������ʾʱ�� 
//	{          
	//	Sleep(1000);        
		t = time(NULL);         
		local = localtime(&t);          
		cout<<"��ǰʱ��:"<< local->tm_year+1900 <<"-"<< local->tm_mon+1 <<"-"<< local->tm_mday 
			<<" "<< local->tm_hour <<":"<< local->tm_min <<":"<< local->tm_sec <<endl;  
		Sleep(1000);
	//	system("cls");
//	}  
}

void Flight::input_fi()					//���뺽����Ϣ
{
	int i=0;
	fstream f_file;
	fi=new FlightInfo;
	cin.sync();
	cout<<"\n�����뺽������:";
	cin>>fi->data;
	cin.sync();
	cout<<"\n�����뺽���:";
	cin>>fi->num;
	cin.sync();
	cout<<"\n��������ʼ��:";
	cin>>fi->start;
	cin.sync();
	cout<<"\n������Ŀ�ĵ�:";
	cin>>fi->end;
	cin.sync();
	cout<<"\n��������ʱ��:";
	cin>>fi->time;
	cin.sync();
	cout<<"\n���������ʱ��:";
	cin>>fi->at;
	cin.sync();
	cout<<"\n�������Ʊ��:";
	cin>>fi->count;
	cin.sync();
	cout<<"\n������Ʊ��:";
	cin>>fi->price;
	fi->next = NULL;
	if((flight_num=load_fn())!=0)
	{
		f_file.open("flight.txt",ios::in);
		if(!f_file)
		{
			cerr<<"�򿪺�����Ϣʧ��!"<<endl;
			return ;
		}
		while(i<flight_num)				//�жϸú�����Ƿ��Ѿ�����
		{
			fn=new FlightInfo;
			f_file>>fn->data>>fn->num>>fn->start>>fn->end>>fn->time;
			if(strcmp(fi->data,fn->data)==0 && 
				strcmp(fi->num,fn->num)==0 && 
				strcmp(fi->start,fn->start)==0 && 
				strcmp(fi->end,fn->end)==0 && strcmp(fi->time,fn->time)==0)
			{
				cout<<"\n�ú�����Ϣ�Ѿ�����!"<<endl;
				cout<<"���������뺽����Ϣ!"<<endl;
				Sleep(1000);
				system("cls");
				input_fi();
			}
			i++;
		}
		f_file.close();
	}
}


void Flight::input_sfi(int note,int note1,int note2)	//��������ҵĺ�����Ϣ
{
	if(note==1)
	{
		fn=new FlightInfo;
		cin.sync();
		cout<<"\n�����뺽�����ʼ��:";
		cin>>fn->start;
		cin.sync();
		cout<<"�����뺽���Ŀ�ĵ�:";
		cin>>fn->end;
	}
	if(note1==1)
	{
		cin.sync();
		cout<<"\n������Ҫ��Ʊ�ĺ����:";
		cin>>fn->num;
		cin.sync();
		cout<<"�����붩Ʊ��:";
		cin>>fn->count;
	}
	if(note2==1)
	{
		cin.sync();
		cout<<"������Ҫ���ҵ�ʱ���:";
		cin>>fn->time;
	}
}

/*
void Flight::save_fitf(FlightInfo *finfo)				//���溽����Ϣ���ļ�
{
	if((F_AI.flight_num=F_AI.load_fn())==0)				//�ж��Ƿ���ں�����Ϣ
	{
		f_file.open("flight.txt",ios::out);				//�������ں�����Ϣ�ļ������½�
		f_file<<finfo->data<<"\t"<<finfo->num<<"\t"<<finfo->start<<"\t"<<finfo->end<<"\t"<<finfo->time<<"\t"<<finfo->at<<"\t"<<finfo->count<<"\t"<<finfo->price<<endl;
		f_file.close();
	}
	else
	{
		f_file1.open("flight.txt",ios::app|ios::out);	//���Ѵ��ں�����Ϣ�ļ�������׷�ӷ�ʽ��
		if(!f_file1)
		{
			cerr<<"Open flight.txt error!"<<endl;
			return ;
		}
		f_file1<<finfo->data<<"\t"<<finfo->num<<"\t"<<finfo->start<<"\t"<<finfo->end<<"\t"<<finfo->time<<"\t"<<finfo->at<<"\t"<<finfo->count<<"\t"<<finfo->price<<endl;
		f_file1.close();
	}
	++F_AI.flight_num;		//��������1
	F_AI.save_fn();			//���溽������
}													*/

void Flight::Inser_fi()						//�Ѻ�����Ϣ������˳���������
{
	FlightInfo *fp,*fpre,*save;
	fp = flight ->next->next;
	fpre = flight->next;
	bool success = false;
	if((flight_num=load_fn())==0)							//��û�����ݽ��ʱ��ֱ�Ӳ�������
	{
		fi->next = NULL;
		flight->next = fi;
		fi->prior = flight;
		success = true;
	}
	else if(flight_num==1 && !success)		//�������һ�����ݽڵ�
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
	while(fp!=NULL && !success)						//������ڶ�����ݽڵ�
	{
		if(strcmp(fi->data,fpre->data)>=0)	//���f�ڵ����ڴ���fpre,����뵽fpreǰ��
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

void Flight::load_fil()		//���ļ��к�����Ϣװ�ص�����
{
	int i=0;
	fstream f_file;//��fight.txt�ļ�
	FlightInfo *tail;
	f_file.open("flight.txt",ios::in);
	if(!f_file)
	{
		cerr<<"������Ϣ��ȡʧ��!"<<endl;
		return ;
	}
	tail=flight;//��ֵ�ڱ����
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

void Flight::save_fil()		//���������к�����Ϣ���ļ���
{
	int i=0;
	fstream f_file;
	fi=flight->next;
	f_file.open("flight.txt",ios::out);
	if(!f_file)
	{
		cerr<<"���溽����Ϣʧ��!"<<endl;
		return ;
	}
	while(fi!=NULL)
	{
		f_file<<fi->data<<"\t"<<fi->num<<"\t"<<fi->start<<"\t"<<fi->end<<"\t"<<fi->time<<"\t"<<fi->at<<"\t"<<fi->count<<"\t"<<fi->price<<endl;
		fi = fi->next;
	}
	f_file.close();
}

void Flight::save_fn()		//���溽������
{
	fstream f_file;
	f_file.open("flight_num.txt",ios::out);
	if(!f_file)
	{
		cerr<<"��ȡ����������Ϣʧ��!"<<endl;
		return ;
	}
	f_file<<flight_num;
	f_file.close();
}

int Flight::load_fn()		//��ȡ��������
{
	fstream f_file1;
	f_file1.open("flight_num.txt",ios::in);
	if(!f_file1)//����״γ�ʼ��
	{
		cerr<<"��ȡ����������Ϣ��������"<<endl;
		return 0;
	}
	f_file1>>flight_num;
	f_file1.close();
	return flight_num;
}
/*
void Flight::save_lfui()	//�����¼ϵͳ���û���Ϣ
{
	
int Flight::load_lfui()		//��ȡ��¼ϵͳ���û���Ϣ
*/