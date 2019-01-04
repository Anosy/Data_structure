#include<iostream>
#include<queue>
#include<stack>

using namespace std;

const int MAXSIZE = 10;
const int INF = 65535;

template <typename T>
class Prim_MGraph
{
public:
	Prim_MGraph(int n = 9, int e = 15); // n个顶点，e条边
	~Prim_MGraph() {}
	void MiniSpanTree_Prim();

private:
	int arc[MAXSIZE][MAXSIZE]; // 存放边的数组
	int vertexNum, arcNum; // 图中顶点和边的数目
};


template<typename T>
inline Prim_MGraph<T>::Prim_MGraph(int n, int e)
{
	vertexNum = n;
	arcNum = e;

	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			if (i == j)
				arc[i][j] = 0;
			else
				arc[i][j] = arc[j][i] = INF;
		}
	}

	arc[0][1] = 10;
	arc[0][5] = 11;
	arc[1][2] = 18;
	arc[1][8] = 12;
	arc[1][6] = 16;
	arc[2][8] = 8;
	arc[2][3] = 22;
	arc[3][8] = 21;
	arc[3][6] = 24;
	arc[3][7] = 16;
	arc[3][4] = 20;
	arc[4][7] = 7;
	arc[4][5] = 26;
	arc[5][6] = 17;
	arc[6][7] = 19;


	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = i; j < vertexNum; j++)
		{
			arc[j][i] = arc[i][j];
		}
	}


	/*cout << "输入下标i，下标j，边权值w：\n";
	for (int k = 0; k < arcNum; k++)
	{
		int i, j, w;
		cin >> i >> j >> w;
		arc[i][j] = w;
		arc[j][i] = w;
	}*/

}


/*
prim算法原理
核心就是管理lowcost数组和adjvex数组
lowcost数组：保存与树上所有结点相连的边权值最小的结点的下标。特殊值0，表示该结点已经在树上了，就不用考虑了
adjvex数组，保存于树上结点连接的所有结点的下标。比如[0, 0, 1, 0]，表示v0和v1已经在树上了，而v2于v1相连，v3与v0相连
大循环，循环所有的结点：
	找到与树上的结点连接的边权值最小的结点，并且打印，然后将其的lowcost值赋0，表示该结点已经在树上了
	再将与该结点所有连接的边的权值给添加到lowcost中，并且将与其相连的结点给添加到adjvex中

*/
template<typename T>
inline void Prim_MGraph<T>::MiniSpanTree_Prim()
{
	int min, j, k;
	int adjvex[MAXSIZE]; // 保存相关顶点下标
	int lowcost[MAXSIZE]; // 保存相关顶点间边的权值
	lowcost[0] = 0; // 初始化第一个权值，lowcost的值为0，表示vo已经加入到最小生成树
	adjvex[0] = 0; // 初始化第一个顶点下标

	for (int i = 1; i < vertexNum; i++)
	{
		lowcost[i] = arc[0][i]; // 将顶点与之有边的权值都给存放到数组中
		adjvex[i] = 0; // 初始v0的下标
	}
	//以上的过程为初始化过程，已经将假设从v0开始，并且将lowcast和adrjvex都已经初始化好了

	// 以下的循环就是构造最小生成树的过程
	for (int i = 1; i < vertexNum; i++) // 循环vertexNum顶点个数-1次，因为v0已经加入生成树
	{
		min = INF;
		j = 1;
		k = 0;
		while (j < vertexNum)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j]; // min保存最后lowcast中最小的权值
				k = j; // 保存最小权值的下标
			}
			j++;
		}
		cout << "当前顶点权值最小的边：" << "v" << adjvex[k] << "-v" << k << endl; // 打印当前顶点中权值最小的边
		lowcost[k] = 0; // 将当前顶点的权值给设为0，表示该顶点已经加入到最小生成树
		
		for (int j = 1; j < vertexNum; j++)
		{
			// 循环和k相连的所有结点，将k结点附近连接结点的权值给加入到lowcost中，
			// adjvex表示与生成树上结点相连接的结点的下标，如[0, 0, 1, 1...]  表示1与0相连，2与1相连， 3与1相连，且0，1都是生成树上的结点
			if (lowcost[j] != 0 && arc[k][j] < lowcost[j])
			{
				lowcost[j] = arc[k][j];
				adjvex[j] = k;
			}
		}
	
	}
}


