//#include"DoubleSeqStack.h"
#include"myDoubleSeqStack.h"
using namespace std;

int main()
{
	int value;
	int a[4] = { 1, 2, 3, 4 };
	int b[4] = { 4, 3, 2, 1 };
	
	cout << "������ջ����ռ�" << endl;
	myDoubleSeqStack<int> doublestack(a, 4, b, 4);
	
	cout << "��ӡ��ջ��Ԫ��" << endl;
	doublestack.Print(1);
	doublestack.Print(2);

	cout << "��ջ����" << endl;
	doublestack.Push(1, 11);
	doublestack.Push(2, 22);
	
	cout << "��ӡ��ջ��Ԫ��" << endl;
	doublestack.Print(1);
	doublestack.Print(2);

	cout << "��ջ����" << endl;
	cout << "��ջ��Ԫ��Ϊ��" << doublestack.Pop(1) << endl;
	cout << "��ջ��Ԫ��Ϊ��" << doublestack.Pop(2) << endl;

	cout << "��ӡ��ջ��Ԫ��" << endl;
	doublestack.Print(1);
	doublestack.Print(2);

	system("pause");
	return 0;
}