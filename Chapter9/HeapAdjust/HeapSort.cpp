#include<iostream>

using namespace std;

void HeapAdjust(int a[], int parent, int length)
{
	int temp = a[parent];   // temp得到当前双亲结点的值
	int child = 2 * parent + 1; // 得到左孩子

	while (child < length)
	{
		// 如果存在右结点，并且左结点的值小于右结点的值, 选择右结点
		if (child + 1 < length && a[child] < a[child + 1])
		{
			child++; 
		}

		// 如果双亲结点的值大于其孩子结点的值，那么就结束循环
		if (temp >= a[child])
		{
			break;
		}

		// 将孩子节点的值给双亲结点
		a[parent] = a[child]; 

		// 选择孩子结点的左孩子结点，继续向下筛选
		parent = child;
		child = 2 * child + 1;
	}
	a[parent] = temp;
}

void HeapSort(int a[], int length)
{
	// 循环构建初始堆
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		HeapAdjust(a, i, length);
	}

	// 打印初始堆
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	// 进行n-1次循环，完成排序
	for (int i = length - 1; i > 0; i--)
	{
		// 交换最后一个元素和第一个元素
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		
		// 重新调整堆
		HeapAdjust(a, 0, i);
		cout << "第" << length - i << "次堆调整	" << endl;
	}
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

	HeapSort(a, len);

	cout << "排序后的数组" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}