#include<iostream>

using namespace std;

//����˼��Ϊÿһ�˴Ӵ����������Ԫ����ѡ����С������󣩵�һ��Ԫ����Ϊ��Ԫ�أ�ֱ������Ԫ������Ϊֹ
void InsertSort(int a[], int n)
{
	int i, j, k; 
	// ��a[1]��ʼ����ʾa[0]�Լ��������
	for (i = 1; i < n; i++)
	{
		// ��i��ǰһ��Ԫ�ؿ�ʼ����һ��Ԫ��Ϊֹ����Ѱ�Ҳ����λ�á����ҵ���a[i]С��λ�ã����ǽ���j�ĺ���һ��λ��j+1����
		for (j = i-1; j >= 0; j--)
		{
			if (a[j] < a[i])
			{
				break;
			}
		}
		// �ҵ���λ��j
		if (i - 1 != j)
		{
			int temp = a[i];
			for (k = i - 1; k > j; k--)  // ��j֮��i֮ǰ��Ԫ������ƶ�һλ
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


	cout << "����ǰ������" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	InsertSort(a, len);

	cout << "����������" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}