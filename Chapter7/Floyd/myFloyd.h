#include<iostream>

using namespace std;

const int MAXVEX = 9;
const int INF = 65535;


class my_Floyd_MGraph
{
public:
	my_Floyd_MGraph();
	~my_Floyd_MGraph() {}
	void ShortPath_Floyd(int P[MAXVEX][MAXVEX], int D[MAXVEX][MAXVEX]);
private:
	int arc[MAXVEX][MAXVEX];
	int numVertexes;
};

inline my_Floyd_MGraph::my_Floyd_MGraph()
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

inline void my_Floyd_MGraph::ShortPath_Floyd(int P[MAXVEX][MAXVEX], int D[MAXVEX][MAXVEX])
{
	// 初始化两个数组
	for (int i = 0; i < numVertexes; i++)
	{
		for (int j = 0; j < numVertexes; j++)
		{
			D[i][j] = arc[i][j];
			P[i][j] = j;
		}
	}
	for (int k = 0; k < numVertexes; k++)
	{
		for (int i = 0; i < numVertexes; i++)
		{
			for (int j = 0; j < numVertexes; j++)
			{
				if (D[i][j] > D[i][k] + D[k][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = P[i][k];
				}
			}
		}
	}
}
