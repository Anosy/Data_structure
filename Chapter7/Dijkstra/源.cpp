//#include"Dijkstra.h"
#include"myDijkstra.h"

int main()
{
	my_Dijkstra_MGraph DjGraph;
	int Patharc[MAXVEX]; // �洢���·���±������
	int ShortPathTable[MAXVEX];// �洢���·����
	int v0 = 0;

	DjGraph.ShortestPath_Dijkstra(v0, Patharc, ShortPathTable);
	
	int i = 1;
	int j;
	cout << "���·����������:\n";
	for (unsigned i = 2; i < size(Patharc); ++i)
	{	
		cout << "v"<< v0 << "-v" << i << "��";
		j = i;
		while (Patharc[j] != 0)
		{
			cout << Patharc[j] << " ";
			j = Patharc[j];
		}
		cout << endl;
	}
	cout << endl;

	cout << "Դ�㵽����������·������Ϊ:\n" << endl;
	for (unsigned i = 1; i < size(ShortPathTable); i++)
	{
		cout << "v" << v0 << "-v" << i << " " << ShortPathTable[i] << endl;
	}

	system("pause");
	return 0;
}

