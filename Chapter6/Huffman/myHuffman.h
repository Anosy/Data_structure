#include<iostream>
#include<stack>
using namespace std;

const int MAXSIZE = 20;

template <typename T>
struct HuffmanNode
{
	HuffmanNode(T k, HuffmanNode<T> *l, HuffmanNode<T> *r) :
		key(k), lchild(l), rchild(r) {}
	T key;
	HuffmanNode<T> *lchild;
	HuffmanNode<T> *rchild;
	int flag;
};

template <typename T>
class HuffmanTree
{
public:
	HuffmanTree() :root(NULL) {}
	~HuffmanTree() { destory(root); }
	void PreOrder() { preOrder(root); }
	void InOrder() { inOrder(root); }
	void PostOrder() { postOrder(root); }

	void Creat(T a[], int size);
	void Destory() { destory(root); }
	void Print() { print(root); }

private:
	void preOrder(HuffmanNode<T>* root);
	void inOrder(HuffmanNode<T>* root);
	void postOrder(HuffmanNode<T>* root);
	void print(HuffmanNode<T>* root);
	void destory(HuffmanNode<T>* root);
	void mysort(int size);

	HuffmanNode<T>* root;
	HuffmanNode<T>* forest[MAXSIZE];
};

template<typename T>
inline void HuffmanTree<T>::Creat(T a[], int size)
{
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		HuffmanNode<T>* p = new HuffmanNode<T>(a[i], NULL, NULL);
		forest[i] = p;
	}
	for (int i = 0; i < size - 1; i++) // 需要构建的次数为size-1次
	{
		mysort(size + k);
		for (int j = 0; j < size + k; j++)
		{
			if (forest[j]->flag != 1 && forest[j+1]->flag != 1)
			{
				HuffmanNode<T> *node =
					new HuffmanNode<T>(forest[j]->key + forest[j + 1]->key, forest[j], forest[j + 1]);
				forest[size + k] = node;
				k++;
				forest[j]->flag = 1;
				forest[j + 1]->flag = 1;
				break;
			}
			else
			{
				continue;
			}
		}
	}
	root = forest[size + k - 1];
}

template<typename T>
inline void HuffmanTree<T>::destory(HuffmanNode<T>* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		destory(root->lchild);
		destory(root->rchild);
		delete root;
		root = NULL;
	}
}

template<typename T>
inline void HuffmanTree<T>::mysort(int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (forest[i]->key > forest[j]->key)
			{
				swap(forest[i], forest[j]);
			}
			else
			{
				continue;
			}
		}
	}
}

template<typename T>
inline void HuffmanTree<T>::preOrder(HuffmanNode<T>* root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->key;
	preOrder(root->lchild);
	preOrder(root->rchild);
}

template<typename T>
inline void HuffmanTree<T>::inOrder(HuffmanNode<T>* root)
{
	if (root == NULL)
	{
		return;
	}
	inOrder(root->lchild);
	cout << root->key;
	inOrder(root->rchild);
}

template<typename T>
inline void HuffmanTree<T>::postOrder(HuffmanNode<T>* root)
{
	if (root == NULL)
	{
		return;
	}
	postOrder(root->lchild);
	postOrder(root->rchild);
	cout << root->key;
}

// 前序非递归遍历打印
template<typename T>
inline void HuffmanTree<T>::print(HuffmanNode<T>* root)
{
	if (root == NULL)
	{
		return;
	}
	stack<HuffmanNode<T>*> S;

	while (!S.empty() || root != NULL)
	{
		while (root != NULL)
		{
			cout << "当前结点为：" << root->key << ".";
			if (root->lchild != NULL)
			{
				cout << "它的左孩子结点为：" << root->lchild->key << ".";
			}
			else
			{
				cout << "它没有左孩子.";
			}
			if (root->rchild != NULL)
			{
				cout << "它的右孩子结点为：" << root->rchild->key << ".";
			}
			else
			{
				cout << "它没有右孩子.";
			}
			cout << endl;

			S.push(root);
			root = root->lchild;
		}
		root = S.top()->rchild;
		S.pop();
	}
}
