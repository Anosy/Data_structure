#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdexcept>
#include<iostream>


struct Node
{
	int data;
	Node *next;
};

class LinkList
{
public:
	LinkList();
	LinkList(int a[], int n);
	~LinkList();
	int GetElem(int i);
	void Insert(int i, int x);
	int Delete(int i);
	void Print();

private:
	Node *first;

};

inline LinkList::LinkList()
{
	first = new Node;
	first->next = NULL;
}

// 头插法
//inline LinkList::LinkList(int a[], int n)
//{
//	first = new Node; // 创建头结点
//	first->next = NULL; // 初始化一个空链表
//	for (int i = 0; i < n; ++i)
//	{
//		Node *S = new Node;
//		S->data = a[i]; // 新的结点的数据为数组的当前位置的值
//		S->next = first->next; // 新结点的下一个位置为头结点之前指向的下一个位置
//		first->next = S; // 头结点的下一个位置为新加入结点的位置
//	}
//}

inline LinkList::~LinkList()
{
	while (first != NULL)
	{
		Node * p = first;
		first = first->next;
		delete p;
	}
}

inline int LinkList::GetElem(int i)
{
	int count = 0;
	Node *p = first->next;
	while (p != NULL)
	{
		count++;
		if (count == i)
		{
			return p->data;
		}
		p = p->next;
	}
	if (p == NULL)
	{
		return -1; // 越界
	}
}

inline void LinkList::Insert(int i, int x)
{
	int count = 0;
	Node *p = first;
	while (p != NULL)
	{
		if (count == i - 1)
		{
			Node *S = new Node;
			S->data = x;
			S->next = p->next;
			p->next = S;
		}
		p = p->next;
		count++;
	}
}	

inline int LinkList::Delete(int i)
{
	int count = 0;
	Node *p = new Node;
	while (p != NULL)
	{
		if (count == i - 1)
		{
			auto q = p->next;
			auto x = q->data;
			p->next = q->next;
			delete q;
			return x;
		}
		p = p->next;
		count++;

	}
	if (p == NULL)
	{
		return -1;
	}
}

inline void LinkList::Print()
{
	Node * p = first->next;
	while (p != NULL)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
}

// 尾插法
inline LinkList::LinkList(int a[], int n)
{
	first = new Node;
	first->next = NULL;
	Node *r = first; // 初始化一个尾结点
	for (int i = 0; i < n; ++i)
	{
		Node *S = new Node; 
		S->data = a[i]; // 新的结点的数据为数组的当前位置的值
		r->next = S; // 尾结点的下一个位置为新加入的结点
		r = S; // 将尾结点的位置更新为新加入的结点
	}
	r->next = NULL; // 结束循环后，将最后一个结点的下一个位置至为空
}

#endif // !LINKLIST_H

