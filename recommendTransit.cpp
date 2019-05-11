#include"Flight.h"
#include"City.h"
#include<iostream>
#include<iomanip>

using namespace std;

void Flight::recommendTransit(string start, string end)
{
	if (GLCT->CheckMain(start, end)) {
		cout << "��ֱ�ﺽ�࣬����Ϊ�Ƽ�����ת����" << endl;
		string start = start;
		//string end = GLCT->recommentCity->front();
		//GLCT->recommentCity->pop();
		
		while (!GLCT->recommentCity_Distance->empty()) {//����ת���ж��в���ʱ
			Flight::FlightInfo* tempinfo = Flight::flight->next;
			
			
			while (tempinfo) {
				if (tempinfo->start == start && tempinfo->end == end) {
					cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  ��Ʊ��  Ʊ��  ��ת��\t��תʱ�� ����" << endl;
					cout.setf(ios::left);
					cout << setw(8) << tempinfo->data << " " << setw(7) << tempinfo->num << " " << setw(5) << tempinfo->start << "\t" << setw(5) << tempinfo->end << "\t" <<
						setw(11) << tempinfo->time << "\t" << setw(3) << tempinfo->at << "����" << "    " << setw(4) << tempinfo->count << "  " << setw(5) << tempinfo->price << "  "
						<< setw(5) << tempinfo->transit << "\t" << setw(3) << tempinfo->transittime << "����" << "   ";
					if (tempinfo->isDelay) {
						cout << "��" << endl;
					}
					else {
						cout << "��" << endl;
					}

				}

				tempinfo = tempinfo->next;
			}

			start = end;
			//end = GLCT->recommentCity->front();
			//GLCT->recommentCity->pop();
		}
	}
	else {
		cout << "��ֱ�ﺽ�࣬Ҳ��������ת����" << endl;
	}
}