//#include"Hash_Table.h"
#include"myHash_Table.h"

int main()
{
	int arr[HASHSIZE] = { 12,67,56,16,25,37,22,29,15,47,48,34 };
	myHashTable H;
	int key = 39;
	int p;

	for (int i = 0; i < m; i++)
	{
		H.InsertHash(arr[i]);
	}
	bool result = H.SearchHash(key, &p);
	if (result)
	{
		cout << "���� " << key << " �ĵ�ַΪ��" << p << endl;
	}
	else
	{
		cout << "���� " << key << " ʧ��" << endl;
	}

	for (int i = 0; i < m; i++)
	{
		key = arr[i];
		H.SearchHash(key, &p);
		cout << "���� " << key << " �ĵ�ַΪ��" << p << endl;
	}

	system("pause");
	return 0;
}