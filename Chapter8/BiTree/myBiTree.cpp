#include"myBiTree.h"

int main()
{
	myBiTree mytree;
	int a[10] = { 62,88,58,47,35,73,51,99,37,93 };
	int len = sizeof(a) / sizeof(a[0]);

	cout << "----����----" << endl;
	for (int i = 0; i < len; i++)
	{
		mytree.InSertBST(a[i]);
	}

	cout << "----�������----" << endl;	
	mytree.InOder();
	cout << endl;

	cout << "----ɾ������----" << endl;
	mytree.Delete_BST(58);

	cout << "----�������----" << endl;
	mytree.InOder();
	cout << endl;

	system("pause");
	return 0;
}