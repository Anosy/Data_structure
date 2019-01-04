#include<iostream>

using namespace std;

void swap(int arr[], int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

// -------------快速排序优化：三数取中-------------//
// 交换left,mid,right的位置，保证left是mid和right的中间值
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
	if (a[mid] > a[left])
	{
		swap(a, mid, left);
	}
}

void QuickSort(int a[], int left, int right)
{
	int i, j, temp;
	if (left > right)
	{
		return;
	}

	dealPivot(a, left, right);

	temp = a[left]; // temp中存放着基准数
	i = left;
	j = right;
	while (i != j)
	{
		// 先从右边开始找
		// 如果遇到a[j]大于等于temp的，向左移位，直到出现比temp小的a[j]为止
		while (a[j] >= temp && i < j)
		{
			j--;
		}
		// 如果遇到a[i]小于等于temp的，向右位移，直到出现比temp大的a[i]为止
		while (a[i] <= temp && i < j)
		{
			i++;
		}
		// 假如找到了两个点，那么交换两者的值
		if (i < j)
		{
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	// i==j的情况出现，交换基准数和当前相遇位置的值
	a[left] = a[i];
	a[i] = temp;
	QuickSort(a, left, i - 1);
	QuickSort(a, i + 1, right);
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

	QuickSort(a, 0, len - 1);

	cout << "排序后的数组" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}