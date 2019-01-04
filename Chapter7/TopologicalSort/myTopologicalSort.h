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

class my_TP_AdjList
{
public:
	my_TP_AdjList();
	~my_TP_AdjList() {};
	void TopologicalSort();

private:
	VertexNode adjlist[MAXVEX];
	int numVertexes, numEdges;
};

inline my_TP_AdjList::my_TP_AdjList()
{
	numVertexes = 14;
	numEdges = 20;
	for (int i = 0; i < numVertexes; i++)
	{
		adjlist[i].data = i;
		adjlist[i].in = 0;
		adjlist[i].firstedge = NULL;
	}

	int arc[14][14];

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


	for (int i = 0; i < numVertexes; i++)
	{
		for (int j = 0; j < numVertexes; j++)
		{
			if (arc[i][j] == 1)
			{
				// 头插法
				EdgeNode * node = new EdgeNode;
				node->adjvex = j;
				node->next = adjlist[i].firstedge;
				adjlist[i].firstedge = node;
				adjlist[j].in++;

				// 尾插法
				/*if (adjlist[i].firstedge == NULL)
				{
					EdgeNode *node = new EdgeNode;
					node->adjvex = j;
					node->next = NULL;
					adjlist[i].firstedge = node;
					adjlist[j].in++;
				}
				else
				{
					EdgeNode *p = adjlist[i].firstedge;
					EdgeNode *node = new EdgeNode;
					while (p->next != NULL)
					{
						p = p->next;
					}
					node->adjvex = j;
					node->next = NULL;
					p->next = node;
					adjlist[j].in++;
				}*/
			}
		}
	}
}

inline void my_TP_AdjList::TopologicalSort()
{
	int count = 0;
	stack<int> S;

	for (int i = 0; i < numVertexes; i++)
	{
		if (adjlist[i].in == 0)
		{
			S.push(i);
		}
	}
	while (!S.empty())
	{
		int top = S.top();
		S.pop();
		cout << adjlist[top].data << " -> ";
		count++;

		for (EdgeNode * e = adjlist[top].firstedge; e; e = e->next)
		{
			int k = e->adjvex;
			if ((--adjlist[k].in) == 0)
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
