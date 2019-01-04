#include<iostream>

using namespace std;

const int MAXSIZE = 20;

template <typename T>
struct HuffmanNode
{
	HuffmanNode<T>(T k, HuffmanNode<T>* l, HuffmanNode<T>* r) :key(k), lchild(l), rchild(r), flag(0) {}
	T key;  // �ڵ��Ȩֵ
	HuffmanNode<T>* lchild; // �ڵ������
	HuffmanNode<T>* rchild; // �ڵ���Һ���
	int flag; // ��־���ж��Ƿ��ɭ����ɾ��
};

template <typename T>
class Huffman
{
public:
	Huffman() :root(NULL) {}
	~Huffman() { destory(root); }
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
inline void Huffman<T>::Creat(T a[], int size)
{
	int j, k = 0;
	for (int i = 0; i < size; i++)
	{
		HuffmanNode<T>* ptr = new HuffmanNode<T>(a[i], NULL, NULL);
		forest[i] = ptr;  
	}
	for (int i = 0; i < size - 1; i++)
	{
		mysort(size + k);
		for (j = 0; j < size + k; j++)
		{
			if (forest[j]->flag != 1 && forest[j + 1]->flag != 1)
			{
				HuffmanNode<T>* node = new HuffmanNode<T>(forest[j]->key + forest[j + 1]->key, forest[j], forest[j + 1]);
				forest[size + k] = node;
				k++;
				forest[j]->flag = 1;
				forest[j + 1]->flag = 1;
				break;
			}
			else
				continue;
		}
	}
	root = forest[size + k - 1];
}

template<typename T>
inline void Huffman<T>::destory(HuffmanNode<T>* root)
{
	if (root == NULL)
	{
		return;
	}
	destory(root->lchild);
	destory(root->rchild);
	delete root;
	root = NULL;
}

template<typename T>
inline void Huffman<T>::mysort(int size)
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
inline void Huffman<T>::preOrder(HuffmanNode<T>* root)
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
inline void Huffman<T>::inOrder(HuffmanNode<T>* root)
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
inline void Huffman<T>::postOrder(HuffmanNode<T>* root)
{
	if (root == NULL)
	{
		return;
	}
	postOrder(root->lchild);
	postOrder(root->rchild);
	cout << root->key;
}

// �ݹ��ӡ
template<typename T>
inline void Huffman<T>::print(HuffmanNode<T>* root)
{
	if (root == NULL)
	{
		return;
	}
	cout << "��ǰ���Ϊ��" << root->key << ".";
	if (root->lchild != NULL)
	{
		cout << "�������ӽ��Ϊ��" << root->lchild->key << ".";
	}
	else
	{
		cout << "��û������.";
	}
	if (root->rchild != NULL)
	{
		cout << "�����Һ��ӽ��Ϊ��" << root->rchild->key << ".";
	}
	else
	{
		cout << "��û���Һ���.";
	}
	cout << endl;
	print(root->lchild);
	print(root->rchild);
}
