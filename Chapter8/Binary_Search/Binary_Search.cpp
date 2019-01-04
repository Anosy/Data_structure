#include<iostream>

using namespace std;

//int Binary_Search(int *a, int n, int key)
//{
//	int low = 1;
//	int mid;
//	int high = n;
//	
//	while (low <= high)
//	{
//		mid = (low + high) / 2;
//		if (key < a[mid])
//		{
//			high = mid - 1;
//		}
//		else if (key > a[mid])
//		{
//			low = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return 0;
//}

int Binary_Search2(int a[], int size, int key)
{
	int low = 0;
	int mid;
	int high = size;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key < a[mid])
		{
			high = mid - 1;
		}
		else if (key > a[mid])
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
	int a[] = { 1, 16, 26, 36, 45, 55, 69, 72, 81, 99};
	//int result = Binary_Search(a, 10, 55);
	int result = Binary_Search2(a, 10, 36);

	cout << result << endl;

	system("pause");
	return 0;
}