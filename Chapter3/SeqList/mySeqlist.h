#include<iostream>
#include<stdexcept>

const int MAXSIZE = 20;

template <typename T>
class mySeqList
{
public:
	mySeqList() :length(0) {}
	mySeqList(T a[], int n);
	T GetElem(int i); // 获取元素
	void ListInsert(int i, T e); // 插入
	T ListDelete(int i); // 删除
	void ListPrint();
	~mySeqList() {}
private:
	T data[MAXSIZE];
	int length;
};

template<typename T>
inline mySeqList<T>::mySeqList(T a[], int n)
{
	if (n > MAXSIZE)
	{
		throw std::out_of_range("非法参数");
	}
	for (int i = 0; i < n; i++)
	{
		data[i] = a[i];
	}
	length = n;
}

template<typename T>
inline T mySeqList<T>::GetElem(int i)
{
	if (length == 0 || i < 0 || i > length)
	{
		std::cout << "查找异常" << std::endl;
		return -1;
	}
	T e = data[i - 1];
	return e;
}

template<typename T>
inline void mySeqList<T>::ListInsert(int i, T e)
{
	if (length == MAXSIZE)
	{
		std::cout << "已经达到最大的长度了" << std::endl;
		return;
	}
	if (i > length || i < 1)
	{
		std::cout << "插入的位置有误" << std::endl;
		return;
	}
	if (i < length) 
	{
		for (int k = length - 1; k >= i - 1; --k)  
		{
			data[k + 1] = data[k];
		}
	}
	data[i - 1] = e;
	length++;
}

template<typename T>
inline T mySeqList<T>::ListDelete(int i)
{
	if (length == 0) 
	{
		std::cout << "没有元素无法删除" << std::endl;	
		return -1;
	}
	if (i < 1 || i > length)  
	{
		std::cout << "删除的位置不合法" << std::endl;
		return -1;
	}
	T e = data[i - 1];
	if (i < length)  
	{
		for (int k = i; k < length; ++k)  
		{
			data[k - 1] = data[k];
		}
	}
	length--;
	return e;
}

template<typename T>
inline void mySeqList<T>::ListPrint()
{
	for (int k = 0; k < length; ++k)
	{
		std::cout << data[k] << " ";
	}
}


