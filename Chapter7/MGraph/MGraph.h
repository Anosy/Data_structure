#include<iostream>
#include<queue>
#include<stack>

using namespace std;

const int MAXSIZE = 10;
const int INF = 65535;
int visited[MAXSIZE] = {  };

template <typename T>
class MGraph
{
public:
	MGraph(T a[], int n, int e); // n�����㣬e����
	~MGraph(){}
	void DFS(int i); // ������ȵݹ����
	void DFS_Iteration(int i); // ������ȱ����ǵݹ��
	void DFSTraverse(); // ��ȱ�������

	void BFS(int i); // ������ȵݹ����
	void BFStraverse(); // ��ȱ�������


private:
	void GreateMGraph();
	T vexs[MAXSIZE]; // ��Ŷ��������
	int arc[MAXSIZE][MAXSIZE]; // ��űߵ�����
	int vertexNum, arcNum; // ͼ�ж���ͱߵ���Ŀ

};

template<typename T>
inline MGraph<T>::MGraph(T a[], int n, int e)
{
	vertexNum = n;
	arcNum = e;
	for (int i = 0; i < vertexNum; i++)
	{
		vexs[i] = a[i];
	}
	for (int  i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			arc[i][j] = INF;
		}
	}

	cout << "�����±�i���±�j��\n";
	for (int k = 0; k < arcNum; k++)
	{
		int i, j;
		cin >> i >> j;
		arc[i][j] = 1;
		arc[j][i] = 1;
	}

}

template<typename T>
inline void MGraph<T>::DFS(int i) // ��Ϊ��ͼͼ��ʱ�򣬵���һ�μ���
{
	visited[i] = 1;
	cout << vexs[i] << " ";
	for (int j = 0; j < vertexNum; j++)
	{
		if (arc[i][j] == 1 && visited[j] == 0)
		{
			DFS(j);
		}
	}
}


template<typename T>
inline void MGraph<T>::DFSTraverse() // ��ÿ������ã�Ŀ����Ϊ�˷�ֹ���ֹ���������
{
	for (int i = 0; i < vertexNum; i++)
	{
		visited[i] = 0;
	}
	for (int i = 0; i < vertexNum; i++)
	{
		if (visited[i] == 0)
		{
			DFS(i);
		}
	}
}

// ʹ��ջstack�ļ���
// ÿ�ζ��Ƿ��ʹ��Ľ����ջ��Ȼ��Ѱ����ý�����ӵĽ�㣬�������Ҳ��ջ
// Ȼ���´ο�ʼ�ҵ���ʼ��������ջ�Ľ��
// ֱ���ý�����ӵĶ������ʹ�������û�����ӵĽ���ˣ���ô�ͽ�ջ����������Ȼ�󷵻ص�ǰһ�������ɼ���Ѱ�ҵĹ���
// ֱ���ص�����Ľ�㣬����������������ӽ��ķ���Ϊֹ

template<typename T>
inline void MGraph<T>::DFS_Iteration(int i) // ��������ͨͼ��������ڹ����㣬����Ҫ�������еĶ���
{
	for (int i = 0; i < vertexNum; i++)
	{
		visited[i] = 0;
	}
	stack<int> S;
	cout << vexs[i] << " ";
	visited[i] = 1;
	S.push(i);
	while (!S.empty())
	{
		int i = S.top();
		int j;
		for (j = 0; j < vertexNum; j++)
		{
			if (arc[i][j] == 1 && visited[j] == 0)
			{
				cout << vexs[j] << " ";
				visited[j] = 1;
				S.push(j);
				break;
			}
		}
		if (j == vertexNum)
		{
			S.pop();
		}
	}
}



template<typename T>
inline void MGraph<T>::BFS(int i)
{
	queue<int> Q;
	for (int i = 0; i < vertexNum; i++) // ��ʼ���е�visited
	{
		visited[i] = 0;
	}
	visited[i] = 1;
	cout << vexs[i] << " ";
	Q.push(i);

	while (!Q.empty())
	{
		int i = Q.front();
		Q.pop();
		for (int j = 0; j < vertexNum; j++)
		{
			if (arc[i][j] == 1 && visited[j] == 0)
			{
				visited[j] = 1;
				cout << vexs[j] << " ";
				Q.push(j);
			}
		}
	}
}

template<typename T>
inline void MGraph<T>::BFStraverse()
{
	queue<int> Q;
	for (int i = 0; i < vertexNum; i++) // ��ʼ���е�visited
	{
		visited[i] = 0;
	}
	for (int i = 0; i < vertexNum; i++) // ��ֹ���ֹ����㣬�Ӷ����ѭ��
	{
		if (!visited[i])
		{
			visited[i] = 1;
			cout << vexs[i] << " ";
			Q.push(i);
			
			while (!Q.empty())
			{	
				int i = Q.front();
				Q.pop();
				for (int j = 0; j < vertexNum; j++)
				{
					if (arc[i][j] == 1 && visited[j] == 0)
					{
						visited[j] = 1;
						cout << vexs[j] << " ";
						Q.push(j);
					}
				}
			}
		}
	}
}


//  �鱾��ʼ������
template<typename T>
inline void MGraph<T>::GreateMGraph()
{
	int numVertexes, numEdges;
	int i, j, w;
	char ch;
	cout << "���붥�����ͱߵ���Ŀ" << endl;
	cin >> numVertexes >> numEdges;
	cout << "���붥�����Ϣ" << endl;
	for (int i = 0; i < numVertexes; i++)
	{
		cin >> ch;
		vexs[i] = ch;
	}
	for (int  i = 0; i < numVertexes; i++)
	{
		for (int j = 0; j < numVertexes; j++)
		{
			arc[i][j] = INF;
		}
	}
	for (int k = 0; k < numEdges; k++)
	{
		cout << "�����(vi, vj)�ϵ��±�Ϊi���±�Ϊj��Ȩw:\n";
		cin >> i >> j >> w;
		arc[i][j] = w;
		arc[j][i] = arc[i][j];
	}
}
