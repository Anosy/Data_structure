#include<iostream>

using namespace std;

int Fib(int i)
{
	if (i < 2)
	{
		return i == 0 ? 0 : 1;
	}
	return Fib(i - 1) + Fib(i - 2);
}

int Fibonacci_Search(int a[], int F[], int n, int key)
{
	int low = 0;
	int high = n;
	int mid;
	int k = 0;
	while (n > F[k] - 1) // 计算在Fib数组中的位置
	{
		k++;
	}

	for (int i = n; i < F[k] - 1; i++) // 将不满的数值补全
	{
		a[i] = a[n];
	}

	while (low <= high)
	{
		mid = low + F[k - 1] - 1; // 计算当前的分隔下标
		if (key < a[mid])
		{
			high = mid - 1;
			k = k - 1;
		}
		else if(key > a[mid])
		{
			low = mid + 1;
			k = k - 2;
		}
		else
		{
			if (mid <= n)
			{
				return mid;
			}
			else
			{
				return n;
			}
		}
	}
	return -1;
}


int main()
{
	int a[20] = { 1, 16, 26, 36, 45, 55, 69, 72, 81, 99 };
	int F[10];
	for (int i = 0; i < 10; i++)
	{
		F[i] = Fib(i);
	}
	int result = Fibonacci_Search(a, F, 10, 45);

	cout << result << endl;

	system("pause");
	return 0;
}