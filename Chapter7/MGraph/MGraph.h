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
	MGraph(T a[], int n, int e); // n个顶点，e条边
	~MGraph(){}
	void DFS(int i); // 深度优先递归遍历
	void DFS_Iteration(int i); // 深度优先遍历非递归版
	void DFSTraverse(); // 深度遍历操作

	void BFS(int i); // 广度优先递归遍历
	void BFStraverse(); // 广度遍历操作


private:
	void GreateMGraph();
	T vexs[MAXSIZE]; // 存放顶点的数组
	int arc[MAXSIZE][MAXSIZE]; // 存放边的数组
	int vertexNum, arcNum; // 图中顶点和边的数目

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

	cout << "输入下标i，下标j：\n";
	for (int k = 0; k < arcNum; k++)
	{
		int i, j;
		cin >> i >> j;
		arc[i][j] = 1;
		arc[j][i] = 1;
	}

}

template<typename T>
inline void MGraph<T>::DFS(int i) // 当为连图图的时候，调用一次即可
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
inline void MGraph<T>::DFSTraverse() // 对每个点调用，目的是为了防止出现孤立点的情况
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

// 使用栈stack的技术
// 每次都是访问过的结点入栈，然后寻找与该结点连接的结点，如果存在也入栈
// 然后下次开始找到开始就是新入栈的结点
// 直到该结点连接的都被访问过，或者没有连接的结点了，那么就将栈顶给弹出，然后返回到前一个结点完成继续寻找的工作
// 直到回到最初的结点，完成这个结点所有连接结点的访问为止

template<typename T>
inline void MGraph<T>::DFS_Iteration(int i) // 适用于连通图，如果存在孤立点，则需要调用所有的顶点
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
	for (int i = 0; i < vertexNum; i++) // 初始所有的visited
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
	for (int i = 0; i < vertexNum; i++) // 初始所有的visited
	{
		visited[i] = 0;
	}
	for (int i = 0; i < vertexNum; i++) // 防止出现孤立点，从而多次循环
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


//  书本初始化程序
template<typename T>
inline void MGraph<T>::GreateMGraph()
{
	int numVertexes, numEdges;
	int i, j, w;
	char ch;
	cout << "输入顶点数和边的数目" << endl;
	cin >> numVertexes >> numEdges;
	cout << "输入顶点的信息" << endl;
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
		cout << "输入边(vi, vj)上的下标为i，下标为j和权w:\n";
		cin >> i >> j >> w;
		arc[i][j] = w;
		arc[j][i] = arc[i][j];
	}
}
