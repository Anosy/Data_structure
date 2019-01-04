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

class CP_AdjListGraph
{
public:
	CP_AdjListGraph();
	~CP_AdjListGraph(){}
	void TopologicalSort();
	void CriticalPath();
private:
	VertexNode adjlist[MAXVEX];
	int numVertexes, numEdges;
};


inline CP_AdjListGraph::CP_AdjListGraph()
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

	for (int  i = 0; i < numVertexes; i++)
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

// �޸�������������Ϊ�ؼ�·����������������Ļ����ϣ�Ҫ���϶Աߵ�Ȩֵ���Ӷ�����Դ�㵽�����ʱ�䣬�Ӷ��õ��ؼ�·��
/*
1.�����Ϊ0�Ķ������ջ
2.��etv�¼����翪ʼʱ�����ʼ��Ϊ0
3.���ջ�ǿգ���ô��ѭ��
	��S1ջ������ջ��Ȼ�󽫵�����Ԫ�ظ���ջ��S2�У�Ҳ����S2�б���ľ������е���������
	�����ҵ���ջ������Ϊβ�Ķ��㣬Ȼ�������ȼ�1�������ж��Ƿ���ʱ�����Ϊ0�����Ϊ0����ջ��
	���Ҹ����¼������緢��ʱ�䡣ѡȡ���е�ջ�����㵽��Ķ���k������ʱ������ֵ��Ϊʲô�����ֵ����ΪҪ��ǰ�����еĶ��㵽���˵�ǰ�Ķ�����������������
4.ͨ��ѭ��etv���Լ�ջS2
*/
inline void CP_AdjListGraph::TopologicalSort()
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

	etv = new int[10]; // ������̬����

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

		for (EdgeNode *e  = adjlist[gettop].firstedge; e; e = e->next)
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

// �ؼ�·���Ĺ���
/*
1.ͨ��TopologicalSort�õ�etv��S2
2.��ltv�¼�������ʱ�����ʼ��Ϊ�������緢��ʱ�䡣��Ϊ�������緢��ʱ�����ٷ���ʱ������ͬ�ģ������൱���û���������ʱ���ʼ��ȫ����������ʱ��
3.S2��ʼ��ջ����ʱ���Ǵӻ�㿪ʼ
	���ȴӻ�㿪ʼ���˵�Դ�㡣
	��������һ�����㣬������û���ڽӱ߱�
	Ȼ�����Ķ��������ʱ�䶼����߱�ָ��Ķ��������ʱ��-�߷������¼�(�������ʱ��)���ҽ��ȡ��Сֵ��
	Ϊʲôȡ��Сֵ����Ϊ�����ȡ��Сֵ�����ܽ��ᵼ�¸Ķ������һ�����ӵĶ��㣬���¼�����ķ���ʱ��Ҫ�Ƴ�
4.����ѭ���õ���ltv���¼�������ʱ��
5. Ѱ��ͼ�Ĺؼ�·��
	����������е����еĶ��㣬����ö��㵽�������Ķ���Ļ���緢��ʱ��ͻ������ʱ��
	����緢��ʱ��Ϊ��ǰ��������ķ���ʱ�䡣��Ϊ�ֻ����������㷢����֮����ܷ�����
	�������ʱ��Ϊ��ǰ�������ӵ���һ�������������ʱ��-�ߵ�ʱ�䣬���¼�ֻ������һ������������֮ǰ���ܷ���
	�����ʱ�������緢��ʱ����ڻ��������ʱ�䣬��ô˵���ûû�п��е�ʱ�䣬ȫ����ռ���ˣ����ԸûΪ�ؼ��
	���������翪ʼʱ�������ʼʱ�䲻��ͬ��˵�����ʼ��ʱ�䲻ȷ�������Բ����ܹ��������̵ģ����ǹؼ��
*/
inline void CP_AdjListGraph::CriticalPath()
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


 