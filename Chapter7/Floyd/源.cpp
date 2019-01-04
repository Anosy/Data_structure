#include"Floyd.h"

int main()
{
	Floyd_MGraph graph;
	int Patharc[MAXVEX][MAXVEX];
	int ShortPathTable[MAXVEX][MAXVEX];
	graph.ShortPath_Floyd(Patharc, ShortPathTable);

	cout << "����������·������:\n";
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			cout << "v" << i << "-v" << j << " ����: " << ShortPathTable[i][j];
			int k = Patharc[i][j];
			cout << " ·��:\t" << i;
			while (k != j)
			{
				cout << " -> " << k;
				k = Patharc[k][j];
			}
			cout << " -> " << j << endl;
		}
		cout << endl;
	}

	cout << "���·��D��" << endl;
	for (auto p = begin(ShortPathTable); p != end(ShortPathTable); p++)
	{
		for (auto q = begin(*p); q != end(*p); q++)
		{
			cout << *q << "\t";
		}
		cout << endl;
	}
	cout << endl;

	cout << "���·��P��" << endl;
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