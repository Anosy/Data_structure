#ifndef SEQLIST_H
#define SEQLIST_H


#include<iostream>
#include<stdexcept>
// ˳�������б�L��,1 << i  << ListLength(L),��λ���ǰ���1��ʼ�����

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
	Status GetElem(SeqList L, int i, ElemType *e); // ��ȡԪ��
	Status ListInsert(SeqList *L, int i, ElemType e); // ����
	Status ListDelete(SeqList *L, int i, ElemType *e); // ɾ��
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
		throw std::out_of_range("�Ƿ�����");
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
	*e = L.data[i - 1]; // ˳���б��е�i����������Ӧ����i-1
	return OK;
}

inline
Status SeqList::ListInsert(SeqList * L, int i, ElemType e)
{
	if (L->length == MAXSIZE) // ����б��Ѿ����������ĳ���
	{
		return ERROR;
	}
	if (i > L->length || i < 1) // ��������λ�ò������߼�
	{
		return ERROR;
	}
	if (i < L->length) // ������뵽�б���м�
	{
		for (int k = L->length - 1; k >= i - 1; --k) // �������λ�ú���Ķ�����ƶ�һλ
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
	if (L->length == 0) // ����б�ĳ���Ϊ0
	{
		return ERROR;
	}
	if (i < 1 || i > L->length) // ɾ�������ڵ�λ��
	{
		return ERROR;
	}
	*e = L->data[i - 1];
	if (i < L->length) // ���ɾ����λ�ò������һ��Ԫ��
	{
		for (int k = i; k < L->length; ++k) // ��ɾ����λ�ú��Ԫ�ض���ǰ�ƶ�һλ
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

