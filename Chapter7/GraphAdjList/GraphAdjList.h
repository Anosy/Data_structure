#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct ArcNode // �߱���
{
	int adjvex; // �ڽӵ���
	ArcNode *next; 
};

struct dataNode // �������
{
	char data; 
	ArcNode *firstedge; // �߱�ͷָ��
};

const int MAXSIZE = 10;
int visited[MAXSIZE] = {};

class ALGraph
{
public:
	ALGraph(char a[], int n, int e); 
	~ALGraph() {} 
	void DFS(int i); // ������ȱ����㷨
	void DFS_Iteration(int i); // ������ȱ����ǵݹ��
	void DFSTraverse(); // ��ȱ�������

	void BFS(int i); // �����������
	void BFSTraverse(); // ������ȱ���

private:
	dataNode adjlist[MAXSIZE]; // ��Ŷ��������
	int dataNum, arcNum; // ͼ�еĶ������ͱ���
};


inline ALGraph::ALGraph(char a[], int n, int e)
{
	dataNum = n;
	arcNum = e;
	for (int i = 0; i < dataNum; i++) // ��ʼ��
	{
		adjlist[i].data = a[i];
		adjlist[i].firstedge = NULL;
	}

	cout << "�����±�i���±�j��\n";
	for (int k = 0; k < arcNum; k++)
	{
		int i, j;
		cin >> i >> j;
		ArcNode* node = new ArcNode;

		// ͷ�巨
		/*node->adjvex = j;
		node->next = adjlist[i].firstedge;
		adjlist[i].firstedge = node;

		node->adjvex = i;
		node->next = adjlist[j].firstedge;
		adjlist[j].firstedge = node;*/

		// β�巨
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
			while (p->next != NULL) // �ҵ������������λ��
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
			while (p->next != NULL) // �ҵ������������λ��
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

inline void ALGraph::DFS(int i) // �����ͼͼ�Ļ�һ�θ㶨
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
����ڽӾ���
ÿ�ζ��ǽ����ʹ��Ľ�����ջ��Ȼ���Ҹý��Ϊ���������ָ����p�����ж�p
�Ƿ�Ϊ�գ������λ�գ���ô�ʹӸ�ָ����ʼ���ҵ��Ƿ���ý�����ӣ�����
��û�з��ʹ��Ľ�㣬������ڣ���ӡ�����ҽ������ջ��Ȼ����һ��ѭ����ʹ��
���ҵ��Ľ�㿪ʼ��Ȼ�����Ѱ���������ģ�������û�б����ʹ��ġ�
ֱ���ý�����ӵĶ������ʹ�������û�����ӵĽ���ˣ���ô�ͽ�ջ����������Ȼ�󷵻ص�ǰһ�������ɼ���Ѱ�ҵĹ���
ʲôʱ���ʾ��ǰ�Ľ�����ڵĽ�㶼�����ʹ����أ���p�ڲ��ϵĸ��£�ֱ��p���µ����ָ��NULL��ָ��Ϊֹ
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
