#include<iostream>

using namespace std;

//基本思想为每一趟从待排序的数据元素中选择最小（或最大）的一个元素作为首元素，直到所有元素排完为止
void InsertSort(int a[], int n)
{
	int i, j, k; 
	// 从a[1]开始，表示a[0]以及排序好了
	for (i = 1; i < n; i++)
	{
		// 从i的前一个元素开始到第一个元素为止倒序，寻找插入的位置。即找到比a[i]小的位置，我们将在j的后面一个位置j+1插入
		for (j = i-1; j >= 0; j--)
		{
			if (a[j] < a[i])
			{
				break;
			}
		}
		// 找到了位置j
		if (i - 1 != j)
		{
			int temp = a[i];
			for (k = i - 1; k > j; k--)  // 将j之后到i之前的元素向后移动一位
			{
				a[k + 1] = a[k];
			}
			a[k + 1] = temp;
		}
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

	InsertSort(a, len);

	cout << "排序后的数组" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}