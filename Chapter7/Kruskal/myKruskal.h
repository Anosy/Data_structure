#include<iostream>

using namespace std;

const int MAXEDGE = 20;
const int MAXVEX = 20;
const int INF = 65535;

struct Edge
{
	int begin;
	int end;
	int weight;
};

class Kruskal_MGraph
{
public:
	Kruskal_MGraph();
	~Kruskal_MGraph() {};
	void MiniSpanTree_Kruskal();

private:
	void Swapn(Edge edges[], int i, int j);
	void mysort(Edge edges[]);
	int Find(int parent[], int f);
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
};

inline Kruskal_MGraph::Kruskal_MGraph()
{
	numEdges = 15;
	numVertexes = 9;

	for (int i = 0; i < numVertexes; i++)/* 初始化图 */
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

	for (int i = 0; i < numVertexes; i++)
	{
		for (int j = i; j < numVertexes; j++)
		{
			arc[j][i] = arc[i][j];
		}
	}
}

inline void Kruskal_MGraph::MiniSpanTree_Kruskal()
{
	int n, m;
	int k = 0;
	int parent[MAXVEX];

	Edge edges[MAXEDGE]; // 定义边集数组
	
	for (int i = 0; i < numVertexes - 1; i++)
	{
		for (int j = i + 1; j < numVertexes; j++)
		{

			if (arc[i][j] < INF)
			{
				edges[k].begin = i;
				edges[k].end = j;
				edges[k].weight = arc[i][j];
				k++;
			}
		}
	}

	mysort(edges);

	// 初始化parent数组
	for (int i = 0; i < numVertexes; i++)
	{
		parent[i] = 0;
	}

	cout << "打印最小生成树" << endl;
	for (int i = 0; i < numEdges; i++)
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if (n != m)
		{
			parent[n] = m; // 说明vn顶点已经在加入到生成树的集合中,n和m是在一个集合中的
			cout <<
				edges[i].begin << " " <<
				edges[i].end << " " <<
				edges[i].weight << endl;
		}
	}

}

inline void Kruskal_MGraph::Swapn(Edge edges[], int i, int j)
{
	int temp;

	temp = edges[i].begin;
	edges[i].begin = edges[j].begin;
	edges[j].begin = temp;

	temp = edges[i].end;
	edges[i].end = edges[j].end;
	edges[j].end = temp;

	temp = edges[i].weight;
	edges[i].weight = edges[j].weight;
	edges[j].weight = temp;

}

inline void Kruskal_MGraph::mysort(Edge edges[])
{
	for (int i = 0; i < numEdges; i++)
	{
		for (int j = i + 1; j < numEdges; j++)
		{
			if (edges[i].weight > edges[j].weight)
			{
				Swapn(edges, i, j);
			}
		}
	}
	cout << "权排序之后的为:\n";
	for (int i = 0; i < numEdges; i++)
	{
		cout <<
			edges[i].begin << " " <<
			edges[i].end << " " <<
			edges[i].weight << endl;
	}
}

inline int Kruskal_MGraph::Find(int parent[], int f)
{
	while (parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}
