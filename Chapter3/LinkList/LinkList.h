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

// ͷ�巨
//inline LinkList::LinkList(int a[], int n)
//{
//	first = new Node; // ����ͷ���
//	first->next = NULL; // ��ʼ��һ��������
//	for (int i = 0; i < n; ++i)
//	{
//		Node *S = new Node;
//		S->data = a[i]; // �µĽ�������Ϊ����ĵ�ǰλ�õ�ֵ
//		S->next = first->next; // �½�����һ��λ��Ϊͷ���֮ǰָ�����һ��λ��
//		first->next = S; // ͷ������һ��λ��Ϊ�¼������λ��
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
		return -1; // Խ��
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

// β�巨
inline LinkList::LinkList(int a[], int n)
{
	first = new Node;
	first->next = NULL;
	Node *r = first; // ��ʼ��һ��β���
	for (int i = 0; i < n; ++i)
	{
		Node *S = new Node; 
		S->data = a[i]; // �µĽ�������Ϊ����ĵ�ǰλ�õ�ֵ
		r->next = S; // β������һ��λ��Ϊ�¼���Ľ��
		r = S; // ��β����λ�ø���Ϊ�¼���Ľ��
	}
	r->next = NULL; // ����ѭ���󣬽����һ��������һ��λ����Ϊ��
}

#endif // !LINKLIST_H

