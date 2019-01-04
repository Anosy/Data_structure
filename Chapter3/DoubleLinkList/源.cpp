// #include"DoubleLinkList.h"
#include"myDoubleLinkList.h"

using namespace std;

int main()
{
	int index, value;
	myDoubleLinkList<int> doublelink;
	cout << "打印链表的大小" << endl;
	cout << doublelink.Size() << endl;

	cout << "创建大小为5的双向链表" << endl;
	doublelink.CreatList(5);
	
	cout << "打印双向链表" << endl;
	doublelink.Print();

	cout << "打印链表的大小" << endl;
	cout << doublelink.Size() << endl;

	cout << "获取某个位置的元素" << endl;
	cin >> index;
	cout << "当前位置的值为：" << doublelink.GetItem(index) << endl;


	cout << "链表插入的位置和数值" << endl;
	cin >> index >> value;
	doublelink.Insert(index, value);

	cout << "打印双向链表" << endl;
	doublelink.Print();

	cout << "链表删除的位置" << endl;
	cin >> index;
	cout << "删除的元素是：" << doublelink.Delete(index) << endl;

	cout << "打印双向链表" << endl;
	doublelink.Print();

	system("pause");
	return 0;
}