//#include"CircularLinkList.h"
#include"myCircularLinkList.h"

using namespace std;

int main()
{
	int index = 0, value;
	myCircularLinkList<int> cirlinklist;

	cout << "创建5个元素的链表" << endl;
	cirlinklist.CreateLinkList(5);
	
	cout << "打印链表长度" << endl;
	cout << cirlinklist.GetLength() << endl;
	
	cout << "打印链表内容" << endl;
	cirlinklist.PrintList();
	cout << endl;

	cout << "插入元素的位置和内容" << endl;
	cin >> index >> value;
	cirlinklist.InsertNode(index, value);

	cout << "打印链表内容" << endl;
	cirlinklist.PrintList();

	cout << "删除元素的位置" << endl;
	cin >> index;
	cout << "被删除的元素是:" << cirlinklist.DeleteNode(index) << endl;

	cout << "打印链表内容" << endl;
	cirlinklist.PrintList();

	cout << "获取某个位置元素" << endl;
	cin >> index;
	cout << "当前位置的值为：" << cirlinklist.GetElem(index) << endl;

	system("pause");
	return 0;
}