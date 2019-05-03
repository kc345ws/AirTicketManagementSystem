//�û��͹���Ա��½
#include "Flight.h"
#include "User.h"
#include <iostream>

using namespace std;

void User::print_login()	//��ӡ��½�ɹ�����
{
	system("cls");
	cout<<"��½�ɹ�!"<<endl;
	cout<<"���������Ʊ����ϵͳ,���Ժ�..."<<endl;
	Sleep(1000);
	if((mode=load_mode())==1)
		login_mf();
	else if(mode==0)
		login_uf();
}

void User::input_loop()		//ѭ��ѡ���
{
	char relogin;			//�����ж��Ƿ���������
	cout<<"�Ƿ���������!(y(��),n(��))!"<<endl;
	cin>>relogin;
	if(relogin!='Y' && relogin!='y' && relogin!='N' && relogin!='n')
	{
		cout<<"��������!����������!"<<endl;
		Sleep(1000);
		system("cls");
		input_loop();
	}
	else if(relogin=='Y' || relogin=='y')
	{		
		system("cls");
		if((mode=load_mode())==1)
			login_m();  
		else if(mode==0)
			login_u();
	}
	else if(relogin=='N' || relogin=='n')
	{
		system("cls");
		mode=-1;
		save_mode();
		identify();
	}	
}

void User::login_m() 		//����Ա��½
{
	int success=0;				//�����ж��Ƿ��½�ɹ���ȫ�ֱ���

	system("cls");
	mode=1;
	save_mode();
	if((judge=load_judge())==0)	//�ж��Ƿ����״�ʹ�ø�ϵͳ
	{
		print_item(3);
		input_linfo();
	}
	else		/*��������״ε�¼��ϵͳ��ֱ���������Ա���������뼴��*/
	{
		print_item(4);
		input_linfo();
	}
	if(strcmp(mg->id,"admin")==0 && strcmp(mg->passport,"admin")==0)
	{
		success = 1;
		++judge;
		save_judge();
//		save_lfui();
		print_login();
	}
	if(success==0)	//��¼ʧ��
	{
		system("cls");
		cout<<"�����û�������������!"<<endl;
		input_loop();
	}
}
	   
void User::login_u()		//�û���¼
{
	int success=0;			//�����ж��Ƿ��½�ɹ���ȫ�ֱ���
	system("cls");
	mode=0;
	save_mode();
	if((user_num=load_un())==0)	//�ж��Ƿ����û���Ϣ
	{
		print_item(5);
		Sleep(1000);
		system("cls");
		cout<<"������ת�����˵�����ע��..."<<endl;
		Sleep(1000);
		home();
	}
	else		//���û���Ϣʱ���������²���
	{
		print_item(6);
		input_linfo();
		load_list();
		ui=user->next;
		while(ui!=NULL)
		{
			if(strcmp(mg->id,ui->id)==0 && strcmp(mg->passport,ui->passport)==0)	//���ڸ��û�����Ϣʱ����success��1
			{
				success=1;

				//��½�ʺ�����������˺�
				LoginedUser->mg = mg;
				//LoginedUser->mg->userTicket = mg->userTicket;
				break;
			}
			ui=ui->next;
		}
	}
	if(success==1)	//successΪ1ʱ,��ת����Ʊ����ϵͳ
	{
		print_login();
	}
	else			//successΪ0ʱ����Ӧ����
	{
		system("cls");
		cout<<"�����û�������������!"<<endl;
		Sleep(1000);
		input_loop();
	}
}