//#include"AVL_Tree.h"
#include"myAVL_Tree.h"

int main()
{
	myAVLTree<int> mytree;
	int a[] = { 3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9 };
	int len = sizeof(a) / sizeof(a[0]);

	cout << "----�������----" << endl;
	for (int i = 0; i < len; i++)
	{
		mytree.insert(a[i]);
	}
	cout << endl;

	cout << "----�������----" << endl;
	mytree.inOrder();
	cout << endl;

	cout << "----�߶�----" << endl;
	cout << mytree.height() << endl;

	cout << "----���ֵ----" << endl;
	cout << mytree.maximum() << endl;

	cout << "----��Сֵ----" << endl;
	cout << mytree.minimum() << endl;

	cout << "----���Ҳ���----" << endl;
	cout << mytree.search(5)->key << endl;

	cout << "----��ӡ��----" << endl;
	mytree.print();
	cout << endl;

	cout << "----ɾ������----" << endl;
	mytree.remove(2);

	cout << "----��ӡ��----" << endl;
	mytree.print();
	cout << endl;

	system("pause");
	return 0;
}


