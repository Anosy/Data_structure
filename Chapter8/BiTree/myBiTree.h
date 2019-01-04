#include<iostream>

using namespace std;

struct BiTNode
{
	int data;
	BiTNode *lchild, *rchild;
};

class myBiTree
{
public:
	myBiTree() { root = NULL; }
	~myBiTree() { Release(root); }
	void InSertBST(int key) { root = insertBST(root, key); };
	void InOder() { inorder(root); }
	BiTNode* Tree_Search(int key) { return tree_search(root, key); }
	BiTNode* IterativeTreeSearch(int key) { return iterativetreesearch(root, key); };
	void Delete_BST(int key) { root = DeleteBST(root, key); }
private:
	BiTNode *root;
	void Release(BiTNode* &root);
	BiTNode* insertBST(BiTNode *root, int key);
	void inorder(BiTNode *root);
	BiTNode* tree_search(BiTNode *root, int key);
	BiTNode* iterativetreesearch(BiTNode *root, int key);
	BiTNode *DeleteBST(BiTNode* root, int key);
	BiTNode *Delete(BiTNode* p);

};

inline void myBiTree::Release(BiTNode* &root)
{
	if (root != NULL)
	{
		Release(root->lchild);
		Release(root->rchild);
		delete root;
	}
}

inline BiTNode * myBiTree::insertBST(BiTNode * root, int key)
{
	if (root == NULL)  // 首先判当前的结点是否为空，如果为空表示树中没有该结点
	{
		BiTNode * p = new BiTNode;
		p->data = key;
		p->lchild = p->rchild = NULL;
		root = p;
	}
	else if (key < root->data) // 如果比当前结点小，那么从它的左子树插入
	{
		root->lchild = insertBST(root->lchild, key);
	}
	else if (key > root->data) // 如果比当前的结点大，那么从它的右子树插入
	{
		root->rchild = insertBST(root->rchild, key);
	}
	return root;
}

inline void myBiTree::inorder(BiTNode * root)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->lchild);
	cout << root->data << " ";
	inorder(root->rchild);
}

inline BiTNode * myBiTree::tree_search(BiTNode * root, int key)
{
	if (root == NULL || root->data == key)
	{
		return root; // 如果返回的是空表明不存在，如果返回非空，表示返回对应结点的指针
	}
	else
	{
		if (key < root->data)
		{
			root = tree_search(root->lchild, key);
		}
		else
		{
			root = tree_search(root->rchild, key);
		}
	}
}

inline BiTNode * myBiTree::iterativetreesearch(BiTNode * root, int key)
{
	while (root != NULL && root->data != key)
	{
		if (key < root->data)
		{
			root = root->lchild;
		}
		else if (key > root->data)
		{
			root = root->rchild;
		}
	}
	if (root == NULL)
	{
		cout << "不存在该元素" << endl;
	}
	else
	{
		cout << "存在该元素" << endl;
	}
	return root;
}

inline BiTNode * myBiTree::DeleteBST(BiTNode * root, int key)
{
	if (root == NULL)
	{
		return root;
	}
	else
	{
		if (key == root->data)
		{
			root = Delete(root);
		}
		else if (key < root->data)
		{
			root->lchild = DeleteBST(root->lchild, key);
		}
		else
		{
			root->rchild = DeleteBST(root->rchild, key);
		}
	}
	return root;
}

/*
删除操作存在三种情况
1.删除的点为叶子结点，那么直接删除结点即可
2.删除的点的只有左子树或者只有右子树的情况，那么直接接左子树和右子树即可
3.删除的点不仅有左子树还存在右子树，那么我们需要特殊处理
*/
inline BiTNode * myBiTree::Delete(BiTNode * p)
{
	BiTNode *q;
	if (p->rchild == NULL)
	{
		q = p;
		p = p->lchild;
		delete q;
	}
	else if (p->lchild == NULL)
	{
		q = p;
		p = p->rchild;
		delete q;
	}
	else
	{
		q = p;
		BiTNode *s = p->lchild; // 先找到要删除点的左子树
		while (s->rchild) // 循环找到要删除点p的前驱顶点s
		{
			q = s;
			s = s->rchild;
		}

		p->data = s->data; // 替换要被删除点的值为其的前驱s的值

		if (q != p) // 说明p点存在右子树
		{
			q->rchild = s->lchild;
		}
		else     // 说明p点只存在左子树，所以p的左孩子接s的左孩子即可
		{
			q->lchild = s->lchild;
		}
		delete s;
	}
	return p;
}


