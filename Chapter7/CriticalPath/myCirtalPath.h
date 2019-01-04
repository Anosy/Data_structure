#include<iostream>
#include<stack>

using namespace std;

const int MAXVEX = 10;
const int MAXEDGE = 13;
const int INF = 65535;

stack<int> S2;
int *etv, *ltv;

struct EdgeNode
{
	int adjvex;
	int weight;
	EdgeNode *next;
};

struct VertexNode
{
	int in;
	int data;
	EdgeNode *firstedge;
};

class my_CP_AdjListGraph
{
public:
	my_CP_AdjListGraph();
	~my_CP_AdjListGraph() {}
	void TopologicalSort();
	void CriticalPath();
private:
	VertexNode adjlist[MAXVEX];
	int numVertexes, numEdges;
};

inline my_CP_AdjListGraph::my_CP_AdjListGraph()
{
	numVertexes = 10;
	numEdges = 13;

	for (int i = 0; i < numVertexes; i++)
	{
		adjlist[i].in = 0;
		adjlist[i].data = i;
		adjlist[i].firstedge = NULL;
	}

	// 固定初始化
	int arc[13][13] = {};
	arc[0][1] = 3;
	arc[0][2] = 4;
	arc[1][3] = 5;
	arc[1][4] = 6;
	arc[2][3] = 8;
	arc[2][5] = 7;
	arc[3][4] = 3;
	arc[4][6] = 9;
	arc[4][7] = 4;
	arc[5][7] = 6;
	arc[6][9] = 2;
	arc[7][8] = 5;
	arc[8][9] = 3;

	for (int i = 0; i < numVertexes; i++)
	{
		for (int j = 0; j < numVertexes; j++)
		{
			if (arc[i][j] != 0)
			{
				EdgeNode * e = new EdgeNode;
				e->adjvex = j;
				e->weight = arc[i][j];
				e->next = adjlist[i].firstedge;
				adjlist[i].firstedge = e;
				adjlist[j].in++;
			}
		}
	}
}

inline void my_CP_AdjListGraph::TopologicalSort()
{
	int count = 0;
	stack<int> S1;

	for (int i = 0; i < numVertexes; i++)
	{
		if (adjlist[i].in == 0)
		{
			S1.push(i);
		}
	}

	etv = new int[MAXVEX]; // 创建动态数组

	for (int j = 0; j < numVertexes; j++)
	{
		etv[j] = 0; // 初始为0
	}

	while (!S1.empty())
	{
		int gettop = S1.top();
		S1.pop();
		count++;
		S2.push(gettop); // 将S1弹出的顶点序号给压入到拓扑序列的栈中

		for (EdgeNode *e = adjlist[gettop].firstedge; e; e = e->next)
		{
			int k = e->adjvex;
			if ((--adjlist[k].in) == 0)
			{
				S1.push(k);
			}
			if ((etv[gettop] + e->weight) > etv[k]) // 最早开始时间为max{etv[i] + len(vi,vk)}。也就是所有能到达顶点k的顶点+与k的距离，取最大值
			{									    // 因为可能到达k之前，所有的工作应该都做完，所以取最大
				etv[k] = etv[gettop] + e->weight;
			}
		}
	}
	if (count < numVertexes)
	{
		cout << "图中存在环，不是拓扑图" << endl;

	}
	else
	{
		cout << "图是拓扑图" << endl;
	}
}

inline void my_CP_AdjListGraph::CriticalPath()
{
	int ete, lte; // 活动最早发生时间数组，活动最迟发生时间数组
	TopologicalSort();
	ltv = new int[10];

	for (int i = 0; i < numVertexes; i++)
	{
		ltv[i] = etv[numVertexes - 1]; // 将事件最迟发生的时间给初始化
	}

	while (!S2.empty())
	{
		int gettop = S2.top();
		S2.pop();
		for (EdgeNode * e = adjlist[gettop].firstedge; e; e = e->next)
		{
			int k = e->adjvex;
			if (ltv[k] - e->weight < ltv[gettop]) // 事件最晚发生时间为：min{ltv[i] - len(vk, vj)} ,为什么是最小，因为要保证所有的与k相连顶点的最小时间
			{
				ltv[gettop] = ltv[k] - e->weight;
			}
		}
	}

	cout << "etv 事件最早发生时间" << endl;
	for (int i = 0; i < numVertexes; i++)
	{
		cout << etv[i] << " ";
	}
	cout << endl;

	cout << "ltv 事件最迟发生时间" << endl;
	for (int j = 0; j < numVertexes; j++)
	{
		cout << ltv[j] << " ";
	}
	cout << endl;

	cout << "图的关键路径" << endl;
	for (int j = 0; j < numVertexes; j++)
	{
		for (EdgeNode *e = adjlist[j].firstedge; e; e = e->next)
		{
			int k = e->adjvex;
			ete = etv[j];
			lte = ltv[k] - e->weight;
			if (ete == lte)
			{
				cout << "<v" << adjlist[j].data << ", v" << adjlist[k].data << "> length: " << e->weight << endl;
			}
		}
	}
}
