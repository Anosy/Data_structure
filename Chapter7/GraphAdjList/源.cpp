#include"myGraphAdjList.h"

int main()
{
	myAdjListGraph graph;

	cout << "深度优先遍历算法" << endl;
	graph.DFS(0);
	cout << endl;
	cout << endl;

	cout << "深度遍历操作" << endl;
	graph.DFSTraverse();
	cout << endl;
	cout << endl;

	cout << "深度优先遍历非递归" << endl;
	graph.DFS_Iteration(0);
	cout << endl;
	cout << endl;

	/*cout << "广度优先遍历算法" << endl;
	graph.BFS(0);
	cout << endl;*/

	cout << "广度优先遍历" << endl;
	graph.BFSTraverse();
	cout << endl;



	system("pause");
	return 0;
}