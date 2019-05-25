#include"City.h"
#include<iostream>
#include"User.h"
#include"Flight.h"
#include<queue>
#include<stack>
using namespace std;

Graph_List_City::Graph_List_City() {



	ALLCITY->load_citynum();
	ALLCITY->load_city();
	ALLCITY->getcitycount();
	ALLCITY->getallcityname();

	GraphSize = ALLCITY->citycount;
	Visited = new int[GraphSize] {0};
	vertices = new Vertex_City[1000];
	recommentCity_Distance = new queue<string>;

	ALLCITY->cntp = ALLCITY->cnsentine->next;
	City::CityName* tempCN = ALLCITY->cntp;
	for (int i = 0; i < GraphSize; i++) {//����CityName���������
		vertices[i].verinfor = tempCN->name;
		vertices[i].adjacent = nullptr;//��������ͷָ����Ϊnull

		tempCN = tempCN->next;
	}

	for (int i = 0; i < GraphSize; i++) {
		Edge_City* Temp = nullptr;

			ALLCITY->tempcityinfo = ALLCITY->sentine->next;
			City::CityInfo* tempci = ALLCITY->tempcityinfo;
			while (tempci) {
				if (tempci->start == vertices[i].verinfor) {//���������Ϣ�е���ɵ��붥����������ͬ
					if (!vertices[i].adjacent){//����ǵ�һ���߽��������ֵ��adjacent
						vertices[i].adjacent = new Edge_City();
						for (int j = 0; j < GraphSize; j++) {//�ڶ�������ҵ�������е����
							if (vertices[j].verinfor == tempci->end){
								//�������ص���ͬ
								vertices[i].adjacent->verAdj = j;
								vertices[i].adjacent->distance = tempci->distance;
								break;
							}
						}
						//Temp = vertices[i].adjacent;
					}

					else {
						Temp = vertices[i].adjacent;
						while (1){//�ҵ����һ���ǿձ߽��
							if (!Temp->next){
								break;
							}
							else{
								Temp = Temp->next;
							}
						}
						Temp->next = new Edge_City();
						Temp = Temp->next;
						//Temp->verAdj = Adj;
						for (int j = 0; j < GraphSize; j++) {//�ڶ�������ҵ�������е����
							if (vertices[j].verinfor == tempci->end){
								Temp->verAdj = j;
								Temp->distance = tempci->distance; 
								break;
							}
						}
					}
				}
				tempci = tempci->next;
			}		
	}	
}

void Graph_List_City::DFSCity(const int v,int* visited){

	cout << vertices[v].verinfor;
	
	visited[v] = 1;

	Edge_City* Temp = vertices[v].adjacent;
	while (Temp != nullptr)
	{
		if (visited[Temp->verAdj] != 1)//������û�б����ʹ�
		{
			cout << "->";
			DFSCity(Temp->verAdj,visited);
			cout << "|" << endl;	
		}
		Temp = Temp->next;
		
	}
	//cout << endl;
}

void Graph_List_City::DFS_Main()
{
	system("CLS");
	cout << "����Ϊ�����еĽ�ͨ�����" << endl;
	User UI;
	for (int i = 0; i < GraphSize; i++) {
		Visited = new int[GraphSize] {0};
		if (vertices[i].adjacent) {
			DFSCity(i, Visited);
			cout << endl;
			cout << endl;
		}
	}
	cout << "�����������" << endl;
	getchar();
	getchar();
	if (LoginedUser->mode == 1) {
		UI.login_mf();
	}
	else {
		UI.login_uf();
	}
}

void Graph_List_City::BFS(const int v, int* vis)
{
	queue<Vertex_City>Queue;
	int* visited = vis;
	for (int i = 0; i < GraphSize; i++)
	{
		visited[i] = 0;
	}
	cout << vertices[v].verinfor << "->";
	visited[v] = 1;
	Queue.push(vertices[v]);

	while (!Queue.empty())
	{
		Vertex_City TempVertex = Queue.front();
		Queue.pop();
		Edge_City *TempEdge = TempVertex.adjacent;
		while (TempEdge)
		{
			if (visited[TempEdge->verAdj] == 0)
			{
				//cout << TempVertex.verinfor << " ";
				cout << vertices[TempEdge->verAdj].verinfor << "->";
				visited[TempEdge->verAdj] = 1;
				Queue.push(vertices[TempEdge->verAdj]);
			}
			cout << endl;
			TempEdge = TempEdge->next;
		}
	}
}

