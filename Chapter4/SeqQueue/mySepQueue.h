#include<iostream>

using namespace std;

const int MAXSIZE = 10;

template <typename T>
class mySepQueue
{
public:
	mySepQueue();
	~mySepQueue() {};
	bool isEmpty();
	bool isFull();
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
inline mySepQueue<T>::mySepQueue()
{
	front = rear = 0;
}

template<typename T>
inline bool mySepQueue<T>::isEmpty()
{
	return front == rear;
}

template<typename T>
inline bool mySepQueue<T>::isFull()
{
	return (rear + 1) % MAXSIZE == front;
}

template<typename T>
inline void mySepQueue<T>::EnQueue(T e)
{
	if (isFull())
	{
		cout << "队列满" << endl;
		return;
	}
	data[rear] = e;
	rear = (rear + 1) % MAXSIZE;
}

template<typename T>
inline T mySepQueue<T>::GetHead()
{
	return data[front];
}

template<typename T>
inline T mySepQueue<T>::DeQueue()
{
	if (isEmpty())
	{
		cout << "队列空" << endl;
		return -1;
	}
	T e = data[front];
	front = (front + 1) % MAXSIZE;

	return e;
}

template<typename T>
inline int mySepQueue<T>::QueueLength()
{
	return (rear - front + MAXSIZE) % MAXSIZE;
}

template<typename T>
inline void mySepQueue<T>::ClearQueue()
{
	front = rear = 0;
}

