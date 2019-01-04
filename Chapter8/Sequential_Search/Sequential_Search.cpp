#include<iostream>

using namespace std;


int Sequential_Search_1(int *a, int n, int key)
{
	for (int i = 0; i <= n; i++)
	{
		if (a[i] == key)
		{
			return i;
		}
	}
	return 0;
}

// 优化方法：带哨兵
int Sequential_Search_2(int *a, int n, int key)
{
	a[n] = key; //在数组尾部设置一个哨兵，从而减少了每次循环需要判断i是否越界
	int i = 0;
	while (a[i] != key)
	{
		i++;
	}
	return i; // 返回n说明查找失败
}


int main()
{
	int a[10] = { 0, 1, 2, 3, 4 };
	int result1 = Sequential_Search_1(a, 5, 3);

	int result2 = Sequential_Search_2(a, 5, 10);

	cout << result1 << endl;

	cout << result2 << endl;

	system("pause");
	return 0;
}