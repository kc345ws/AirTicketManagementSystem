//��Ʊ
#include "Flight.h"
#include "User.h"
#include <iostream>

using namespace std;
void changechar(char ch[], int changeobjID, UserTicket::Ticket* info);//�޸�char���͵�����

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
				if(fn->count<=0)//����Ķ�Ʊ��С�ڵ���0
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
					if(fi->count==0)//�����Ʊ��ʣ��Ʊ��Ϊ0
					{
						fi->prior->next = fi->next;//���ú����ǰһ���������һ��������Ϊ�ú������һ������
						fi->next->prior = fi->prior;//�ú������һ�������ǰһ��������Ϊ�ú����ǰһ������
						delete fi;
						--flight_num;//����������1
						save_fn();
					}

					//***********************************************
					//����Ʊ��Ϣ��ӵ��û���Ʊ��
					//LoginedUser->userTicket->next;
					UserTicket* TempUT;
					UserTicket::Ticket* TempPorior;
					TempUT->temp =LoginedUser->userTicket->sentine;
					while (TempUT->temp->next) {
						TempUT->temp = TempUT->temp->next;
					}
					TempUT->temp->next = new UserTicket::Ticket();
					TempPorior = TempUT->temp;
					TempUT->temp = TempUT->temp->next;
					changechar(fi->data, 1, TempUT->temp);
					changechar(fi->num, 2, TempUT->temp);
					changechar(fi->start, 3, TempUT->temp);
					changechar(fi->end, 4, TempUT->temp);
					changechar(fi->time, 5, TempUT->temp);
					changechar(fi->at, 6, TempUT->temp);
					TempUT->temp->price = fi->price;

					time_t tm;
					time(&tm);
					char tmp[128] = { NULL };
					strcpy(tmp, ctime(&tm));
					changechar(tmp, 7, TempUT->temp);
					//δ���***********************************

					TempUT->temp->prior = TempPorior;//����ǰ�̽��
					TempUT->temp->next = nullptr;
					//***********************************************
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
				else if(fi->count==0)//ҪԤ�������ʣ��Ʊ��
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