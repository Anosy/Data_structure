#include<iostream>

int const MAXSIZE = 20;

template <typename T>
class myDoubleSeqStack
{
public:
	myDoubleSeqStack() : top1(-1), top2(MAXSIZE) {}
	myDoubleSeqStack(T a[], int n, T b[], int m);
	~myDoubleSeqStack() {}
	void Push(int StackNumber, T x);
	T Pop(int StackNumber);
	T GetTop(int StackNumber);
	bool Empty(int StackNumber);
	void Print(int StackNumber);

private:
	T data[MAXSIZE];
	int top1, top2;
};

template<typename T>
inline myDoubleSeqStack<T>::myDoubleSeqStack(T a[], int n, T b[], int m)
{
	top1 = -1;
	top2 = MAXSIZE;
	if (n + m <= MAXSIZE)
	{
		for (int i = 0; i < n; ++i)
		{
			data[++top1] = a[i];
		}
		for (int j = 0; j < m; ++j)
		{
			data[--top2] = b[j];
		}
	}
}

template<typename T>
inline void myDoubleSeqStack<T>::Push(int StackNumber, T x)
{

	if (top1 + 1 == top2)
	{
		std::cout << "Õ»ÒÑÂú" << std::endl;
		return;
	}
	if (StackNumber == 1)
	{
		data[++top1] = x;
	}
	if (StackNumber == 2)
	{
		data[--top2] = x;
	}
}

template<typename T>
inline T myDoubleSeqStack<T>::Pop(int StackNumber)
{
	if (StackNumber == 1)
	{
		if (top1 == -1)
		{
			std::cout << "Õ»1Îª¿ÕÕ»" << std::endl;
			return -1;
		}
		return data[top1--];
	}
	if (StackNumber == 2)
	{
		if (top2 == MAXSIZE)
		{
			std::cout << "Õ»2Îª¿ÕÕ»" << std::endl;
			return -1;
		}
	}
	return -1;
}

template<typename T>
inline T myDoubleSeqStack<T>::GetTop(int StackNumber)
{
	if (StackNumber == 1)
	{
		return data[top1];
	}
	if (StackNumber == 2)
	{
		return data[top2];
	}
}

template<typename T>
inline bool myDoubleSeqStack<T>::Empty(int StackNumber)
{
	if (StackNumber == 1)
	{
		return top1 == -1;
	}
	if (StackNumber == 2)
	{
		return top2 = MAXSIZE;
	}
}

template<typename T>
inline void myDoubleSeqStack<T>::Print(int StackNumber)
{
	if (top1 + 1 == top2)
	{
		std::cout << "¿ÕÕ»" << std::endl;
	}
	if (StackNumber == 1)
	{
		std::cout << "Õ»1µÄÔªËØÎª£º";
		int i = top1;
		while (i != -1)
		{
			std::cout << data[i--] << " ";
		}
		std::cout << std::endl;
	}
	if (StackNumber == 2)
	{
		std::cout << "Õ»2µÄÔªËØÎª£º";
		int j = top2;
		while (j != MAXSIZE)
		{
			std::cout << data[j++] << " ";
		}
		std::cout << std::endl;
	}
}
