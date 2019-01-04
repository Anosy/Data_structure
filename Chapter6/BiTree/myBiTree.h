#include<iostream>
#include<queue>
#include<stack>

using namespace std;

template <typename T>
struct BiNode
{
	BiNode() = default;
	BiNode(T d) :data(d), lchild(NULL), rchild(NULL) {}
	T data;
	BiNode<T> *lchild;
	BiNode<T> *rchild;
};

template <typename T>
class myBiTree
{
public:
	myBiTree() { root = Creat(root); }
	~myBiTree() { Release(root); }
	void PreOrder() { preorder(root); }
	void InOrder() { inorder(root); }
	void PostOrder() { postorder(root); }
	void Iteration_PreOrder(){ iteration_preorder(root); }
	void Iteration_InOrder(){iteration_inorder(root);}
	void IterationPostOrder(){ iteration_postorder(root); }
	void LevelOrder();
	int CountAllNode() { return countallnode(root); }
	int CountLeaves() { return countleaves(root); }
	int GetDepth() { return getdepth(root); }
	int GetLevel_K(int k) { return getlevel_k(root, k); }
	int GetMaxDistance();
	void Mirror() { root = mirror(root); }
	bool Is_In_Tree(BiNode<T> *t) { return is_in_tree(root, t); }

private:
	BiNode<T> *root;
	BiNode<T>* Creat(BiNode<T> *bt);
	void Release(BiNode<T> *bt);
	void preorder(BiNode<T> *bt);
	void inorder(BiNode<T> *bt);
	void postorder(BiNode<T> *bt);
	void iteration_preorder(BiNode<T> *bt);
	void iteration_inorder(BiNode<T> *bt);
	void iteration_postorder(BiNode<T> *bt);
	int countallnode(BiNode<T>* bt);
	int countleaves(BiNode<T>* bt);
	int getdepth(BiNode<T>* bt);
	int getlevel_k(BiNode<T> *bt, int k);
	int getmaxdistance(BiNode<T> * bt, int &maxdistance);
	bool is_in_tree(BiNode<T> *root, BiNode<T> *t);
	BiNode<T>* mirror(BiNode<T>* bt);
};

