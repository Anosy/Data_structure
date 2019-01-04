// #include"LinkQueue.h"
#include"myLinkQueue.h"

int main()
{
	int value;
	cout << "创建一个空链队列" << endl;
	myLinkQueue<int> linkqueue;

	cout << "打印链表" << endl;
	linkqueue.Print();

	cout << "入队" << endl;	
	cin >> value;
	linkqueue.EnQueue(value);

	cout << "入队" << endl;
	cin >> value;
	linkqueue.EnQueue(value);

	cout << "打印链表" << endl;
	linkqueue.Print();

	cout << "链表长度为：";
	cout << linkqueue.Length() << endl;

	cout << "出队" << endl;
	cout << "出队的元素为：" << linkqueue.DeQueue() << endl;

	cout << "打印链表" << endl;
	linkqueue.Print();

	system("pause");
	return 0;
}