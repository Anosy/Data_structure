#include<iostream>

template <typename T>
struct Node
{
	int data;
	Node<T> *prior; // ֱ��ǰ��ָ��
	Node<T> *next; // ֱ�Ӻ���ָ��
};

template <typename T>
class myDoubleLinkList
{
public:
	myDoubleLinkList();
	~myDoubleLinkList() {};
	void CreatList(int n);
	void Insert(int index, T data);
	T Delete(int index);
	int Size();
	T GetItem(int index);
	void Print();

private:
	int length;
	Node<T> *head;
};

template<typename T>
inline myDoubleLinkList<T>::myDoubleLinkList()
{
	head = new Node<T>;
	head->prior = head;
	head->next = head;
}

// ǰ�巨
//template<typename T>
//inline void myDoubleLinkList<T>::CreatList(int n)
//{
//	Node<T> *p = head;
//	for (int i = 0; i < n; ++i)
//	{
//		std::cout << "�����" << i + 1 << "�����ֵ��";
//		Node<T> *S = new Node<T>;
//		std::cin >> S->data;
//		S->prior = p;
//		S->next = p->next;
//		p->next->prior = S;
//		p->next = S;
//	}
//	length = n;
//}

// ��巨
template<typename T>
inline void myDoubleLinkList<T>::CreatList(int n)
{
	Node<T> *r = head;
	for (int i = 0; i < n; ++i)
	{
		std::cout << "�����" << i + 1 << "�����ֵ��";
		Node<T> *S = new Node<T>;
		std::cin >> S->data;
		S->prior = r;
		r->next = S;
		r = S;
	}
	r->next = head;
	length = n;
}

template<typename T>
inline void myDoubleLinkList<T>::Insert(int index, T data)
{
	if (index < 1 || index > length)
	{
		std::cout << "�����λ������" << std::endl;
		return;
	}
	Node<T> *q = head;
	Node<T> *p = new Node<T>;
	p->data = data;
	for (int i = 0; i < index - 1; i++)
	{
		q = q->next;
	}
	p->prior = q;
	p->next = q->next;
	q->next->prior = p;
	q->next = p;
	++length;
}

template<typename T>
inline T myDoubleLinkList<T>::Delete(int index)
{
	if (index < 1 || index > length)
	{
		std::cout << "ɾ����λ������" << std::endl;
		return -1;
	}
	Node<T> *p = head;
	for (int i = 0; i < index - 1; ++i)
	{
		p = p->next;
	}
	Node<T> *q = p->next;
	T x = q->data;
	q->prior->next = q->next;
	q->next->prior = q->prior;
	--length;
	return x;
}


template<typename T>
inline int myDoubleLinkList<T>::Size()
{
	return length;
}

template<typename T>
inline T myDoubleLinkList<T>::GetItem(int index)
{
	Node<T> *p = head;
	for (int i = 0; i < index; ++i)
	{
		p = p->next;
	}
	return p->data;
}

template<typename T>
inline void myDoubleLinkList<T>::Print()
{
	Node<T> *p = head->next;
	while (p != head)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}
