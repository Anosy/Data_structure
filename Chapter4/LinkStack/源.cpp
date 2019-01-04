//#include"LinkStack.h"
#include"myLinkStack.h"
using namespace std;

int main()
{
	int value;
	cout << "创建一个空的链栈" << endl;
	myLinkStack<int> linkstack;

	cout << "栈是否为空：" << linkstack.Empty() << endl;

	cout << "入栈操作" << endl;
	cin >> value;
	linkstack.push(value);

	cout << "入栈操作" << endl;
	cin >> value;
	linkstack.push(value);

	cout << "打印栈的内容" << endl;
	linkstack.Print();

	cout << "出栈操作" << endl;
	cout << "出栈的元素为：" << linkstack.pop() << endl;

	cout << "打印栈的内容" << endl;
	linkstack.Print();

	cout << "出栈操作" << endl;
	cout << "出栈的元素为：" << linkstack.pop() << endl;

	cout << "打印栈的内容" << endl;
	linkstack.Print();

	cout << "出栈操作" << endl;
	cout << "出栈的元素为：" << linkstack.pop() << endl;

	system("pause");
	return 0;
}