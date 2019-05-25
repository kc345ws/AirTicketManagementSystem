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
		cout << endl;
		cout << "****************************************************************************************************" << endl;
		Flight::minprice(start, end);
		cout << endl;
		cout << "****************************************************************************************************" << endl;
		Flight::mintime(start, end);
		cout << endl;
		cout << "****************************************************************************************************" << endl;
		Flight::minticket(start, end);
		cout << endl;
		cout << "****************************************************************************************************" << endl;
		Flight::mintranstime(start, end);

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
		cout << "��ֱ�ﺽ�࣬Ҳ��������ת���߷���" << endl;
	}
}

void Flight::mindistance(string start, string end)
{
	float Distance = 0;
	GLCT->Dijkstra_Distance(GLCT->getverticesIndex(start), GLCT);
	stack<Vertex_City>* Stack_GLCT = new stack<Vertex_City>();
	if ((Stack_GLCT->size()) > 2) {
		cout << "�����·���Ƽ�:" << endl;
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
			string Tempname = Stack_GLCT->top().verinfor;//ǰһ�����н��

			Stack_GLCT->pop();

			if (!Stack_GLCT->empty()) {
				for (int i = 0; i < GLCT->GraphSize; i++) {
					if (GLCT->vertices[i].verinfor == Tempname) {
						Edge_City* Tempedge = GLCT->vertices[i].adjacent;
						while (Tempedge) {
							if (GLCT->vertices[Tempedge->verAdj].verinfor == Stack_GLCT->top().verinfor)
							{//��һ�����н��
								Distance += Tempedge->distance;
							}
							Tempedge = Tempedge->next;
						}
						break;
					}
				}
			}
		}
		cout << endl;
		cout << "��������:" << Distance << "����" << endl;



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
	else if((Stack_GLCT->size()) == 2){
		cout << start << "->" << end << endl;
		cout << "��ͨ�˺��ߵ�û����Ӧ�ĺ���" << endl;
	}
	else {
		cout << start << "->" << end << endl;
		cout << "û�п�ֱͨ�ﺽ��" << endl;
	}
}


