#include<iostream>

using namespace std;

template <typename T>
struct QNode
{
	T data;
	QNode<T> *next;
};

template <typename T>
class LinkQueue
{
public:
	LinkQueue();
	~LinkQueue();
	void EnQueue(T e);
	T DeQueue();
	bool isEmpty();
	int Length();
	T GetTop();
	void Print();

private:
	QNode<T> *front;
	QNode<T> *rear;
};

template<typename T>
inline LinkQueue<T>::LinkQueue()
{
	QNode<T> *p = new QNode<T>;
	p->next = NULL;
	front = p;
	rear = p;
}

template<typename T>
inline LinkQueue<T>::~LinkQueue()
{
	while (front != NULL)
	{
		QNode<T> *p = front;
		front = p->next;
		delete p;
	}
}

template<typename T>
inline void LinkQueue<T>::EnQueue(T e)
{
	QNode<T> *S = new QNode<T>;
	S->data = e;
	S->next = NULL; // 新结点的下一个结点为空
	rear->next = S; // 尾结点的下一个结点为新结点
	rear = S; // 尾节点更新为新结点
}

template<typename T>
inline T LinkQueue<T>::DeQueue()
{
	if (isEmpty())
	{
		cout << "链队列为空";
		return -1;
	}
	QNode<T> *p = front->next;
	T e = p->data;
	front->next = p->next;
	if (rear == p)
	{
		rear = front;
	}
	delete p;
	return e;
}

template<typename T>
inline bool LinkQueue<T>::isEmpty()
{
	return rear == front;
}

template<typename T>
inline int LinkQueue<T>::Length()
{
	unsigned count = 0;
	QNode<T> *p = front->next;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

template<typename T>
inline T LinkQueue<T>::GetTop()
{
	return front->next->data;
}

template<typename T>
inline void LinkQueue<T>::Print()
{
	if (isEmpty())
	{
		cout << "链表为空" << endl;
		return;
	}
	QNode<T> *p = front->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
