#include<iostream>
#include<queue>
#include<stack>

using namespace std;

const int MAXSIZE = 10;
const int INF = 65535;
int visited[MAXSIZE] = {};

class myMGraph
{
public:
	myMGraph();  
	~myMGraph(){}
	void DFS(int i); // ������ȵݹ����
	void DFS_Iteration(int i); // ������ȱ����ǵݹ��
	void DFSTraverse(); // ��ȱ�������

	void BFS(int i); // ������ȵݹ����
	void BFStraverse(); // ��ȱ�������

private:
	char vexs[MAXSIZE]; // ��Ŷ��������
	int arc[MAXSIZE][MAXSIZE]; // ��űߵ�����
	int numVertexes, numEdges; // ͼ�ж���ͱߵ���Ŀ
};

inline myMGraph::myMGraph()
{
	numVertexes = 9;
	numEdges = 15;
	char a[] = "ABCDEFGHI";

	for (int i = 0; i < numVertexes; i++)
	{
		vexs[i] = a[i];
	}

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
	
	// �̶���ʼ��
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
			arc[j][i] = arc[i][j];
		}
	}

	cout << "��������" << endl;
	for (int i = 0; i < numVertexes; i++)
	{
		cout << vexs[i] << " ";
	}
	cout << endl;
	cout << endl;

	cout << "������" << endl;
	for (int i = 0; i < numVertexes; i++)
	{
		for (int j = 0; j < numVertexes; j++)
		{
			cout << arc[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

}

inline void myMGraph::DFS(int i)
{
	visited[i] = 1;
	cout << vexs[i] << " ";

	for (int j = 0; j < numVertexes; j++)
	{
		if (visited[j] == 0 && arc[i][j] == 1)
		{
			DFS(j);
		}
	}
}

inline void myMGraph::DFS_Iteration(int i)
{
	for (int i = 0; i < numVertexes; i++)
	{
		visited[i] = 0;
	}
	stack<int> S;
	S.push(i);
	visited[i] = 1;
	cout << vexs[i] << " ";

	while (!S.empty())
	{
		int i = S.top();
		int j;
		for (j = 0; j < numVertexes; j++)
		{
			if (arc[i][j] == 1 && visited[j] == 0)
			{
				cout << vexs[j] << " ";
				S.push(j);
				visited[j] = 1;
				break;
			}
		}
		if (j == numVertexes)
		{
			S.pop();
		}
	}
}

inline void myMGraph::DFSTraverse()
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

inline void myMGraph::BFS(int i)
{
	queue<int> Q;
	cout << vexs[i] << " ";
	Q.push(i);
	visited[i] = 1;

	while (!Q.empty())
	{
		int i = Q.front();
		Q.pop();

		for (int j = 0; j < numVertexes; j++)
		{
			if (arc[i][j] == 1 && visited[j] == 0)
			{
				cout << vexs[j] << " ";
				visited[j] = 1;
				Q.push(j);
			}
		}
	}
}

inline void myMGraph::BFStraverse()
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