void Graph_List_City::BFS_Main()
{
	system("CLS");
	cout << "����Ϊ�����еĽ�ͨ�����" << endl;
	User UI;
	for (int i = 0; i < GraphSize; i++) {
		Visited = new int[GraphSize] {0};
		if (vertices[i].adjacent) {
			BFS(i, Visited);
			cout << endl;
			cout << endl;
		}
	}
	cout << "�����������" << endl;
	getchar();
	getchar();
	UI.login_mf();
}

int Graph_List_City::getverticesIndex(string name)
{
	for (int i = 0; i < GraphSize; i++) {
		if (vertices[i].verinfor == name) {
			return i;
		}
	}
	return -1;
}

bool Graph_List_City::Checkisconnected(const int index, int* visited,string endname)
{//DFS�ǵݹ�ʵ��

	/*visited[index] = 1;

	Edge_City* Temp = vertices[index].adjacent;
	while (Temp != nullptr)
	{
		//recommentCity->push_back(vertices[index].verinfor);//ѹ����ת������
		recommentCity->push(vertices[Temp->verAdj].verinfor);
		if (vertices[Temp->verAdj].verinfor == endname) {
			return true;
		}
		if (visited[Temp->verAdj] != 1)//������û�б����ʹ�
		{
			//DFSCity(Temp->verAdj, visited);
			Checkisconnected(Temp->verAdj, visited, endname);
		}
		Temp = Temp->next;
	}
	recommentCity = new queue<string>;//���һ������û���ҵ����¿�ʼ
	return false;*/
	stack<Vertex_City> *CityStack = new stack<Vertex_City>;
	CityStack->push(GLCT->vertices[index]);
	while (!CityStack->empty()) {
		Vertex_City temp = CityStack->top();
		if (temp.verinfor == endname) {
			return true;
		}

		for (int i = 0; i < GraphSize; i++) {
			if (vertices[i].verinfor == temp.verinfor) {
				visited[i] = 1;
				break;
			}
		}
		CityStack->pop();
		
		Edge_City* tempedge = temp.adjacent;
		while (tempedge) {//��ѹ��һ���ھ�
			if (visited[tempedge->verAdj] ==0) {//������û�б����ʹ�
				CityStack->push(vertices[tempedge->verAdj]);
				visited[tempedge->verAdj] = 1;
			}
			tempedge = tempedge->next;
		}
	}

	return false;
}

bool Graph_List_City::CheckMain(string startname, string endname)
{
	int index = getverticesIndex(startname);
	if (index >= 0) {//�����ɳ����ڶ�����б��ҵ�
		int* Visited = new int[GraphSize] {0};
		if (Checkisconnected(index, Visited, endname)) {
			return true;
		}
	}
	return false;
}

