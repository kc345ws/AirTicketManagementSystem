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

void Graph_List_City::Dijkstra_Distance(int start, Graph_List_City* G)
{
	int j, t, p;

	//float DistanceSum = 0;

	//int path[G->GraphSize];
	path = new int[G->GraphSize];

	//int dist[G->n];
	dist = new int[G->GraphSize];

	for (int i = 0; i < G->GraphSize; i++) {
		dist[i] = INT_MAX;//先各点到源点的距离设为无穷
	}
	
	for (Edge_City* w = G->vertices[start].adjacent; w != NULL; w = w->next)
	{
		dist[w->verAdj] = w->distance;
	}//初始化各顶点到源点的距离

	dist[start] = 0;//源点到源点的距离设为0

	for (int i = 0; i < G->GraphSize; i++)
	{
		if (dist[i] == INT_MAX) {
			path[i] = -1;//如果某个点到源点的距离为无穷，前驱结点序号设为-1
		}
		else {
			path[i] = start;
		}
	}

	path[start] = -2;//源点的前驱结点序号设为-2

	bool* collected = new bool[G->GraphSize]{false};

	while (1)
	{
		t = INT_MAX;
		j = -1;
		for (int i = 0; i < G->GraphSize; i++)
		{
				if (collected[i] == false && dist[i] < t)//找到距离源点最近 次近...
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

			p = w->verAdj;//邻接点的下标

			if (dist[p] > dist[j] + w->distance) {//dist[p]为当前距离源点的距离
				dist[p] = dist[j] + w->distance;

				//DistanceSum += dist[p];

				path[p] = j;//如果找到比当前更近的距离则更新该点的前驱结点
			}
			

		}

	}

	//return DistanceSum;
}


