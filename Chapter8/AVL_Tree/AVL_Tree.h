#include<iostream>
#include<iomanip>

using namespace std;

template <typename T>
class AVLTreeNode
{
public:
	T key; // 键值
	int height; // 高度
	AVLTreeNode *left;    // 左孩子
	AVLTreeNode *right;    // 右孩子

	AVLTreeNode(T value, AVLTreeNode *l, AVLTreeNode *r) :
		key(value), height(0), left(l), right(r) {}
};

template <typename T>
class AVLTree
{
public:
	AVLTree() { mRoot = NULL; }
	~AVLTree() { destroy(mRoot); }

	// 获取树的高度
	int height() { return height(mRoot); }
	// 获取树的高度
	int max(int a, int b);

	// 中序遍历"AVL树"
	void inOrder() { inOrder(mRoot); }

	// (递归实现)查找"AVL树"中键值为key的节点
	AVLTreeNode<T>* search(T key) { return search(mRoot, key); }
	// (非递归实现)查找"AVL树"中键值为key的节点
	AVLTreeNode<T>* iterativeSearch(T key) { return iterativeSearch(mRoot, key); }

	// 查找最小结点：返回最小结点的键值。
	T minimum()
	{
		AVLTreeNode<T> *minnode = minimum(mRoot);
		if (minnode != NULL)
		{
			return minnode->key;
		}
		return T(NULL);
	}
	// 查找最大结点：返回最大结点的键值。
	T maximum() 
	{
		AVLTreeNode<T> *maxnode = maximum(mRoot);
		if (maxnode != NULL)
		{
			return maxnode->key;
		}
		return T(NULL);
	}

	// 将结点(key为节点键值)插入到AVL树中
	void insert(T key) { mRoot = insert(mRoot, key); }

	// 删除结点(key为节点键值)
	void remove(T key) 
	{
		AVLTreeNode<T> *node;
		if ((node = search(mRoot, key)) != NULL)
		{
			mRoot = remove(mRoot, node);
		}
	}

	// 打印AVL树
	void print() 
	{
		if (mRoot != NULL)
		{
			print(mRoot, mRoot->key, 0);
		}
	}

private:
	AVLTreeNode<T> *mRoot; // 根结点
	// 获取树的高度
	int height(AVLTreeNode<T>* tree);

	// 中序遍历"AVL树"
	void inOrder(AVLTreeNode<T>* tree) const;

	// (递归实现)查找"AVL树x"中键值为key的节点
	AVLTreeNode<T>* search(AVLTreeNode<T>* x, T key) const;
	// (非递归实现)查找"AVL树x"中键值为key的节点
	AVLTreeNode<T>* iterativeSearch(AVLTreeNode<T>* x, T key) const;

	// 查找最小结点：返回tree为根结点的AVL树的最小结点。
	AVLTreeNode<T>* minimum(AVLTreeNode<T>* tree);
	// 查找最大结点：返回tree为根结点的AVL树的最大结点。
	AVLTreeNode<T>* maximum(AVLTreeNode<T>* tree);

	// LL：左左对应的情况(左单旋转)。
	AVLTreeNode<T>* leftLeftRotation(AVLTreeNode<T>* k2);

	// RR：右右对应的情况(右单旋转)。
	AVLTreeNode<T>* rightRightRotation(AVLTreeNode<T>* k1);

	// LR：左右对应的情况(左双旋转)。
	AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* k3);

	// RL：右左对应的情况(右双旋转)。
	AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* k1);

	// 将结点(z)插入到AVL树(tree)中
	AVLTreeNode<T>* insert(AVLTreeNode<T>* root, T key);

	// 删除AVL树(tree)中的结点(z)，并返回被删除的结点
	AVLTreeNode<T>* remove(AVLTreeNode<T>* root, AVLTreeNode<T>* node);

	// 销毁AVL树
	void destroy(AVLTreeNode<T> *root);

	// 打印AVL树
	void print(AVLTreeNode<T>* tree, T key, int direction);
};


template<typename T>
inline int AVLTree<T>::height(AVLTreeNode<T>* tree)
{
	if (tree != NULL)
	{
		return tree->height;
	}
	return 0;
}

template<typename T>
inline int AVLTree<T>::max(int a, int b)
{
	return a > b ? a : b;
}


template<typename T>
inline void AVLTree<T>::inOrder(AVLTreeNode<T>* tree) const
{
	if (tree == NULL)
	{
		return;
	}
	inOrder(tree->left);
	cout << tree->key << " ";
	inOrder(tree ->right);
}

template<typename T>
inline AVLTreeNode<T>* AVLTree<T>::search(AVLTreeNode<T>* x, T key) const
{
	if (x == NULL || x->key == key) // 如果x==NULL，表示没有找到，返回的就是NULL。如果x->key=key,表示找到了，返回指向x的指针
	{
		return x;
	}
	if (key < x->key)
	{
		return search(x->left, key);
	}
	else
	{
		return search(x->right, key);
	}
}

template<typename T>
inline AVLTreeNode<T>* AVLTree<T>::iterativeSearch(AVLTreeNode<T>* x, T key) const
{
	while (x != NULL && x->key != key)
	{
		if (key < x->key)
		{
			x = x->key;
		}
		else
		{
			x = x->right;
		}
	}
	return x;
}

