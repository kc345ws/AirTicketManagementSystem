#pragma once
#ifndef CITY_HEAD
#define CITY_HEAD

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
	Edge_City* adjacent;//��������ͷָ��
};

class Graph_List_City {//���е�ͼ���ڽӱ���ʾ��ʽ
private:
	Vertex_City* vertices;//�������ͷָ��
	int GraphSize;//����ĸ���
	

public:
	Graph_List_City();
	int* Visited;
	//void browsecity();
	void DFSCity(const int v,int* visited);//������ȱ���������Ϣ
	void DFS_Main();
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