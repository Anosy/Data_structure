#include"myGraphAdjList.h"

int main()
{
	myAdjListGraph graph;

	cout << "������ȱ����㷨" << endl;
	graph.DFS(0);
	cout << endl;
	cout << endl;

	cout << "��ȱ�������" << endl;
	graph.DFSTraverse();
	cout << endl;
	cout << endl;

	cout << "������ȱ����ǵݹ�" << endl;
	graph.DFS_Iteration(0);
	cout << endl;
	cout << endl;

	/*cout << "������ȱ����㷨" << endl;
	graph.BFS(0);
	cout << endl;*/

	cout << "������ȱ���" << endl;
	graph.BFSTraverse();
	cout << endl;



	system("pause");
	return 0;
}