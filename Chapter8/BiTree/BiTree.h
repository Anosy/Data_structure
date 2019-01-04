#include<iostream>

using namespace std;

struct BiNode
{
	int data;
	BiNode *lchild, *rchild;
};

class BiTree
{
public:
	BiTree() { root = NULL; }
	~BiTree() {}
	void InSertBST(int key) { root = insertBST(root, key); };
	void InOder() { inorder(root); }
	BiNode* Tree_Search(int key) { return tree_search(root, key); }
	BiNode* IterativeTreeSearch(int key) { return iterativetreesearch(root, key); };
	void Delete_BST(int key) { root = DeleteBST(root, key); }
private:
	BiNode *root;
	void Release(BiNode* root);
	BiNode* insertBST(BiNode *root, int key);
	void inorder(BiNode *root);
	BiNode* tree_search(BiNode *root, int key);
	BiNode* iterativetreesearch(BiNode *root, int key);
	BiNode *DeleteBST(BiNode* root, int key);
	BiNode* Delete(BiNode* root);

};

inline void BiTree::Release(BiNode * root)
{
	if (root != NULL)
	{
		Release(root->lchild);
		Release(root->rchild);
		delete root;
	}
}

inline BiNode* BiTree::insertBST(BiNode *root, int key)
{
	if (root == NULL) 
	{
		BiNode * p = new BiNode;
		p->data = key;
		p->lchild = p->rchild = NULL;
		root = p;
	}
	else if (key < root->data)
	{
		root->lchild = insertBST(root->lchild, key);
	}
	else if (key > root->data)
	{
		root->rchild = insertBST(root->rchild, key);
	}

	return root;
}



//inline BiNode* BiTree::Creat(BiNode * root)
//{
//	int key;
//	root = NULL;
//	cout << "请输入结点的值" << endl;
//	while (cin >> key)
//	{
//		root = InSertBST(root, key);
//	}
//	/*for (int i = 1; i < 4; i++)
//	{
//		root = InSertBST(root, i);
//	}*/
//
//	return root;
//}

inline void BiTree::inorder(BiNode * root)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->lchild);
	cout << root->data << " ";
	inorder(root->rchild);
}

inline BiNode * BiTree::tree_search(BiNode * root, int key)
{
	if ((root == NULL) || (root->data == key))
	{
		if (root == NULL) // 找不到就返回NULL
		{
			cout << "不存在该元素" << endl;
		}
		else // 找到就返回对应结点的指针
		{
			cout << "存在该元素" << endl;
		}
		return root;
	}
	if (key < root->data)
	{
		return tree_search(root->lchild, key);
	}
	else
	{
		return tree_search(root->rchild, key);
	}
}

inline BiNode * BiTree::iterativetreesearch(BiNode * root, int key)
{
	while (root != NULL && key != root->data)
	{
		if (key < root->data)
		{
			root = root->lchild;
		}
		else
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
 
inline BiNode * BiTree::DeleteBST(BiNode * root, int key)
{
	if (root == NULL)
	{
		cout << "不存在该元素" << endl;
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

inline BiNode* BiTree::Delete(BiNode * p)
{
	BiNode *q;
	if (p->rchild == NULL) // 如果右子树为空，则只需要重新接它的左子树
	{
		q = p;
		p = p->lchild;
		delete q;
	}
	else if (p->lchild == NULL) // 如果左子树为空，直接接右子树
	{
		q = p;
		p = p->rchild;
		delete q;
	}
	else // 如果左右子树都存在
	{
		q = p;
		BiNode* s = p->lchild;
		while (s->rchild) // 转左子树，然后向右走到尽头，找到待删除点的前驱s
		{
			q = s;
			s = s->rchild;
		}

		p->data = s->data; // 替换要被删除结点的数据

		if (q != p)			// 说明s存在右孩子，s为p的前驱结点，q这时候为s的根结点，q的右孩子更新为s的左孩子（其实就是s为q的右孩子）
		{
			q->rchild = s->lchild;
		}
		else                 // q == p说明s没有右孩子，也就是s当前结点就是p结点的前驱，所以直接断了s，连接s的左孩子（其实就是s为p的左孩子）
		{
			q->lchild = s->lchild;
		}
		delete s;
		s = NULL;
	}
	return p;
}
