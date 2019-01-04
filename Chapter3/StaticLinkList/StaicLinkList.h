#include<iostream>

const size_t MAXSIZE = 1000;
struct Node
{
	int data;
	int cur;
};


class StaticLinkList
{
public:
	StaticLinkList(); // ��ʼһ��������
	~StaticLinkList(){};
	bool Insert(const int e, int index = 1);
	bool Delete(int &e, int index);
	bool Show();

private:
	int NewSpace();// Ϊ��������һ�������õĿռ�
	void DeleteSpace(int index);//ɾ��list�е�indexԪ��
	bool Empty()const;
	bool Full()const;
	Node StList[MAXSIZE];
	int Length = 0;
};

inline StaticLinkList::StaticLinkList()
{
	for (int i = 0; i < MAXSIZE - 1; i++)
	{
		StList[i].cur = i + 1;
	}
	StList[MAXSIZE - 1].cur = 0;
}

inline int StaticLinkList::NewSpace() 
{
	int i = StList[0].cur; // ���ص�ǰ�����õĿռ���±�
	if (StList[0].cur) 
	{
		StList[0].cur = StList[i].cur; // ����ǰ���ÿռ���±��趨Ϊ���´���λ�õ���һ���±�λ��
	}
	return i; // �����´���λ�õ��±�
}

inline void StaticLinkList::DeleteSpace(int index)
{
	StList[index].cur = StList[0].cur; // ����ǰҪɾ�����Ľ����±��趨Ϊ��һ������λ�õ��±�
	StList[0].cur = index; // ����һ������λ�ø���Ϊ��ǰҪɾ�����±�  (�������������˼���ǽ�ɾ��λ����Ϊ��һ����������λ�ã�Ȼ����������һ������λ��)
}

inline bool StaticLinkList::Empty() const
{
	return Length == 0;
}

inline bool StaticLinkList::Full() const // ��֤ͷβ�������븲��
{
	if (Length > MAXSIZE - 2)
	{
		return true;
	}
	return false;
}


inline bool StaticLinkList::Insert(const int e, int index)
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
	int k = NewSpace(); // �½�һ��λ��
	int j = MAXSIZE - 1; // �������һ��Ԫ�ص��±�
	if (k)
	{
		StList[k].data = e;
		for (int i = 1; i <= index - 1; ++i) // �ҵ��������ǰһ�����
		{
			j = StList[j].cur;
		}
		StList[k].cur = StList[j].cur; // ������λ��ǰһ������cur�����½�λ�õ�cur
		StList[j].cur = k; // ���¼�λ�õ��±������ǰһ������cur
		++Length;
		return true;
	}
	return false;

}

inline bool StaticLinkList::Delete(int &e, int index)
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
	for (int i = 1; i <= index - 1; ++i)
	{
		k = StList[k].cur;
	}
	int j = StList[k].cur;
	StList[k].cur = StList[j].cur; // ��index - 1����cur�趨Ϊ��index����cur
	e = StList[j].data; 
	DeleteSpace(j); 
	--Length; 
	return true;
}

inline bool StaticLinkList::Show()
{
	if (Empty())
	{
		std::cout << "The List is Empty!\n";
		return false;
	}
	int k = StList[MAXSIZE - 1].cur;
	for (int i = 1; i <= Length; ++i)
	{
		std::cout << StList[k].data << " ";
		k = StList[k].cur;
	}
	std::cout << std::endl;
	return true;
}
