#include "Ticket.h"
#include "Ticket1.h"
#include <iostream>

using namespace std;

void Flight::order()		//��Ʊ
{
	User U_AI;
	int success=0;
	bool exist = false;

	system("cls");
	U_AI.print_item(14);
	current_time();
	if((flight_num=load_fn())==0)	//û�к�����Ϣ�ɹ�Ԥ��
	{
		cout<<"û�к�����Ϣ!�޷��ṩԤ������!"<<endl;
		cout<<"������ת����Ʊ����ϵͳ��ҳ..."<<endl;
		Sleep(1000);
		goto loop2;
	}
	else					//���ں�����Ϣʱ�������������²���
	{
		input_sfi(1,0,0);
		load_fil();
		cout<<"�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��\t��Ʊ��\tƱ��"<<endl;
		for(fi=flight->next;fi!=NULL;fi=fi->next)
		{
			if(strcmp(fi->start,fn->start)==0 && strcmp(fi->end,fn->end)==0)
			{
				exist = true;
				cout<<fi->data<<" "<<fi->num<<"\t"<<fi->start<<"\t"<<fi->end<<"\t"<<fi->time<<"\t"<<fi->at<<"\t\t"<<fi->count<<"\t"<<fi->price<<endl;
			}
		}
		if(!exist)
			goto Nofind;
		input_sfi(0,1,0);
		for(fi=flight->next;fi!=NULL;fi=fi->next)
		{
			if(strcmp(fi->num,fn->num)==0)
			{
				if(fn->count<=0)
				{
					cout<<"���붩Ʊ����Ч!"<<endl;
					Sleep(1000);
					order();
					break;
				}
				else if(fi->count>=fn->count)
				{
					success = 1;
					fi->count = fi->count - fn->count;
					cout<<"��Ʊ�ɹ�!"<<endl;
					Sleep(2000);
					system("cls");
					cout<<"�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��\t��Ʊ��\tƱ��"<<endl;
					cout<<fi->data<<" "<<fi->num<<"\t"<<fi->start<<"\t"<<fi->end<<"\t"<<fi->time<<"\t"<<fi->at<<"\t\t"<<fi->count<<"\t"<<fi->price<<endl;
					if(fi->count==0)
					{
						fi->prior->next = fi->next;
						fi->next->prior = fi->prior;
						delete fi;
						--flight_num;
						save_fn();
					}
					break;
				}
				else if(fi->count>0 && fi->count<fn->count)
				{
					cout<<"��Ʊ����!�޷���ɶ�Ʊ!"<<endl;
					cout<<"�����¶�Ʊ!"<<endl;
					Sleep(2000);
					order();
					break;
				}
				else if(fi->count==0)
				{
					cout<<"�ú���Ʊ���ۿ�!��Ļ����ඩ��!"<<endl;
					Sleep(2000);
					order();
					break;
				}
			}
		}
Nofind:	if(success==0)
		{
			system("cls");
			cout<<"û�к�����Ϣ�����ۿ�!"<<endl;
			Sleep(2000);
			order();
		}
		save_fil();
loop2:	Sleep(2000);
		if((U_AI.mode=U_AI.load_mode())==1)
			U_AI.login_mf();
		else if(U_AI.mode==0)
			U_AI.login_uf();
	}
}