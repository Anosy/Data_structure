//#include"MGraph.h"
#include"myMGraph.h"

int main()
{
	myMGraph mgraph;

	cout << "������ȱ����㷨" << endl;
	mgraph.DFS(0);
	cout << endl;
	cout << endl;


	cout << "��ȱ�������" << endl;
	mgraph.DFSTraverse();
	cout << endl;
	cout << endl;

	cout << "������ȱ����ǵݹ�" << endl;
	mgraph.DFS_Iteration(0);
	cout << endl;
	cout << endl;

	/*cout << "������ȱ����㷨" << endl;
	mgraph.BFS(0);
	cout << endl;*/

	cout << "������ȱ���" << endl;
	mgraph.BFStraverse();
	cout << endl;

	

	system("pause");
	return 0;
}