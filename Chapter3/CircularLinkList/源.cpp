//#include"CircularLinkList.h"
#include"myCircularLinkList.h"

using namespace std;

int main()
{
	int index = 0, value;
	myCircularLinkList<int> cirlinklist;

	cout << "����5��Ԫ�ص�����" << endl;
	cirlinklist.CreateLinkList(5);
	
	cout << "��ӡ������" << endl;
	cout << cirlinklist.GetLength() << endl;
	
	cout << "��ӡ��������" << endl;
	cirlinklist.PrintList();
	cout << endl;

	cout << "����Ԫ�ص�λ�ú�����" << endl;
	cin >> index >> value;
	cirlinklist.InsertNode(index, value);

	cout << "��ӡ��������" << endl;
	cirlinklist.PrintList();

	cout << "ɾ��Ԫ�ص�λ��" << endl;
	cin >> index;
	cout << "��ɾ����Ԫ����:" << cirlinklist.DeleteNode(index) << endl;

	cout << "��ӡ��������" << endl;
	cirlinklist.PrintList();

	cout << "��ȡĳ��λ��Ԫ��" << endl;
	cin >> index;
	cout << "��ǰλ�õ�ֵΪ��" << cirlinklist.GetElem(index) << endl;

	system("pause");
	return 0;
}