void Graph_List_City::Dijkstra_Distance(int start, Graph_List_City* G)
{
	int j, t, p;

	//float DistanceSum = 0;

	//int path[G->GraphSize];
	path = new int[G->GraphSize];

	//int dist[G->n];
	dist = new int[G->GraphSize];

	for (int i = 0; i < G->GraphSize; i++) {
		dist[i] = INT_MAX;//�ȸ��㵽Դ��ľ�����Ϊ����
	}
	
	for (Edge_City* w = G->vertices[start].adjacent; w != NULL; w = w->next)
	{
		dist[w->verAdj] = w->distance;
	}//��ʼ�������㵽Դ��ľ���

	dist[start] = 0;//Դ�㵽Դ��ľ�����Ϊ0

	for (int i = 0; i < G->GraphSize; i++)
	{
		if (dist[i] == INT_MAX) {
			path[i] = -1;//���ĳ���㵽Դ��ľ���Ϊ���ǰ����������Ϊ-1
		}
		else {
			path[i] = start;
		}
	}

	path[start] = -2;//Դ���ǰ����������Ϊ-2

	bool* collected = new bool[G->GraphSize]{false};

	while (1)
	{
		t = INT_MAX;
		j = -1;
		for (int i = 0; i < G->GraphSize; i++)
		{
				if (collected[i] == false && dist[i] < t)//�ҵ�����Դ����� �ν�...
				{
					t = dist[i];
					j = i;
				}
		}
		if (j == -1) {
			break;
		}
		collected[j] = true;

		for (Edge_City* w = G->vertices[j].adjacent; w != NULL; w = w->next)

		{

			p = w->verAdj;//�ڽӵ���±�

			if (dist[p] > dist[j] + w->distance) {//dist[p]Ϊ��ǰ����Դ��ľ���
				dist[p] = dist[j] + w->distance;

				//DistanceSum += dist[p];

				path[p] = j;//����ҵ��ȵ�ǰ�����ľ�������¸õ��ǰ�����
			}
			

		}

	}

	//return DistanceSum;
}


void Graph_List_City::Dijkstra_Pirce(int start, Graph_List_City* G)
{//���ݼ۸��Ƽ���ת����
	Flight F;
	F.load_fn();
	F.load_fil();

	int j, t, p;

	//int path[G->GraphSize];
	path = new int[G->GraphSize];

	//int dist[G->n];
	dist = new int[G->GraphSize];

	for (int i = 0; i < G->GraphSize; i++) {
		dist[i] = INT_MAX;//�ȸ��㵽Դ��ļ۸���Ϊ����
	}

	for (Edge_City* w = G->vertices[start].adjacent; w != NULL; w = w->next)
	{//������ɳ��еı߽��

		//dist[w->verAdj] = w->distance;
		
		dist[w->verAdj] = F.getAverage_price(G->vertices[start].verinfor, G->vertices[w->verAdj].verinfor);

	}//��ʼ�������㵽Դ��ļ۸�

	dist[start] = 0;//Դ�㵽Դ��ļ۸���Ϊ0

	for (int i = 0; i < G->GraphSize; i++)
	{
		if (dist[i] == INT_MAX) {
			path[i] = -1;//���ĳ���㵽Դ��ľ���Ϊ���ǰ����������Ϊ-1
		}
		else {
			path[i] = start;
		}
	}

	path[start] = -2;//Դ���ǰ����������Ϊ-2

	bool* collected = new bool[G->GraphSize]{ false };
	//collected[start] = true;

	while (1)
	{
		t = INT_MAX;
		j = -1;
		for (int i = 0; i < G->GraphSize; i++)
		{
			if (collected[i] == false && dist[i] < t)//�ҵ�����Դ����� �ν�...
			{
				t = dist[i];
				j = i;
			}
		}
		if (j == -1) {
			break;
		}
		collected[j] = true;

		for (Edge_City* w = G->vertices[j].adjacent; w != NULL; w = w->next)

		{

			p = w->verAdj;//�ڽӵ���±�

			double TempPrice = F.getAverage_price(G->vertices[j].verinfor, G->vertices[w->verAdj].verinfor);

			if (dist[p] > dist[j] + TempPrice) {//dist[p]Ϊ��ǰ����Դ��ľ���
				dist[p] = dist[j] + TempPrice;

				path[p] = j;//����ҵ��ȵ�ǰ�����ľ�������¸õ��ǰ�����
			}


		}

	}

	/*for (int i = 0; i < GraphSize; i++) {
		cout << vertices[i].verinfor << ":";
		cout << path[i] << " " ;
	}
	cout << endl;
	for (int i = 0; i < GraphSize; i++) {
		cout << dist[i] << " " ;
	}*/
}


