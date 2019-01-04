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

	// 固定初始化
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

// 修改了拓扑排序，因为关键路径就是在拓扑排序的基础上，要加上对边的权值，从而考虑源点到汇点的最长时间，从而得到关键路径
/*
1.将入度为0的顶点给入栈
2.将etv事件最早开始时间给初始化为0
3.如果栈非空，那么就循环
	将S1栈顶给弹栈，然后将弹出的元素给入栈到S2中，也就是S2中保存的就是所有的拓扑序列
	接着找到以栈顶顶点为尾的顶点，然后将其的入度减1，并且判断是否这时候入度为0，如果为0，入栈。
	并且更新事件的最早发生时间。选取所有的栈顶顶点到达的顶点k的最早时间的最大值。为什么是最大值，因为要等前面所有的顶点到达了当前的顶点才能算任务完成了
4.通过循环etv表，以及栈S2
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

	etv = new int[10]; // 创建动态数组

	for (int j = 0; j < numVertexes; j++)
	{
		etv[j] = 0; // 初始为0
	}

	while (!S1.empty())
	{
		int gettop = S1.top();
		S1.pop();
		count++;
		S2.push(gettop); // 将S1弹出的顶点序号给压入到拓扑序列的栈中

		for (EdgeNode *e  = adjlist[gettop].firstedge; e; e = e->next)
		{
			int k = e->adjvex;
			if ((--adjlist[k].in) == 0)
			{
				S1.push(k);
			}
			if ((etv[gettop] + e->weight) > etv[k]) // 最早开始时间为max{etv[i] + len(vi,vk)}。也就是所有能到达顶点k的顶点+与k的距离，取最大值
			{									    // 因为可能到达k之前，所有的工作应该都做完，所以取最大
				etv[k] = etv[gettop] + e->weight;
			}
		}
	}
	if (count < numVertexes)
	{
		cout << "图中存在环，不是拓扑图" << endl;

	}
	else
	{
		cout << "图是拓扑图" << endl;
	}
}

// 关键路径的构建
/*
1.通过TopologicalSort得到etv和S2
2.将ltv事件最晚发生时间给初始化为汇点的最早发生时间。因为汇点的最早发生时间和最迟发生时间是相同的，所以相当于用汇点的最晚发生时间初始化全部的最晚发生时间
3.S2开始出栈，这时候是从汇点开始
	首先从汇点开始倒退到源点。
	汇点是最后一个顶点，所以其没有邻接边表
	然后后面的顶点的最晚时间都是其边表指向的顶点的最晚时间-边发生的事件(活动发生的时间)，且结果取最小值。
	为什么取最小值？因为如果不取最小值，可能将会导致改顶点的下一个连接的顶点，其事件最晚的发生时间要推迟
4.上述循环得到了ltv，事件最晚发生时间
5. 寻找图的关键路径
	遍历顶点表中的所有的顶点，计算该顶点到其相连的顶点的活动最早发生时间和活动最晚发生时间
	活动最早发生时间为当前顶点最早的发生时间。因为活动只有在这个顶点发生了之后才能发生。
	活动最晚发生时间为当前顶点连接的下一个顶点的最晚发生时间-边的时间，该事件只有在下一个顶点最晚发生之前才能发生
	如果这时候活动的最早发生时间等于活动的最晚发生时间，那么说明该活动没有空闲的时间，全部被占满了，所以该活动为关键活动
	如果活动的最早开始时间和最晚开始时间不相同，说明活动开始的时间不确定，所以不是能够主导工程的，不是关键活动
*/
inline void CP_AdjListGraph::CriticalPath()
{
	int ete, lte; // 活动最早发生时间数组，活动最迟发生时间数组
	TopologicalSort();
	ltv = new int[10];

	for (int i = 0; i < numVertexes; i++)
	{
		ltv[i] = etv[numVertexes - 1]; // 将事件最迟发生的时间给初始化
	}

	while (!S2.empty())
	{
		int gettop = S2.top();
		S2.pop();
		for (EdgeNode * e = adjlist[gettop].firstedge; e; e = e->next)
		{
			int k = e->adjvex;
			if (ltv[k] - e->weight < ltv[gettop]) // 事件最晚发生时间为：min{ltv[i] - len(vk, vj)} ,为什么是最小，因为要保证所有的与k相连顶点的最小时间
			{
				ltv[gettop] = ltv[k] - e->weight;
			}
		}
	}

	cout << "etv 事件最早发生时间" << endl;
	for (int i = 0; i < numVertexes; i++)
	{
		cout << etv[i] << " ";
	}
	cout << endl;

	cout << "ltv 事件最迟发生时间" << endl;
	for (int j = 0; j < numVertexes; j++)
	{
		cout << ltv[j] << " ";
	}
	cout << endl;

	cout << "图的关键路径" << endl;
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


 