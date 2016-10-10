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
	/*cp�ǽ�λ*/
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


/*���������������ĳ˷�����*/
void bigNumberMul(int c,int b)
{
	/*cp�ǽ�λ*/
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


/*������Ľ׳�*/
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

	//cout << "\n�ڵ����=" << bc.NodeCount() << endl;
	//cout << "\n��Ϊ2�Ľڵ���=" << bc.Node2Child() << endl;
	//cout << "\n��Ϊ1�Ľڵ���=" << bc.Node1Child() << endl;
	//bc.CopyTree(bt);
	//cout << "���ƵĽ��\n";
	//bt.DispBTNode();

	//cout << "\n�ڵ�Ķ�=" << bc.Level('O') << endl;
	//cout << "�ڵ��˫��:";
	//bc.Parent('U');
	//
	//cout << "\n�ڵ����������:";
	//bc.Ancestor('P');



	//BTNode<char> *p = bc.FindNode('O');
	//if (p != NULL)cout <<endl << p->data << endl;
	//else
	//{
	//	cout << "\n�Ҳ���\n";
	//}
	//cout << bc.BTNodeHeight() << endl;

	//cout << "\n���������\n";
	//bc.PreOrder();

	//cout << "\n���������\n";
	//bc.MediumOrder();

	//cout << "\n���������\n";
	//bc.PostOrder();    

	//cout << "\n�ݹ���ڵ���" <<endl;
	//cout << "\n�ڵ����=" << bc.NodeCount() << endl;

	//cout << "Ҷ�ӽڵ㣺\n";
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
	/*cout << "��α���:\n";
	bc.LevelOrder();*/





	//cout << "\n�ǵݹ����������\n";
	//bc.PreOrder();

	//cout << "\n�ǵݹ����������\n";
	//bc.MediumOrder();


	//bc.PostOrder();


	system("pause");
	return 0;
}
