#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct ArcNode // 边表结点
{
	int adjvex; // 邻接点域
	ArcNode *next; 
};

struct dataNode // 顶点表结点
{
	char data; 
	ArcNode *firstedge; // 边表头指针
};

const int MAXSIZE = 10;
int visited[MAXSIZE] = {};

class ALGraph
{
public:
	ALGraph(char a[], int n, int e); 
	~ALGraph() {} 
	void DFS(int i); // 深度优先遍历算法
	void DFS_Iteration(int i); // 深度优先遍历非递归版
	void DFSTraverse(); // 深度遍历操作

	void BFS(int i); // 广度优先搜索
	void BFSTraverse(); // 广度优先遍历

private:
	dataNode adjlist[MAXSIZE]; // 存放顶点的数组
	int dataNum, arcNum; // 图中的顶点数和边数
};


inline ALGraph::ALGraph(char a[], int n, int e)
{
	dataNum = n;
	arcNum = e;
	for (int i = 0; i < dataNum; i++) // 初始化
	{
		adjlist[i].data = a[i];
		adjlist[i].firstedge = NULL;
	}

	cout << "输入下标i，下标j：\n";
	for (int k = 0; k < arcNum; k++)
	{
		int i, j;
		cin >> i >> j;
		ArcNode* node = new ArcNode;

		// 头插法
		/*node->adjvex = j;
		node->next = adjlist[i].firstedge;
		adjlist[i].firstedge = node;

		node->adjvex = i;
		node->next = adjlist[j].firstedge;
		adjlist[j].firstedge = node;*/

		// 尾插法
		if (adjlist[i].firstedge == NULL)
		{
			ArcNode* s = new ArcNode;
			s->adjvex = j;
			s->next = NULL;
			adjlist[i].firstedge = s;
		}
		else
		{
			ArcNode *p = adjlist[i].firstedge;
			while (p->next != NULL) // 找到该链表的最后的位置
			{
				p = p->next;
			}
			ArcNode* s = new ArcNode;
			s->adjvex = j;
			s->next = NULL;
			p->next = s;
		}

		if (adjlist[j].firstedge == NULL)
		{
			ArcNode* s = new ArcNode;
			s->adjvex = i;
			s->next = NULL;
			adjlist[j].firstedge = s;
		}
		else
		{
			ArcNode *p = adjlist[j].firstedge;
			while (p->next != NULL) // 找到该链表的最后的位置
			{
				p = p->next;
			}
			ArcNode* s = new ArcNode;
			s->adjvex = i;
			s->next = NULL;
			p->next = s;
		}


	}
}

inline void ALGraph::DFS(int i) // 针对连图图的话一次搞定
{
	ArcNode *p = new ArcNode;
	visited[i] = 1;
	cout << adjlist[i].data << " ";
	p = adjlist[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvex])
		{
			DFS(p->adjvex);
		}
		p = p->next;
	}
}

/*
借鉴邻接矩阵
每次都是将访问过的结点给入栈，然后找该结点为顶点数组的指针域p，先判断p
是否为空，如果部位空，那么就从该指针域开始，找到是否与该结点连接，但是
还没有访问过的结点，如果存在，打印，并且将其给入栈，然后下一次循环就使用
新找到的结点开始，然后继续寻找它相连的，但是又没有被访问过的。
直到该结点连接的都被访问过，或者没有连接的结点了，那么就将栈顶给弹出，然后返回到前一个结点完成继续寻找的工作
什么时候表示当前的结点相邻的结点都被访问过了呢？答：p在不断的更新，直到p更新到最后指向NULL的指针为止
*/
inline void ALGraph::DFS_Iteration(int i)
{
	for (int i = 0; i < dataNum; i++)
	{
		visited[i] = 0;
	}
	stack<int> S;
	visited[i] = 1;
	cout << adjlist[i].data << " ";
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

inline void ALGraph::DFSTraverse()
{
	for (int i = 0; i < dataNum; i++)
	{
		visited[i] = 0;
	}
	for (int  i = 0; i < dataNum; i++)
	{
		if (!visited[i])
		{
			DFS(i);
		}
	}
}

inline void ALGraph::BFS(int i)
{
	queue<int> Q;
	for (int i = 0; i < dataNum; i++)
	{
		visited[i] = 0;
	}

	visited[i] = 1;
	cout << adjlist[i].data << " ";
	Q.push(i);

	while (!Q.empty())
	{
		int i = Q.front();
		ArcNode *p = adjlist[i].firstedge;
		Q.pop();
		while (p)
		{
			if (!visited[p->adjvex])
			{
				visited[p->adjvex] = 1;
				cout << adjlist[p->adjvex].data << " ";
				Q.push(p->adjvex);
			}
			p = p->next;
		}
	}
}

inline void ALGraph::BFSTraverse()
{
	queue<int> Q;
	for (int i = 0; i < dataNum; i++)
	{
		visited[i] = 0;
	}
	for (int i = 0; i < dataNum; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			cout << adjlist[i].data << " ";
			Q.push(i);
			
			while (!Q.empty())
			{
				int i = Q.front();
				ArcNode *p = adjlist[i].firstedge;
				Q.pop();
				while (p)
				{
					if (!visited[p->adjvex])
					{
						visited[p->adjvex] = 1;
						cout << adjlist[p->adjvex].data << " ";
						Q.push(p->adjvex);
					}
					p = p->next;
				}
			}
		}
	}
}
