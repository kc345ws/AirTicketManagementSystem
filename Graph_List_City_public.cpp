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
	for (int i = 0; i < GraphSize; i++) {//利用CityName创建顶点表
		vertices[i].verinfor = tempCN->name;
		vertices[i].adjacent = nullptr;//将边链表头指针设为null

		tempCN = tempCN->next;
	}

	for (int i = 0; i < GraphSize; i++) {
		Edge_City* Temp = nullptr;

			ALLCITY->tempcityinfo = ALLCITY->sentine->next;
			City::CityInfo* tempci = ALLCITY->tempcityinfo;
			while (tempci) {
				if (tempci->start == vertices[i].verinfor) {//如果城市信息中的起飞地与顶点表的名字相同
					if (!vertices[i].adjacent){//如果是第一个边结点则将它赋值给adjacent
						vertices[i].adjacent = new Edge_City();
						for (int j = 0; j < GraphSize; j++) {//在顶点表中找到降落城市的序号
							if (vertices[j].verinfor == tempci->end){
								//如果降落地点相同
								vertices[i].adjacent->verAdj = j;
								vertices[i].adjacent->distance = tempci->distance;
								break;
							}
						}
						//Temp = vertices[i].adjacent;
					}

					else {
						Temp = vertices[i].adjacent;
						while (1){//找到最后一个非空边结点
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
						for (int j = 0; j < GraphSize; j++) {//在顶点表中找到降落城市的序号
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
		if (visited[Temp->verAdj] != 1)//如果结点没有被访问过
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
	cout << "以下为各城市的交通网情况" << endl;
	User UI;
	for (int i = 0; i < GraphSize; i++) {
		Visited = new int[GraphSize] {0};
		if (vertices[i].adjacent) {
			DFSCity(i, Visited);
			cout << endl;
			cout << endl;
		}
	}
	cout << "按任意键返回" << endl;
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
	cout << "以下为各城市的交通网情况" << endl;
	User UI;
	for (int i = 0; i < GraphSize; i++) {
		Visited = new int[GraphSize] {0};
		if (vertices[i].adjacent) {
			BFS(i, Visited);
			cout << endl;
			cout << endl;
		}
	}
	cout << "按任意键返回" << endl;
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
{//DFS非递归实现

	/*visited[index] = 1;

	Edge_City* Temp = vertices[index].adjacent;
	while (Temp != nullptr)
	{
		//recommentCity->push_back(vertices[index].verinfor);//压入中转城市名
		recommentCity->push(vertices[Temp->verAdj].verinfor);
		if (vertices[Temp->verAdj].verinfor == endname) {
			return true;
		}
		if (visited[Temp->verAdj] != 1)//如果结点没有被访问过
		{
			//DFSCity(Temp->verAdj, visited);
			Checkisconnected(Temp->verAdj, visited, endname);
		}
		Temp = Temp->next;
	}
	recommentCity = new queue<string>;//如果一条线上没有找到重新开始
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
		while (tempedge) {//先压入一级邻居
			if (visited[tempedge->verAdj] ==0) {//如果结点没有被访问过
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
	if (index >= 0) {//如果起飞城市在顶点表中被找到
		int* Visited = new int[GraphSize] {0};
		if (Checkisconnected(index, Visited, endname)) {
			return true;
		}
	}
	return false;
}

