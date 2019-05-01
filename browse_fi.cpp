#include "Flight.h"
#include "User.h"
#include <iostream>

using namespace std;

void Flight::browse_fi(bool isback) 	//���������Ϣ
{
	User U_AI;
	
	system("cls");
	U_AI.print_item(11);
	if((flight_num=load_fn())==0)		//�жϺ�����Ϣ�Ƿ�Ϊ��
	{
		cout<<"�޺�����Ϣ�ɹ���ʾ!"<<endl;
		Sleep(2000);
	}
	else	//��������Ϣ��Ϊ��ʱ������ִ�����²���
	{
		cout<<"�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��\t��Ʊ��\tƱ��"<<endl;
		load_fil();
		fi=flight->next;
		while(fi!=NULL)
		{
			cout<<fi->data<<" "<<fi->num<<"\t"<<fi->start<<"\t"<<fi->end<<"\t"<<fi->time<<"\t"<<fi->at<<"\t\t"<<fi->count<<"\t"<<fi->price<<endl;
			fi=fi->next;
		}
		
	}

	if (isback) {
		cin.sync();
		cout << "\n\n������������ػ�Ʊ����ϵͳ��ҳ\n";
		getchar();
		getchar();
		system("cls");
		U_AI.mode = U_AI.load_mode();
		if (U_AI.mode == 1)
			U_AI.login_mf();
		else if (U_AI.mode == 0)
			U_AI.login_uf();
	}
}
