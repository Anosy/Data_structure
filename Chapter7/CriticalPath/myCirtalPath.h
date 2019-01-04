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

	// �̶���ʼ��
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

	etv = new int[MAXVEX]; // ������̬����

	for (int j = 0; j < numVertexes; j++)
	{
		etv[j] = 0; // ��ʼΪ0
	}

	while (!S1.empty())
	{
		int gettop = S1.top();
		S1.pop();
		count++;
		S2.push(gettop); // ��S1�����Ķ�����Ÿ�ѹ�뵽�������е�ջ��

		for (EdgeNode *e = adjlist[gettop].firstedge; e; e = e->next)
		{
			int k = e->adjvex;
			if ((--adjlist[k].in) == 0)
			{
				S1.push(k);
			}
			if ((etv[gettop] + e->weight) > etv[k]) // ���翪ʼʱ��Ϊmax{etv[i] + len(vi,vk)}��Ҳ���������ܵ��ﶥ��k�Ķ���+��k�ľ��룬ȡ���ֵ
			{									    // ��Ϊ���ܵ���k֮ǰ�����еĹ���Ӧ�ö����꣬����ȡ���
				etv[k] = etv[gettop] + e->weight;
			}
		}
	}
	if (count < numVertexes)
	{
		cout << "ͼ�д��ڻ�����������ͼ" << endl;

	}
	else
	{
		cout << "ͼ������ͼ" << endl;
	}
}

inline void my_CP_AdjListGraph::CriticalPath()
{
	int ete, lte; // ����緢��ʱ�����飬���ٷ���ʱ������
	TopologicalSort();
	ltv = new int[10];

	for (int i = 0; i < numVertexes; i++)
	{
		ltv[i] = etv[numVertexes - 1]; // ���¼���ٷ�����ʱ�����ʼ��
	}

	while (!S2.empty())
	{
		int gettop = S2.top();
		S2.pop();
		for (EdgeNode * e = adjlist[gettop].firstedge; e; e = e->next)
		{
			int k = e->adjvex;
			if (ltv[k] - e->weight < ltv[gettop]) // �¼�������ʱ��Ϊ��min{ltv[i] - len(vk, vj)} ,Ϊʲô����С����ΪҪ��֤���е���k�����������Сʱ��
			{
				ltv[gettop] = ltv[k] - e->weight;
			}
		}
	}

	cout << "etv �¼����緢��ʱ��" << endl;
	for (int i = 0; i < numVertexes; i++)
	{
		cout << etv[i] << " ";
	}
	cout << endl;

	cout << "ltv �¼���ٷ���ʱ��" << endl;
	for (int j = 0; j < numVertexes; j++)
	{
		cout << ltv[j] << " ";
	}
	cout << endl;

	cout << "ͼ�Ĺؼ�·��" << endl;
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
