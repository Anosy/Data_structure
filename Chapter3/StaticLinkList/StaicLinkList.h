#include<iostream>

const size_t MAXSIZE = 1000;
struct Node
{
	int data;
	int cur;
};


class StaticLinkList
{
public:
	StaticLinkList(); // 初始一个空链表
	~StaticLinkList(){};
	bool Insert(const int e, int index = 1);
	bool Delete(int &e, int index);
	bool Show();

private:
	int NewSpace();// 为链表创建一个可以用的空间
	void DeleteSpace(int index);//删除list中的index元素
	bool Empty()const;
	bool Full()const;
	Node StList[MAXSIZE];
	int Length = 0;
};

inline StaticLinkList::StaticLinkList()
{
	for (int i = 0; i < MAXSIZE - 1; i++)
	{
		StList[i].cur = i + 1;
	}
	StList[MAXSIZE - 1].cur = 0;
}

inline int StaticLinkList::NewSpace() 
{
	int i = StList[0].cur; // 返回当前可以用的空间的下标
	if (StList[0].cur) 
	{
		StList[0].cur = StList[i].cur; // 将当前备用空间的下标设定为，新创建位置的下一个下标位置
	}
	return i; // 返回新创建位置的下标
}

inline void StaticLinkList::DeleteSpace(int index)
{
	StList[index].cur = StList[0].cur; // 将当前要删除掉的结点的下标设定为第一个备用位置的下标
	StList[0].cur = index; // 将第一个备用位置更新为当前要删除的下标  (两句合起来的意思就是将删除位置作为第一个备用链表位置，然后后面接着下一个备用位置)
}

inline bool StaticLinkList::Empty() const
{
	return Length == 0;
}

inline bool StaticLinkList::Full() const // 保证头尾不被插入覆盖
{
	if (Length > MAXSIZE - 2)
	{
		return true;
	}
	return false;
}


inline bool StaticLinkList::Insert(const int e, int index)
{
	if (Full()) 
	{
		std::cout << "Can't insert element to a full List!\n";
		return false;
	}
	if (index < 1 || index > Length + 1) // 确保插入位置合法
	{
		std::cout << "The invalid index!\n";
		return false;
	}
	int k = NewSpace(); // 新建一个位置
	int j = MAXSIZE - 1; // 返回最后一个元素的下标
	if (k)
	{
		StList[k].data = e;
		for (int i = 1; i <= index - 1; ++i) // 找到插入结点的前一个结点
		{
			j = StList[j].cur;
		}
		StList[k].cur = StList[j].cur; // 将插入位置前一个结点的cur给了新建位置的cur
		StList[j].cur = k; // 将新键位置的下标给插入前一个结点的cur
		++Length;
		return true;
	}
	return false;

}

inline bool StaticLinkList::Delete(int &e, int index)
{
	if (Empty())
	{
		std::cout << "Can't delete element in a empty list!\n";
		return false;
	}
	if (index<1 || index > Length)//如果删除的位置不合法，返回false
	{
		std::cout << "The invalid index!\n";
		return false;
	}
	int k = MAXSIZE - 1;
	for (int i = 1; i <= index - 1; ++i)
	{
		k = StList[k].cur;
	}
	int j = StList[k].cur;
	StList[k].cur = StList[j].cur; // 将index - 1结点的cur设定为第index结点的cur
	e = StList[j].data; 
	DeleteSpace(j); 
	--Length; 
	return true;
}

inline bool StaticLinkList::Show()
{
	if (Empty())
	{
		std::cout << "The List is Empty!\n";
		return false;
	}
	int k = StList[MAXSIZE - 1].cur;
	for (int i = 1; i <= Length; ++i)
	{
		std::cout << StList[k].data << " ";
		k = StList[k].cur;
	}
	std::cout << std::endl;
	return true;
}

