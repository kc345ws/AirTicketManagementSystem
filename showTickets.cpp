#include"Flight.h"
#include"User.h"
#include"UserTicket.h"
#include<iostream>

void UserTicket::showTickets(bool isback) {
	system("CLS");
	load_ut();//���ļ��м���
	User ui;
	ui.print_item(18);//��ӡ�ҵĻ�Ʊ��Ϣ
	temp = LoginedUser->mg->userTicket->sentine;
	if (!temp->next) {
		cout << "û�й����κλ�Ʊ" << endl;
	}
	else {
		temp = temp->next;
		//ui.print_item(19);
		cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  Ʊ��\t����\t����ʱ��\t����  ȡ��" << endl;
		while (temp) {
			cout << temp->data << " " << temp->num << "\t" << temp->start << "\t" << temp->end << "\t" << temp->time << "\t" << temp->at << "\t"
				<< temp->price << "\t" << temp->Ticketcount << "\t"<<temp->buytime<<"  ";
			if (!temp->isDelay) {//���������
				cout << "��"<<"  ";
			}
			else {
				cout << "��"<<"  ";
			}
			if (!temp->isCancel) {//���û��ȡ��
				cout << "��" << endl;
			}
			else{
				cout << "��" << endl;
			}
			temp = temp->next;
		}
	}
	cout << "�����������������" << endl;
	getchar();
	getchar();
	ui.login_uf();
}