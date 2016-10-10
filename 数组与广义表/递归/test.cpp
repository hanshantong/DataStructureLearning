#include <iostream>
#include <ctype.h>
#include <fstream>
using namespace std;


void hanota(int n, char x, char y, char z)
{
	static streambuf *coutbuf = cout.rdbuf();
	static ofstream out("res.txt");

	if (1 == n)
		cout << "将第" << n << "个圆盘从" << x << "移动到" << z << "上\n";
	else
	{
		hanota(n - 1, x, z, y);
		cout << "将第" << n << "个圆盘从" << x << "移动到" << z << "上\n";
		hanota(n-1,y,x,z);
	}

	cout.rdbuf(coutbuf);
}

int matriMin(int a[], int n)
{
	int min;
	if (0 == n)
		return a[n];
	else
	{
		//cout << "matrixMin(a," << n - 1 << ")\n";
		return (a[n-1] < matriMin(a,n - 1)) ? a[n-1] : matriMin(a,n - 1);

	}
	
}

int main()
{
	int n = 10;
	//hanota(3,'x','y','z');
	int a[] = {10,12,2,65,89,74,123,65,14,-70};
	cout << matriMin(a, n) << endl;
	system("pause");
	return 0;
}


