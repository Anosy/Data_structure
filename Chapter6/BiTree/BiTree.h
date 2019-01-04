#include<iostream>
#include<queue>
#include<stack>

using namespace std;


template <typename T>
struct BiNode
{
	T data;
	BiNode<T> *lchild;
	BiNode<T> *rchild;
	bool ltag;
	bool rtag;
};

template <typename T>
class BiTree
{
public:
	BiTree() { root = Create(root); }
	~BiTree() { Release(root); }
	void PreOrder() { PreOrder(root); }
	void Iteration_PreOrder() { Iteration_PreOrder(root); }
	void InOrder() { InOrder(root); }
	void Iteration_InOrder() { Iteration_InOrder(root); }
	void PostOrder() { PostOrder(root); }
	void IterationPostOrder() { IterationPostOrder(root); }
	void LeverOrder();    
	int CountAllNode() { return CountAllNode(root); }
	int CountLeaves() { return CountLeaves(root); }
	int GetDepth() { return GetDepth(root); }
	bool StructureCmp(BiNode<T> *bt1, BiNode<T>* bt2);

private:
	BiNode<T> *root; // ʹ��ָ���Ŀ����Ϊ�˷����޸�root������
	BiNode<T> *Create(BiNode<T> *bt); // ���� BiNode<T> *����
	void Release(BiNode<T> *bt);
	void PreOrder(BiNode<T> *bt);
	void Iteration_PreOrder(BiNode<T> *bt);
	void InOrder(BiNode<T> *bt);
	void Iteration_InOrder(BiNode<T> *bt);
	void PostOrder(BiNode<T> *bt);
	void IterationPostOrder(BiNode<T> *bt);
	int CountAllNode(BiNode<T>* bt);
	int CountLeaves(BiNode<T>* bt);
	int GetDepth(BiNode<T>* bt);
	int Mirror(BiNode<T>* bt);
};

template<typename T>
inline void BiTree<T>::LeverOrder()
{
	queue<BiNode<T>*> rel;
	if (root == NULL)
	{
		return;
	}
	rel.push(root);
	while (!rel.empty())
	{
		BiNode<T>* front = rel.front();
		cout << front->data;
		rel.pop();
		if (front->lchild != NULL)
		{
			rel.push(front->lchild);
		}
		if (front->rchild != NULL)
		{
			rel.push(front->rchild);
		}
	}

}

template<typename T>
inline bool BiTree<T>::StructureCmp(BiNode<T>* bt1, BiNode<T>* bt2)
{
	if (bt1 == NULL && bt2 == NULL)
	{
		return true;
	}
	else
	{
		return 
	}
}

template<typename T>
inline int BiTree<T>::CountAllNode(BiNode<T>* bt)
{

	if (bt == NULL)
	{
		return 0;
	}

	return CountAllNode(bt->lchild) + CountAllNode(bt->rchild) + 1;
}

template<typename T>
inline int BiTree<T>::CountLeaves(BiNode<T>* bt)
{
	if (bt == NULL)
	{
		return 0;
	}
	if (!bt->lchild && !bt->rchild)
	{
		return 1;
	}
	return CountLeaves(bt->lchild) + CountLeaves(bt->rchild);
}

template<typename T>
inline int BiTree<T>::GetDepth(BiNode<T>* bt)
{
	if (bt == NULL)
	{
		return 0;
	}
	int left_depth = GetDepth(bt->lchild) + 1;
	int right_depth = GetDepth(bt->rchild) + 1;

	return left_depth > right_depth ? left_depth : right_depth;
}

template<typename T>
inline int BiTree<T>::Mirror(BiNode<T>* bt)
{

}

//template<typename T>
//inline void BiTree<T>::InThreading(BiNode<T>* bt)
//{
//	if (bt)
//	{
//		InThreading(bt->lchild);
//		if (!bt->lchild)
//		{
//			bt->ltag = 1;
//			bt->lchild = pre;
//		}
//		if (!pre->rchild)
//		{
//			pre->rtag = 0;
//			pre->rchild = bt;
//		}
//		pre = p;
//
//		InThreading(bt->rchild);
//	}
//}

template<typename T>
inline BiNode<T>* BiTree<T>::Create(BiNode<T>* bt)
{
	T ch;
	cin >> ch;
	if (ch == '#')
	{
		bt = NULL;
	}
	else
	{
		bt = new BiNode<T>;
		bt->data = ch;
		bt->lchild = Create(bt->lchild);
		bt->rchild = Create(bt->rchild);
	}
	return bt;
}

template<typename T>
inline void BiTree<T>::Release(BiNode<T>* bt)
{
	if (bt != NULL)
	{
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt;
	}
}

template<typename T>
inline void BiTree<T>::PreOrder(BiNode<T>* bt)
{
	if (bt == NULL)
	{
		return;
	}
	cout << bt->data;
	PreOrder(bt->lchild);
	PreOrder(bt->rchild);
}

