#include "Flight.h"
#include "User.h"
#include <iostream>
#include<iomanip>

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
		cout<<"�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  ��Ʊ��  Ʊ��  ��ת��\t��תʱ�� ����"<<endl;
		load_fil();
		fi=flight->next;
		while(fi!=NULL)
		{
			cout.setf(ios::left);
			cout<< setw(8) <<fi->data<<" "<< setw(7) <<fi->num<<" "<< setw(5) <<fi->start<<"\t"<< setw(5) <<fi->end<<"\t"<< 
				setw(11) <<fi->time<<"\t"<< setw(3) <<fi->at << "����" <<"    "<< setw(4) <<fi->count<<"  "<< setw(5) <<fi->price<<"  "
				<< setw(5) <<fi->transit<< "\t"<<setw(3) <<fi->transittime<<"����"<<"   ";
			if (fi->isDelay) {
				cout << "��" << endl;
			}
			else {
				cout << "��" << endl;
			}
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