template<typename T>
inline void myBiTree<T>::LevelOrder()
{
	if (root == NULL)
	{
		return;
	}
	
	queue<BiNode<T>*> rel;
	rel.push(root);
	
	while (!rel.empty())
	{
		BiNode<T> * front = rel.front();
		cout << front->data << " ";
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
inline int myBiTree<T>::GetMaxDistance()
{
	int maxdistance = 0;
	getmaxdistance(root, maxdistance);
	return maxdistance;
}

template<typename T>
inline BiNode<T>* myBiTree<T>::Creat(BiNode<T>* bt)
{
	T ch;
	cin >> ch;
	if (ch == '#')
	{
		bt = NULL;
	}
	else
	{
		bt = new BiNode<T>();
		bt->data = ch;
		bt->lchild = Creat(bt->lchild);
		bt->rchild = Creat(bt->rchild);
	}
	return bt;
}

template<typename T>
inline void myBiTree<T>::Release(BiNode<T>* bt)
{
	if (bt != NULL)
	{
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt;
	}
}

template<typename T>
inline void myBiTree<T>::preorder(BiNode<T>* bt)
{
	if (bt == NULL)
	{
		return;
	}
	cout << bt->data << " ";
	preorder(bt->lchild);
	preorder(bt->rchild);
}

template<typename T>
inline void myBiTree<T>::inorder(BiNode<T>* bt)
{
	if (bt == NULL)
	{
		return;
	}
	inorder(bt->lchild);
	cout << bt->data << " ";
	inorder(bt->rchild);
}

template<typename T>
inline void myBiTree<T>::postorder(BiNode<T>* bt)
{
	if (bt == NULL)
	{
		return;
	}
	postorder(bt->lchild);
	postorder(bt->rchild);
	cout << bt->data << " ";
}

template<typename T>
inline void myBiTree<T>::iteration_preorder(BiNode<T>* bt)
{
	if (bt == NULL)
	{
		return;
	}
	stack<BiNode<T>*> S;
	/*cout << bt->data << " ";
	S.push(bt);
	bt = bt->lchild;*/
	
	while (!S.empty() || bt)
	{
		while (bt)
		{
			cout << bt->data << " ";
			S.push(bt);
			bt = bt->lchild;
		}
		bt = S.top()->rchild;
		S.pop();
	}
}

template<typename T>
inline void myBiTree<T>::iteration_inorder(BiNode<T>* bt)
{
	if (bt == NULL)
	{
		return;
	}
	stack<BiNode<T>*> S;
	//S.push(bt);
	//bt = bt->lchild;
	
	while (!S.empty() || bt)
	{
		while (bt)
		{
			S.push(bt);
			bt = bt->lchild;
		}
		cout << S.top()->data << " ";
		bt = S.top()->rchild;
		S.pop();
	}
}

template<typename T>
inline void myBiTree<T>::iteration_postorder(BiNode<T>* bt)
{
	if (bt == NULL)
	{
		return;
	}
	BiNode<T> *pre = NULL;
	stack<BiNode<T>*> S;
	S.push(bt);

	while (!S.empty())
	{
		bt = S.top();
		if ((!bt->lchild && !bt->rchild) ||
			(pre && (pre == bt->lchild || pre == bt->rchild)))
		{
			cout << bt->data << " ";
			pre = bt;
			S.pop();
		}
		else
		{
			if (bt->rchild)
			{
				S.push(bt->rchild);
			}
			if (bt->lchild)
			{
				S.push(bt->lchild);
			}
		}
	}
}

template<typename T>
inline int myBiTree<T>::countallnode(BiNode<T>* bt)
{
	if (bt == NULL)
	{
		return 0;
	}
	return countallnode(bt->lchild) + countallnode(bt->rchild) + 1;
}

template<typename T>
inline int myBiTree<T>::countleaves(BiNode<T>* bt)
{
	if (bt == NULL)
	{
		return 0;
	}
	if (bt->lchild == NULL && bt->rchild == NULL)
	{
		return 1;
	}
	
	return countleaves(bt->lchild) + countleaves(bt->rchild);
}

template<typename T>
inline int myBiTree<T>::getdepth(BiNode<T>* bt)
{
	if (bt == NULL)
	{
		return 0;
	}
	int left_depth = getdepth(bt->lchild) + 1;
	int right_depth = getdepth(bt->rchild) + 1;
	
	return left_depth > right_depth ? left_depth : right_depth;
}

template<typename T>
inline int myBiTree<T>::getlevel_k(BiNode<T>* bt, int k)
{
	if (bt == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return getlevel_k(bt->lchild, k - 1) + getlevel_k(bt->rchild, k - 1);
}

template<typename T>
inline int myBiTree<T>::getmaxdistance(BiNode<T>* bt, int & maxdistance)
{
	if (bt == NULL)
	{
		return 0;
	}
	int left_depth = getmaxdistance(bt->lchild, maxdistance) + 1;
	int right_depth = getmaxdistance(bt->rchild, maxdistance) + 1;
	int new_distance = left_depth + right_depth + 2;
	maxdistance = maxdistance > new_distance ? maxdistance : new_distance;
	
	return getmaxdistance(bt->lchild, maxdistance) + getmaxdistance(bt->rchild, maxdistance);
}

template<typename T>
inline bool myBiTree<T>::is_in_tree(BiNode<T>* root, BiNode<T>* t)
{
	if (root == NULL)
	{
		return false;
	}
	else if(root->data == t->data) // 假设只要判断data成员在树上就行
	{
		return true;
	}
	else
	{
		bool temp = false;
		if (root->lchild != NULL)
		{
			temp = is_in_tree(root->lchild, t);
		}
		if (!temp && root->rchild != NULL)
		{
			temp = is_in_tree(root->rchild, t);
		}
		return temp;	
	}
}

template<typename T>
inline BiNode<T>* myBiTree<T>::mirror(BiNode<T>* bt)
{
	if (bt == NULL)
	{
		return NULL;
	}
	BiNode<T> * temp = bt->lchild;
	bt->lchild = bt->rchild;
	bt->rchild = temp;
	
	mirror(bt->lchild);
	mirror(bt->rchild);
	
	return bt;
}
