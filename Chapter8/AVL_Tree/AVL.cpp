//#include"AVL_Tree.h"
#include"myAVL_Tree.h"

int main()
{
	myAVLTree<int> mytree;
	int a[] = { 3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9 };
	int len = sizeof(a) / sizeof(a[0]);

	cout << "----插入操作----" << endl;
	for (int i = 0; i < len; i++)
	{
		mytree.insert(a[i]);
	}
	cout << endl;

	cout << "----中序遍历----" << endl;
	mytree.inOrder();
	cout << endl;

	cout << "----高度----" << endl;
	cout << mytree.height() << endl;

	cout << "----最大值----" << endl;
	cout << mytree.maximum() << endl;

	cout << "----最小值----" << endl;
	cout << mytree.minimum() << endl;

	cout << "----查找操作----" << endl;
	cout << mytree.search(5)->key << endl;

	cout << "----打印树----" << endl;
	mytree.print();
	cout << endl;

	cout << "----删除操作----" << endl;
	mytree.remove(2);

	cout << "----打印树----" << endl;
	mytree.print();
	cout << endl;

	system("pause");
	return 0;
}


