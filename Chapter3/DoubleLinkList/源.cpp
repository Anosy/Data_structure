// #include"DoubleLinkList.h"
#include"myDoubleLinkList.h"

using namespace std;

int main()
{
	int index, value;
	myDoubleLinkList<int> doublelink;
	cout << "��ӡ����Ĵ�С" << endl;
	cout << doublelink.Size() << endl;

	cout << "������СΪ5��˫������" << endl;
	doublelink.CreatList(5);
	
	cout << "��ӡ˫������" << endl;
	doublelink.Print();

	cout << "��ӡ����Ĵ�С" << endl;
	cout << doublelink.Size() << endl;

	cout << "��ȡĳ��λ�õ�Ԫ��" << endl;
	cin >> index;
	cout << "��ǰλ�õ�ֵΪ��" << doublelink.GetItem(index) << endl;


	cout << "��������λ�ú���ֵ" << endl;
	cin >> index >> value;
	doublelink.Insert(index, value);

	cout << "��ӡ˫������" << endl;
	doublelink.Print();

	cout << "����ɾ����λ��" << endl;
	cin >> index;
	cout << "ɾ����Ԫ���ǣ�" << doublelink.Delete(index) << endl;

	cout << "��ӡ˫������" << endl;
	doublelink.Print();

	system("pause");
	return 0;
}