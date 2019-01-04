#include<iostream>

using namespace std;

const int HASHSIZE = 12; // �����ϣ��Ϊ���鳤��
const int NULLKEY = -32768;
int m = 0;

class HashTable
{
public:
	HashTable();
	void InsertHash(int key);
	bool SearchHash(int key, int *addr);
private:
	int *elem; // ����Ԫ�صĴ洢�ĵ�ַ����̬����
	int count; // ��ǰ����Ԫ�صĸ���
	int Hash(int key); // ��ϣ����
};

inline HashTable::HashTable()
{
	m = HASHSIZE;
	count = m;
	elem = new int[m];
	for (int i = 0; i < m; i++)
	{
		elem[i] = NULLKEY;
	}
}

inline void HashTable::InsertHash(int key)
{
	int addr = Hash(key);
	while (elem[addr] != NULLKEY) // �����Ϊ�գ���ô�ͱ�ʾ��ͻ
	{
		addr = (addr + 1) % m; // ���ŵ�ַ��������̽��
	}
	elem[addr] = key;
}

inline bool HashTable::SearchHash(int key, int *addr)
{
	*addr = Hash(key);
	while (elem[*addr] != key)
	{
		*addr = (*addr + 1) % m;
		if (elem[*addr] == NULLKEY || *addr == Hash(key)) // ���ѭ���ص�ԭ��˵�����о�û�и�Ԫ�ػ���ѭ�����յ�λ��˵������û�в����Ԫ��
		{
			return 0;
		}
	}
	return 1;
}

inline int HashTable::Hash(int key)
{
	return key % m; // ����������
}