template<typename T>
inline void BiTree<T>::Iteration_PreOrder(BiNode<T>* bt)
{
	/*
	����ǰ������������ͣ��� - �� - �ң���˳�����������������������ʱ�򣬱���Ҫ��֪�����ĸ���㡣��
	��Ϊǰ��Ļ�����������������ȱ���������������Ҫ�����������Ӧ�������һ���������ĸ�������������
	������ǿ���ʹ��stack�ķ������洢����㡣
	����Ϊ����������������������ڴ��뵽stack�е�ʱ�򣬾���ֱ�Ӹ���ӡ������Ȼ���ٷ������ǵ�������
	����������������ڵĻ������Ǿʹ�ӡ��������Ȼ��������Ҳ������stack�У�Ȼ��������������������
	��������������ڣ���ô�ͷ�������������Ȼ����Ϊ�����������ڲ��ڣ����Ƕ��Ѿ�������������ˣ����ԾͿ��Խ�������ջ��ɾ��
	*/
	if (bt == NULL)
	{
		return;
	}
	stack<BiNode<T>*> S; // ����һ��stack������ĺ���ȳ�
	cout << bt->data; 
	S.push(bt);
	bt = bt->lchild;
	
	// ����1
	while (!S.empty() || bt)
	{
		while (bt)
		{
			cout << bt->data;
			S.push(bt);
			bt = bt->lchild;
		}
		bt = S.top()->rchild; // ����һ�������ʹ������߲�����
		S.pop();
	}

	// ����2
	/*while (!S.empty() && bt)
	{
		BiNode<T>* p = S.top();
		cout << p->data;
		S.pop();
		if (p->rchild != NULL)
		{
			S.push(p->rchild);
		}
		if (p->lchild != NULL)
		{
			S.push(p->lchild);
		}
	}*/

}

template<typename T>
inline void BiTree<T>::InOrder(BiNode<T>* bt)
{
	if (bt == NULL)
	{
		return;
	}
	InOrder(bt->lchild);S
	cout << bt->data;
	InOrder(bt->rchild);
}

template<typename T>
inline void BiTree<T>::Iteration_InOrder(BiNode<T>* bt)
{
	/*
	���������������˳��Ϊ(�� - �� - ��)��ͬ����������Ķ��壬����Ҫ�ȱ�����������������Ȼ����ʸ���㣬������������
	���ԣ�����Ӧ�ñ������з��ʵ��������ĸ���㣬Ȼ���ڷ�������������ʱ����ó���������Ҳ�����Ǻ���ȳ������Ի�����stack
	
	�������ǽ���ʼ���ĸ���������stack�У�Ȼ���ٷ����������������������������ڵĻ����򽫸��������ĸ������������������ҽ��ŷ������������
	�������ʵ��������������ˣ���ô���ȴ�ջ�н�����ĸ�����ȡ�������ȴ�ӡ����Ȼ������Ҫ�����������ˣ���Ϊ�����Ķ����ʹ��ˣ���Ϊ������
	�����������ǽ��ý���ȡ���ɾ���ˡ�
	*/
	if (bt == NULL)
	{
		return;
	}
	stack<BiNode<T>*> S;
	S.push(bt);
	bt = bt->lchild;

	while (!S.empty() || bt)
	{
		while (bt)
		{
			S.push(bt);
			bt = bt->lchild;
		}
		cout << S.top()->data;
		bt = S.top()->rchild; // ����һ�������ʹ������߲�����
		S.pop();
	}	

}

template<typename T>
inline void BiTree<T>::PostOrder(BiNode<T>* bt)
{
	if (bt == NULL)
	{
		return;
	}
	PostOrder(bt->lchild);
	PostOrder(bt->rchild);
	cout << bt->data;
}

template<typename T>
inline void BiTree<T>::IterationPostOrder(BiNode<T>* bt)
{
	/*
	���������������˳��Ϊ(�� - �� - ��)
	�������ǽ���ʼ�ĸ������뵽stack�С�
	�����жϸ��������:�Ƿ���û�����������˻������������������������ˣ���ô���ʱ����Ϳ���ֱ�ӷ���������������ˡ�
	����������˵��û���������������߶��������ˣ����Կ��Է��ʸ�����ˣ��������ǽ��ø������pre�������ˣ�������������ж�
		����������ȫ�����������ˣ�����ɾ��
	���������������Ǿͽ�������������ջ���ٽ�����������ջ���������ȷ��ʵľ�һ����������
	*/
	if (bt == NULL)
	{
		return;
	}
	BiNode<T> * pre = nullptr;
	stack<BiNode<T> *> S;
	S.push(bt);
	while (!S.empty())
	{
		bt = S.top();

		if ((!bt->lchild && !bt->rchild) ||                    // ��һ������ı��������Һ��ӵ�Ҷ�ӽ�㣬ֻҪ��һ����������
			(pre && (pre == bt->lchild || pre == bt->rchild))) // �Ժ�� pre �Ͳ����ǿա��˴����ж�������һ�� pre��ֻ������
		{                                                       // ȷ��������ȷ�����һ����㡣
			cout << bt->data;  // ���Һ��Ӷ�ȫ��������������ǰ���
			pre = bt;
			S.pop();
		}
		else
		{
			if (bt->rchild)
				S.push(bt->rchild);  // �Ƚ��Һ��ӣ��ٽ����ӣ�ȡ�����Ĳ�������
			if (bt->lchild)
				S.push(bt->lchild);
		}
	}
}
