#include<iostream>

using namespace std;

void mergearray(int a[], int frist, int mid, int last, int temp[])
{
	int i = frist, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	// �Ƚ��������еĶ�Ӧλ�ã�����С��ֵ�����뵽temp�����У�ֱ����һ��ȫ�������뵽tempΪֹ
	while (i <= m && j <=n)
	{
		if (a[i] <= a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}

	// ��ĳһ��ʣ�µ�ȫ�����뵽temp�ĺ��棬��Ϊʣ��Ҳ�������
	while (i <= m)
	{
		temp[k++] = a[i++];
	}
	while (j <= n)
	{
		temp[k++] = a[j++];
	}

	// ��ֵ�����¸�ֵ��a��first��ʼ��λ�ã�����Ϊk
	for (int i = 0; i < k; i++)
	{
		a[frist + i] = temp[i];
	}
}

void mergesort(int a[], int frist, int last, int temp[])
{
	if (frist < last)
	{
		int mid = (frist + last) / 2;
		mergesort(a, frist, mid, temp);
		mergesort(a, mid + 1, last, temp);
		mergearray(a, frist, mid, last, temp);
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

	int *p = new int[len];
	mergesort(a, 0, len - 1, p);

	cout << "����������" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;

	delete[] p; // ɾ����̬����

	system("pause");
	return 0;
}