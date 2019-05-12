#pragma once
#ifndef CITY_HEAD
#define CITY_HEAD
#include<queue>
#include<string>

using namespace std;

class Edge_City {//城市的边结点结构 邻接表为链接存储
public:
	friend class Graph_List_City;
	int verAdj;//邻接顶点序号(在结点在顶点表中的位置)
	int distance;//距离
	Edge_City* next;//下一个边结点的指针
};

class Vertex_City {//城市的顶点结构 顶点为顺序存储
public:
	friend class Graph_List_City;
	string verinfor;//城市的名称
	Edge_City* adjacent;//边链表的头指针
};

class Graph_List_City {//城市的图的邻接表表示形式
public:
	Vertex_City* vertices;//顶点表的头指针
	int GraphSize;//顶点的个数

	int* path;
	int* dist;

public:
	Graph_List_City();
	int* Visited;
	queue<string>* recommentCity_Distance;
	//void browsecity();
	void DFSCity(const int v,int* visited);//深度优先遍历城市信息
	void DFS_Main();
	void BFS(const int v, int* vis);
	void BFS_Main();
	int getverticesIndex(string name);
	bool Checkisconnected(const int index, int* visited,string endname);
	bool CheckMain(string startname, string endname);

	void Dijkstra_Distance(int start, Graph_List_City* G);
};

class City {
public:
	
	struct CityInfo {
		string start;
		string end;
		float distance;

		CityInfo* next;//下一个城市信息
	}*sentine,*newcity,*tempcityinfo,*last;

	struct CityName {
		string name;
		CityName* next;
	}*cnsentine,*cntp;

	int citynumber;//城市信息数
	int citycount;//城市数量

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