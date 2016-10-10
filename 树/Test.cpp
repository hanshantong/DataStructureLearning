#include "BTNodeClass.h"


void reverse(char *a, int n)
{
	
	if (1 == n)return;
	else
	{
		
		char ch = a[0];
		a[0] = a[n - 1];
		a[n - 1] = ch;
		reverse(a+1,n-2);
	}
}

#define N 10000
void func(int n)
{
	/*cp是进位*/
	int a[N];
	int i, j, cp, x, t, m = 2;
	a[N - 1] = 1;
	j = N - 2; cp = 0;
	for (t = 1; t<n; t++, m++)
	{
		for (i = N - 1; i>j; i--)
		{
			x = a[i] * m + cp;
			a[i] = x % 10;
			cp = x / 10;
		}
		while (cp)
		{
			a[j--] = cp % 10;
			cp = cp / 10;
		}
	}
	for (i = j + 1; i<N; i++)
		printf("%d", a[i]);
}


/*求任意两个大数的乘法运算*/
void bigNumberMul(int c,int b)
{
	/*cp是进位*/
	int a[N];
	int i, j, cp, x, m = 2;
	a[N - 1] = c;
	j = N - 2; cp = 0;
	
		for (i = N - 1; i>j; i--)
		{
			x = a[i] * b + cp;
			a[i] = x % 10;
			cp = x / 10;
		}
		while (cp)
		{
			a[j--] = cp % 10;
			cp = cp / 10;
		}
	
	for (i = j + 1; i<N; i++)
		printf("%d", a[i]);
	
}


/*求大数的阶乘*/
void bigNumberFac(int n)
{
	int a[N];
	a[N - 1] = 1;
	int cp = 0;
	int i = N - 1;
	int j = N - 2;
	int m = 2;
	int x;
	for (int t = 1; t < n; t++, m++)
	{
		for (i = N - 1; i > j; i--)
		{
			x = a[i] * m + cp;
			a[i] = x % 10;
			cp = x / 10;
		}


		while (cp)
		{
			a[j--] = cp % 10;
			cp = cp / 10;
		}
	}
	for (int t = j + 1; t < N; t++)
		cout << a[t];
	cout << endl;
}

typedef void (*PFunc)(int);

int main1()
{
	/*int a[4] = { 8, 7, 6, 5 };
	int b[3] = { 4, 3, 2 };*/
	//bigNumberMul(8765,432);
	//cout << endl << 8765 * 432 << endl;
	/*char *p = "Hello,world!";
	reverse(p, 12);
	cout << p << endl;*/


	bigNumberFac(5);







	//char *str = "A(B(D(,U)),C(T,G(Y(,H(P,O)))))";
	//BTNodeClass<char> bc,bt;
	//bc.CreateBTNode(str);
	//bc.DispBTNode();

	//cout << "\n节点个数=" << bc.NodeCount() << endl;
	//cout << "\n度为2的节点数=" << bc.Node2Child() << endl;
	//cout << "\n度为1的节点数=" << bc.Node1Child() << endl;
	//bc.CopyTree(bt);
	//cout << "复制的结果\n";
	//bt.DispBTNode();

	//cout << "\n节点的度=" << bc.Level('O') << endl;
	//cout << "节点的双亲:";
	//bc.Parent('U');
	//
	//cout << "\n节点的所有祖先:";
	//bc.Ancestor('P');



	//BTNode<char> *p = bc.FindNode('O');
	//if (p != NULL)cout <<endl << p->data << endl;
	//else
	//{
	//	cout << "\n找不到\n";
	//}
	//cout << bc.BTNodeHeight() << endl;

	//cout << "\n先序遍历：\n";
	//bc.PreOrder();

	//cout << "\n中序遍历：\n";
	//bc.MediumOrder();

	//cout << "\n后序遍历：\n";
	//bc.PostOrder();    

	//cout << "\n递归求节点数" <<endl;
	//cout << "\n节点个数=" << bc.NodeCount() << endl;

	//cout << "叶子节点：\n";
	//bc.printLeaves();



	

	system("pause");
	return 0;
}

int main()
{
	







	char *str = "A(B(D(,U)),C(T,G(Y(,H(P,O)))))";
	BTNodeClass<char> bc,bt;
	bc.CreateBTNode(str);
	bc.DispBTNode();

	bc.PreOrder();
	/*cout << "层次遍历:\n";
	bc.LevelOrder();*/





	//cout << "\n非递归先序遍历：\n";
	//bc.PreOrder();

	//cout << "\n非递归中序遍历：\n";
	//bc.MediumOrder();


	//bc.PostOrder();


	system("pause");
	return 0;
}
