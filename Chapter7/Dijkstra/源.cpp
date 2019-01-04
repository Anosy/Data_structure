//#include"Dijkstra.h"
#include"myDijkstra.h"

int main()
{
	my_Dijkstra_MGraph DjGraph;
	int Patharc[MAXVEX]; // 存储最短路径下标的数组
	int ShortPathTable[MAXVEX];// 存储最短路径数
	int v0 = 0;

	DjGraph.ShortestPath_Dijkstra(v0, Patharc, ShortPathTable);
	
	int i = 1;
	int j;
	cout << "最短路径倒序如下:\n";
	for (unsigned i = 2; i < size(Patharc); ++i)
	{	
		cout << "v"<< v0 << "-v" << i << "；";
		j = i;
		while (Patharc[j] != 0)
		{
			cout << Patharc[j] << " ";
			j = Patharc[j];
		}
		cout << endl;
	}
	cout << endl;

	cout << "源点到各顶点的最短路径长度为:\n" << endl;
	for (unsigned i = 1; i < size(ShortPathTable); i++)
	{
		cout << "v" << v0 << "-v" << i << " " << ShortPathTable[i] << endl;
	}

	system("pause");
	return 0;
}

