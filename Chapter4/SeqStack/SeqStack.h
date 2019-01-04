#include<iostream>

const int MAXSIZE = 20;
template <typename T>
class SeqStack
{
public:
	SeqStack() :top(-1){}
	~SeqStack()	{}
	void Push(T x);
	T Pop();
	T GetTop();
	bool Empty();
	void Print();

private:
	T data[MAXSIZE];
	int top; // 栈的指针(0)开始
};

template<typename T>
inline void SeqStack<T>::Push(T x)
{
	if (top == MAXSIZE - 1)
	{
		std::cout << "栈已满" << std::endl;
		return;
	}
	top++;
	data[top] = x;
}

template<typename T>
inline T SeqStack<T>::Pop()
{
	if (Empty())
	{
		std::cout << "栈为空" << std::endl;
		return -1;
	}
	T e = data[top];
	top--;
	return e;
}

template<typename T>
inline T SeqStack<T>::GetTop()
{
	return data[top];
}

template<typename T>
inline bool SeqStack<T>::Empty()
{
	return top == -1;
}

template<typename T>
inline void SeqStack<T>::Print()
{
	if (Empty())
	{
		std::cout << "当前栈为空栈" << std::endl;
	}
	int i = 0;
	while (i <= top)
	{
		std::cout << data[i] << " ";
		++i;
	}
	std::cout << std::endl;
}
