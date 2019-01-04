#include<iostream>

template <typename T>
class Node {
public:
	T data;
	Node<T> *next;
};

template <typename T>
class myCircularLinkList
{
public:
	myCircularLinkList();
	~myCircularLinkList();
	void CreateLinkList(int n);
	T GetElem(int index);
	void InsertNode(int index, T x);
	T DeleteNode(int index);
	int GetLength();
	void PrintList();

private:
	Node<T> *head;
};

template<typename T>
inline myCircularLinkList<T>::myCircularLinkList()
{
	head = new Node<T>;
	head->next = head;
}

template<typename T>
inline myCircularLinkList<T>::~myCircularLinkList()
{
	Node<T> *p = head->next;
	while (p != head)
	{
		Node<T> *q = p;
		p = p->next;
		delete q;
	}
	delete head;
	head = NULL;
}

// 尾插法
template<typename T>
inline void myCircularLinkList<T>::CreateLinkList(int n)
{
	if (n < 0)
	{
		std::cout << "输入结点的数量错误！" << std::endl;
		return;
	}
	Node<T> *r = head;
	for (int i = 0; i < n; ++i)
	{
		std::cout << "输入第" << i + 1 << "个结点值：";
		Node<T> *S = new Node<T>;
		std::cin >> S->data;
		r->next = S;
		r = S;
	}
	r->next = head;
}

template<typename T>
inline T myCircularLinkList<T>::GetElem(int index)
{
	Node<T> * p = head;
	for (int i = 0; i < index; ++i)
	{
		p = p->next;
	}
	return p->data;
}

template<typename T>
inline void myCircularLinkList<T>::InsertNode(int index, T x)
{
	if (index < 1 || index > GetLength())
	{
		std::cout << "位置错误!" << std::endl;
		return;
	}
	Node<T> *p = head;
	for (int j = 0; j < index - 1; ++j) // 获取i前一个位置
	{
		p = p->next;
	}
	Node<T> *S = new Node<T>;
	S->data = x;
	S->next = p->next;
	p->next = S;
}

template<typename T>
inline T myCircularLinkList<T>::DeleteNode(int index)
{
	if (index < 1 || index > GetLength())
	{
		std::cout << "位置错误!" << std::endl;
		return -1;
	}

	Node<T> *p = head;
	for (int i = 0; i < index - 1; ++i)
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
inline int myCircularLinkList<T>::GetLength()
{
	if (head->next == head)
	{
		return 0;
	}
	int n = 0;
	Node<T> *p = head->next;
	while (p != head)
	{
		++n;
		p = p->next;
	}
	return n;
}

template<typename T>
inline void myCircularLinkList<T>::PrintList()
{
	Node<T> *p = head->next;
	while (p != head)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;

}
