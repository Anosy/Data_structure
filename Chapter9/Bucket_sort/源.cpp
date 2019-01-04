#include<iostream>
using namespace std;

void Bucket_Sort(int a[], int length)
{
	int b[100];
	for (int i = 0; i < 100; i++)
	{
		b[i] = 0;
	}
	for (int i = 0; i < length; i++)
	{
		b[a[i]]++;
	}
	for (int i = 0; i < 100; i++)
	{
		for (int j = 1; j <= b[i]; j++)
		{
			cout << i << " ";
		}
	}
	cout << endl;
}

int main()
{
	int a[] = { 2,3,1,6,9,7,5,8,4,4 };
	int length = sizeof(a) / sizeof(a[0]);
	Bucket_Sort(a, length);

	system("pause");
	return 0;
}