#include"UserTicket.h"
#include<iostream>
#include<iomanip>

void UserTicket::showCancel_ut() {
	User UI;
	system("CLS");
	UI.print_item(22);
	LoginedUser->mg->userTicket->load_ut();
	UserTicket::Ticket* tempticket = LoginedUser->mg->userTicket->sentine->next;
	bool isfound = false;
	cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  Ʊ��\t����\t����ʱ��\t ���� ȡ�� ��ת�� ��תʱ��" << endl;
	while (tempticket) {
		if (tempticket->isCancel) {
			isfound = true;
			cout.setf(ios::left);
			cout << setw(8) << tempticket->data << " " << setw(7) << tempticket->num << " " << setw(5) << tempticket->start << "\t" << setw(5) << tempticket->end << "\t"
				<< setw(11) << tempticket->time << "\t" << setw(3) << tempticket->at << "����" << "  " << setw(5) << tempticket->price << "  " << tempticket->Ticketcount << "\t"
				<< setw(17) << tempticket->buytime << "  ";

			if (!tempticket->isDelay) {//���������
				cout << "��" << " ";
			}
			else {
				cout << "��" << " ";
			}
			if (!tempticket->isCancel) {//���û��ȡ��
				cout << "��   ";
			}
			else {
				cout << "��   ";
			}
			if (tempticket->transit == "��") {//���û����ת
				cout.setf(ios::left);
				cout << setw(10) << "��" << setw(8) << "��" << endl;
			}
			else {
				cout.setf(ios::left);
				cout << setw(8) << tempticket->transit << " " << setw(3) << tempticket->transittime << "����" << endl;
			}
			//temp = temp->next;
		}
		tempticket = tempticket->next;
	}

	if (!isfound) {
		cout << "û���κη�������ȡ���Ļ�Ʊ" << endl;
	}
	cout << "�����������������" << endl;
	getchar();
	getchar();
	UI.login_uf();
}