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
//	cout << "���������ֵ" << endl;
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
		if (root == NULL) // �Ҳ����ͷ���NULL
		{
			cout << "�����ڸ�Ԫ��" << endl;
		}
		else // �ҵ��ͷ��ض�Ӧ����ָ��
		{
			cout << "���ڸ�Ԫ��" << endl;
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
		cout << "�����ڸ�Ԫ��" << endl;
	}
	else
	{
		cout << "���ڸ�Ԫ��" << endl;
	}
	return root;
}
 
inline BiNode * BiTree::DeleteBST(BiNode * root, int key)
{
	if (root == NULL)
	{
		cout << "�����ڸ�Ԫ��" << endl;
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
	if (p->rchild == NULL) // ���������Ϊ�գ���ֻ��Ҫ���½�����������
	{
		q = p;
		p = p->lchild;
		delete q;
	}
	else if (p->lchild == NULL) // ���������Ϊ�գ�ֱ�ӽ�������
	{
		q = p;
		p = p->rchild;
		delete q;
	}
	else // �����������������
	{
		q = p;
		BiNode* s = p->lchild;
		while (s->rchild) // ת��������Ȼ�������ߵ���ͷ���ҵ���ɾ�����ǰ��s
		{
			q = s;
			s = s->rchild;
		}

		p->data = s->data; // �滻Ҫ��ɾ����������

		if (q != p)			// ˵��s�����Һ��ӣ�sΪp��ǰ����㣬q��ʱ��Ϊs�ĸ���㣬q���Һ��Ӹ���Ϊs�����ӣ���ʵ����sΪq���Һ��ӣ�
		{
			q->rchild = s->lchild;
		}
		else                 // q == p˵��sû���Һ��ӣ�Ҳ����s��ǰ������p����ǰ��������ֱ�Ӷ���s������s�����ӣ���ʵ����sΪp�����ӣ�
		{
			q->lchild = s->lchild;
		}
		delete s;
		s = NULL;
	}
	return p;
}
