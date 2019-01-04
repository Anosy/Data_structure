#include<iostream>

using namespace std;

const int MAXVEX = 9;
const int INF = 65535;



class my_Dijkstra_MGraph
{
public:
	my_Dijkstra_MGraph();
	~my_Dijkstra_MGraph() {}
	void ShortestPath_Dijkstra(int v0, int P[], int D[]);
private:
	int arc[MAXVEX][MAXVEX];
	int numVertexes;
};

inline my_Dijkstra_MGraph::my_Dijkstra_MGraph()
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
	//  �̶���ʼ��
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

inline void my_Dijkstra_MGraph::ShortestPath_Dijkstra(int v0, int P[], int D[])
{
	int k;
	int min;
	int finnal[MAXVEX];

	// ��ʼ��
	for (int i = 0; i < numVertexes; i++)
	{
		finnal[i] = 0;
		P[i] = 0;
		D[i] = arc[v0][i];
	}

	finnal[v0] = 1;
	D[v0] = 0;

	// ��ѭ��
	for (int w = 1; w < numVertexes; w++)
	{
		// Ѱ�Ҷ��㵽ĳ�������̵ľ���
		min = INF;
		for (int v = 0; v < numVertexes; v++)
		{
			if (finnal[v] == 0 && D[v] < min)
			{
				k = v;
				min = D[v];
			}
		}
		finnal[k] = 1;

		// ���´���ʼ�㵽Ŀ�궥��ľ���
		for (int i = 0; i < numVertexes; i++)
		{
			if (finnal[i] == 0 && (min + arc[k][i] < D[i]))
			{
				D[i] = min + arc[k][i];
				P[i] = k;
			}
		}
	}

	cout << "finnal����" << endl;
	for (int i = 0; i < numVertexes; i++)
	{
		cout << finnal[i] << " ";
	}
	cout << endl;

	cout << "P����" << endl;
	for (int i = 0; i < numVertexes; i++)
	{
		cout << P[i] << " ";
	}
	cout << endl;

	cout << "D����" << endl;
	for (int i = 0; i < numVertexes; i++)
	{
		cout << D[i] << " ";
	}
	cout << endl;


}
