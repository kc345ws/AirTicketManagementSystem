#include"User.h"
#include"UserTicket.h"
#include"Flight.h"
#include<iostream>
#include<iomanip>

void User::RecommendFlight() {
	UserTicket::Ticket *delayticket = LoginedUser->mg->userTicket->sentine->next;
	string delaystart[100];
	string delayend[100];
	int count = 0;
	while (delayticket) {
		if (delayticket->isDelay) {
			delaystart[count] = delayticket->start;
			delayend[count] = delayticket->end;
			count++;
		}
		delayticket = delayticket->next;
	}
	cout << "����Ϊ���󺽰��Ƽ�������δ���󺽰�" << endl;
	cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  Ʊ��\t���� ����  ��ת�� ��תʱ��" << endl;
	
	Flight F;
	F.load_fil();
	for (int i = 0; i < count; i++) {
		//delayticket = LoginedUser->mg->userTicket->sentine->next;
		Flight::FlightInfo* tempinfo = F.flight->next;
		cout << delaystart[i] << "->" << delayend[i] << ":"<<endl;
		while (tempinfo) {
			if (tempinfo->start == delaystart[i] && tempinfo->end == delayend[i]&&!tempinfo->isDelay) {
				cout.setf(ios::left);
				cout << setw(8) << tempinfo->data << " " << setw(7) << tempinfo->num << " " << setw(5) << tempinfo->start << "\t" << setw(5) << tempinfo->end << "\t"
					<< setw(11) << tempinfo->time << "\t" << setw(3) << tempinfo->at << "����" << "  " << setw(5) << tempinfo->price << "  " <<setw(3) <<tempinfo->count<< " "
					<< "  ";

				if (!tempinfo->isDelay) {//���������
					cout << "��" << "   ";
				}
				else {
					cout << "��" << "   ";
				}
				if (tempinfo->transit == "��") {//���û����ת
					cout.setf(ios::left);
					cout << setw(10) << "��" << setw(8) << "��" << endl;
				}
				else {
					cout.setf(ios::left);
					cout << setw(8) << tempinfo->transit << " " << setw(3) << tempinfo->transittime << "����" << endl;
				}
			}
			tempinfo = tempinfo->next;
		}
	}
	
}