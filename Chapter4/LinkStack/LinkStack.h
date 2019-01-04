#include<iostream>

template <typename T>
struct StackNode
{
	T data;
	StackNode<T> *next;
};

template <typename T>
class LinkStack
{
public:
	LinkStack();
	~LinkStack();
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
inline LinkStack<T>::LinkStack()
{
	top = NULL;
	count = 0;
}

template<typename T>
inline LinkStack<T>::~LinkStack()
{
	StackNode<T> *p = NULL;
	while (top != NULL)
	{
		p = top->next;
		delete top;
		top = p;
	}
	count = 0;
}

template<typename T>
inline void LinkStack<T>::push(T data)
{
	StackNode<T> *p = new StackNode<T>;
	p->data = data;
	p->next = top; // ��֮ǰ��ջ���趨Ϊ��ǰ�¼�����ĺ��
	top = p;  // ���½������Ϊ�µ�ջ��
	count++;
}

template<typename T>
inline T LinkStack<T>::pop()
{
	StackNode<T> *ptr = top->next;   
	T e = top->data;
	delete top;              
	top = ptr;              
	count--;
	return e;
}

template<typename T>
inline T LinkStack<T>::GetTop()
{
	return top->data;
}

template<typename T>
inline bool LinkStack<T>::Empty()
{
	return top == NULL;
}

template<typename T>
inline void LinkStack<T>::Print()
{
	StackNode<T> *p = top; // �м�ʹ���м����
	while (p != NULL)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

template<typename T>
inline int LinkStack<T>::Length()
{
	return count;
}
