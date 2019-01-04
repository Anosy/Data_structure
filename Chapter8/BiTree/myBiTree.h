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
	if (root == NULL)  // �����е�ǰ�Ľ���Ƿ�Ϊ�գ����Ϊ�ձ�ʾ����û�иý��
	{
		BiTNode * p = new BiTNode;
		p->data = key;
		p->lchild = p->rchild = NULL;
		root = p;
	}
	else if (key < root->data) // ����ȵ�ǰ���С����ô����������������
	{
		root->lchild = insertBST(root->lchild, key);
	}
	else if (key > root->data) // ����ȵ�ǰ�Ľ�����ô����������������
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
		return root; // ������ص��ǿձ��������ڣ�������طǿգ���ʾ���ض�Ӧ����ָ��
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
		cout << "�����ڸ�Ԫ��" << endl;
	}
	else
	{
		cout << "���ڸ�Ԫ��" << endl;
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
ɾ�����������������
1.ɾ���ĵ�ΪҶ�ӽ�㣬��ôֱ��ɾ����㼴��
2.ɾ���ĵ��ֻ������������ֻ�����������������ôֱ�ӽ�������������������
3.ɾ���ĵ㲻��������������������������ô������Ҫ���⴦��
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
		BiTNode *s = p->lchild; // ���ҵ�Ҫɾ�����������
		while (s->rchild) // ѭ���ҵ�Ҫɾ����p��ǰ������s
		{
			q = s;
			s = s->rchild;
		}

		p->data = s->data; // �滻Ҫ��ɾ�����ֵΪ���ǰ��s��ֵ

		if (q != p) // ˵��p�����������
		{
			q->rchild = s->lchild;
		}
		else     // ˵��p��ֻ����������������p�����ӽ�s�����Ӽ���
		{
			q->lchild = s->lchild;
		}
		delete s;
	}
	return p;
}


