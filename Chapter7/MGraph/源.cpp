//#include"MGraph.h"
#include"myMGraph.h"

int main()
{
	myMGraph mgraph;

	cout << "深度优先遍历算法" << endl;
	mgraph.DFS(0);
	cout << endl;
	cout << endl;


	cout << "深度遍历操作" << endl;
	mgraph.DFSTraverse();
	cout << endl;
	cout << endl;

	cout << "深度优先遍历非递归" << endl;
	mgraph.DFS_Iteration(0);
	cout << endl;
	cout << endl;

	/*cout << "广度优先遍历算法" << endl;
	mgraph.BFS(0);
	cout << endl;*/

	cout << "广度优先遍历" << endl;
	mgraph.BFStraverse();
	cout << endl;

	

	system("pause");
	return 0;
}