#include<iostream>
#include<ctime>
#include<cstring>

using namespace std;

void get_next(const char *T, int *next)
{
	// 就是模式串自己的比较过程
	unsigned i = 0; // i的起始位置为0，
	int j = -1;  // j=-1,说明没有可能有前后缀交集，从而j将会从0开始，并且让下一个位置next[i] = 0
	next[0] = -1; // next数组的0的位置规定为-1

	while (i < strlen(T)) // i的范围为0~(len-1)
	{
		if (j == -1 || T[i] == T[j])
			/*
			如果j==-1进入，则直接进入循环。表示让j从0开始，让i也从下一个位置开始，重新比较。也就是没后缀和前缀相等的可能性了，从头来过
			如果T[i] = T[j]， 则说明这个位置存在公共前缀和后缀，所以i++,j++表示都移动到下一个位置进行比较，并且next[i] = j。表示i的位置前存在
			j个前缀和后缀的交集
			*/
		{
			i++;
			j++;
			next[i] = j;
		}
		/*
		如果存在这时候出现T[i] != T[j]。
		前提说明，说明i的位置之前存在next[i]个前后缀交集，也就是出现在0~next[i]+1这个位置。
		j位置存在next[j]个前后缀交集，也就是出现在0~next[j]+1这个位置。
		这时候，如果T[i] != T[j]，那么是否这个位置前后缀交集就应该是0呢？不是的！！
		重新比较j之前是否有出现能够使得前后缀有交集的。那么怎么找呢？
		首先j的位置之前有没有前后缀有交集的，有说明有一部分是和上面那条(i前)位置有交集的。那么我们就找到有交集的位置
		也就是下面条出现前后缀有交集的位置开始寻找，即j = next[j]
		这时候j前的位置一定是和i前的位置有交集的，只要判断这个时候的T[i] 和 T[j]的关系就行.如果再没有交集，再往前找其还有前后缀交集的地方，
		直到找到j=-1位置，从而放弃这个位置，i和j都重新后移
		*/
		else
		{
			j = next[j];
		}
	}
}

// 改进next
void get_nextval(const char *T, int *nextval)
{
	int j = -1;
	int i = 0;
	nextval[0] = -1;
	while (i < strlen(T))
	{
		if (j == -1 || T[i] == T[j])
		{
			++i;
			++j;
			if (T[i] != T[j])
			{
				nextval[i] = j;
			}
			else
			{
				nextval[i] = nextval[j];
			}
		}
		else
		{
			j = nextval[j];
		}
	}
}



int KMP(const char *S, const char *T)
{
	// 两个数组的位置都从0开始
	unsigned i = 0;
	int j = 0;

	// 先求next数组
	int next[20]; // 初始化一个空的数组,长度要足够长
	int nextval[20];
	//get_next(T, next);
	get_nextval(T, nextval);

	/*cout << "next表为：" << endl;
	for (int c : next)
	{
		cout << c << " ";
	}
	cout << endl;*/

	/*cout << "nextval表为：" << endl;
	for (int c : nextval)
	{
		cout << c << " ";
	}
	cout << endl;*/

	while (i < strlen(S))  // i的范围为0~(len(S) - 1)
	{
		/*
		如果j = -1，表示没有前后缀的交集，并且让i移动到下一个位置，j从0第一个位置开始
		如果S[i] == T[j],说明当前两条的位置是相同的，所以移动到下一个位置来接着判断
		*/

		if (j == -1 || S[i] == T[j])
		{
			i++;
			j++;
		}
		/*
		如果相同，让j回溯到存在最大前后缀交集的地方。
		原因：因为现在i位置前的位置是都和j位置前的位置是相同的，至少j和i位置的元素不同。但是j位置前存在前后缀相同的，所以
		假设j前面有相同的k位交集，那么T串的i前k位到i是和 S串的0~k-1是相同的，这时候只要判断i和k的位置是否相同。而k由next的定义刚刚好为next[j]
		*/
		else
		{
			//j = next[j];
			j = nextval[j];
		}
	}
	if (j == strlen(T))
		// 如果j到了最后一个位置的后一个位置，说明j已经被读取完了，说明T被匹配了，所以出现匹配的位置为i-j
		//，否则return -1  表示没有匹配
		return i - j;
	else
		return -1;
}


int main()
{
	auto start = clock();  //开始时间
	cout << "开始KMP" << endl;
	const char t[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	const char p[] = "ab";

	for (int i = 0; i < 2000; i++)
	{
		cout << KMP(t, p) << endl;
	}

	auto finish = clock();   //结束时间
	//cout << finish - start << endl; // 输出运行时间
	
	cout << "The run time is: " << (double)(finish - start) / CLOCKS_PER_SEC << "s" << endl;
	system("pause");
	return 0;
}