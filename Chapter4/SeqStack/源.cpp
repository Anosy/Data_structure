//#include"SeqStack.h"
#include"mySeqStack.h"

using namespace std;

int main()
{
	int value;
	mySeqStack<int> seqstack;
	cout << "ջ�Ƿ�Ϊ�գ�" << seqstack.Empty() << endl;

	cout << "��ջ" << endl;
	cin >> value;
	seqstack.Push(value);

	cout << "��ӡջ" << endl;
	seqstack.Print();

	cout << "��ջ" << endl;
	cout << "��ջ��Ԫ��Ϊ��" << seqstack.Pop() << endl;

	cout << "��ӡջ" << endl;
	seqstack.Print();

	system("pause");
	return 0;
}