template<typename T>
inline AVLTreeNode<T>* AVLTree<T>::minimum(AVLTreeNode<T>* tree)
{
	if (tree == NULL)
	{
		return NULL;
	}
	while (tree->left != NULL)
	{
		tree = tree->left;
	}
	return tree;
}


template<typename T>
inline AVLTreeNode<T>* AVLTree<T>::maximum(AVLTreeNode<T>* tree)
{
	if (tree == NULL)
	{
		return NULL;
	}
	while (tree->right != NULL)
	{
		tree = tree->right;
	}
	return tree;
}

template<typename T>
inline AVLTreeNode<T>* AVLTree<T>::leftLeftRotation(AVLTreeNode<T>* k2)
{
	AVLTreeNode<T>* k1;
	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;

	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), k2->height) + 1;

	return k1;
}

template<typename T>
inline AVLTreeNode<T>* AVLTree<T>::rightRightRotation(AVLTreeNode<T>* k1)
{
	AVLTreeNode<T>* k2;
	k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;

	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(k1->height, height(k2->right)) + 1;

	return k2;
}

template<typename T>
inline AVLTreeNode<T>* AVLTree<T>::leftRightRotation(AVLTreeNode<T>* k3)
{
	k3->left = rightRightRotation(k3->left);
	return leftLeftRotation(k3);
}

template<typename T>
inline AVLTreeNode<T>* AVLTree<T>::rightLeftRotation(AVLTreeNode<T>* k1)
{
	k1->right = leftLeftRotation(k1->right);
	return rightRightRotation(k1);
}

template<typename T>
inline AVLTreeNode<T>* AVLTree<T>::insert(AVLTreeNode<T>* root, T key)
{
	if (root == NULL)
	{
		root = new AVLTreeNode<T>(key, NULL, NULL);
	}
	else if (key < root->key) // 插入到左子树
	{
		root->left = insert(root->left, key);
		if (height(root->left) - height(root->right) == 2) // 插入左子树导致二叉树失衡
		{
			if (key < root->left->key)  // 说明插入到左子树的左子树
			{
				root = leftLeftRotation(root);
			}
			else						// 说明插入到左子树的右子树
			{
				root = leftRightRotation(root);
			}
		}
	}
	else if (key > root->key) // 插入到右子树
	{
		root->right = insert(root->right, key);
		if (height(root->right) - height(root->left) == 2) // 插入右子树导致二叉树失衡
		{
			if (key > root->right->key) // 说明插入到右子树的右子树
			{
				root = rightRightRotation(root);
			}
			else				        // 说明插入到右子树的左子树
			{
				root = rightLeftRotation(root);
			}
		}
	}

	root->height = max(height(root->left), height(root->right)) + 1; // 更新插入后，树的高度

	return root;
}

template<typename T>
inline AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* root, AVLTreeNode<T>* node)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (node->key < root->key)          //如果删除结点在左子树
	{
		root->left = remove(root->left, node);
		root->left = remove(root->left, node);
		if (height(root->right) - height(root->left) == 2) // 删除导致树失去平衡
		{
			AVLTreeNode<T> *rightNode = root->right;
			if (height(rightNode->left) > height(rightNode->right)) // 这时候说明右子树的左子树出现了失衡
			{
				root = rightLeftRotation(root);
			}
			else
			{
				root = rightRightRotation(root);
			}
		}
	}
	else if (node->key > root->key)      // 如果删除的结点在右子树
	{
		root->right = remove(root->right, node);
		if (height(root->left) - height(root->right) == 2) // 删除导致树失去平衡
		{
			AVLTreeNode<T> *leftNode = root->left;
			if (height(leftNode->left) > height(leftNode->right)) // 这时候说明左子树的左子树出现了失衡
			{
				root = leftLeftRotation(root);
			}
			else										// 这时候说明左子树的右子树出现了失衡
			{
				root = leftRightRotation(root);
			}
		}
	}
	else						// 找到了要删除的结点
	{
		if ((root->left != NULL) && (root->right != NULL)) // 如果左右子树都不为空
		{
			if (height(root->left) > height(root->right))
			{
				AVLTreeNode<T>* maxNode = maximum(root->left);
				root->key = maxNode->key;
				root->left = remove(root->left, maxNode); // 采用这种删除的方式是保证删除后的树还是平衡的
			}
			else
			{
				AVLTreeNode<T>* minNode = minimum(root->right);
				root->key = minNode->key;
				root->right = remove(root->right, minNode);
			}
		}
		else
		{
			AVLTreeNode<T>* temp = root;
			root = (root->left != NULL) ? root->left : root->right;
			delete temp;	
		}
		
	}
	return root;
}

template<typename T>
inline void AVLTree<T>::destroy(AVLTreeNode<T> *root)
{
	if (root != NULL)
	{
		destroy(root->left);
		destroy(root->right);
		delete root;
	}
}

template<typename T>
inline void AVLTree<T>::print(AVLTreeNode<T>* tree, T key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)    // tree是根节点
			cout << setw(2) << tree->key << " is root" << endl;
		else                // tree是分支节点
			cout << setw(2) << tree->key << " is " << setw(2) << key << "'s " << setw(12) << (direction == 1 ? "right child" : "left child") << endl;

		print(tree->left, tree->key, -1);
		print(tree->right, tree->key, 1);
	}
}

