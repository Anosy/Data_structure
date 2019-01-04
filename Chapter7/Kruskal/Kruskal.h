#include<iostream>

using namespace std;

const int MAXEDGE = 20;
const int MAXVEX = 20;
const int INF = 65535;

struct Edge
{
	int begin;
	int end;
	int weight;
};

class MGraph
{
public:
	MGraph();
	~MGraph() {};
	void MiniSpanTree_Kruskal();
private:
	void Swapn(Edge edges[], int i, int j);
	void mysort(Edge edges[]);
	int Find(int parent[], int f);
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
};


MGraph::MGraph()
{
	numEdges = 15;
	numVertexes = 9;

	for (int i = 0; i < numVertexes; i++)/* ��ʼ��ͼ */
	{
		for (int j = 0; j < numVertexes; j++)
		{
			if (i == j)
				arc[i][j] = 0;
			else
				arc[i][j] = arc[j][i] = INF;
		}
	}

	//  �̶���ʼ��
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

	for (int i = 0; i < numVertexes; i++)
	{
		for (int j = i; j < numVertexes; j++)
		{
			arc[j][i] = arc[i][j];
		}
	}
}

// ����ͷ��β��Ȩֵ
void MGraph::Swapn(Edge edges[], int i, int j)
{
	int temp;

	temp = edges[i].begin;
	edges[i].begin = edges[j].begin;
	edges[j].begin = temp;

	temp = edges[i].end;
	edges[i].end = edges[j].end;
	edges[j].end = temp;

	temp = edges[i].weight;
	edges[i].weight = edges[j].weight;
	edges[j].weight = temp;

}

void MGraph::mysort(Edge edges[])
{
	for (int i = 0; i < numEdges; i++)
	{
		for (int j = i + 1; j < numEdges; j++)
		{
			if (edges[i].weight > edges[j].weight)
			{
				Swapn(edges, i, j);
			}
		}
	}
	cout << "Ȩ����֮���Ϊ:\n";
	for (int i = 0; i < numEdges; i++)
	{
		cout <<
			edges[i].begin << " " <<
			edges[i].end << " " <<
			edges[i].weight << endl;
	}
}

int MGraph::Find(int parent[], int f)
{
	while (parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}

/*
����ĺ��ľ���Find������parent����
parent���飺������ķ�����Ϊ�������֡�

	1.����Ԫ�ص�ֵ������parent = {1, 5, 8, 7, 7, 8, 0, 0, 6} ���ȴ�v0��ʼ��parent[0]Ϊ1����ʾ0��1��������,���Ǽٶ�����ΪA��Ȼ��1��Ϊ�±꣬parent[1]Ϊ5
	��ʾ5Ҳ�ڼ���A�У�����parent[5]Ϊ8����ʾ8Ҳ�ڼ���A�ϣ�parent[8]Ϊ6.��ʾ6Ҳ�ڼ���A�ϡ���ʱ��parent[6]Ϊ0.˵��6���ڼ���A�ϡ���ʱ��2��û���࣬parent[2]Ϊ5��
	����5�ڼ���A�ϣ�����2Ҳ�ڼ���A�ϡ�����3��4��û���࣬parent[3]Ϊ7��parent[4]Ϊ7����ʾ3,4,7���Ǽ���A�ģ����������ڼ���B��������ֵΪ0��Ԫ�أ������±�
	�������ˡ��ܽ�ΪA{0,1,2,5,6,8} B{3, 4, 7}����Ȼ�������е��±궼�����ˣ������ڲ�ͬ�ļ����У����ǻ���Ҫ������ںϳ�һ����ļ��ϡ��������ǲ�������ͼ
	���һ����·�������������ѭ���У����ǽ�Ҫ�ҵ�parent���±��ֵΪ0��λ�ã���Ϊ����±��ֵ������±껹û���ߣ�������Ϊ���ǲ���һ�������У����Բ���
	���ֻ�·
	2.��ֵ��ĳ���±��ֵΪ0����ʾ�±�Ϊһ�����ϵľ�ͷ(����˵�˵�)������һ��ʼÿ��Ԫ�ض���һ�����ϣ�Ȼ���ڹ����б��ϲ���һ���󼯺���

Find�����������ҵ��±�n��ʹ���Ը��±��parent[n]��ֵΪ0�����ظ��±�n��
Ŀ�ľ���Ҫ�ҵ�һ�����ϵĶˣ�Ȼ�󽫸ö˸���ֵ��

ʲô�Ƕˣ����ǿ����ü����໥�ϲ������Ҳ����ֻ��ļ����еĵ�

*/
void MGraph::MiniSpanTree_Kruskal()
{
	int n, m;
	int k = 0;
	int parent[MAXVEX];/* ����һ���������жϱ�����Ƿ��γɻ�· */

	Edge edges[MAXEDGE];/* ����߼�����,edge�ĽṹΪbegin,end,weight,��Ϊ���� */

	// �����߽�����
	for (int i = 0; i < numVertexes - 1; i++)
	{
		for (int j = i + 1; j < numVertexes; j++)
		{
			if (arc[i][j] < INF)
			{
				edges[k].begin = i;
				edges[k].end = j;
				edges[k].weight = arc[i][j];
				k++;
			}
		}
	}
	// ����edge����
	mysort(edges);

	// ��ʼ�������ֵΪ0
	for (int i = 0; i < numVertexes; i++)
	{
		parent[i] = 0;
	}

	// �㷨���Ĳ��ִ���
	cout << "��ӡ��С������" << endl;
	for (int i = 0; i < numEdges; i++) // ѭ��ÿһ���� 
	{
		n = Find(parent, edges[i].begin); // ��begin��end�Ƿ�����һ������
		m = Find(parent, edges[i].end);
		if (n != m) /* ����n��m���ȣ�˵���˱�û�������е��������γɻ�· */
		{
			parent[n] = m;	/* ���˱ߵĽ�β��������±�Ϊ����parent�С� */
							/* ��ʾ�˶����Ѿ��������������� */
			cout <<
				edges[i].begin << " " <<
				edges[i].end << " " <<
				edges[i].weight << endl;
		}
	}
}
