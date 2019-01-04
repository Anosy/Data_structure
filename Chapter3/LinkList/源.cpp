#include"myLinkList.h"
#include<string>
using namespace std;

int main()
{
	int index;
	string value;
	cout << "创建长度为5的单项链表" << endl;
	myLinkList<string> linklist(5);

	cout << "链表的长度为：";
	cout << linklist.ListLength() << endl;

	cout << "获取元素：";
	cin >> index;
	cout << linklist.GetElem(index) << endl;

	cout << "输出链表中的所有元素" << endl;
	linklist.Print();

	cout << "插入元素的位置和内容" << endl;
	cin >> index >> value;
	linklist.Insert(index, value);

	cout << "输出链表中的所有元素" << endl;
	linklist.Print();

	cout << "删除元素的位置" << endl;
	cin >> index;
	cout << "删除的元素的值为：" << linklist.Delete(index) << endl;

	cout << "输出链表中的所有元素" << endl;
	linklist.Print();

	system("pause");
	return 0;
}