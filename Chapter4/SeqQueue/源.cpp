//#include"SepQueue.h"
#include"mySepQueue.h" 

using namespace std;

int main()
{
	mySepQueue<int> seqqueue;
	
	cout << "�����Ƿ�Ϊ��: ";
	cout << seqqueue.isEmpty() << endl;

	cout << "�����" << endl;
	seqqueue.EnQueue(1);

	cout << "�����" << endl;
	seqqueue.EnQueue(2);

	cout << "���еĳ���: ";
	cout << seqqueue.QueueLength() << endl;

	cout << "��ȡ���еĶ�ͷԪ��" << endl;
	cout << seqqueue.GetHead() << endl;

	cout << "������" << endl;
	cout << "�����е�Ԫ��Ϊ��" << seqqueue.DeQueue() << endl;

	cout << "������" << endl;
	cout << "�����е�Ԫ��Ϊ��" << seqqueue.DeQueue() << endl;

	cout << "�����Ƿ�Ϊ��: ";
	cout << seqqueue.isEmpty() << endl;

	system("pause");
	return 0;
}