void Graph_List_City::Dijkstra_Time(int start, Graph_List_City* G)
{
	Flight F;
	F.load_fn();
	F.load_fil();

	int j, t, p;

	//int path[G->GraphSize];
	path = new int[G->GraphSize];

	//int dist[G->n];
	dist = new int[G->GraphSize];

	for (int i = 0; i < G->GraphSize; i++) {
		dist[i] = INT_MAX;//�ȸ��㵽Դ��ļ۸���Ϊ����
	}

	for (Edge_City* w = G->vertices[start].adjacent; w != NULL; w = w->next)
	{//������ɳ��еı߽��

		//dist[w->verAdj] = w->distance;

		//dist[w->verAdj] = F.getAverage_price(G->vertices[start].verinfor, G->vertices[w->verAdj].verinfor);
		dist[w->verAdj] = F.getAverage_time(G->vertices[start].verinfor, G->vertices[w->verAdj].verinfor);

	}//��ʼ�������㵽Դ��ļ۸�

	dist[start] = 0;//Դ�㵽Դ��ļ۸���Ϊ0

	for (int i = 0; i < G->GraphSize; i++)
	{
		if (dist[i] == INT_MAX) {
			path[i] = -1;//���ĳ���㵽Դ��ľ���Ϊ���ǰ����������Ϊ-1
		}
		else {
			path[i] = start;
		}
	}

	path[start] = -2;//Դ���ǰ����������Ϊ-2

	bool* collected = new bool[G->GraphSize]{ false };

	while (1)
	{
		t = INT_MAX;
		j = -1;
		for (int i = 0; i < G->GraphSize; i++)
		{
			if (collected[i] == false && dist[i] < t)//�ҵ�����Դ����� �ν�...
			{
				t = dist[i];
				j = i;
			}
		}
		if (j == -1) {
			break;
		}
		collected[j] = true;

		for (Edge_City* w = G->vertices[j].adjacent; w != NULL; w = w->next)

		{

			p = w->verAdj;//�ڽӵ���±�

			//double TempPrice = F.getAverage_price(G->vertices[j].verinfor, G->vertices[w->verAdj].verinfor);
			double TempPrice = F.getAverage_time(G->vertices[j].verinfor, G->vertices[w->verAdj].verinfor);
			if (dist[p] > dist[j] + TempPrice) {//dist[p]Ϊ��ǰ����Դ��ľ���
				dist[p] = dist[j] + TempPrice;

				path[p] = j;//����ҵ��ȵ�ǰ�����ľ�������¸õ��ǰ�����
			}


		}

	}
}


void Graph_List_City::Dijkstra_Ticket(int start, Graph_List_City* G)
{
	Flight F;
	F.load_fn();
	F.load_fil();

	int j, t, p;

	//int path[G->GraphSize];
	path = new int[G->GraphSize];

	//int dist[G->n];
	dist = new int[G->GraphSize];

	for (int i = 0; i < G->GraphSize; i++) {
		dist[i] = INT_MAX;//�ȸ��㵽Դ��ļ۸���Ϊ����
	}

	for (Edge_City* w = G->vertices[start].adjacent; w != NULL; w = w->next)
	{//������ɳ��еı߽��

		//dist[w->verAdj] = w->distance;

		//dist[w->verAdj] = F.getAverage_price(G->vertices[start].verinfor, G->vertices[w->verAdj].verinfor);
		//dist[w->verAdj] = F.getAverage_time(G->vertices[start].verinfor, G->vertices[w->verAdj].verinfor);
		dist[w->verAdj] = F.getAverage_ticket(G->vertices[start].verinfor, G->vertices[w->verAdj].verinfor);

	}//��ʼ�������㵽Դ��ļ۸�

	dist[start] = 0;//Դ�㵽Դ��ļ۸���Ϊ0

	for (int i = 0; i < G->GraphSize; i++)
	{
		if (dist[i] == INT_MAX) {
			path[i] = -1;//���ĳ���㵽Դ��ľ���Ϊ���ǰ����������Ϊ-1
		}
		else {
			path[i] = start;
		}
	}

	path[start] = -2;//Դ���ǰ����������Ϊ-2

	bool* collected = new bool[G->GraphSize]{ false };

	while (1)
	{
		t = INT_MAX;
		j = -1;
		for (int i = 0; i < G->GraphSize; i++)
		{
			if (collected[i] == false && dist[i] < t)//�ҵ�����Դ����� �ν�...
			{
				t = dist[i];
				j = i;
			}
		}
		if (j == -1) {
			break;
		}
		collected[j] = true;

		for (Edge_City* w = G->vertices[j].adjacent; w != NULL; w = w->next)

		{

			p = w->verAdj;//�ڽӵ���±�

			//double TempPrice = F.getAverage_price(G->vertices[j].verinfor, G->vertices[w->verAdj].verinfor);
			//double TempPrice = F.getAverage_time(G->vertices[j].verinfor, G->vertices[w->verAdj].verinfor);
			double TempPrice = F.getAverage_ticket(G->vertices[j].verinfor, G->vertices[w->verAdj].verinfor);
			if (dist[p] > dist[j] + TempPrice) {//dist[p]Ϊ��ǰ����Դ��ľ���
				dist[p] = dist[j] + TempPrice;

				path[p] = j;//����ҵ��ȵ�ǰ�����ľ�������¸õ��ǰ�����
			}


		}

	}
}



