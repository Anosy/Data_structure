//#include"Huffman.h"
#include"myHuffman.h"

int main()
{
	HuffmanTree<int> huff;
	int a[] = { 20,10,30,40 };
	huff.Creat(a, 4);
	huff.Print();

	system("pause");
	return 0;
}