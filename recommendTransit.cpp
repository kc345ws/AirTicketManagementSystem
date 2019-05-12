#include"Flight.h"
#include"City.h"
#include<stack>
#include<iostream>
#include<iomanip>

using namespace std;

void Flight::recommendTransit(string start, string end)
{
	if (GLCT->CheckMain(start, end)) {
		cout << "��ֱ�ﺽ�࣬����Ϊ�Ƽ�����ת����" << endl;
		//string start = start;


		Flight::mindistance(start, end);

		/*GLCT->Dijkstra_Distance(GLCT->getverticesIndex(start), GLCT);
		stack<Vertex_City> *Stack_GLCT = new stack<Vertex_City>();
		for (int i = 0; i < GLCT->GraphSize; i++) {
			if (GLCT->vertices[i].verinfor == end) {
				Stack_GLCT->push(GLCT->vertices[i]);//��������м����ջ
			}
		}
		
		while (Stack_GLCT->top().verinfor != start) {//���ջ��Ԫ�ز�Ϊ��ɳ���
			int topindex = GLCT->getverticesIndex(Stack_GLCT->top().verinfor);//ջ��Ԫ���ڶ�����е�����
			int pathindex = GLCT->path[topindex];//Dijkstra�е�ǰ���ڵ�����
			Stack_GLCT->push(GLCT->vertices[pathindex]);
		}
		
		while (!Stack_GLCT->empty()) {
			if (Stack_GLCT->size() > 1) {
				cout << Stack_GLCT->top().verinfor << "->";
			}
			else {
				cout << Stack_GLCT->top().verinfor;
			}
			Stack_GLCT->pop();
		}
		cout << endl;*/




		//string end = GLCT->recommentCity->front();
		//GLCT->recommentCity->pop();
		
		/*while (!GLCT->recommentCity_Distance->empty()) {//����ת���ж��в���ʱ
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
		}*/
	}
	else {
		cout << "��ֱ�ﺽ�࣬Ҳ��������ת����" << endl;
	}
}

void Flight::mindistance(string start, string end)
{
	cout << "�����·���Ƽ�:" << endl;
	GLCT->Dijkstra_Distance(GLCT->getverticesIndex(start), GLCT);
		stack<Vertex_City> *Stack_GLCT = new stack<Vertex_City>();
		for (int i = 0; i < GLCT->GraphSize; i++) {
			if (GLCT->vertices[i].verinfor == end) {
				Stack_GLCT->push(GLCT->vertices[i]);//��������м����ջ
			}
		}
		
		while (Stack_GLCT->top().verinfor != start) {//���ջ��Ԫ�ز�Ϊ��ɳ���
			int topindex = GLCT->getverticesIndex(Stack_GLCT->top().verinfor);//ջ��Ԫ���ڶ�����е�����
			int pathindex = GLCT->path[topindex];//Dijkstra�е�ǰ���ڵ�����
			Stack_GLCT->push(GLCT->vertices[pathindex]);
		}
		
		//vector<int> citydistance;
		while (!Stack_GLCT->empty()) {

			if (Stack_GLCT->size() > 1) {
				cout << Stack_GLCT->top().verinfor << "->";
			}
			else {
				cout << Stack_GLCT->top().verinfor;
			}
			Stack_GLCT->pop();
		}
		cout << endl;


		
		int transtime = 0;//��ת����
		for (int i = 0; i < GLCT->GraphSize; i++) {
			if (GLCT->vertices[i].verinfor == end) {
				Stack_GLCT->push(GLCT->vertices[i]);//��������м����ջ
			}
		}
		while (Stack_GLCT->top().verinfor != start) {//���ջ��Ԫ�ز�Ϊ��ɳ���
			int topindex = GLCT->getverticesIndex(Stack_GLCT->top().verinfor);//ջ��Ԫ���ڶ�����е�����
			int pathindex = GLCT->path[topindex];//Dijkstra�е�ǰ���ڵ�����
			Stack_GLCT->push(GLCT->vertices[pathindex]);
			transtime++;
		}

		string startcity = Stack_GLCT->top().verinfor;
		Stack_GLCT->pop();
		string endcity = Stack_GLCT->top().verinfor;
		Stack_GLCT->pop();
		load_fil();
		for (int i = 0; i < transtime; i++) {
			FlightInfo* tempinfo = flight->next;
			cout << startcity << "->" << endcity << "���Ƽ�����" << endl;
			cout << "�������� �����\t��ʼ��\tĿ�ĵ�\t��ʱ��\t����ʱ��  ��Ʊ��  Ʊ��  ��ת��\t��תʱ�� ����" << endl;
			while (tempinfo) {
				if (tempinfo->start == startcity && tempinfo->end == endcity) {
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
			startcity = endcity;
			if (!Stack_GLCT->empty()) {
				endcity = Stack_GLCT->top().verinfor;
				Stack_GLCT->pop();
			}
		}		
}