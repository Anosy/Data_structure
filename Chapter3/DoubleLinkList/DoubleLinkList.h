#include<iostream>

struct Node
{
	int data;
	Node *prior; // ֱ��ǰ��ָ��
	Node *next; // ֱ�Ӻ���ָ��
};

class DoubleLinkList
{
public:
	DoubleLinkList();
	~DoubleLinkList() {};
	void CreatList(int n);
	void Insert(int index, int data);
	int Delete(int index);
	int Size();
	void Print();

private:
	int length;
	Node *head;
};

inline DoubleLinkList::DoubleLinkList()
{
	head = new Node;
	head->prior = head;
	head->next = head;
	length = 0;
}

inline void DoubleLinkList::CreatList(int n)
{
	if (n < 1)
	{
		std::cout << "���������������" << std::endl;
		return;
	}
	int i = n;
	while (n -- > 0)
	{
		std::cout << "�����" << i - n << "�����ֵ��";
		Node *S = new Node;
		std::cin >> S->data;
		S->prior = head;
		S->next = head->next;
		head->next->prior = S;
		head->next = S;
	}
	length = i;
}

inline void DoubleLinkList::Insert(int index, int data)
{
	if (index < 1 || index > length)
	{
		std::cout << "�����λ������" << std::endl;
		return;
	}
	Node *S = new Node; // ��ǰҪ����Ľ��
	S->data = data;
	Node *p = head;
	for (int i = 0; i < index - 1; ++i)
	{
		p = p->next;
	}
	S->prior = p;
	S->next = p->next;
	p->next->prior = S;
	p->next = S;
	++length;
}

inline int DoubleLinkList::Delete(int index)
{
	if (index < 1 || index > length)
	{
		std::cout << "ɾ����λ������" << std::endl;
		return -1;
	}
	Node *p = head;
	for (int i = 0; i < index; ++i)
	{
		p = p->next;
	}
	int x = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
	--length;
	return x;
}

inline int DoubleLinkList::Size()
{
	return length;
}

inline void DoubleLinkList::Print()
{
	Node *p = head->next;
	while (p != head)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}
