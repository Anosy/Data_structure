// #include"LinkQueue.h"
#include"myLinkQueue.h"

int main()
{
	int value;
	cout << "����һ����������" << endl;
	myLinkQueue<int> linkqueue;

	cout << "��ӡ����" << endl;
	linkqueue.Print();

	cout << "���" << endl;	
	cin >> value;
	linkqueue.EnQueue(value);

	cout << "���" << endl;
	cin >> value;
	linkqueue.EnQueue(value);

	cout << "��ӡ����" << endl;
	linkqueue.Print();

	cout << "������Ϊ��";
	cout << linkqueue.Length() << endl;

	cout << "����" << endl;
	cout << "���ӵ�Ԫ��Ϊ��" << linkqueue.DeQueue() << endl;

	cout << "��ӡ����" << endl;
	linkqueue.Print();

	system("pause");
	return 0;
}