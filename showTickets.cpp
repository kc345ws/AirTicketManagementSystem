#include"Flight.h"
#include"User.h"
#include"UserTicket.h"
#include<iostream>
#include<iomanip>

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
		cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  Ʊ��\t����\t����ʱ��\t ���� ȡ�� ��ת�� ��תʱ��" << endl;
		while (temp) {
			cout.setf(ios::left);
			cout << setw(8) << temp->data << " " << setw(7) <<temp->num << " " << setw(5) <<temp->start << "\t" << setw(5) <<temp->end << "\t" 
				<<setw(11) << temp->time << "\t" <<setw(3) << temp->at << "����"<< "  "<<setw(5)<<temp->price << "  " << temp->Ticketcount << "\t"
				<< setw(12) <<temp->buytime<<"  ";

			/*cout.setf(ios::left);
			cout << setw(8) << fi->data << " " << setw(7) << fi->num << " " << setw(5) << fi->start << "\t" << setw(5) << fi->end << "\t" <<
				setw(11) << fi->time << "\t" << setw(3) << fi->at << "����" << "    " << setw(4) << fi->count << "  " << setw(5) << fi->price << "  "
				<< setw(5) << fi->transit << "\t" << setw(3) << fi->transittime << "����" << endl;*/
			if (!temp->isDelay) {//���������
				cout << "��"<<" ";
			}
			else {
				cout << "��"<<" ";
			}
			if (!temp->isCancel) {//���û��ȡ��
				cout << "��   ";
			}
			else{
				cout << "��   ";
			}
			if(temp->transit=="��") {//���û����ת
				cout.setf(ios::left);
				cout << setw(8) << "��" << setw(5) <<"��"<<endl;
			}
			else {
				cout.setf(ios::left);
				cout << setw(8) << temp->transit << " " << setw(3) <<temp->transittime << "����"<<endl;
			}
			temp = temp->next;
		}
	}
	cout << "�����������������" << endl;
	getchar();
	getchar();
	ui.login_uf();
}