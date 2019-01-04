//#include"SeqList.h"
#include"mySeqlist.h"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int index, value;
	cout << "用10个元素的数组来初始化顺序存储结构" << endl;
	mySeqList<int> seqlist(a, 10);

	cout << "打印当前的顺序存储结构" << endl;
	seqlist.ListPrint();
	cout << endl;

	cout << "插入元素的位置和内容" << endl;
	cin >> index >> value;
	seqlist.ListInsert(index, value);

	cout << "打印当前的顺序存储结构" << endl;
	seqlist.ListPrint();
	cout << endl;

	cout << "删除元素的位置" << endl;
	cin >> index;
	cout << "删除元素为：" << seqlist.ListDelete(index) << endl;

	cout << "打印当前的顺序存储结构" << endl;
	seqlist.ListPrint();
	cout << endl;

	cout << "获取某位置上的元素" << endl;
	cin >> index;
	cout << "获取的元素为" << seqlist.GetElem(index) << endl;


	system("pause");
	return 0;
}