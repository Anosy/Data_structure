//#include"BiTree.h"
#include"myBiTree.h"

using namespace std;

int main()
{
	myBiTree<char> bitree;        
	cout << "ǰ�����" << endl;
	bitree.PreOrder();                            
	cout << endl;
	
	cout << "�ǵݹ��ǰ�����" << endl;
	bitree.Iteration_PreOrder();
	cout << endl;

	cout << "�������" << endl;
	bitree.InOrder();                             
	cout << endl;

	cout << "�ǵ������������" << endl;
	bitree.Iteration_InOrder();                         
	cout << endl;

	cout << "�������" << endl;
	bitree.PostOrder();                            
	cout << endl;

	cout << "�ǵ�����������" << endl;
	bitree.IterationPostOrder();                    
	cout << endl;

	cout << "�������" << endl;
	bitree.LevelOrder();    
	cout << endl;

	cout << "ȫ����������" << endl;
	cout << bitree.CountAllNode() << endl;

	cout << "ȫ����Ҷ�ӵ�����" << endl;
	cout << bitree.CountLeaves() << endl;

	cout << "�������" << endl;
	cout << bitree.GetDepth() << endl;

	cout << "��k��Ľ�����" << endl;
	cout << bitree.GetLevel_K(3) << endl;

	cout << "���н����Զ�ľ���" << endl;
	cout << bitree.GetMaxDistance() << endl;

	cout << "�ж�һ������Ƿ�������" << endl;
	BiNode<char> *t = new BiNode<char>('C');
	cout << (bitree.Is_In_Tree(t) ? "��" : "����") << endl;

	cout << "���쾵����" << endl;
	bitree.Mirror();
	cout << "ǰ�����" << endl;
	bitree.PreOrder();
	cout << endl;

	//delete bitree;

	system("pause");
	return 0;
}