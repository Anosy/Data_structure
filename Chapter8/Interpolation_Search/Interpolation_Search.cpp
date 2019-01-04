#include<iostream>

using namespace std;

int Interpolation_Search(int a[], int n, int key)
{
	int low = 0;
	int mid;
	int high = n;

	while (low <= high)
	{
		mid = low + (high - low) * (key - a[low]) / (a[high] - a[low]);
		if (key < a[mid])
		{
			high = mid - 1;
		}
		else if(key > a[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int a[] = { 1, 16, 26, 36, 45, 55, 69, 72, 81, 99 };
	int result = Interpolation_Search(a, 10, 55);

	cout << result << endl;

	system("pause");
	return 0;
}