#include<iostream>

using namespace std;

template <typename T>
struct QNode
{
	T data;
	QNode<T> *next;
};

template <typename T>
class myLinkQueue
{
public:
	myLinkQueue();
	~myLinkQueue();
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
inline myLinkQueue<T>::myLinkQueue()
{
	front = rear = new QNode<T>;
	front->next = rear->next = NULL;
}

template<typename T>
inline myLinkQueue<T>::~myLinkQueue()
{
	while (front != NULL)
	{
		QNode<T> *p = front;
		front = front->next;
		delete p;
	}
}

template<typename T>
inline void myLinkQueue<T>::EnQueue(T e)
{
	QNode<T> *p = new QNode<T>;
	p->data = e;
	p->next = NULL;
	rear->next = p;
	rear = p;
}

template<typename T>
inline T myLinkQueue<T>::DeQueue()
{
	QNode<T> *p = front->next;
	T e = p->data;
	front->next = p->next;
	if (p == rear)
	{
		front = rear;
	}
	delete p;
	return e;
}

template<typename T>
inline bool myLinkQueue<T>::isEmpty()
{
	return front == rear;
}

template<typename T>
inline int myLinkQueue<T>::Length()
{
	int count = 0;
	QNode<T> *p = front->next;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

template<typename T>
inline T myLinkQueue<T>::GetTop()
{
	return front->next->data;
}

template<typename T>
inline void myLinkQueue<T>::Print()
{
	if (isEmpty())
	{
		cout << "Á´±íÎª¿Õ" << endl;
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
