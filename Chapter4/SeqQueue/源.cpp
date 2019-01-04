//#include"SepQueue.h"
#include"mySepQueue.h" 

using namespace std;

int main()
{
	mySepQueue<int> seqqueue;
	
	cout << "队列是否为空: ";
	cout << seqqueue.isEmpty() << endl;

	cout << "入队列" << endl;
	seqqueue.EnQueue(1);

	cout << "入队列" << endl;
	seqqueue.EnQueue(2);

	cout << "队列的长度: ";
	cout << seqqueue.QueueLength() << endl;

	cout << "获取队列的队头元素" << endl;
	cout << seqqueue.GetHead() << endl;

	cout << "出队列" << endl;
	cout << "出队列的元素为：" << seqqueue.DeQueue() << endl;

	cout << "出队列" << endl;
	cout << "出队列的元素为：" << seqqueue.DeQueue() << endl;

	cout << "队列是否为空: ";
	cout << seqqueue.isEmpty() << endl;

	system("pause");
	return 0;
}