#include"City.h"
#include<iostream>
#include"User.h"
using namespace std;

Graph_List_City::Graph_List_City() {
	
	ALLCITY->load_citynum();
	ALLCITY->load_city();
	ALLCITY->getcitycount();
	ALLCITY->getallcityname();

	GraphSize = ALLCITY->citycount;
	Visited = new int[GraphSize] {0};
	vertices = new Vertex_City[1000];

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