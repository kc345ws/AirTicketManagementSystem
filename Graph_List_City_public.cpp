#include"City.h"
#include<iostream>
#include"User.h"
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
	UI.login_mf();
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

