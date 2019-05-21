#pragma once
#ifndef CITY_HEAD
#define CITY_HEAD
#include<queue>
#include<string>

using namespace std;

class Edge_City {//���еı߽��ṹ �ڽӱ�Ϊ���Ӵ洢
public:
	friend class Graph_List_City;
	int verAdj;//�ڽӶ������(�ڽ���ڶ�����е�λ��)
	int distance;//����
	Edge_City* next;//��һ���߽���ָ��
};

class Vertex_City {//���еĶ���ṹ ����Ϊ˳��洢
public:
	friend class Graph_List_City;
	string verinfor;//���е�����
	Edge_City* adjacent;//�������ͷָ��
};

class Graph_List_City {//���е�ͼ���ڽӱ��ʾ��ʽ
public:
	Vertex_City* vertices;//������ͷָ��
	int GraphSize;//����ĸ���

	int* path;
	int* dist;

public:
	Graph_List_City();
	int* Visited;
	queue<string>* recommentCity_Distance;
	//void browsecity();
	void DFSCity(const int v,int* visited);//������ȱ���������Ϣ
	void DFS_Main();
	void BFS(const int v, int* vis);//������ȱ���
	void BFS_Main();
	int getverticesIndex(string name);//ͨ���������ƻ�ȡ�ڶ�����е�����
	bool Checkisconnected(const int index, int* visited,string endname);//������֮���Ƿ���ͨ
	bool CheckMain(string startname, string endname);

	void Dijkstra_Distance(int start, Graph_List_City* G);//��·��
	void Dijkstra_Pirce(int start, Graph_List_City* G);//���۸�
	void Dijkstra_Time(int start, Graph_List_City* G);//��ʱ��
	void Dijkstra_Ticket(int start, Graph_List_City* G);//��ʣ��Ʊ��
};

class City {
public:
	
	struct CityInfo {
		string start;
		string end;
		float distance;

		CityInfo* next;//��һ��������Ϣ
	}*sentine,*newcity,*tempcityinfo,*last;

	struct CityName {
		string name;
		CityName* next;
	}*cnsentine,*cntp;

	int citynumber;//������Ϣ��
	int citycount;//��������

	City();
	~City();

	void add_city();
	void save_city();
	void load_city();
	void save_citynum();
	void load_citynum();
	void getallcityname();
	void getcitycount();
};
extern City* ALLCITY;
extern Graph_List_City* GLCT;

#endif 