#include"Flight.h"
#include"User.h"
#include"UserTicket.h"
#include<iostream>
#include<iomanip>

void Flight::showzeroTicket_fl() {
	User U_AI;

	system("cls");
	U_AI.print_item(24);
	if ((flight_num = load_fn()) == 0)		//�жϺ�����Ϣ�Ƿ�Ϊ��
	{
		cout << "�޺�����Ϣ�ɹ���ʾ!" << endl;
		Sleep(2000);
	}
	else	//��������Ϣ��Ϊ��ʱ������ִ�����²���
	{
		cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  ��Ʊ��  Ʊ��  ��ת��\t��תʱ��" << endl;
		load_fil();
		fi = flight->next;
		while (fi != NULL)
		{
			if (fi->count == 0) {
				cout.setf(ios::left);
				cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
					setw(11) << fi->time << "\t" << setw(3) << fi->at << "����" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
					<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "����" << endl;
			}
			fi = fi->next;
		}
	}
}