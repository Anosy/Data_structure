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
	cout << "��10��Ԫ�ص���������ʼ��˳��洢�ṹ" << endl;
	mySeqList<int> seqlist(a, 10);

	cout << "��ӡ��ǰ��˳��洢�ṹ" << endl;
	seqlist.ListPrint();
	cout << endl;

	cout << "����Ԫ�ص�λ�ú�����" << endl;
	cin >> index >> value;
	seqlist.ListInsert(index, value);

	cout << "��ӡ��ǰ��˳��洢�ṹ" << endl;
	seqlist.ListPrint();
	cout << endl;

	cout << "ɾ��Ԫ�ص�λ��" << endl;
	cin >> index;
	cout << "ɾ��Ԫ��Ϊ��" << seqlist.ListDelete(index) << endl;

	cout << "��ӡ��ǰ��˳��洢�ṹ" << endl;
	seqlist.ListPrint();
	cout << endl;

	cout << "��ȡĳλ���ϵ�Ԫ��" << endl;
	cin >> index;
	cout << "��ȡ��Ԫ��Ϊ" << seqlist.GetElem(index) << endl;


	system("pause");
	return 0;
}