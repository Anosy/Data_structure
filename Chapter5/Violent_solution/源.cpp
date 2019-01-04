#include<iostream>
#include<ctime>
#include<cstring>

using namespace std;

int Violent_search(const char S[], const char T[])
{
	unsigned i = 0;
	unsigned j = 0;

	while (i < strlen(S) && j < strlen(T))
	{
		if (S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= strlen(T))
	{
		return i - strlen(T);
	}
	else
	{
		return -1;
	}
}


int main()
{
	const char t[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	const char p[] = "aaaaaaab";

	cout << "在主串中匹配的位置为：";
	cout << Violent_search(t, p) << endl;
	
	system("pause");
	return 0;
}