void Graph_List_City::Dijkstra_Pirce(int start, Graph_List_City* G)
{//根据价格推荐中转方案
	Flight F;
	F.load_fn();
	F.load_fil();

	int j, t, p;

	//int path[G->GraphSize];
	path = new int[G->GraphSize];

	//int dist[G->n];
	dist = new int[G->GraphSize];

	for (int i = 0; i < G->GraphSize; i++) {
		dist[i] = INT_MAX;//先各点到源点的价格设为无穷
	}

	for (Edge_City* w = G->vertices[start].adjacent; w != NULL; w = w->next)
	{//遍历起飞城市的边结点

		//dist[w->verAdj] = w->distance;
		
		dist[w->verAdj] = F.getAverage_price(G->vertices[start].verinfor, G->vertices[w->verAdj].verinfor);

	}//初始化各顶点到源点的价格

	dist[start] = 0;//源点到源点的价格设为0

	for (int i = 0; i < G->GraphSize; i++)
	{
		if (dist[i] == INT_MAX) {
			path[i] = -1;//如果某个点到源点的距离为无穷，前驱结点序号设为-1
		}
		else {
			path[i] = start;
		}
	}

	path[start] = -2;//源点的前驱结点序号设为-2

	bool* collected = new bool[G->GraphSize]{ false };
	//collected[start] = true;

	while (1)
	{
		t = INT_MAX;
		j = -1;
		for (int i = 0; i < G->GraphSize; i++)
		{
			if (collected[i] == false && dist[i] < t)//找到距离源点最近 次近...
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

			p = w->verAdj;//邻接点的下标

			double TempPrice = F.getAverage_price(G->vertices[j].verinfor, G->vertices[w->verAdj].verinfor);

			if (dist[p] > dist[j] + TempPrice) {//dist[p]为当前距离源点的距离
				dist[p] = dist[j] + TempPrice;

				path[p] = j;//如果找到比当前更近的距离则更新该点的前驱结点
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
		dist[i] = INT_MAX;//先各点到源点的价格设为无穷
	}

	for (Edge_City* w = G->vertices[start].adjacent; w != NULL; w = w->next)
	{//遍历起飞城市的边结点

		//dist[w->verAdj] = w->distance;

		//dist[w->verAdj] = F.getAverage_price(G->vertices[start].verinfor, G->vertices[w->verAdj].verinfor);
		dist[w->verAdj] = F.getAverage_time(G->vertices[start].verinfor, G->vertices[w->verAdj].verinfor);

	}//初始化各顶点到源点的价格

	dist[start] = 0;//源点到源点的价格设为0

	for (int i = 0; i < G->GraphSize; i++)
	{
		if (dist[i] == INT_MAX) {
			path[i] = -1;//如果某个点到源点的距离为无穷，前驱结点序号设为-1
		}
		else {
			path[i] = start;
		}
	}

	path[start] = -2;//源点的前驱结点序号设为-2

	bool* collected = new bool[G->GraphSize]{ false };

	while (1)
	{
		t = INT_MAX;
		j = -1;
		for (int i = 0; i < G->GraphSize; i++)
		{
			if (collected[i] == false && dist[i] < t)//找到距离源点最近 次近...
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

			p = w->verAdj;//邻接点的下标

			//double TempPrice = F.getAverage_price(G->vertices[j].verinfor, G->vertices[w->verAdj].verinfor);
			double TempPrice = F.getAverage_time(G->vertices[j].verinfor, G->vertices[w->verAdj].verinfor);
			if (dist[p] > dist[j] + TempPrice) {//dist[p]为当前距离源点的距离
				dist[p] = dist[j] + TempPrice;

				path[p] = j;//如果找到比当前更近的距离则更新该点的前驱结点
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
		dist[i] = INT_MAX;//先各点到源点的价格设为无穷
	}

	for (Edge_City* w = G->vertices[start].adjacent; w != NULL; w = w->next)
	{//遍历起飞城市的边结点

		//dist[w->verAdj] = w->distance;

		//dist[w->verAdj] = F.getAverage_price(G->vertices[start].verinfor, G->vertices[w->verAdj].verinfor);
		//dist[w->verAdj] = F.getAverage_time(G->vertices[start].verinfor, G->vertices[w->verAdj].verinfor);
		dist[w->verAdj] = F.getAverage_ticket(G->vertices[start].verinfor, G->vertices[w->verAdj].verinfor);

	}//初始化各顶点到源点的价格

	dist[start] = 0;//源点到源点的价格设为0

	for (int i = 0; i < G->GraphSize; i++)
	{
		if (dist[i] == INT_MAX) {
			path[i] = -1;//如果某个点到源点的距离为无穷，前驱结点序号设为-1
		}
		else {
			path[i] = start;
		}
	}

	path[start] = -2;//源点的前驱结点序号设为-2

	bool* collected = new bool[G->GraphSize]{ false };

	while (1)
	{
		t = INT_MAX;
		j = -1;
		for (int i = 0; i < G->GraphSize; i++)
		{
			if (collected[i] == false && dist[i] < t)//找到距离源点最近 次近...
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

			p = w->verAdj;//邻接点的下标

			//double TempPrice = F.getAverage_price(G->vertices[j].verinfor, G->vertices[w->verAdj].verinfor);
			//double TempPrice = F.getAverage_time(G->vertices[j].verinfor, G->vertices[w->verAdj].verinfor);
			double TempPrice = F.getAverage_ticket(G->vertices[j].verinfor, G->vertices[w->verAdj].verinfor);
			if (dist[p] > dist[j] + TempPrice) {//dist[p]为当前距离源点的距离
				dist[p] = dist[j] + TempPrice;

				path[p] = j;//如果找到比当前更近的距离则更新该点的前驱结点
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
		dist[i] = INT_MAX;//先各点到源点的价格设为无穷
	}

	for (Edge_City* w = G->vertices[start].adjacent; w != NULL; w = w->next)
	{//遍历起飞城市的边结点

		//dist[w->verAdj] = w->distance;

		//dist[w->verAdj] = F.getAverage_price(G->vertices[start].verinfor, G->vertices[w->verAdj].verinfor);
		//dist[w->verAdj] = F.getAverage_time(G->vertices[start].verinfor, G->vertices[w->verAdj].verinfor);
		dist[w->verAdj] = F.getAverage_transtime(G->vertices[start].verinfor, G->vertices[w->verAdj].verinfor);
	}//初始化各顶点到源点的价格

	dist[start] = 0;//源点到源点的价格设为0

	for (int i = 0; i < G->GraphSize; i++)
	{
		if (dist[i] == INT_MAX) {
			path[i] = -1;//如果某个点到源点的距离为无穷，前驱结点序号设为-1
		}
		else {
			path[i] = start;
		}
	}

	path[start] = -2;//源点的前驱结点序号设为-2

	bool* collected = new bool[G->GraphSize]{ false };

	while (1)
	{
		t = INT_MAX;
		j = -1;
		for (int i = 0; i < G->GraphSize; i++)
		{
			if (collected[i] == false && dist[i] < t)//找到距离源点最近 次近...
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

			p = w->verAdj;//邻接点的下标

			//double TempPrice = F.getAverage_price(G->vertices[j].verinfor, G->vertices[w->verAdj].verinfor);
			//double TempPrice = F.getAverage_time(G->vertices[j].verinfor, G->vertices[w->verAdj].verinfor);
			double TempPrice = F.getAverage_transtime(G->vertices[j].verinfor, G->vertices[w->verAdj].verinfor);
			if (dist[p] > dist[j] + TempPrice) {//dist[p]为当前距离源点的距离
				dist[p] = dist[j] + TempPrice;

				path[p] = j;//如果找到比当前更近的距离则更新该点的前驱结点
			}
		}
	}
}




