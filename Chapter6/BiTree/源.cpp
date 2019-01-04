//#include"BiTree.h"
#include"myBiTree.h"

using namespace std;

int main()
{
	myBiTree<char> bitree;        
	cout << "前序遍历" << endl;
	bitree.PreOrder();                            
	cout << endl;
	
	cout << "非递归版前向遍历" << endl;
	bitree.Iteration_PreOrder();
	cout << endl;

	cout << "中序遍历" << endl;
	bitree.InOrder();                             
	cout << endl;

	cout << "非迭代版中序遍历" << endl;
	bitree.Iteration_InOrder();                         
	cout << endl;

	cout << "后序遍历" << endl;
	bitree.PostOrder();                            
	cout << endl;

	cout << "非迭代版后序遍历" << endl;
	bitree.IterationPostOrder();                    
	cout << endl;

	cout << "层序遍历" << endl;
	bitree.LevelOrder();    
	cout << endl;

	cout << "全部结点的数量" << endl;
	cout << bitree.CountAllNode() << endl;

	cout << "全部的叶子的数量" << endl;
	cout << bitree.CountLeaves() << endl;

	cout << "树的深度" << endl;
	cout << bitree.GetDepth() << endl;

	cout << "第k层的结点个数" << endl;
	cout << bitree.GetLevel_K(3) << endl;

	cout << "所有结点最远的距离" << endl;
	cout << bitree.GetMaxDistance() << endl;

	cout << "判断一个结点是否在树上" << endl;
	BiNode<char> *t = new BiNode<char>('C');
	cout << (bitree.Is_In_Tree(t) ? "在" : "不在") << endl;

	cout << "构造镜像树" << endl;
	bitree.Mirror();
	cout << "前序遍历" << endl;
	bitree.PreOrder();
	cout << endl;

	//delete bitree;

	system("pause");
	return 0;
}