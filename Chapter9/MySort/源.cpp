/*
本代码记录了全部的排序算法
1.冒泡排序
*/
#include<iostream>
using namespace std;


// 交换操作
void swap(int arr[], int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

// ------冒泡排序-------
void BubbleSort0(int a[], int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i+1; j < length; j++)
		{
			if (a[i]> a[j])
			{
				swap(a, i, j);
			}
		}
	}
}
void BubbleSort1(int a[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = length - 2; j >= i; j--)
		{
			if (a[j] > a[j+1])
			{
				swap(a, j, j + 1);
			}
		}
	}
}
void BubbleSort2(int a[], int length)
{
	for (int i = 0; i < length-1; i++)
	{
		bool flag = 1;

		for (int j = length - 2; j >= i; j--)
		{
			if (a[j] > a[j + 1])
			{
				swap(a, j, j + 1);
				flag = 0;
			}
		}

		if (flag == 1)
		{
			break;
		}
	}
}

// ------简单选择排序-------
void SelectSort(int a[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(a, i, min);
		}
	}
}

// ------直接插入排序-------
void InsertSort(int a[], int length)
{
	int i, j, k;
	for (i = 1; i < length; i++)
	{
		for (j = i-1; j >= 0; j--)
		{
			if (a[i] > a[j])
			{
				break;
			}
		}
		if (j != i-1)
		{
			int temp = a[i];
			for (k = i - 1; k > j; k--)
			{
				a[k + 1] = a[k];
			}
			a[k + 1] = temp;
		}
	}
}

// ------希尔排序-------
void ShellSort(int a[], int length)
{
	int i, j, temp;
	int increment = length;
	
	do
	{
		increment = increment / 3 + 1;
		for ( i = increment; i < length; i++)
		{
			if (a[i - increment] > a[i])
			{
				temp = a[i];
				for ( j = i - increment; j >= 0 && temp < a[j] ; j -= increment )
				{
					a[j + increment] = a[j];
				}
				a[j + increment] = temp;
			}
		}
	} while (increment > 1);
}

// ------堆排序-------
void HeapAdjust(int a[], int parent, int length)
{
	int temp = a[parent];
	int child = parent * 2 + 1;

	while (child < length)
	{
		if (child + 1 < length && a[child] < a[child + 1])
		{
			child++;
		}

		if (a[child] <= temp)
		{
			break;
		}

		a[parent] = a[child];
		parent = child;
		child = child * 2 + 1;
	}
	a[parent] = temp;
}

void HeapSort(int a[], int length)
{
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		HeapAdjust(a, i, length);
	}

	for (int j = length - 1; j >0; j--)
	{
		swap(a, j, 0);
		HeapAdjust(a, 0, j);
	}
}

// ------归并排序-------
void MergeArray(int a[], int left, int right, int temp[])
{
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= right)
	{
		if (a[i] < a[j])
		{
			temp[k++] = a[i++];
		}
		if (a[i] > a[j])
		{
			temp[k++] = a[j++];
		}
	}
	while (i <= mid)
	{
		temp[k++] = a[i++];
	}
	while (j <= right)
	{
		temp[k++] = a[j++];
	}

	for (int i = 0; i < k; i++)
	{
		a[left + i] = temp[i];
	}
}

void MergerSort(int a[], int left, int right, int temp[])
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergerSort(a, left, mid, temp);
		MergerSort(a, mid + 1, right, temp);
		MergeArray(a, left, right, temp);
	}
}

// ------快速排序-------
void dealPivot(int a[], int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] > a[right])
	{
		swap(a, left, right);
	}
	if (a[mid] > a[right])
	{
		swap(a, mid, right);
	}
	if (a[left] < a[mid])
	{
		swap(a, left, mid);
	}
}



void QuickSort(int a[], int left, int right)
{
	if (left < right)
	{
		dealPivot(a, left, right);

		int privot = a[left];
		int i = left;
		int j = right;

		while (i != j)
		{
			while (a[j] >= privot && i < j)
			{
				j--;
			}
			while (a[i] <= privot && i < j)
			{
				i++;
			}
			if (i < j)
			{
				swap(a, i, j);
			}
		}
		a[left] = a[i];
		a[i] = privot;
		QuickSort(a, left, i - 1);
		QuickSort(a, i + 1, right);
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


	// 排序算法
	
	//BubbleSort0(a, len);
	//BubbleSort1(a, len);
	//BubbleSort2(a, len);
	//SelectSort(a, len);
	//InsertSort(a, len);
	//ShellSort(a, len);
	//HeapSort(a, len);
	//int *p = new int[len];
	//MergerSort(a, 0, len - 1, p);
	QuickSort(a, 0, len - 1);

	cout << "排序后的数组" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	//delete[] p;

	system("pause");
	return 0;
}