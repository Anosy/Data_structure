#include"myLinkList.h"
#include<string>
using namespace std;

int main()
{
	int index;
	string value;
	cout << "��������Ϊ5�ĵ�������" << endl;
	myLinkList<string> linklist(5);

	cout << "����ĳ���Ϊ��";
	cout << linklist.ListLength() << endl;

	cout << "��ȡԪ�أ�";
	cin >> index;
	cout << linklist.GetElem(index) << endl;

	cout << "��������е�����Ԫ��" << endl;
	linklist.Print();

	cout << "����Ԫ�ص�λ�ú�����" << endl;
	cin >> index >> value;
	linklist.Insert(index, value);

	cout << "��������е�����Ԫ��" << endl;
	linklist.Print();

	cout << "ɾ��Ԫ�ص�λ��" << endl;
	cin >> index;
	cout << "ɾ����Ԫ�ص�ֵΪ��" << linklist.Delete(index) << endl;

	cout << "��������е�����Ԫ��" << endl;
	linklist.Print();

	system("pause");
	return 0;
}