#include<iostream>

using namespace std;

// ���ҵ���Сֵ��Ȼ���ж��Ƿ񽻻�
void SelectSort(int a[], int n)
{
	for (int i = 1; i < n - 1; i++)
	{
		int min = i;
		for (int j = i+1; j <= n - 1; j++)
		{
			if (a[min] > a[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			int temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
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

	SelectSort(a, len);

	cout << "����������" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}