void Flight::minprice(string start, string end)
{
	float Price = 0;
	bool isConnetc = true;
	cout << "������ƽ��Ʊ���Ƽ�:" << endl;
	//GLCT->Dijkstra_Distance(GLCT->getverticesIndex(start), GLCT);
	GLCT->Dijkstra_Pirce(GLCT->getverticesIndex(start), GLCT);
	stack<Vertex_City>* Stack_GLCT = new stack<Vertex_City>();
	for (int i = 0; i < GLCT->GraphSize; i++) {
		if (GLCT->vertices[i].verinfor == end) {
			Stack_GLCT->push(GLCT->vertices[i]);//��������м����ջ
			break;
		}
	}

	while (Stack_GLCT->top().verinfor != start) {//���ջ��Ԫ�ز�Ϊ��ɳ���
		int topindex = GLCT->getverticesIndex(Stack_GLCT->top().verinfor);//ջ��Ԫ���ڶ�����е�����
		int pathindex = GLCT->path[topindex];//Dijkstra�е�ǰ���ڵ�����
		if (pathindex == -1) {
			isConnetc = false;//����ͨ
			cout << "��ͨ�˺��ߣ���û����Ӧ�ĺ���" << endl;
			break;
		}
		Stack_GLCT->push(GLCT->vertices[pathindex]);
	}

	//vector<int> citydistance;
	//int FlightCount = 0;
	if (isConnetc) {
		while (!Stack_GLCT->empty()) {

			if (Stack_GLCT->size() > 1) {
				cout << Stack_GLCT->top().verinfor << "->";
			}
			else {
				cout << Stack_GLCT->top().verinfor;
			}

			string Tempname = Stack_GLCT->top().verinfor;//ǰһ�����н��

			Stack_GLCT->pop();

			if (!Stack_GLCT->empty()) {
				Price += getAverage_price(Tempname, Stack_GLCT->top().verinfor);
				//Price += getPrice_sum(Tempname, Stack_GLCT->top().verinfor);
				//FlightCount += get_count(Tempname, Stack_GLCT->top().verinfor);
			}

		}
		cout << endl;
		cout << "���ƽ��Ʊ��:" << Price << "Ԫ" << endl;



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
}


void Flight::mintime(string start, string end)
{
	float Price = 0;
	bool isConnetc = true;
	cout << "������ƽ������ʱ���Ƽ�:" << endl;
	//GLCT->Dijkstra_Distance(GLCT->getverticesIndex(start), GLCT);
	//GLCT->Dijkstra_Pirce(GLCT->getverticesIndex(start), GLCT);
	GLCT->Dijkstra_Time(GLCT->getverticesIndex(start), GLCT);
	stack<Vertex_City>* Stack_GLCT = new stack<Vertex_City>();
	for (int i = 0; i < GLCT->GraphSize; i++) {
		if (GLCT->vertices[i].verinfor == end) {
			Stack_GLCT->push(GLCT->vertices[i]);//��������м����ջ
		}
	}

	while (Stack_GLCT->top().verinfor != start) {//���ջ��Ԫ�ز�Ϊ��ɳ���
		int topindex = GLCT->getverticesIndex(Stack_GLCT->top().verinfor);//ջ��Ԫ���ڶ�����е�����
		int pathindex = GLCT->path[topindex];//Dijkstra�е�ǰ���ڵ�����
		if (pathindex == -1) {
			isConnetc = false;//����ͨ
			cout << "��ͨ�˺��ߣ���û����Ӧ�ĺ���" << endl;
			break;
		}
		Stack_GLCT->push(GLCT->vertices[pathindex]);
	}

	//vector<int> citydistance;
	if (isConnetc) {
		while (!Stack_GLCT->empty()) {

			if (Stack_GLCT->size() > 1) {
				cout << Stack_GLCT->top().verinfor << "->";
			}
			else {
				cout << Stack_GLCT->top().verinfor;
			}

			string Tempname = Stack_GLCT->top().verinfor;//ǰһ�����н��

			Stack_GLCT->pop();

			if (!Stack_GLCT->empty()) {
				//Price += getAverage_price(Tempname, Stack_GLCT->top().verinfor);
				Price += getAverage_time(Tempname, Stack_GLCT->top().verinfor);
			}
			/*if (!Stack_GLCT->empty()) {
				for (int i = 0; i < GLCT->GraphSize; i++) {
					if (GLCT->vertices[i].verinfor == Tempname) {
						Edge_City* Tempedge = GLCT->vertices[i].adjacent;
						while (Tempedge) {
							if (GLCT->vertices[Tempedge->verAdj].verinfor == Stack_GLCT->top().verinfor)
							{//��һ�����н��
								//Distance += Tempedge->distance;

							}
							Tempedge = Tempedge->next;
						}
						break;
					}
				}
			}*/
		}
		cout << endl;
		cout << "����ƽ������ʱ��:" << Price << "����" << endl;



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
}

void Flight::minticket(string start, string end)
{
	float Price = 0;
	bool isConnetc = true;
	cout << "������ƽ��ʣ��Ʊ���Ƽ�:" << endl;
	//GLCT->Dijkstra_Distance(GLCT->getverticesIndex(start), GLCT);
	//GLCT->Dijkstra_Pirce(GLCT->getverticesIndex(start), GLCT);
	//GLCT->Dijkstra_Time(GLCT->getverticesIndex(start), GLCT);
	GLCT->Dijkstra_Ticket(GLCT->getverticesIndex(start), GLCT);
	stack<Vertex_City>* Stack_GLCT = new stack<Vertex_City>();
	for (int i = 0; i < GLCT->GraphSize; i++) {
		if (GLCT->vertices[i].verinfor == end) {
			Stack_GLCT->push(GLCT->vertices[i]);//��������м����ջ
		}
	}

	while (Stack_GLCT->top().verinfor != start) {//���ջ��Ԫ�ز�Ϊ��ɳ���
		int topindex = GLCT->getverticesIndex(Stack_GLCT->top().verinfor);//ջ��Ԫ���ڶ�����е�����
		int pathindex = GLCT->path[topindex];//Dijkstra�е�ǰ���ڵ�����
		if (pathindex == -1) {
			isConnetc = false;//����ͨ
			cout << "��ͨ�˺��ߣ���û����Ӧ�ĺ���" << endl;
			break;
		}
		Stack_GLCT->push(GLCT->vertices[pathindex]);
	}

	//vector<int> citydistance;
	if (isConnetc) {
		int TicketCount = 0;
		while (!Stack_GLCT->empty()) {

			if (Stack_GLCT->size() > 1) {
				cout << Stack_GLCT->top().verinfor << "->";
			}
			else {
				cout << Stack_GLCT->top().verinfor;
			}

			string Tempname = Stack_GLCT->top().verinfor;//ǰһ�����н��

			Stack_GLCT->pop();

			if (!Stack_GLCT->empty()) {
				//Price += getAverage_price(Tempname, Stack_GLCT->top().verinfor);
				//Price += getAverage_ticket(Tempname, Stack_GLCT->top().verinfor);
				Price += getTicket_sum(Tempname, Stack_GLCT->top().verinfor);
				TicketCount += get_count(Tempname, Stack_GLCT->top().verinfor);
			}

		}
		cout << endl;
		cout << "����ƽ��ʣ��Ʊ��:" << Price / TicketCount << "��" << endl;



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
}

void Flight::mintranstime(string start, string end)
{
	float Price = 0;
	bool isConnetc = true;
	cout << "������ƽ����תʱ���Ƽ�:" << endl;
	//GLCT->Dijkstra_Distance(GLCT->getverticesIndex(start), GLCT);
	//GLCT->Dijkstra_Pirce(GLCT->getverticesIndex(start), GLCT);
	//GLCT->Dijkstra_Time(GLCT->getverticesIndex(start), GLCT);
	GLCT->Dijkstra_Transittime(GLCT->getverticesIndex(start), GLCT);
	stack<Vertex_City>* Stack_GLCT = new stack<Vertex_City>();
	for (int i = 0; i < GLCT->GraphSize; i++) {
		if (GLCT->vertices[i].verinfor == end) {
			Stack_GLCT->push(GLCT->vertices[i]);//��������м����ջ
		}
	}

	while (Stack_GLCT->top().verinfor != start) {//���ջ��Ԫ�ز�Ϊ��ɳ���
		int topindex = GLCT->getverticesIndex(Stack_GLCT->top().verinfor);//ջ��Ԫ���ڶ�����е�����
		int pathindex = GLCT->path[topindex];//Dijkstra�е�ǰ���ڵ�����
		if (pathindex == -1) {
			isConnetc = false;//����ͨ
			cout << "��ͨ�˺��ߣ���û����Ӧ�ĺ���" << endl;
			break;
		}
		Stack_GLCT->push(GLCT->vertices[pathindex]);
	}

	//vector<int> citydistance;
	if (isConnetc) {
		while (!Stack_GLCT->empty()) {

			if (Stack_GLCT->size() > 1) {
				cout << Stack_GLCT->top().verinfor << "->";
			}
			else {
				cout << Stack_GLCT->top().verinfor;
			}

			string Tempname = Stack_GLCT->top().verinfor;//ǰһ�����н��

			Stack_GLCT->pop();

			if (!Stack_GLCT->empty()) {
				//Price += getAverage_price(Tempname, Stack_GLCT->top().verinfor);
				//Price += getAverage_time(Tempname, Stack_GLCT->top().verinfor);
				Price += getAverage_transtime(Tempname, Stack_GLCT->top().verinfor);
			}
			/*if (!Stack_GLCT->empty()) {
				for (int i = 0; i < GLCT->GraphSize; i++) {
					if (GLCT->vertices[i].verinfor == Tempname) {
						Edge_City* Tempedge = GLCT->vertices[i].adjacent;
						while (Tempedge) {
							if (GLCT->vertices[Tempedge->verAdj].verinfor == Stack_GLCT->top().verinfor)
							{//��һ�����н��
								//Distance += Tempedge->distance;

							}
							Tempedge = Tempedge->next;
						}
						break;
					}
				}
			}*/
		}
		cout << endl;
		cout << "����ƽ����תʱ��:" << Price << "����" << endl;



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
}
