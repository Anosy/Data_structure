#include<iostream>

using namespace std;

const int MAXVEX = 9;
const int INF = 65535;


class Floyd_MGraph
{
public:
	Floyd_MGraph();
	~Floyd_MGraph(){}
	void ShortPath_Floyd(int P[MAXVEX][MAXVEX], int D[MAXVEX][MAXVEX]);
private:
	int arc[MAXVEX][MAXVEX];
	int numVertexes;
};

inline Floyd_MGraph::Floyd_MGraph()
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

inline void Floyd_MGraph::ShortPath_Floyd(int P[MAXVEX][MAXVEX], int D[MAXVEX][MAXVEX])
{
	// 初始化两个数组，D表示顶点到顶点的最短路径的权值的矩阵，P表示顶点的最小路径的前驱矩阵
	for (int i = 0; i < numVertexes; i++)
	{
		for (int j = 0; j < numVertexes; j++)
		{
			D[i][j] = arc[i][j];
			P[i][j] = j;
		}
	}

	/*
	三层嵌套的循环
	判断经过下标为k的顶点，两点之间的距离比两点之间的直接距离短的话，那么就将两点之间的距离给更新成当前的最小距离
	并且将并且将要到达最小路径的前驱顶点设为k下标的顶点
	最终形成的表D，每一行表示当前点到其他顶点的最短距离
	表P：比如P[0][8]=1表示，我们从V0到V8就需要通过V1，然后再将V1作为开始，P[1][8] = 2，说明路径为V0-V1-V2 ...
	*/
	for (int k = 0; k < numVertexes; k++)
	{
		for (int i = 0; i < numVertexes; i++)
		{
			for (int j = 0; j < numVertexes; j++)
			{
				if (D[i][j] > (D[i][k] + D[k][j]))
				{
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = P[i][k];
				}
			}
		}
	}
}
