#include<iostream>

using namespace std;

const int HASHSIZE = 12; // �����ϣ��Ϊ���鳤��
const int NULLKEY = -32768;
int m = 0;

class myHashTable
{
public:
	myHashTable();
	void InsertHash(int key);
	bool SearchHash(int key, int *addr);
private:
	int *elem; // ����Ԫ�صĴ洢�ĵ�ַ����̬����
	int count; // ��ǰ����Ԫ�صĸ���
	int Hash(int key); // ��ϣ����
};

inline myHashTable::myHashTable()
{
	m = HASHSIZE;
	count = m;
	elem = new int[m];
	for (int i = 0; i < m; i++)
	{
		elem[i] = NULLKEY;
	}
}

inline void myHashTable::InsertHash(int key)
{
	int addr = Hash(key);
	while (elem[addr] != NULLKEY)
	{
		addr = (addr + 1) % m; //  ���ŵ�ַ��������̽��
	}
	elem[addr] = key;
}

inline bool myHashTable::SearchHash(int key, int * addr)
{
	*addr = Hash(key);
	while (elem[*addr] != key)
	{
		*addr = (*addr + 1) % m;
		if (elem[*addr] == NULLKEY || *addr == Hash(key))
		{
			return 0;
		}
	}
	return 1;
}

inline int myHashTable::Hash(int key)
{
	return key % m; // ����������
}
