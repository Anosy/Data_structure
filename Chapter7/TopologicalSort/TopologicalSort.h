#include<iostream>
#include<stack>

using namespace std;

const int MAXEDGE = 20;
const int INF = 65535;
const int MAXVEX = 14;


struct EdgeNode // �߱���
{
	int adjvex;
	int weight;
	EdgeNode *next;
};

struct VertexNode // �������
{
	int in; // �洢���
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


// �����ڽ�ͼ
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

	// �̶���ʼ��
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
	
	// ����ͼ
	/*arc[0][1] = 1;
	arc[1][2] = 1;
	arc[2][3] = 1;
	arc[3][1] = 1;*/
	
}

// ���ڽ�ͼת��Ϊ�ڽӱ�
/*
��Ҫ�Ĳ���Ϊ��
1. �Ƚ�������ʼ��
2. �ٽ��߱����ʼ��
*/
inline TP_AdjList::TP_AdjList(TP_MGraph G)
{
	
	numVertexes = G.numVertexes;
	numEdges = G.numEdges;

	// ��ʼ���ڽӱ�Ķ����
	for (int i = 0; i < numVertexes; i++)
	{
		adjList[i].in = 0;
		adjList[i].data = G.vexs[i]; // ��������Ϣ����
		adjList[i].firstedge = NULL;
	}
	// �����߱�
	for (int i = 0; i < numVertexes; i++)
	{
		for (int j = 0; j < numVertexes; j++)
		{
			if (G.arc[i][j] == 1)
			{
				// ͷ�巨
				EdgeNode *e = new EdgeNode;
				e->adjvex = j;
				e->next = adjList[i].firstedge;
				adjList[i].firstedge = e;
				adjList[j].in++;

				// β�巨
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

// ��������
/*
��Ҫ��Ҫʹ��ջ������Ҫɾ���Ľ�㡣
���ĵ�˼�룺�Ƚ����Ϊ0�Ķ������룬Ȼ��ɾ��������ɾ���Դ˶���Ϊβ�Ļ��������ظ���ֱ�����ȫ���Ķ�����߲��������Ϊ0�Ķ���Ϊֹ
*/
inline void TP_AdjList::TopologicalSort()
{
	int count = 0; // ͳ���������ĸ���
	stack<int> S;

	// �������еĶ��㣬�ҵ����е����Ϊ0�Ķ��㣬��ջ
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
			int k = e->adjvex; // ��ջ�������ڽӵĶ����±�k
			if ((--adjList[k].in) == 0) // ��k�������ȼ�1�����k�������ȼ�1�����Ϊ0���������ջ
			{
				S.push(k);
			}
		}
	}

	cout << "NULL" << endl;
	if (count < numVertexes)
	{
		cout << "ͼ�д��ڻ�����������ͼ" << endl;
	}
	else
	{
		cout << "ͼ������ͼ" << endl;
	}
}
