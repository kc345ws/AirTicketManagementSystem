#include "Flight.h"
#include "User.h"
#include <iostream>

using namespace std;

void Flight::sort_byfp()	//��ȫ�����ఴƱ��������ʾ
{
	User U_AI;
	FlightInfo *temp;

	system("cls");
	U_AI.print_item(13);
	if((flight_num=load_fn())!=0)
	{	
		load_fil();
		FlightInfo *f_ai;
		/*�Ժ�����Ϣ��Ʊ�۽�������*/
		f_ai = new FlightInfo;
		f_ai = flight;
		fi = f_ai->next->next;
		f_ai->next->next = NULL;
		while(fi!=NULL)
		{
			temp=fi->next;
			fn=f_ai;
			while(fn->next!=NULL && fn->next->price>fi->price)
				fn=fn->next;
			fi->next=fn->next;
			fn->next=fi;
			fi=temp;
		}
		/*�������*/
		cout<<"�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��\t��Ʊ��\tƱ��"<<endl;
		fi=f_ai->next;
		while(fi!=NULL)
		{
			cout<<fi->data<<" "<<fi->num<<"\t"<<fi->start<<"\t"<<fi->end<<"\t"<<fi->time<<"\t"<<fi->at<<"\t\t"<<fi->count<<"\t"<<fi->price<<endl;
			fi=fi->next;
		}
		cin.sync();
		cout<<"\n����������ػ�Ʊ����ϵͳ��ҳ."<<endl;
		getchar();
		getchar();
	}
	else
	{
		cout<<"û�к�����Ϣ!"<<endl;
		Sleep(2000);
	}
	system("cls");
	if((U_AI.mode=U_AI.load_mode())==1)
		U_AI.login_mf();
	else if(U_AI.mode==0)
		U_AI.login_uf();
}