//#include"DoubleSeqStack.h"
#include"myDoubleSeqStack.h"
using namespace std;

int main()
{
	int value;
	int a[4] = { 1, 2, 3, 4 };
	int b[4] = { 4, 3, 2, 1 };
	
	cout << "创建两栈共享空间" << endl;
	myDoubleSeqStack<int> doublestack(a, 4, b, 4);
	
	cout << "打印两栈的元素" << endl;
	doublestack.Print(1);
	doublestack.Print(2);

	cout << "入栈操作" << endl;
	doublestack.Push(1, 11);
	doublestack.Push(2, 22);
	
	cout << "打印两栈的元素" << endl;
	doublestack.Print(1);
	doublestack.Print(2);

	cout << "出栈操作" << endl;
	cout << "出栈的元素为：" << doublestack.Pop(1) << endl;
	cout << "出栈的元素为：" << doublestack.Pop(2) << endl;

	cout << "打印两栈的元素" << endl;
	doublestack.Print(1);
	doublestack.Print(2);

	system("pause");
	return 0;
}