#include<stdexcept>
#include<iostream>

template <typename T>
struct Node
{
	T data;
	Node<T> *next;
};

template <typename T>
class myLinkList
{
public:
	myLinkList();
	myLinkList(int n);
	~myLinkList();
	T GetElem(int i);
	int ListLength();
	void Insert(int i, T x);
	T Delete(int i);
	void Print();

private:
	Node<T> *head; // ͷ���
};

template <typename T>
inline myLinkList<T>::myLinkList()
{
	head = new Node<T>;
	head->next = NULL;
}

// ͷ�巨
//template<typename T>
//inline myLinkList<T>::myLinkList(int n)
//{
//	head = new Node<T>;
//	head->next = NULL;
//	for (int i = 0; i < n; ++i)
//	{
//		Node<T> *p = new Node<T>;
//		std::cout << "�����" << i+1  << "�����ֵ��";
//		std::cin >> p->data;
//		p->next = head->next;
//		head->next = p;
//	}
//}

// β�巨
template<typename T>
inline myLinkList<T>::myLinkList(int n)
{
	head = new Node<T>;
	head->next = NULL;
	Node<T> *r = head;
	for (int i = 0; i < n; ++i)
	{
		Node<T> *p = new Node<T>;
		std::cout << "�����" << i + 1 << "�����ֵ��";
		std::cin >> p->data;
		r->next = p;
		r = p;
	}
	r->next = NULL; // �ǳ���Ҫ�����򱨴�
}



template<typename T>
inline myLinkList<T>::~myLinkList()
{
	while (head != NULL)
	{
		Node<T> *p = head;
		head = head->next;
		delete p;
	}
}

template<typename T>
inline T myLinkList<T>::GetElem(int i)
{
	if (i < 1 || i > ListLength())
	{
		std::cout << "�Ƿ�����" << std::endl;
		return "";
	}

	Node<T> *p = head;
	for (int j = 0; j < i; ++j)
	{
		p = p->next;
	}
	T e = p->data;
	return e;
}

template<typename T>
inline int myLinkList<T>::ListLength()
{
	int count = 0;
	Node<T> *p = head->next;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}

template<typename T>
inline void myLinkList<T>::Insert(int i, T x)
{
	if (i < 1 || i > ListLength() + 1)
	{
		std::cout << "�Ƿ�����" << std::endl;
		return;
	}
	Node<T> *p = head;
	for (int j = 0; j < i - 1; ++j) // ��ȡiǰһ��λ��
	{
		p = p->next;
	}
	Node<T> *S = new Node<T>;
	S->data = x;
	S->next = p->next;
	p->next = S;
}

template<typename T>
inline T myLinkList<T>::Delete(int i)
{
	if (i < 1 || i > ListLength())
	{
		std::cout << "�Ƿ�����" << std::endl;
		return "";
	}
	Node<T> *p = head;
	for (int j = 0; j < i - 1; ++j) // ��ȡi��ǰһ��Ԫ��
	{
		p = p->next;
	}
	Node<T> *q = p->next;
	T e = q->data;
	p->next = q->next;
	delete q;
	return e;
}

template<typename T>
inline void myLinkList<T>::Print()
{
	Node<T> *p = head->next;
	while (p != NULL)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}
