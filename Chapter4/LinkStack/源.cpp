//#include"LinkStack.h"
#include"myLinkStack.h"
using namespace std;

int main()
{
	int value;
	cout << "����һ���յ���ջ" << endl;
	myLinkStack<int> linkstack;

	cout << "ջ�Ƿ�Ϊ�գ�" << linkstack.Empty() << endl;

	cout << "��ջ����" << endl;
	cin >> value;
	linkstack.push(value);

	cout << "��ջ����" << endl;
	cin >> value;
	linkstack.push(value);

	cout << "��ӡջ������" << endl;
	linkstack.Print();

	cout << "��ջ����" << endl;
	cout << "��ջ��Ԫ��Ϊ��" << linkstack.pop() << endl;

	cout << "��ӡջ������" << endl;
	linkstack.Print();

	cout << "��ջ����" << endl;
	cout << "��ջ��Ԫ��Ϊ��" << linkstack.pop() << endl;

	cout << "��ӡջ������" << endl;
	linkstack.Print();

	cout << "��ջ����" << endl;
	cout << "��ջ��Ԫ��Ϊ��" << linkstack.pop() << endl;

	system("pause");
	return 0;
}