void Graph_List_City::Dijkstra_Transittime(int start, Graph_List_City* G)
{
	Flight F;
	F.load_fn();
	F.load_fil();

	int j, t, p;

	//int path[G->GraphSize];
	path = new int[G->GraphSize];

	//int dist[G->n];
	dist = new int[G->GraphSize];

	for (int i = 0; i < G->GraphSize; i++) {
		dist[i] = INT_MAX;//�ȸ��㵽Դ��ļ۸���Ϊ����
	}

	for (Edge_City* w = G->vertices[start].adjacent; w != NULL; w = w->next)
	{//������ɳ��еı߽��

		//dist[w->verAdj] = w->distance;

		//dist[w->verAdj] = F.getAverage_price(G->vertices[start].verinfor, G->vertices[w->verAdj].verinfor);
		//dist[w->verAdj] = F.getAverage_time(G->vertices[start].verinfor, G->vertices[w->verAdj].verinfor);
		dist[w->verAdj] = F.getAverage_transtime(G->vertices[start].verinfor, G->vertices[w->verAdj].verinfor);
	}//��ʼ�������㵽Դ��ļ۸�

	dist[start] = 0;//Դ�㵽Դ��ļ۸���Ϊ0

	for (int i = 0; i < G->GraphSize; i++)
	{
		if (dist[i] == INT_MAX) {
			path[i] = -1;//���ĳ���㵽Դ��ľ���Ϊ���ǰ����������Ϊ-1
		}
		else {
			path[i] = start;
		}
	}

	path[start] = -2;//Դ���ǰ����������Ϊ-2

	bool* collected = new bool[G->GraphSize]{ false };

	while (1)
	{
		t = INT_MAX;
		j = -1;
		for (int i = 0; i < G->GraphSize; i++)
		{
			if (collected[i] == false && dist[i] < t)//�ҵ�����Դ����� �ν�...
			{
				t = dist[i];
				j = i;
			}
		}
		if (j == -1) {
			break;
		}
		collected[j] = true;

		for (Edge_City* w = G->vertices[j].adjacent; w != NULL; w = w->next)

		{

			p = w->verAdj;//�ڽӵ���±�

			//double TempPrice = F.getAverage_price(G->vertices[j].verinfor, G->vertices[w->verAdj].verinfor);
			//double TempPrice = F.getAverage_time(G->vertices[j].verinfor, G->vertices[w->verAdj].verinfor);
			double TempPrice = F.getAverage_transtime(G->vertices[j].verinfor, G->vertices[w->verAdj].verinfor);
			if (dist[p] > dist[j] + TempPrice) {//dist[p]Ϊ��ǰ����Դ��ľ���
				dist[p] = dist[j] + TempPrice;

				path[p] = j;//����ҵ��ȵ�ǰ�����ľ�������¸õ��ǰ�����
			}
		}
	}
}




