#include<iostream>

const size_t MAXSIZE = 1000;

template <typename T>
struct Node
{
	T data;
	int cur;
};

template <typename T>
class myStaticLinkList
{
public:
	myStaticLinkList(); // ��ʼһ��������
	~myStaticLinkList() {};
	bool Insert(const T e, int index = 1);
	bool Delete(int index);
	bool Print();

private:
	int NewSpace();// Ϊ������һ�������õĿռ�
	void DeleteSpace(int index);//ɾ��list�е�indexԪ��
	bool Empty()const;
	bool Full()const;
	Node<T> StList[MAXSIZE];
	int Length = 0;
};

template<typename T>
inline myStaticLinkList<T>::myStaticLinkList()
{
	for (int i = 0; i < MAXSIZE - 1; ++i)
	{
		StList[i].cur = i + 1;
	}
	StList[MAXSIZE - 1].cur = 0;
}

template<typename T>
inline bool myStaticLinkList<T>::Insert(const T e, int index)
{
	if (Full())
	{
		std::cout << "Can't insert element to a full List!\n";
		return false;
	}
	if (index < 1 || index > Length + 1) // ȷ������λ�úϷ�
	{
		std::cout << "The invalid index!\n";
		return false;
	}
	int k = NewSpace();
	int j = MAXSIZE - 1;
	if (k)
	{
		StList[k].data = e;
		for (int i = 0; i < index - 1; ++i)
		{
			j = StList[j].cur;
		}
		StList[k].cur = StList[j].cur;
		StList[j].cur = k;
		++Length;
		return true;
	}
	return false;
}

template<typename T>
inline bool myStaticLinkList<T>::Delete(int index)
{
	if (Empty())
	{
		std::cout << "Can't delete element in a empty list!\n";
		return false;
	}
	if (index<1 || index > Length)//���ɾ����λ�ò��Ϸ�������false
	{
		std::cout << "The invalid index!\n";
		return false;
	}
	int k = MAXSIZE - 1;
	for (int i = 0; i < index - 1; ++i)
	{
		k = StList[k].cur;
	}
	int j = StList[k].cur;
	StList[k].cur = StList[j].cur;
	DeleteSpace(j);
	--Length;
	return true;
}

template<typename T>
inline bool myStaticLinkList<T>::Print()
{
	if (Empty())
	{
		std::cout << "The List is Empty!\n";
		return false;
	}
	int k = StList[MAXSIZE - 1].cur;
	for (int i = 0; i < Length; ++i)
	{
		std::cout << StList[k].data << " ";
		k = StList[k].cur;
	}
	std::cout << std::endl;
	return true;
}

template<typename T>
inline int myStaticLinkList<T>::NewSpace()
{
	int i = StList[0].cur; // �ҵ���ǰ��һ�����ý����±�
	if (StList[0].cur)
	{
		StList[0].cur = StList[i].cur; // ���ǽ������±��趨Ϊ�����һ���±�
	}
	return i; // �����´������±�
}

template<typename T>
inline void myStaticLinkList<T>::DeleteSpace(int index)
{
	StList[index].cur = StList[0].cur;
	StList[0].cur = index;
}

template<typename T>
inline bool myStaticLinkList<T>::Empty() const
{
	return Length == 0;
}

template<typename T>
inline bool myStaticLinkList<T>::Full() const
{
	if (Length > MAXSIZE  - 2)
	{
		return true;
	}
	return false;
}
