#include<iostream>
#include<iomanip>

using namespace std;

template <typename T>
class AVLTreeNode
{
public:
	T key; // ��ֵ
	int height; // �߶�
	AVLTreeNode *left;    // ����
	AVLTreeNode *right;    // �Һ���

	AVLTreeNode(T value, AVLTreeNode *l, AVLTreeNode *r) :
		key(value), height(0), left(l), right(r) {}
};

template <typename T>
class myAVLTree
{
public:
	myAVLTree() { mRoot = NULL; }
	~myAVLTree() { destroy(mRoot); }

	// ��ȡ���ĸ߶�
	int height() { return height(mRoot); }
	// ��ȡ���ĸ߶�
	int max(int a, int b);

	// �������"AVL��"
	void inOrder() { inOrder(mRoot); }

	// (�ݹ�ʵ��)����"AVL��"�м�ֵΪkey�Ľڵ�
	AVLTreeNode<T>* search(T key) { return search(mRoot, key); }
	// (�ǵݹ�ʵ��)����"AVL��"�м�ֵΪkey�Ľڵ�
	AVLTreeNode<T>* iterativeSearch(T key) { return iterativeSearch(mRoot, key); }

	// ������С��㣺������С���ļ�ֵ��
	T minimum()
	{
		AVLTreeNode<T> *minnode = minimum(mRoot);
		if (minnode != NULL)
		{
			return minnode->key;
		}
		return T(NULL);
	}
	// ��������㣺���������ļ�ֵ��
	T maximum()
	{
		AVLTreeNode<T> *maxnode = maximum(mRoot);
		if (maxnode != NULL)
		{
			return maxnode->key;
		}
		return T(NULL);
	}

	// �����(keyΪ�ڵ��ֵ)���뵽AVL����
	void insert(T key) { mRoot = insert(mRoot, key); }

	// ɾ�����(keyΪ�ڵ��ֵ)
	void remove(T key)
	{
		AVLTreeNode<T> *node;
		if ((node = search(mRoot, key)) != NULL)
		{
			mRoot = remove(mRoot, node);
		}
	}

	// ��ӡAVL��
	void print()
	{
		if (mRoot != NULL)
		{
			print(mRoot, mRoot->key, 0);
		}
	}

private:
	AVLTreeNode<T> *mRoot; // �����
	// ��ȡ���ĸ߶�
	int height(AVLTreeNode<T>* root);

	// �������"AVL��"
	void inOrder(AVLTreeNode<T>* root) const;

	// (�ݹ�ʵ��)����"AVL��x"�м�ֵΪkey�Ľڵ�
	AVLTreeNode<T>* search(AVLTreeNode<T>* x, T key) const;
	// (�ǵݹ�ʵ��)����"AVL��x"�м�ֵΪkey�Ľڵ�
	AVLTreeNode<T>* iterativeSearch(AVLTreeNode<T>* x, T key) const;

	// ������С��㣺����treeΪ������AVL������С��㡣
	AVLTreeNode<T>* minimum(AVLTreeNode<T>* root);
	// ��������㣺����treeΪ������AVL��������㡣
	AVLTreeNode<T>* maximum(AVLTreeNode<T>* root);

	// LL�������Ӧ�����(����ת)��
	AVLTreeNode<T>* leftLeftRotation(AVLTreeNode<T>* k2);

	// RR�����Ҷ�Ӧ�����(�ҵ���ת)��
	AVLTreeNode<T>* rightRightRotation(AVLTreeNode<T>* k1);

	// LR�����Ҷ�Ӧ�����(��˫��ת)��
	AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* k3);

	// RL�������Ӧ�����(��˫��ת)��
	AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* k1);

	// �����(z)���뵽AVL��(tree)��
	AVLTreeNode<T>* insert(AVLTreeNode<T>* root, T key);

	// ɾ��AVL��(tree)�еĽ��(z)�������ر�ɾ���Ľ��
	AVLTreeNode<T>* remove(AVLTreeNode<T>* root, AVLTreeNode<T>* node);

	// ����AVL��
	void destroy(AVLTreeNode<T> *root);

	// ��ӡAVL��
	void print(AVLTreeNode<T>* root, T key, int direction);
};

template<typename T>
inline int myAVLTree<T>::max(int a, int b)
{
	return a > b ? a : b;
}

template<typename T>
inline int myAVLTree<T>::height(AVLTreeNode<T>* root)
{
	if (root != NULL)
	{
		return root->height;
	}
	return 0;
}

template<typename T>
inline void myAVLTree<T>::inOrder(AVLTreeNode<T>* root) const
{
	if (root == NULL)
	{
		return;
	}
	inOrder(root->left);
	cout << root->key << " ";
	inOrder(root->right);
}

