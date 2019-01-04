#include<iostream>

using namespace std;

void ShellSort(int a[], int n)
{
	int i, j;
	int increment = n;
	do
	{
		increment = increment / 3 + 1; // 增量
		// 首先是i从increment开始
		for (i = increment; i < n; i++)
		{
			// 以increment为间隔，找出是否存在后向比前向小的情况出现，如果出现然后进行直接插入排序
			if (a[i - increment] > a[i])
			{
				int temp = a[i];
				for (j = i - increment; j >= 0 && temp < a[j]; j -= increment)
				{
					a[j + increment] = a[j];
				}
				a[j + increment] = temp;
			}
		}
	} while (increment > 1);
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

	ShellSort(a, len);

	cout << "排序后的数组" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}