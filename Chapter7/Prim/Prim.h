#include<iostream>
#include<queue>
#include<stack>

using namespace std;

const int MAXSIZE = 10;
const int INF = 65535;

template <typename T>
class Prim_MGraph
{
public:
	Prim_MGraph(int n = 9, int e = 15); // n�����㣬e����
	~Prim_MGraph() {}
	void MiniSpanTree_Prim();

private:
	int arc[MAXSIZE][MAXSIZE]; // ��űߵ�����
	int vertexNum, arcNum; // ͼ�ж���ͱߵ���Ŀ
};


template<typename T>
inline Prim_MGraph<T>::Prim_MGraph(int n, int e)
{
	vertexNum = n;
	arcNum = e;

	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			if (i == j)
				arc[i][j] = 0;
			else
				arc[i][j] = arc[j][i] = INF;
		}
	}

	arc[0][1] = 10;
	arc[0][5] = 11;
	arc[1][2] = 18;
	arc[1][8] = 12;
	arc[1][6] = 16;
	arc[2][8] = 8;
	arc[2][3] = 22;
	arc[3][8] = 21;
	arc[3][6] = 24;
	arc[3][7] = 16;
	arc[3][4] = 20;
	arc[4][7] = 7;
	arc[4][5] = 26;
	arc[5][6] = 17;
	arc[6][7] = 19;


	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = i; j < vertexNum; j++)
		{
			arc[j][i] = arc[i][j];
		}
	}


	/*cout << "�����±�i���±�j����Ȩֵw��\n";
	for (int k = 0; k < arcNum; k++)
	{
		int i, j, w;
		cin >> i >> j >> w;
		arc[i][j] = w;
		arc[j][i] = w;
	}*/

}


/*
prim�㷨ԭ��
���ľ��ǹ���lowcost�����adjvex����
lowcost���飺�������������н�������ı�Ȩֵ��С�Ľ����±ꡣ����ֵ0����ʾ�ý���Ѿ��������ˣ��Ͳ��ÿ�����
adjvex���飬���������Ͻ�����ӵ����н����±ꡣ����[0, 0, 1, 0]����ʾv0��v1�Ѿ��������ˣ���v2��v1������v3��v0����
��ѭ����ѭ�����еĽ�㣺
	�ҵ������ϵĽ�����ӵı�Ȩֵ��С�Ľ�㣬���Ҵ�ӡ��Ȼ�����lowcostֵ��0����ʾ�ý���Ѿ���������
	�ٽ���ý���������ӵıߵ�Ȩֵ����ӵ�lowcost�У����ҽ����������Ľ�����ӵ�adjvex��

*/
template<typename T>
inline void Prim_MGraph<T>::MiniSpanTree_Prim()
{
	int min, j, k;
	int adjvex[MAXSIZE]; // ������ض����±�
	int lowcost[MAXSIZE]; // ������ض����ߵ�Ȩֵ
	lowcost[0] = 0; // ��ʼ����һ��Ȩֵ��lowcost��ֵΪ0����ʾvo�Ѿ����뵽��С������
	adjvex[0] = 0; // ��ʼ����һ�������±�

	for (int i = 1; i < vertexNum; i++)
	{
		lowcost[i] = arc[0][i]; // ��������֮�бߵ�Ȩֵ������ŵ�������
		adjvex[i] = 0; // ��ʼv0���±�
	}
	//���ϵĹ���Ϊ��ʼ�����̣��Ѿ��������v0��ʼ�����ҽ�lowcast��adrjvex���Ѿ���ʼ������

	// ���µ�ѭ�����ǹ�����С�������Ĺ���
	for (int i = 1; i < vertexNum; i++) // ѭ��vertexNum�������-1�Σ���Ϊv0�Ѿ�����������
	{
		min = INF;
		j = 1;
		k = 0;
		while (j < vertexNum)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j]; // min�������lowcast����С��Ȩֵ
				k = j; // ������СȨֵ���±�
			}
			j++;
		}
		cout << "��ǰ����Ȩֵ��С�ıߣ�" << "v" << adjvex[k] << "-v" << k << endl; // ��ӡ��ǰ������Ȩֵ��С�ı�
		lowcost[k] = 0; // ����ǰ�����Ȩֵ����Ϊ0����ʾ�ö����Ѿ����뵽��С������
		
		for (int j = 1; j < vertexNum; j++)
		{
			// ѭ����k���������н�㣬��k��㸽�����ӽ���Ȩֵ�����뵽lowcost�У�
			// adjvex��ʾ���������Ͻ�������ӵĽ����±꣬��[0, 0, 1, 1...]  ��ʾ1��0������2��1������ 3��1��������0��1�����������ϵĽ��
			if (lowcost[j] != 0 && arc[k][j] < lowcost[j])
			{
				lowcost[j] = arc[k][j];
				adjvex[j] = k;
			}
		}
	
	}
}


