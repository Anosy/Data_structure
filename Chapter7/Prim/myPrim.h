#include<iostream>

using namespace std;

const int MAXSIZE = 10;
const int INF = 65535;


class my_Prim_MGraph
{
public:
	my_Prim_MGraph(int n = 9, int e = 15); // n个顶点，e条边
	~my_Prim_MGraph() {}
	void MiniSpanTree_Prim();

private:
	int arc[MAXSIZE][MAXSIZE]; // 存放边的数组
	int vertexNum, arcNum; // 图中顶点和边的数目
};

inline my_Prim_MGraph::my_Prim_MGraph(int n, int e)
{
	vertexNum = n;
	arcNum = e;

	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			if (i == j)
				arc[i][j] = 0;
			else
				arc[i][j] = arc[j][i] = INF;
		}
	}

	arc[0][1] = 10;
	arc[0][5] = 11;
	arc[1][2] = 18;
	arc[1][8] = 12;
	arc[1][6] = 16;
	arc[2][8] = 8;
	arc[2][3] = 22;
	arc[3][8] = 21;
	arc[3][6] = 24;
	arc[3][7] = 16;
	arc[3][4] = 20;
	arc[4][7] = 7;
	arc[4][5] = 26;
	arc[5][6] = 17;
	arc[6][7] = 19;


	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = i; j < vertexNum; j++)
		{
			arc[j][i] = arc[i][j];
		}
	}
}

inline void my_Prim_MGraph::MiniSpanTree_Prim()
{
	int min, k;
	int adjvex[MAXSIZE];
	int lowcost[MAXSIZE];

	lowcost[0] = 0;
	adjvex[0] = 0;
	
	for (int i = 1; i < vertexNum; i++)
	{
		lowcost[i] = arc[0][i];
		adjvex[i] = 0;
	}

	for (int i = 1; i < vertexNum; i++)
	{
		min = INF;
		k = 0;
		
		for (int j = 1; j < vertexNum; j++)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
		}
		cout << "当前顶点权值最小的边：" << "v" << adjvex[k] << "-v" << k << endl; // 打印当前顶点中权值最小的边
		lowcost[k] = 0;
		
		for (int v = 1; v < vertexNum; v++)
		{
			if (lowcost[v] != 0 && arc[k][v] < lowcost[v])
			{
				lowcost[v] = arc[k][v];
				adjvex[v] = k;
			}
		}
	}

	cout << "lowcost数组" << endl;
	for (int i = 0; i < vertexNum; i++)
	{
		cout << lowcost[i] << " ";
	}
	cout << endl;

	cout << "adjvex数组" << endl;
	for (int j = 0; j < vertexNum; j++)
	{
		cout << adjvex[j] << " ";
	}
	cout << endl;
}
