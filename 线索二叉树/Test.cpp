#include "BthTree.h"
int main()
{


	char *str = "A(B(D(,G)),C(E,F))";
	BthTree<char> bc;
	bc.CreateTree(str);
	bc.DispBthNode();

	//bc.CreatBTreeThread();
	//cout << "\n�����������������:\n";
	//bc.ThInOrder();

	//bc.CreatePreOrder();
	//bc.PreOrder();

	bc.CreatePostOrder();
	bc.PostOrder();
	system("pause");
	return 0;
}