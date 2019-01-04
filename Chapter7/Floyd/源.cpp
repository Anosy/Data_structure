#include"Floyd.h"

int main()
{
	Floyd_MGraph graph;
	int Patharc[MAXVEX][MAXVEX];
	int ShortPathTable[MAXVEX][MAXVEX];
	graph.ShortPath_Floyd(Patharc, ShortPathTable);

	cout << "各顶点间最短路径如下:\n";
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			cout << "v" << i << "-v" << j << " 距离: " << ShortPathTable[i][j];
			int k = Patharc[i][j];
			cout << " 路径:\t" << i;
			while (k != j)
			{
				cout << " -> " << k;
				k = Patharc[k][j];
			}
			cout << " -> " << j << endl;
		}
		cout << endl;
	}

	cout << "最短路径D表" << endl;
	for (auto p = begin(ShortPathTable); p != end(ShortPathTable); p++)
	{
		for (auto q = begin(*p); q != end(*p); q++)
		{
			cout << *q << "\t";
		}
		cout << endl;
	}
	cout << endl;

	cout << "最短路径P表" << endl;
	for (auto p = begin(Patharc); p != end(Patharc); p++)
	{
		for (auto q = begin(*p); q != end(*p); q++)
		{
			cout << *q << "\t";
		}
		cout << endl;
	}
	cout << endl;


	system("pause");
	return 0;
}