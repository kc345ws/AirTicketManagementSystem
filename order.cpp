//��Ʊ
#include "Flight.h"
#include "User.h"
#include"UserTicket.h"
#include <iostream>
#include<iomanip>

using namespace std;
void changechar(char ch[], int changeobjID, UserTicket::Ticket* info);//�޸�char���͵�����

void Flight::order()		//��Ʊ
{
	User U_AI;
	Flight F;
	int success=0;
	bool exist = false;

	system("cls");
	string choice;
	//U_AI.print_item(14);
	//current_time();
	if((flight_num=load_fn())==0)	//û�к�����Ϣ�ɹ�Ԥ��
	{
		cout<<"û�к�����Ϣ!�޷��ṩԤ������!"<<endl;
		cout<<"������ת����Ʊ����ϵͳ��ҳ..."<<endl;
		Sleep(1000);
		goto loop2;
	}
	else					//���ں�����Ϣʱ�������������²���
	{
		Sleep(2000);
		browse_fi(false);
		U_AI.print_item(14);
		current_time();
		input_sfi(1,0,0);
		load_fil();
		//cout<<"�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��\t��Ʊ��\tƱ�� ��ת�� ��תʱ��"<<endl;
		cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  ��Ʊ��  Ʊ��  ��ת��\t��תʱ�� ����" << endl;
		for(fi=flight->next;fi!=NULL;fi=fi->next)
		{
			if(strcmp(fi->start,fn->start)==0 && strcmp(fi->end,fn->end)==0)
			{
				exist = true;
				//cout<<fi->data<<" "<<fi->num<<"\t"<<fi->start<<"\t"<<fi->end<<"\t"<<fi->time<<"\t"<<fi->at<<"\t\t"<<fi->count<<"\t"<<fi->price<<" "<<fi->transit<<" "<< fi->transittime<<endl;
				cout.setf(ios::left);
				cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
					setw(11) << fi->time << "\t" << setw(3) << fi->at << "����" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
					<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "����" <<"  " ;
				if (fi->isDelay) {
					cout << "��" << endl;
				}
				else {
					cout << "��" << endl;
				}
			}
		}
		if(!exist)
			goto Nofind;
		input_sfi(0,1,0);
		for(fi=flight->next;fi!=NULL;fi=fi->next)
		{
			if(strcmp(fi->num,fn->num)==0 && strcmp(fi->data,fn->data) == 0)
			{
				if(fn->count<=0)//����Ķ�Ʊ��С�ڵ���0
				{
					cout<<"���붩Ʊ����Ч!"<<endl;
					cout << "�Ƿ������Ʊ(y/n)?" << endl;
					cin >> choice;
					if (choice == "y" || choice == "Y") {
						order();
					}
					else {
						U_AI.login_uf();
					}
					break;
				}
				else if(fi->count>=fn->count)
				{
					success = 1;
					fi->count = fi->count - fn->count;
					cout<<"��Ʊ�ɹ�!"<<endl;
					Sleep(2000);
					system("cls");
					cout<<"�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��\t��Ʊ��\tƱ�� ����"<<endl;
					
					cout<<fi->data<<" "<<fi->num<<"\t"<<fi->start<<"\t"<<fi->end<<"\t"<<fi->time<<"\t"<<fi->at<<"\t\t"<<fi->count<<"\t"<<fi->price<<"  "<<endl;
					if (fi->isDelay) {
						cout << "��" << endl;
					}
					else {
						cout << "��" << endl;
					}

					/*if(fi->count==0)//�����Ʊ��ʣ��Ʊ��Ϊ0
					{
						fi->prior->next = fi->next;//���ú����ǰһ���������һ��������Ϊ�ú������һ������
						fi->next->prior = fi->prior;//�ú������һ�������ǰһ��������Ϊ�ú����ǰһ������
						delete fi;
						--flight_num;//����������1
						save_fn();
					}*/

					//***********************************************
					//����Ʊ��Ϣ��ӵ��û���Ʊ��
					LoginedUser->mg->userTicket->addTicket(fi,fn->count);

					//************************************************/
					save_fil();
					cout << "�Ƿ������Ʊ(y/n)?" << endl;
					cin >> choice;
					if (choice == "y" || choice == "Y") {
						order();
					}
					else {
						U_AI.login_uf();
					}

					break;
				}
				else if(fi->count>0 && fi->count<fn->count)
				{
					cout<<"��Ʊ����!�޷���ɶ�Ʊ!"<<endl;
					cout<<"�����¶�Ʊ!"<<endl;
					cout << "�Ƿ������Ʊ(y/n)?" << endl;
					cin >> choice;
					if (choice == "y" || choice == "Y") {
						order();
					}
					else {
						U_AI.login_uf();
					}
					break;
				}
				else if(fi->count==0)//ҪԤ�������ʣ��Ʊ��
				{
					cout<<"�ú���Ʊ���ۿ�!��Ļ����ඩ��!"<<endl;
					cout << "�Ƿ������Ʊ(y/n)?" << endl;
					cin >> choice;
					if (choice == "y" || choice == "Y") {
						order();
					}
					else {
						U_AI.login_uf();
					}
					break;
				}
			}
		}

		cout << "�������Ϣ����" << endl;
		cout << "�Ƿ������Ʊ(y/n)?" << endl;
		cin >> choice;
		if (choice == "y" || choice == "Y") {
			order();
		}
		else {
			U_AI.login_uf();
		}
		


Nofind:	if(success==0)
		{//��ֱ�ﺽ��
			system("cls");
			F.recommendTransit(fn->start, fn->end);
			//cout<<"û�к�����Ϣ�����ۿ�!"<<endl;
			cout << "�Ƿ������Ʊ(y/n)?" << endl;
			cin >> choice;
			if (choice == "y" || choice == "Y") {
				order();
			}
			else {
				U_AI.login_uf();
			}
		}
		save_fil();
loop2:	Sleep(2000);
		if((U_AI.mode=U_AI.load_mode())==1)
			U_AI.login_mf();
		else if(U_AI.mode==0)
			U_AI.login_uf();
	}
}

void changechar(char ch[], int changeobjID, UserTicket::Ticket* info) {//�޸�char���͵�����

	if (changeobjID == 1) {//���Ҫ�޸ĺ�������
		for (int i = 0; i < strlen(ch); i++) {
			info->data[i] = ch[i];
		}
	}
	else if (changeobjID == 2) {
		for (int i = 0; i < strlen(ch); i++) {
			info->num[i] = ch[i];
		}
	}
	else if (changeobjID == 3) {
		for (int i = 0; i < strlen(ch); i++) {
			info->start[i] = ch[i];
		}
	}
	else if (changeobjID == 4) {
		for (int i = 0; i < strlen(ch); i++) {
			info->end[i] = ch[i];
		}
	}
	else if (changeobjID == 5) {
		for (int i = 0; i < strlen(ch); i++) {
			info->time[i] = ch[i];
		}
	}
	else if (changeobjID == 6) {
		for (int i = 0; i < strlen(ch); i++) {
			info->at[i] = ch[i];
		}
	}
	else if (changeobjID == 7) {
		for (int i = 0; i < strlen(ch); i++) {
			info->buytime[i] = ch[i];
		}
	}
}