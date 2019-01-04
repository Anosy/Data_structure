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
	p->next = top; // 将之前的栈顶设定为当前新加入结点的后继
	top = p;  // 将新结点设置为新的栈顶
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
	StackNode<T> *p = top; // 切记使用中间变量
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
