#include<iostream>
#include<stack>

using namespace std;

const int MAXEDGE = 20;
const int INF = 65535;
const int MAXVEX = 14;


struct EdgeNode // 边表结点
{
	int adjvex;
	int weight;
	EdgeNode *next;
};

struct VertexNode // 顶点表结点
{
	int in; // 存储入度
	int data; 
	EdgeNode * firstedge;
};

class TP_AdjList;

class TP_MGraph
{
	friend class TP_AdjList;
public:
	TP_MGraph();
	~TP_MGraph(){}

private:
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
};


class TP_AdjList
{
public:
	TP_AdjList(TP_MGraph G);
	~TP_AdjList() {};
	void TopologicalSort();

private:
	VertexNode adjList[MAXVEX];
	int numVertexes, numEdges;
};


// 创建邻接图
inline TP_MGraph::TP_MGraph()
{
	numVertexes = MAXVEX;
	numEdges = MAXEDGE;

	for (int i = 0; i < numVertexes; i++)
	{
		for (int j = 0; j < numVertexes; j++)
		{
			if (i == j)
			{
				arc[i][j] = 0;
			}
			else
			{
				arc[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < numVertexes; i++)
	{
		vexs[i] = i;
	}

	// 固定初始化
	arc[0][4] = 1;
	arc[0][5] = 1;
	arc[0][11] = 1;
	arc[1][2] = 1;
	arc[1][4] = 1;
	arc[1][8] = 1;
	arc[2][5] = 1;
	arc[2][6] = 1;
	arc[2][9] = 1;
	arc[3][2] = 1;
	arc[3][13] = 1;
	arc[4][7] = 1;
	arc[5][8] = 1;
	arc[5][12] = 1;
	arc[6][5] = 1;
	arc[8][7] = 1;
	arc[9][10] = 1;
	arc[9][11] = 1;
	arc[10][13] = 1;
	arc[12][9] = 1;
	
	// 有向环图
	/*arc[0][1] = 1;
	arc[1][2] = 1;
	arc[2][3] = 1;
	arc[3][1] = 1;*/
	
}

// 将邻接图转化为邻接表
/*
主要的操作为：
1. 先将顶点表初始化
2. 再将边表给初始化
*/
inline TP_AdjList::TP_AdjList(TP_MGraph G)
{
	
	numVertexes = G.numVertexes;
	numEdges = G.numEdges;

	// 初始化邻接表的顶点表
	for (int i = 0; i < numVertexes; i++)
	{
		adjList[i].in = 0;
		adjList[i].data = G.vexs[i]; // 将顶点信息存入
		adjList[i].firstedge = NULL;
	}
	// 建立边表
	for (int i = 0; i < numVertexes; i++)
	{
		for (int j = 0; j < numVertexes; j++)
		{
			if (G.arc[i][j] == 1)
			{
				// 头插法
				EdgeNode *e = new EdgeNode;
				e->adjvex = j;
				e->next = adjList[i].firstedge;
				adjList[i].firstedge = e;
				adjList[j].in++;

				// 尾插法
				/*if (adjList[i].firstedge == NULL)
				{
					EdgeNode * e = new EdgeNode;
					e->adjvex = j;
					e->next = NULL;
					adjList[i].firstedge = e;
					adjList[j].in++;
				}
				else
				{
					EdgeNode *p = adjList[i].firstedge;
					while (p->next != NULL)
					{
						p = p->next;
					}
					EdgeNode *e = new EdgeNode;
					e->adjvex = j;
					e->next = NULL;
					p->next = e;
					adjList[j].in++;
				}*/
			}
		}
	}
}

// 拓扑排序
/*
主要是要使用栈来保存要删除的结点。
核心的思想：先将入度为0的顶点输入，然后将删除，并且删除以此顶点为尾的弧，继续重复，直到输出全部的顶点或者不存在入度为0的顶点为止
*/
inline void TP_AdjList::TopologicalSort()
{
	int count = 0; // 统计输出顶点的个数
	stack<int> S;

	// 对于所有的顶点，找到所有的入度为0的顶点，入栈
	for (int  i = 0; i < numVertexes; i++)
	{
		if (adjList[i].in == 0)
		{
			S.push(i);
		}
	}
	while (!S.empty())
	{
		int top = S.top();
		S.pop();
		cout << adjList[top].data << " -> ";
		count++;
		for (EdgeNode* e = adjList[top].firstedge; e != NULL; e = e->next)
		{
			int k = e->adjvex; // 与栈顶顶点邻接的顶点下标k
			if ((--adjList[k].in) == 0) // 将k顶点的入度减1，如果k顶点的入度减1后，入度为0，则将其给入栈
			{
				S.push(k);
			}
		}
	}

	cout << "NULL" << endl;
	if (count < numVertexes)
	{
		cout << "图中存在环，不是拓扑图" << endl;
	}
	else
	{
		cout << "图是拓扑图" << endl;
	}
}
