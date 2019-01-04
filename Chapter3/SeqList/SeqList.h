#ifndef SEQLIST_H
#define SEQLIST_H


#include<iostream>
#include<stdexcept>
// 顺序线性列表L中,1 << i  << ListLength(L),即位置是按照1开始计算的

const int MAXSIZE = 20;
typedef int ElemType;
const bool OK = 1;
const bool ERROR = 0;
const bool True = 1;
const bool FALSE = 0;
typedef int Status;

class SeqList
{
public:
	SeqList() :length(0) {}
	SeqList(int a[], int n);
	Status GetElem(SeqList L, int i, ElemType *e); // 获取元素
	Status ListInsert(SeqList *L, int i, ElemType e); // 插入
	Status ListDelete(SeqList *L, int i, ElemType *e); // 删除
	Status ListPrint();
	~SeqList() {}
private:
	ElemType data[MAXSIZE];
	int length;
};

inline SeqList::SeqList(int a[], int n)
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

inline
Status SeqList::GetElem(SeqList L, int i, ElemType *e)
{
	if (L.length == 0 || i < 0 || i > L.length)
	{
		return  ERROR;
	}
	*e = L.data[i - 1]; // 顺序列表中的i，在数组中应该是i-1
	return OK;
}

inline
Status SeqList::ListInsert(SeqList * L, int i, ElemType e)
{
	if (L->length == MAXSIZE) // 如果列表已经到达了最大的长度
	{
		return ERROR;
	}
	if (i > L->length || i < 1) // 如果插入的位置不符合逻辑
	{
		return ERROR;
	}
	if (i < L->length) // 如果插入到列表的中间
	{
		for (int k = L->length - 1; k >= i - 1; --k) // 将插入的位置后面的都向后移动一位
		{
			L->data[k + 1] = L->data[k];
		}
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}

inline Status SeqList::ListDelete(SeqList * L, int i, ElemType * e)
{
	if (L->length == 0) // 如果列表的长度为0
	{
		return ERROR;
	}
	if (i < 1 || i > L->length) // 删除不存在的位置
	{
		return ERROR;
	}
	*e = L->data[i - 1];
	if (i < L->length) // 如果删除的位置不是最后一个元素
	{
		for (int k = i; k < L->length; ++k) // 将删除的位置后的元素都向前移动一位
		{
			L->data[k - 1] = L->data[k];
		}
	}
	L->length--;
	return OK;
}

inline Status SeqList::ListPrint()
{
	for (int k = 0; k < length; ++k)
	{
		std::cout << data[k] << " ";
	}
	return OK;
}



#endif // !SEQLIST_H

