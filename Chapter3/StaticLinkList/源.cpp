// #include"StaicLinkList.h"
#include"myStaticLinkList.h"

using namespace std;

int main()
{
	myStaticLinkList<int> myList;
	myList.Insert(111, 1);
	myList.Insert(222, 2);
	myList.Print();
	myList.Delete(2);
	myList.Print();

	system("pause");
	return 0;
}