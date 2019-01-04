#include<iostream>

using namespace std;

void swap(int arr[], int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

// -------------���������Ż�������ȡ��-------------//
// ����left,mid,right��λ�ã���֤left��mid��right���м�ֵ
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

	temp = a[left]; // temp�д���Ż�׼��
	i = left;
	j = right;
	while (i != j)
	{
		// �ȴ��ұ߿�ʼ��
		// �������a[j]���ڵ���temp�ģ�������λ��ֱ�����ֱ�tempС��a[j]Ϊֹ
		while (a[j] >= temp && i < j)
		{
			j--;
		}
		// �������a[i]С�ڵ���temp�ģ�����λ�ƣ�ֱ�����ֱ�temp���a[i]Ϊֹ
		while (a[i] <= temp && i < j)
		{
			i++;
		}
		// �����ҵ��������㣬��ô�������ߵ�ֵ
		if (i < j)
		{
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	// i==j��������֣�������׼���͵�ǰ����λ�õ�ֵ
	a[left] = a[i];
	a[i] = temp;
	QuickSort(a, left, i - 1);
	QuickSort(a, i + 1, right);
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

	QuickSort(a, 0, len - 1);

	cout << "����������" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}