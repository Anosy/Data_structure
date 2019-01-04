#include<iostream>

using namespace std;

const int MAXSIZE = 10;

template <typename T>
class SepQueue
{
public:
	SepQueue();
	~SepQueue() {};
	bool isEmpty();
	void EnQueue(T e);
	T GetHead();
	T DeQueue();
	int QueueLength();
	void ClearQueue();

private:
	T data[MAXSIZE];
	int front;
	int rear;
};

template<typename T>
inline SepQueue<T>::SepQueue()
{
	front = 0;
	rear = 0;
}

template<typename T>
inline bool SepQueue<T>::isEmpty()
{
	return front == rear;
}

template<typename T>
inline void SepQueue<T>::EnQueue(T e)
{
	if ((rear + 1) % MAXSIZE == front)
	{
		cout << "队列满" << endl;
		return;
	}
	data[rear] = e;
	rear = (rear + 1) % MAXSIZE;
}

template<typename T>
inline T SepQueue<T>::GetHead()
{
	return data[front];
}

template<typename T>
inline T SepQueue<T>::DeQueue()
{
	if (isEmpty())
	{
		cout << "队列为空" << endl;
		return -1;
	}
	T e = data[front];
	front = (front + 1) % MAXSIZE;

	return e;
}

template<typename T>
inline int SepQueue<T>::QueueLength()
{
	return (rear - front + MAXSIZE) % MAXSIZE;
}

template<typename T>
inline void SepQueue<T>::ClearQueue()
{
	front = 0;
	rear = 0;
}
