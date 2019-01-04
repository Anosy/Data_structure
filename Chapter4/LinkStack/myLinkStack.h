#include<iostream>

template <typename T>
struct StackNode
{
	T data;
	StackNode<T> *next;
};

template <typename T>
class myLinkStack
{
public:
	myLinkStack();
	~myLinkStack();
	void push(T data);
	T pop();
	T GetTop();
	bool Empty();
	void Print();
	int Length();

private:
	StackNode<T> *top;
	int count;
};

template<typename T>
inline myLinkStack<T>::myLinkStack()
{
	top = NULL;
	count = 0;
}

template<typename T>
inline myLinkStack<T>::~myLinkStack()
{
	while (top != NULL)
	{
		StackNode<T> *p = top;
		top = top->next;
		delete p;
	}
	count = 0;
}

template<typename T>
inline void myLinkStack<T>::push(T data)
{
	StackNode<T> *p = new StackNode<T>;
	p->data = data;
	p->next = top; // 向下指向
	top = p;
	count++;
}

template<typename T>
inline T myLinkStack<T>::pop()
{
	if (Empty())
	{
		std::cout << "空栈" << std::endl;
		return -1;
	}
	StackNode<T> *p = top;
	T e = p->data;
	top = p->next;
	delete p;
	count--;
	
	return e;
}

template<typename T>
inline T myLinkStack<T>::GetTop()
{
	return top->data;
}

template<typename T>
inline bool myLinkStack<T>::Empty()
{
	return top == NULL;
}

template<typename T>
inline void myLinkStack<T>::Print()
{
	StackNode<T> *p = top;
	while (p != NULL)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

template<typename T>
inline int myLinkStack<T>::Length()
{
	return count;
}
