#include<iostream>
#include<queue>
#include<stack>

using namespace std;

struct ArcNode // 边结点
{
	int adjvex;
	ArcNode *next;
};

struct VexNode  // 顶点结点
{
	char data;
	ArcNode *firstedge;
};

const int MAXSIZE = 10;
int visited[MAXSIZE] = {};

class myAdjListGraph
{
public:
	myAdjListGraph();
	~myAdjListGraph(){}
	void DFS(int i); // 深度优先遍历算法
	void DFS_Iteration(int i); // 深度优先遍历非递归版
	void DFSTraverse(); // 深度遍历操作

	void BFS(int i); // 广度优先搜索
	void BFSTraverse(); // 广度优先遍历

private:
	VexNode adjlist[MAXSIZE];
	int numVertexes, numEdges;
};

inline myAdjListGraph::myAdjListGraph()
{
	numVertexes = 9;
	numEdges = 15;
	const char a[] = "ABCDEFGHI";

	for (int i = 0; i < numVertexes; i++)
	{
		adjlist[i].data = a[i];
		adjlist[i].firstedge = NULL;
	}

	int arc[9][9] = {};
	// 固定初始化
	arc[0][1] = 1;
	arc[0][5] = 1;
	arc[1][2] = 1;
	arc[1][6] = 1;
	arc[1][8] = 1;
	arc[2][3] = 1;
	arc[2][8] = 1;
	arc[3][4] = 1;
	arc[3][6] = 1;
	arc[3][7] = 1;
	arc[3][8] = 1;
	arc[4][5] = 1;
	arc[4][7] = 1;
	arc[5][6] = 1;
	arc[6][7] = 1;

	for (int i = 0; i < numVertexes; i++)
	{
		for (int j = 0; j < numVertexes; j++)
		{
			if (arc[i][j] == 1)
			{
				// 头插法
				/*ArcNode * node = new ArcNode;
				node->adjvex = j;
				node->next = adjlist[i].firstedge;
				adjlist[i].firstedge = node;*/

				// 尾插法
				if (adjlist[i].firstedge == NULL)
				{
					ArcNode *node = new ArcNode;
					node->adjvex = j;
					node->next = NULL;
					adjlist[i].firstedge = node;
				}
				else
				{
					ArcNode *p = adjlist[i].firstedge;
					ArcNode *node = new ArcNode;
					while (p->next != NULL)
					{
						p = p->next;
					}
					node->adjvex = j;
					node->next = NULL;
					p->next = node;
				}

				if (adjlist[j].firstedge == NULL)
				{
					ArcNode *node = new ArcNode;
					node->adjvex = i;
					node->next = NULL;
					adjlist[j].firstedge = node;
				}
				else
				{
					ArcNode *p = adjlist[j].firstedge;
					ArcNode *node = new ArcNode;
					while (p->next != NULL)
					{
						p = p->next;
					}
					node->adjvex = i;
					node->next = NULL;
					p->next = node;
				}

			}
		}
	}
	
	cout << "邻接表" << endl;
	for (int i = 0; i < numVertexes; i++)
	{
		cout << adjlist[i].data << "->";
		ArcNode *node = adjlist[i].firstedge;
		while (node)
		{
			cout << adjlist[node->adjvex].data << "->";
			node = node->next;
		}
		if (!node)
		{
			cout << "NULL";
		}
		cout << endl;
	}
	cout << endl;

}

inline void myAdjListGraph::DFS(int i)
{
	cout << adjlist[i].data << " ";
	visited[i] = 1;
	ArcNode * node = adjlist[i].firstedge;

	while (node)
	{
		if (visited[node->adjvex] == 0)
		{
			DFS(node->adjvex);
		}
		node = node->next;
	}
}

inline void myAdjListGraph::DFS_Iteration(int i)
{
	for (int i = 0; i < numVertexes; i++)
	{
		visited[i] = 0;
	}
	stack<int> S;
	cout << adjlist[i].data << " ";
	visited[i] = 1;
	S.push(i);

	while (!S.empty())
	{
		ArcNode *p = new ArcNode;
		int i = S.top();
		p = adjlist[i].firstedge;
		while (p)
		{
			if (visited[p->adjvex] == 0)
			{
				cout << adjlist[p->adjvex].data << " ";
				visited[p->adjvex] = 1;
				S.push(p->adjvex);
				break;
			}
			p = p->next;
		}
		if (p == NULL)
		{
			S.pop();
		}
	}
}

inline void myAdjListGraph::DFSTraverse()
{
	for (int i = 0; i < numVertexes; i++)
	{
		visited[i] = 0;
	}
	for (int i = 0; i < numVertexes; i++)
	{
		if (visited[i] == 0)
		{
			DFS(i);
		}
	}
}

inline void myAdjListGraph::BFS(int i)
{
	queue<int> Q;
	cout << adjlist[i].data << " ";
	Q.push(i);
	visited[i] = 1;

	while (!Q.empty())
	{
		int i = Q.front();
		ArcNode *p = adjlist[i].firstedge;
		Q.pop();

		while (p)
		{
			if (visited[p->adjvex] == 0)
			{
				Q.push(p->adjvex);
				visited[p->adjvex] = 1;
				cout << adjlist[p->adjvex].data << " ";
			}
			p = p->next;
		}
	}

}

inline void myAdjListGraph::BFSTraverse()
{
	for (int i = 0; i < numVertexes; i++)
	{
		visited[i] = 0;
	}
	for (int i = 0; i < numVertexes; i++)
	{
		if (visited[i] == 0)
		{
			BFS(i);
		}
	}
}
