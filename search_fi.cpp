#include "Flight.h"
#include "User.h"
#include <sstream>
#include <iostream>

using namespace std;

void Flight::search_fi()	//������Ų��Һ�����Ϣ
{
	int i;
	int success=0;
	char ch;
	User U_AI;
	char str[5],des[5];
	char str1[5];

	system("cls");
	browse_fi(false);
	U_AI.print_item(12);
	if((flight_num=load_fn())==0)
	{
		cout<<"û�к�����Ϣ�ɹ�����!"<<endl;
		Sleep(2000);
		system("cls");
		if((U_AI.mode=U_AI.load_mode())==1)
			U_AI.login_mf();
		else if(U_AI.mode==0)
			U_AI.login_uf();		
	}
	else
	{
		load_fil();
		input_sfi(1,0,1);
		ostringstream oss,oss1;
		for(i=0;i<11;i++)
		{
			if(i>5)
				oss1<<fn->time[i];
			else if(i>=0 && i<5)
				oss<<fn->time[i];
		}
		
		istringstream iss(oss.str());
		istringstream iss1(oss1.str());

		iss>>str;
		iss1>>des;

		fi=flight->next;
		cout<<"\n��ѯ�ɹ�!"<<endl;
		cout<<"������Ϣ����:\n";
		cout<<"�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��\t��Ʊ��\tƱ��"<<endl;		
		while(fi!=NULL)
		{
			ostringstream oss2;
			for(i=0;i<5;i++)
			{
				oss2<<fi->time[i];
			}
			istringstream iss2(oss2.str());
			iss2>>str1;

			if(strcmp(fi->start,fn->start)==0 && strcmp(fi->end,fn->end)==0 && strcmp(str1,str)>=0 && strcmp(str1,des)<=0)
			{
				success=1;
				cout<<fi->data<<" "<<fi->num<<"\t"<<fi->start<<"\t"<<fi->end<<"\t"<<fi->time<<"\t"<<fi->at<<"\t\t"<<fi->count<<"\t"<<fi->price<<endl;
			}
			fi=fi->next;
		}
		if(success==0)
		{
			system("cls");
			cout<<"\nû������Ҫ����Ϣ!"<<endl;
		}
		cin.sync();
F:		cout<<"\n�Ƿ��������?(y(��),n(��))"<<endl;
		cin>>ch;
		if(ch!='Y' && ch!='y' && ch!='N' && ch!='n')
		{
			cout<<"��������!����������!"<<endl;
			system("cls");
			goto F;
		}
		else if(ch=='y' || ch=='Y')
		{
			system("cls");
			search_fi();
		}
		else if(ch=='n' || ch=='N')
		{
			system("cls");
			if((U_AI.mode=U_AI.load_mode())==1)
				U_AI.login_mf();
			else if(U_AI.mode==0)
				U_AI.login_uf();	
		}
	}
}
