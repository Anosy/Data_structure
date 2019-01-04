//#include"SeqStack.h"
#include"mySeqStack.h"

using namespace std;

int main()
{
	int value;
	mySeqStack<int> seqstack;
	cout << "栈是否为空：" << seqstack.Empty() << endl;

	cout << "入栈" << endl;
	cin >> value;
	seqstack.Push(value);

	cout << "打印栈" << endl;
	seqstack.Print();

	cout << "出栈" << endl;
	cout << "出栈的元素为：" << seqstack.Pop() << endl;

	cout << "打印栈" << endl;
	seqstack.Print();

	system("pause");
	return 0;
}