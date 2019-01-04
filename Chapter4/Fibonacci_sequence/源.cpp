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

int main()
{
	for (int k = 0; k < 40; k++)
	{
		cout << Fib(k) << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
