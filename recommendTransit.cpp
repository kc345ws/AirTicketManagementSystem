#include"Flight.h"
#include"City.h"
#include<iostream>
#include<iomanip>

using namespace std;

void Flight::recommendTransit(string start, string end)
{
	if (GLCT->CheckMain(start, end)) {
		cout << "无直达航班，以下为推荐的中转方案" << endl;
		string start = start;
		//string end = GLCT->recommentCity->front();
		//GLCT->recommentCity->pop();
		
		while (!GLCT->recommentCity_Distance->empty()) {//当中转城市队列不空时
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
		}
	}
	else {
		cout << "无直达航班，也无其他中转方案" << endl;
	}
}