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
	BiNode<T> *root; // 使用指针的目的是为了返回修改root的内容
	BiNode<T> *Create(BiNode<T> *bt); // 返回 BiNode<T> *类型
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
	首先前序遍历二叉树就（根 - 左 - 右）的顺序。我们在输出根的右子树的时候，必须要先知道他的根结点。而
	因为前序的话，如果有左子树则先遍历左子树，所以要求的右子树，应该是最后一个左子树的根结点的右子树，
	因此我们考虑使用stack的方法来存储根结点。
	而因为考虑先输出根，所以我们在存入到stack中的时候，就先直接给打印出来。然后再访问它们的左子树
	访问如果左子树存在的话，我们就打印左子树，然后将左子树也给存在stack中，然后继续访问其的左子树。
	如果左子树不存在，那么就访问其右子树，然后因为无论右子树在不在，我们都已经访问完这颗树了，所以就可以将棵树在栈中删除
	*/
	if (bt == NULL)
	{
		return;
	}
	stack<BiNode<T>*> S; // 创建一个stack基于其的后进先出
	cout << bt->data; 
	S.push(bt);
	bt = bt->lchild;
	
	// 方法1
	while (!S.empty() || bt)
	{
		while (bt)
		{
			cout << bt->data;
			S.push(bt);
			bt = bt->lchild;
		}
		bt = S.top()->rchild; // 左结点一定都访问过，或者不存在
		S.pop();
	}

	// 方法2
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
	中序遍历二叉树的顺序为(左 - 根 - 右)。同理，按照中序的定义，我们要先遍历根结点的左子树，然后访问根结点，最后才是右子树
	所以，我们应该保存所有访问的左子树的根结点，然后在访问左、右子树的时候调用出来，而且也还得是后进先出。所以还是用stack
	
	首先我们将起始树的根都给存在stack中，然后再访问其的左子树，如果该左子树存在的话，则将该左子树的根结点给保存起来，并且接着访问其的左子树
	如果其访问的左子树不存在了，那么我先从栈中将保存的根结点给取出来，先打印根，然后我们要访问右子树了，因为其他的都访问过了，因为都访问
	过了所以我们将该结点读取完就删除了。
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
		bt = S.top()->rchild; // 左结点一定都访问过，或者不存在
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
	后序遍历二叉树的顺序为(左 - 右 - 根)
	首先我们将起始的根给加入到stack中。
	我们判断根结点的情况:是否其没有左右子树了或者是其左右子树都被访问了，那么这个时候其就可以直接访问其根结点的内容了。
	条件成立：说明没有左右子树，或者都访问完了，所以可以访问根结点了，并且我们将该根结点用pre给保存了，用作其根结点的判断
		，并且由于全部都访问完了，所以删除
	条件不成立：我们就将其右子树给入栈，再将其左子树入栈，这样首先访问的就一定是左子树
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

		if ((!bt->lchild && !bt->rchild) ||                    // 第一个输出的必是无左右孩子的叶子结点，只要第一个结点输出，
			(pre && (pre == bt->lchild || pre == bt->rchild))) // 以后的 pre 就不会是空。此处的判断语句加入一个 pre，只是用来
		{                                                       // 确保可以正确输出第一个结点。
			cout << bt->data;  // 左右孩子都全部输出，再输出当前结点
			pre = bt;
			S.pop();
		}
		else
		{
			if (bt->rchild)
				S.push(bt->rchild);  // 先进右孩子，再进左孩子，取出来的才是左孩子
			if (bt->lchild)
				S.push(bt->lchild);
		}
	}
}
