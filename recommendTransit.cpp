#include"Flight.h"
#include"City.h"
#include<stack>
#include<iostream>
#include<iomanip>

using namespace std;

void Flight::recommendTransit(string start, string end)
{
	if (GLCT->CheckMain(start, end)) {
		cout << "无直达航班，以下为推荐的中转方案" << endl;
		//string start = start;


		Flight::mindistance(start, end);

		/*GLCT->Dijkstra_Distance(GLCT->getverticesIndex(start), GLCT);
		stack<Vertex_City> *Stack_GLCT = new stack<Vertex_City>();
		for (int i = 0; i < GLCT->GraphSize; i++) {
			if (GLCT->vertices[i].verinfor == end) {
				Stack_GLCT->push(GLCT->vertices[i]);//将降落城市加入堆栈
			}
		}
		
		while (Stack_GLCT->top().verinfor != start) {//如果栈顶元素不为起飞城市
			int topindex = GLCT->getverticesIndex(Stack_GLCT->top().verinfor);//栈顶元素在顶点表中的索引
			int pathindex = GLCT->path[topindex];//Dijkstra中的前驱节点索引
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
		
		/*while (!GLCT->recommentCity_Distance->empty()) {//当中转城市队列不空时
			Flight::FlightInfo* tempinfo = Flight::flight->next;
			
			
			while (tempinfo) {
				if (tempinfo->start == start && tempinfo->end == end) {
					cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  余票数  票价  中转地\t中转时间 延误" << endl;
					cout.setf(ios::left);
					cout << setw(8) << tempinfo->data << " " << setw(7) << tempinfo->num << " " << setw(5) << tempinfo->start << "\t" << setw(5) << tempinfo->end << "\t" <<
						setw(11) << tempinfo->time << "\t" << setw(3) << tempinfo->at << "分钟" << "    " << setw(4) << tempinfo->count << "  " << setw(5) << tempinfo->price << "  "
						<< setw(5) << tempinfo->transit << "\t" << setw(3) << tempinfo->transittime << "分钟" << "   ";
					if (tempinfo->isDelay) {
						cout << "是" << endl;
					}
					else {
						cout << "否" << endl;
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
		cout << "无直达航班，也无其他中转方案" << endl;
	}
}

void Flight::mindistance(string start, string end)
{
	cout << "按最短路程推荐:" << endl;
	GLCT->Dijkstra_Distance(GLCT->getverticesIndex(start), GLCT);
		stack<Vertex_City> *Stack_GLCT = new stack<Vertex_City>();
		for (int i = 0; i < GLCT->GraphSize; i++) {
			if (GLCT->vertices[i].verinfor == end) {
				Stack_GLCT->push(GLCT->vertices[i]);//将降落城市加入堆栈
			}
		}
		
		while (Stack_GLCT->top().verinfor != start) {//如果栈顶元素不为起飞城市
			int topindex = GLCT->getverticesIndex(Stack_GLCT->top().verinfor);//栈顶元素在顶点表中的索引
			int pathindex = GLCT->path[topindex];//Dijkstra中的前驱节点索引
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


		
		int transtime = 0;//中转次数
		for (int i = 0; i < GLCT->GraphSize; i++) {
			if (GLCT->vertices[i].verinfor == end) {
				Stack_GLCT->push(GLCT->vertices[i]);//将降落城市加入堆栈
			}
		}
		while (Stack_GLCT->top().verinfor != start) {//如果栈顶元素不为起飞城市
			int topindex = GLCT->getverticesIndex(Stack_GLCT->top().verinfor);//栈顶元素在顶点表中的索引
			int pathindex = GLCT->path[topindex];//Dijkstra中的前驱节点索引
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
			cout << startcity << "->" << endcity << "的推荐航班" << endl;
			cout << "航班日期 航班号\t起始地\t目的地\t起降时间\t飞行时间  余票数  票价  中转地\t中转时间 延误" << endl;
			while (tempinfo) {
				if (tempinfo->start == startcity && tempinfo->end == endcity) {
					cout.setf(ios::left);
					cout << setw(8) << tempinfo->data << " " << setw(7) << tempinfo->num << " " << setw(5) << tempinfo->start << "\t" << setw(5) << tempinfo->end << "\t" <<
						setw(11) << tempinfo->time << "\t" << setw(3) << tempinfo->at << "分钟" << "    " << setw(4) << tempinfo->count << "  " << setw(5) << tempinfo->price << "  "
						<< setw(5) << tempinfo->transit << "\t" << setw(3) << tempinfo->transittime << "分钟" << "   ";
					if (tempinfo->isDelay) {
						cout << "是" << endl;
					}
					else {
						cout << "否" << endl;
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