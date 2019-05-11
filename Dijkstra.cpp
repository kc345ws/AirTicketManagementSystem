#include<iostream>
#include"City.h"
using namespace std;

/*
Dijkstra::Dijkstra()
{
	n = GLCT->GraphSize;
	for (int i = 1; i <= n; ++i) {
		
		dist[i] = maxint;
	}

}
void Dijkstra_Distance(int n, int v, int* dist, int* prev, int c[maxnum][maxnum]) {
	for (int i = 1; i <= n; ++i)
	{
		dist[i] = c[v][i];
		s[i] = 0;     // 初始都未用过该点
		if (dist[i] == maxint)
			prev[i] = 0;
		else
			prev[i] = v;
	}
	dist[v] = 0;
	s[v] = 1;

	// 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
	// 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
		 // 注意是从第二个节点开始，第一个为源点
	for (int i = 2; i <= n; ++i)
	{
		int tmp = maxint;
		int u = v;
		// 找出当前未使用的点j的dist[j]最小值
		for (int j = 1; j <= n; ++j)
			if ((!s[j]) && dist[j] < tmp)
			{
				u = j;              // u保存当前邻接点中距离最小的点的号码
				tmp = dist[j];
			}
		s[u] = 1;    // 表示u点已存入S集合中

		// 更新dist
		for (int j = 1; j <= n; ++j)
			if ((!s[j]) && c[u][j] < maxint)
			{
				int newdist = dist[u] + c[u][j];
				if (newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				}
			}
	}
}

// 查找从源点v到终点u的路径，并输出
void searchPath(int* prev, int v, int u)
{
	int que[maxnum];
	int tot = 1;
	que[tot] = u;
	tot++;
	int tmp = prev[u];
	while (tmp != v)
	{
		que[tot] = tmp;
		tot++;
		tmp = prev[tmp];
	}
	que[tot] = v;
	for (int i = tot; i >= 1; --i)
		if (i != 1)
			cout << que[i] << " -> ";
		else
			cout << que[i] << endl;
}

/*
int main()
{
	freopen("input.txt", "r", stdin);
	// 各数组都从下标1开始

	// 输入结点数
	cin >> n;
	// 输入路径数
	cin >> line;
	int p, q, len;          // 输入p, q两点及其路径长度

	// 初始化c[][]为maxint
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			c[i][j] = maxint;

	for(int i=1; i<=line; ++i)
	{
		cin >> p >> q >> len;
		if(len < c[p][q])       // 有重边
		{
			c[p][q] = len;      // p指向q
			c[q][p] = len;      // q指向p，这样表示无向图
		}
	}

	for(int i=1; i<=n; ++i)
		dist[i] = maxint;
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
			printf("%8d", c[i][j]);
		printf("\n");
	}

	Dijkstra(n, 1, dist, prev, c);

	// 最短路径长度
	cout << "源点到最后一个顶点的最短路径长度: " << dist[n] << endl;

	// 路径
	cout << "源点到最后一个顶点的路径为: ";
	searchPath(prev, 1, n);
}
*/
