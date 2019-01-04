#include<iostream>

// 结点类
class Node {
public:
	int data;
	Node *next;
};

class CircularLinkList
{
public:
	CircularLinkList();
	~CircularLinkList();
	void CreateLinkList(int n);
	void InsertNode(int index, int x);
	int DeleteNode(int index);
	int GetLength();
	void PrintList();
private:
	Node *head;
};

// 默认初始化链表，其头结点的下一个就是当前的结点
inline CircularLinkList::CircularLinkList() 
{
	head = new Node;
	head->data = 0;
	head->next = head;
}

inline CircularLinkList::~CircularLinkList()
{
	/*while (head->next != head)
	{
		Node *p = head;
		head = head->next;
		delete p;
	}
	delete head;*/
}

inline void CircularLinkList::CreateLinkList(int n)
{
	if (n < 0)
	{
		std::cout << "输入结点的数量错误！" << std::endl;
		return;
	}
	int i = n;
	while (n-- > 0) 
	{
		std::cout << "输入第" << i - n << "个结点值：";
		Node *S = new Node;
		std::cin >> S->data;
		S->next = head->next;
		head->next = S;
	}
}

inline void CircularLinkList::InsertNode(int index, int x)
{
	if (index < 1 || index > GetLength())
	{
		std::cout << "位置错误!" << std::endl;
		return;
	}
	int count = 0;
	Node *p = head;
	while (p->next != head)
	{
		if (count == index - 1)
		{
			Node *S = new Node;
			S->data = x;
			S->next = p->next;
			p->next = S;
		}
		p = p->next;
		++count;
	}
}

inline int CircularLinkList::DeleteNode(int index)
{
	if (index < 1 || index > GetLength())
	{
		std::cout << "位置错误!" << std::endl;
		return - 1;
	}
	int count = 0;
	Node *p = head;
	while (p->next != head)
	{
		if (count == index - 1)
		{
			Node *q = p->next;
			int x = q->data;
			p->next = q->next;
			delete q;
			return x;
		}
		p = p->next;
		++count;
	}
	return -1;
}

inline int CircularLinkList::GetLength()
{
	if (head->next == head)
	{
		return 0;
	}
	int n = 1;
	Node *p = head->next;
	while (p->next != head)
	{
		++n;
		p = p->next;
	}
	return n;
}

inline void CircularLinkList::PrintList()
{
	Node *p = head->next;
	while (p != head)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

