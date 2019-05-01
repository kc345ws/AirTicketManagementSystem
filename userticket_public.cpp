#include"UserTicket.h"
#include<iostream>
extern UserTicket* ZeroTicket = nullptr;
extern UserTicket* MyTickets  = nullptr;


UserTicket::UserTicket() {
	
	Ticketnum = 0;				//机票总数设为0
	sentine = new Ticket();		//哨兵节点
	sentine->next = nullptr;
	sentine->prior = nullptr;

	temp = nullptr;
}

UserTicket::~UserTicket() {
	Destroy();
}

void UserTicket :: Destroy() {
	//MyTickets = ZeroTicket->next;
	Ticket* T1, * T2;
	//UserTicket* Temp = ZeroTicket;
	T1 = sentine;
	T2 = sentine->next;
	while (T2) {
		delete T1;
		T1 = T2;
		T2 = T2->next;
	}
	delete T1;
}

void UserTicket::addTicket() {

}

