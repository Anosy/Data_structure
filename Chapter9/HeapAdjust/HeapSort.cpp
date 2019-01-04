#include<iostream>

using namespace std;

void HeapAdjust(int a[], int parent, int length)
{
	int temp = a[parent];   // temp�õ���ǰ˫�׽���ֵ
	int child = 2 * parent + 1; // �õ�����

	while (child < length)
	{
		// ��������ҽ�㣬���������ֵС���ҽ���ֵ, ѡ���ҽ��
		if (child + 1 < length && a[child] < a[child + 1])
		{
			child++; 
		}

		// ���˫�׽���ֵ�����亢�ӽ���ֵ����ô�ͽ���ѭ��
		if (temp >= a[child])
		{
			break;
		}

		// �����ӽڵ��ֵ��˫�׽��
		a[parent] = a[child]; 

		// ѡ���ӽ������ӽ�㣬��������ɸѡ
		parent = child;
		child = 2 * child + 1;
	}
	a[parent] = temp;
}

void HeapSort(int a[], int length)
{
	// ѭ��������ʼ��
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		HeapAdjust(a, i, length);
	}

	// ��ӡ��ʼ��
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	// ����n-1��ѭ�����������
	for (int i = length - 1; i > 0; i--)
	{
		// �������һ��Ԫ�غ͵�һ��Ԫ��
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		
		// ���µ�����
		HeapAdjust(a, 0, i);
		cout << "��" << length - i << "�ζѵ���	" << endl;
	}
}

int main()
{
	int a[] = { 2,3,5,1,4,7,6,10,9,8 };
	int len = sizeof(a) / sizeof(a[0]);


	cout << "����ǰ������" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	HeapSort(a, len);

	cout << "����������" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}