template<typename T>
inline AVLTreeNode<T>* myAVLTree<T>::search(AVLTreeNode<T>* x, T key) const
{
	if (x == NULL || x->key == key) // ���x==NULL����ʾû���ҵ������صľ���NULL�����x->key=key,��ʾ�ҵ��ˣ�����ָ��x��ָ��
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
inline AVLTreeNode<T>* myAVLTree<T>::iterativeSearch(AVLTreeNode<T>* x, T key) const
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
inline AVLTreeNode<T>* myAVLTree<T>::minimum(AVLTreeNode<T>* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}

template<typename T>
inline AVLTreeNode<T>* myAVLTree<T>::maximum(AVLTreeNode<T>* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	while (root->right != NULL)
	{
		root = root->right;
	}
	return  root;
}

template<typename T>
inline AVLTreeNode<T>* myAVLTree<T>::leftLeftRotation(AVLTreeNode<T>* k2)
{
	AVLTreeNode<T> *k1;
	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;

	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), k2->height) + 1;

	return k1;
}

template<typename T>
inline AVLTreeNode<T>* myAVLTree<T>::rightRightRotation(AVLTreeNode<T>* k1)
{
	AVLTreeNode<T> *k2;
	k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;

	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(k1->height, height(k2->right)) + 1;
	
	return k2;
}

template<typename T>
inline AVLTreeNode<T>* myAVLTree<T>::leftRightRotation(AVLTreeNode<T>* k3)
{
	k3->left = rightRightRotation(k3->left);
	return leftLeftRotation(k3);
}

template<typename T>
inline AVLTreeNode<T>* myAVLTree<T>::rightLeftRotation(AVLTreeNode<T>* k1)
{
	k1->right = leftLeftRotation(k1->right);
	return rightRightRotation(k1);
}

template<typename T>
inline AVLTreeNode<T>* myAVLTree<T>::insert(AVLTreeNode<T>* root, T key)
{
	if (root == NULL)
	{
		root = new AVLTreeNode<T>(key, NULL, NULL);
	}
	else if (key < root->key)
	{
		root->left = insert(root->left, key);
		if (height(root->left) - height(root->right) == 2)
		{
			if (key < root->left->key)
			{
				root = leftLeftRotation(root);
			}
			else
			{
				root = leftRightRotation(root);
			}
		}
	}
	else if (key > root->key)
	{
		root->right = insert(root->right, key);
		if (height(root->right) - height(root->left) == 2)
		{
			if (key > root->right->key)
			{
				root = rightRightRotation(root);
			}
			else
			{
				root = rightLeftRotation(root);
			}
		}
	}
	root->height = max(height(root->left), height(root->right)) + 1; // ���²�������ĸ߶�

	return root;
}

template<typename T>
inline AVLTreeNode<T>* myAVLTree<T>::remove(AVLTreeNode<T>* root, AVLTreeNode<T>* node)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (node->key < root->key)
	{
		root->left = remove(root->left, node);
		if (height(root->right) - height(root->left) == 2) // ɾ��������ʧȥƽ��
		{
			AVLTreeNode<T> *rightNode = root->right;
			if (height(rightNode->left) > height(rightNode->right)) // ��ʱ��˵����������������������ʧ��
			{
				root = rightLeftRotation(root);
			}
			else
			{
				root = rightRightRotation(root);
			}
		}
	}
	else if (node->key > root->key)
	{
		root->right = remove(root->right, node);
		if (height(root->left) - height(root->right) == 2) // ɾ��������ʧȥƽ��
		{
			AVLTreeNode<T> *leftNode = root->left;
			if (height(leftNode->left) > height(leftNode->right)) // ��ʱ��˵����������������������ʧ��
			{
				root = leftLeftRotation(root);
			}
			else										// ��ʱ��˵����������������������ʧ��
			{
				root = leftRightRotation(root);
			}
		}
	}
	else // �ҵ�Ҫɾ���Ľ����
	{
		if ((root->left != NULL) && (root->right != NULL)) // ���������������Ϊ��
		{
			if (height(root->left) > height(root->right))
			{
				AVLTreeNode<T>* maxNode = maximum(root->left);
				root->key = maxNode->key;
				root->left = remove(root->left, maxNode); // ��������ɾ���ķ�ʽ�Ǳ�֤ɾ�����������ƽ���
			}
			else
			{
				AVLTreeNode<T>* minNode = minimum(root->right);
				root->key = minNode->key;
				root->right = remove(root->right, minNode);
			}
		}
		else   // �����������������ֻ���������������
		{
			AVLTreeNode<T>* temp = root;
			root = (root->left != NULL) ? root->left : root->right;
			delete temp;
		}
	}
	if (root != NULL)
	{
		root->height = max(height(root->left), height(root->right)) + 1; // ����ɾ�������ĸ߶�
	}
	return root;
}

template<typename T>
inline void myAVLTree<T>::destroy(AVLTreeNode<T>* root)
{
	if (root != NULL)
	{
		destroy(root->left);
		destroy(root->right);
		delete root;
	}
}

template<typename T>
inline void myAVLTree<T>::print(AVLTreeNode<T>* root, T key, int direction)
{
	if (root != NULL)
	{
		if (direction == 0)
		{
			cout << setw(2) << root->key << " is root" << endl;
		}
		else
		{
			cout << setw(2) << root->key << " is " << setw(2) << key << "'s " << setw(12) << (direction == 1 ? "right child" : "left child") << endl;
		}
		print(root->left, root->key, -1);
		print(root->right, root->key, 1);
	}
}
