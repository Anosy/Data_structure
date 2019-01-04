#include<iostream>

using namespace std;


// ��ÿһ��i����i��������е������бȽ�
void BubbleSort0(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j <= n -1; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}

// ÿһ��ѭ����ֻ�Ƚ����ڵ�������
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 2 ; j >= i; j--)
		{
			if (a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

// �������flag,��һ��ѭ���У�flag����0��ʾû�н��н�������������ֱ��ֹͣ����ʾ�Լ��������
void BubbleSort2(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (int j = n - 2; j >= i; j--)
		{
			if (a[j] > a[j+1])
			{
				int temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}


int main()
{
	int a[] = { 2,3,5,1,4,7,6,10,9,8 };
	//int a[] = { 2,1,3,4,5 };
	int len = sizeof(a) / sizeof(a[0]);

	cout << "����ǰ������" << endl;	
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	//BubbleSort0(a, len);
	//BubbleSort(a, len);
	BubbleSort2(a, len);

	cout << "����������" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}