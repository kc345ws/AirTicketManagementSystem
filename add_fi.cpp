//����Ա��Ӻ�����Ϣ
#include "Ticket.h"
#include "Ticket1.h"
#include <iostream>

using namespace std;

void Flight::add_fi()		//��Ӻ�����Ϣ
{
	int i=0;
	User U_AI;

	system("cls");
	U_AI.print_item(10);

	load_fil();				//���ļ��к�����Ϣװ�ص�����
	input_fi();				//����Ҫ��ӵĺ�����Ϣ
	Inser_fi();				//�Ѻ�����Ϣ������˳���������
	save_fil();				//���º�����Ϣ�����浽�ļ�

	++flight_num;			//��������1
	save_fn();				//���溽������

	cout<<"\n���ڽ��к�����Ϣ¼��..."<<endl;
	Sleep(2000);
	system("cls");
	cout<<"������Ϣ¼��ɹ�!"<<endl;
	cout<<"������ת����Ϣ����ϵͳ��ҳ..."<<endl;
	Sleep(2000);
	system("cls");
	U_AI.login_mf();
}
