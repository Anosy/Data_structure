#include<iostream>

using namespace std;

const int HASHSIZE = 12; // 定义哈希表长为数组长度
const int NULLKEY = -32768;
int m = 0;

class HashTable
{
public:
	HashTable();
	void InsertHash(int key);
	bool SearchHash(int key, int *addr);
private:
	int *elem; // 数组元素的存储的地址，动态数组
	int count; // 当前数据元素的个数
	int Hash(int key); // 哈希函数
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
	while (elem[addr] != NULLKEY) // 如果不为空，那么就表示冲突
	{
		addr = (addr + 1) % m; // 开放地址法的线性探针
	}
	elem[addr] = key;
}

inline bool HashTable::SearchHash(int key, int *addr)
{
	*addr = Hash(key);
	while (elem[*addr] != key)
	{
		*addr = (*addr + 1) % m;
		if (elem[*addr] == NULLKEY || *addr == Hash(key)) // 如果循环回到原点说明表中就没有该元素或者循环到空的位置说明表中没有插入该元素
		{
			return 0;
		}
	}
	return 1;
}

inline int HashTable::Hash(int key)
{
	return key % m; // 除留余数法
}

