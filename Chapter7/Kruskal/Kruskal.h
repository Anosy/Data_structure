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

class MGraph
{
public:
	MGraph();
	~MGraph() {};
	void MiniSpanTree_Kruskal();
private:
	void Swapn(Edge edges[], int i, int j);
	void mysort(Edge edges[]);
	int Find(int parent[], int f);
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
};


MGraph::MGraph()
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

// 交换头，尾，权值
void MGraph::Swapn(Edge edges[], int i, int j)
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

void MGraph::mysort(Edge edges[])
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

int MGraph::Find(int parent[], int f)
{
	while (parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}

/*
代码的核心就是Find操作和parent数组
parent数组：该数组的分析分为两个部分。

	1.数组元素的值。比如parent = {1, 5, 8, 7, 7, 8, 0, 0, 6} 首先从v0开始，parent[0]为1，表示0和1都在树上,我们假定集合为A，然后将1作为下标，parent[1]为5
	表示5也在集合A中，继续parent[5]为8，表示8也在集合A上，parent[8]为6.表示6也在集合A上。这时候parent[6]为0.说明6不在集合A上。这时候2还没归类，parent[2]为5，
	由于5在集合A上，所以2也在集合A上。还有3，4还没归类，parent[3]为7，parent[4]为7，表示3,4,7不是集合A的，所以设其在集合B。除了数值为0的元素，其他下标
	都考虑了。总结为A{0,1,2,5,6,8} B{3, 4, 7}。虽然现在所有的下标都访问了，但是在不同的集合中，我们还需要将其给融合成一个大的集合。但是我们不能让整图
	变成一个环路。所以在下面的循环中，我们将要找到parent的下标的值为0的位置，因为这个下标的值和这个下标还没连线，并且因为它们不在一个集合中，所以不会
	出现环路
	2.数值中某个下标的值为0，表示下标为一个集合的尽头(或者说端点)。所以一开始每个元素都是一个集合，然后在过程中被合并到一个大集合中

Find操作：就是找到下标n，使得以该下标的parent[n]的值为0，返回该下标n。
目的就是要找到一个集合的端，然后将该端给赋值。

什么是端，就是可以让集合相互合并，而且不出现环的集合中的点

*/
void MGraph::MiniSpanTree_Kruskal()
{
	int n, m;
	int k = 0;
	int parent[MAXVEX];/* 定义一数组用来判断边与边是否形成环路 */

	Edge edges[MAXEDGE];/* 定义边集数组,edge的结构为begin,end,weight,均为整型 */

	// 构建边界数组
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
	// 排序edge数组
	mysort(edges);

	// 初始化数组的值为0
	for (int i = 0; i < numVertexes; i++)
	{
		parent[i] = 0;
	}

	// 算法核心部分代码
	cout << "打印最小生成树" << endl;
	for (int i = 0; i < numEdges; i++) // 循环每一条边 
	{
		n = Find(parent, edges[i].begin); // 找begin和end是否是在一个集合
		m = Find(parent, edges[i].end);
		if (n != m) /* 假如n与m不等，说明此边没有与现有的生成树形成环路 */
		{
			parent[n] = m;	/* 将此边的结尾顶点放入下标为起点的parent中。 */
							/* 表示此顶点已经在生成树集合中 */
			cout <<
				edges[i].begin << " " <<
				edges[i].end << " " <<
				edges[i].weight << endl;
		}
	}
}
