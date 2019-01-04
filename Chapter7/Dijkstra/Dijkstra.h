#include<iostream>

using namespace std;

const int MAXVEX = 9;
const int INF = 65535;



class Dijkstra_MGraph
{
public:
	Dijkstra_MGraph();
	~Dijkstra_MGraph(){}
	void ShortestPath_Dijkstra(int v0, int P[], int D[]);
private:
	int arc[MAXVEX][MAXVEX];
	int numVertexes;
};

Dijkstra_MGraph::Dijkstra_MGraph()
{
	numVertexes = 9;
	for (int i = 0; i < numVertexes; i++) 
	{
		for (int j = 0; j < numVertexes; j++)
		{
			if (i == j)
				arc[i][j] = 0;
			else
				arc[i][j] = arc[j][i] = INF;
		}
	}
	//  固定初始化
	arc[0][1] = 1;
	arc[0][2] = 5;
	arc[1][2] = 3;
	arc[1][3] = 7;
	arc[1][4] = 5;

	arc[2][4] = 1;
	arc[2][5] = 7;
	arc[3][4] = 2;
	arc[3][6] = 3;
	arc[4][5] = 3;

	arc[4][6] = 6;
	arc[4][7] = 9;
	arc[5][7] = 5;
	arc[6][7] = 2;
	arc[6][8] = 7;

	arc[7][8] = 4;

	for (int i = 0; i < numVertexes; i++)
	{
		for (int j = i; j < numVertexes; j++)
		{
			arc[j][i] = arc[i][j];
		}
	}
}
inline void Dijkstra_MGraph::ShortestPath_Dijkstra(int v0, int P[], int D[])
{
	int k; // k保存起始点出发最短距离的点
	int min; // 起始点到最短距离点之间的距离
	int finnal[MAXVEX]; // finnal数组：finnal[w] = 1,表示v0到Vw的最短路径已经有结果了

	// ---------初始准备
	for (int  v = 0; v < numVertexes; v++)
	{
		finnal[v] = 0;
		D[v] = arc[v0][v]; // 将D数组给初始化成与v0相连接的顶点的权值
		P[v] = 0;
	}
	D[v0] = 0; // v0到自己的距离为0
	finnal[v0] = 1; // v0到自己的距离无须求解
	// ---------

	// 开始主要循环
	for (int v = 1; v < numVertexes; v++) // 求解v0到某个顶点的最短距离，并且求出路径
	{
		min = INF;
		for (int w = 0; w < numVertexes; w++) // 寻找到v0最短的顶点和最短的距离
		{
			if (finnal[w] == 0 && D[w] < min)  // D保存的就是v0到某个结点的距离，如D[3] = 4,表示v0到v3的最短距离为4
			{
				k = w;
				min = D[w];
			}
		}
		finnal[k] = 1; // 将找到的最短距离的点给至1，下次不再访问

		for (int w = 0; w < numVertexes; w++) // 修改v0到各个点的最短距离
		{
			if (finnal[w] == 0 && (min + arc[k][w] < D[w])) // 如果w没有被访问过，并且新路径比旧的路径小
			{
				D[w] = min + arc[k][w]; // 更新新的距离
				P[w] = k; // 并且将v0到w的最短距离需要通过的前一个结点给保存下来。所以P[n] = k， 就是保存V0-Vn的前一个结点需要通过k
			}
		}
	}
}
