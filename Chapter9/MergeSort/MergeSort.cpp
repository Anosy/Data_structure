#include<iostream>

using namespace std;

void mergearray(int a[], int frist, int mid, int last, int temp[])
{
	int i = frist, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	// 比较两个序列的对应位置，将较小的值给放入到temp数组中，直到有一方全部都加入到temp为止
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

	// 将某一方剩下的全部加入到temp的后面，因为剩下也是有序的
	while (i <= m)
	{
		temp[k++] = a[i++];
	}
	while (j <= n)
	{
		temp[k++] = a[j++];
	}

	// 将值给重新赋值给a的first开始的位置，长度为k
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


	cout << "排序前的数组" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	int *p = new int[len];
	mergesort(a, 0, len - 1, p);

	cout << "排序后的数组" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;

	delete[] p; // 删除动态数组

	system("pause");
	return 0;
}