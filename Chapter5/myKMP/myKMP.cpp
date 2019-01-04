#include<iostream>
#include<ctime>
#include<cstring>

using namespace std;

void get_next(const char *T, int *next)
{
	// ����ģʽ���Լ��ıȽϹ���
	unsigned i = 0; // i����ʼλ��Ϊ0��
	int j = -1;  // j=-1,˵��û�п�����ǰ��׺�������Ӷ�j�����0��ʼ����������һ��λ��next[i] = 0
	next[0] = -1; // next�����0��λ�ù涨Ϊ-1

	while (i < strlen(T)) // i�ķ�ΧΪ0~(len-1)
	{
		if (j == -1 || T[i] == T[j])
			/*
			���j==-1���룬��ֱ�ӽ���ѭ������ʾ��j��0��ʼ����iҲ����һ��λ�ÿ�ʼ�����±Ƚϡ�Ҳ����û��׺��ǰ׺��ȵĿ������ˣ���ͷ����
			���T[i] = T[j]�� ��˵�����λ�ô��ڹ���ǰ׺�ͺ�׺������i++,j++��ʾ���ƶ�����һ��λ�ý��бȽϣ�����next[i] = j����ʾi��λ��ǰ����
			j��ǰ׺�ͺ�׺�Ľ���
			*/
		{
			i++;
			j++;
			next[i] = j;
		}
		/*
		���������ʱ�����T[i] != T[j]��
		ǰ��˵����˵��i��λ��֮ǰ����next[i]��ǰ��׺������Ҳ���ǳ�����0~next[i]+1���λ�á�
		jλ�ô���next[j]��ǰ��׺������Ҳ���ǳ�����0~next[j]+1���λ�á�
		��ʱ�����T[i] != T[j]����ô�Ƿ����λ��ǰ��׺������Ӧ����0�أ����ǵģ���
		���±Ƚ�j֮ǰ�Ƿ��г����ܹ�ʹ��ǰ��׺�н����ġ���ô��ô���أ�
		����j��λ��֮ǰ��û��ǰ��׺�н����ģ���˵����һ�����Ǻ���������(iǰ)λ���н����ġ���ô���Ǿ��ҵ��н�����λ��
		Ҳ��������������ǰ��׺�н�����λ�ÿ�ʼѰ�ң���j = next[j]
		��ʱ��jǰ��λ��һ���Ǻ�iǰ��λ���н����ģ�ֻҪ�ж����ʱ���T[i] �� T[j]�Ĺ�ϵ����.�����û�н���������ǰ���仹��ǰ��׺�����ĵط���
		ֱ���ҵ�j=-1λ�ã��Ӷ��������λ�ã�i��j�����º���
		*/
		else
		{
			j = next[j];
		}
	}
}

// �Ľ�next
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
	// ���������λ�ö���0��ʼ
	unsigned i = 0;
	int j = 0;

	// ����next����
	int next[20]; // ��ʼ��һ���յ�����,����Ҫ�㹻��
	int nextval[20];
	//get_next(T, next);
	get_nextval(T, nextval);

	/*cout << "next��Ϊ��" << endl;
	for (int c : next)
	{
		cout << c << " ";
	}
	cout << endl;*/

	/*cout << "nextval��Ϊ��" << endl;
	for (int c : nextval)
	{
		cout << c << " ";
	}
	cout << endl;*/

	while (i < strlen(S))  // i�ķ�ΧΪ0~(len(S) - 1)
	{
		/*
		���j = -1����ʾû��ǰ��׺�Ľ�����������i�ƶ�����һ��λ�ã�j��0��һ��λ�ÿ�ʼ
		���S[i] == T[j],˵����ǰ������λ������ͬ�ģ������ƶ�����һ��λ���������ж�
		*/

		if (j == -1 || S[i] == T[j])
		{
			i++;
			j++;
		}
		/*
		�����ͬ����j���ݵ��������ǰ��׺�����ĵط���
		ԭ����Ϊ����iλ��ǰ��λ���Ƕ���jλ��ǰ��λ������ͬ�ģ�����j��iλ�õ�Ԫ�ز�ͬ������jλ��ǰ����ǰ��׺��ͬ�ģ�����
		����jǰ������ͬ��kλ��������ôT����iǰkλ��i�Ǻ� S����0~k-1����ͬ�ģ���ʱ��ֻҪ�ж�i��k��λ���Ƿ���ͬ����k��next�Ķ���ոպ�Ϊnext[j]
		*/
		else
		{
			//j = next[j];
			j = nextval[j];
		}
	}
	if (j == strlen(T))
		// ���j�������һ��λ�õĺ�һ��λ�ã�˵��j�Ѿ�����ȡ���ˣ�˵��T��ƥ���ˣ����Գ���ƥ���λ��Ϊi-j
		//������return -1  ��ʾû��ƥ��
		return i - j;
	else
		return -1;
}


int main()
{
	auto start = clock();  //��ʼʱ��
	cout << "��ʼKMP" << endl;
	const char t[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	const char p[] = "ab";

	for (int i = 0; i < 2000; i++)
	{
		cout << KMP(t, p) << endl;
	}

	auto finish = clock();   //����ʱ��
	//cout << finish - start << endl; // �������ʱ��
	
	cout << "The run time is: " << (double)(finish - start) / CLOCKS_PER_SEC << "s" << endl;
	system("pause");
	return 0;
}