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
inline void Dijkstra_MGraph::ShortestPath_Dijkstra(int v0, int P[], int D[])
{
	int k; // k������ʼ�������̾���ĵ�
	int min; // ��ʼ�㵽��̾����֮��ľ���
	int finnal[MAXVEX]; // finnal���飺finnal[w] = 1,��ʾv0��Vw�����·���Ѿ��н����

	// ---------��ʼ׼��
	for (int  v = 0; v < numVertexes; v++)
	{
		finnal[v] = 0;
		D[v] = arc[v0][v]; // ��D�������ʼ������v0�����ӵĶ����Ȩֵ
		P[v] = 0;
	}
	D[v0] = 0; // v0���Լ��ľ���Ϊ0
	finnal[v0] = 1; // v0���Լ��ľ����������
	// ---------

	// ��ʼ��Ҫѭ��
	for (int v = 1; v < numVertexes; v++) // ���v0��ĳ���������̾��룬�������·��
	{
		min = INF;
		for (int w = 0; w < numVertexes; w++) // Ѱ�ҵ�v0��̵Ķ������̵ľ���
		{
			if (finnal[w] == 0 && D[w] < min)  // D����ľ���v0��ĳ�����ľ��룬��D[3] = 4,��ʾv0��v3����̾���Ϊ4
			{
				k = w;
				min = D[w];
			}
		}
		finnal[k] = 1; // ���ҵ�����̾���ĵ����1���´β��ٷ���

		for (int w = 0; w < numVertexes; w++) // �޸�v0�����������̾���
		{
			if (finnal[w] == 0 && (min + arc[k][w] < D[w])) // ���wû�б����ʹ���������·���Ⱦɵ�·��С
			{
				D[w] = min + arc[k][w]; // �����µľ���
				P[w] = k; // ���ҽ�v0��w����̾�����Ҫͨ����ǰһ��������������������P[n] = k�� ���Ǳ���V0-Vn��ǰһ�������Ҫͨ��k
			}
		}
	}
}
