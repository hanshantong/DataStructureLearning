#include "SeqStack.h"



static bool isSerial(int str[],int n)
{
	int i, j, e;
	int a[MAX_SIZE];
	SeqStackClass<int> st;
	for (i = 0; i < n; i++)a[i] = i + 1;
	i = 0; j = 0;
	while (i < n && j < n)
	{
		if (st.IsStackEmpty() || (st.GetTop(e) && e != str[j]))
		{
			st.Push(a[i]);
			cout << "元素" << a[i] << "进栈\n";
			i++;
			
		}
		else {
			st.Pop(e);
			cout << "元素" << e << "出栈\n";
			j++;

		}
	}

	while (!st.IsStackEmpty() && (st.GetTop(e) && e == str[j])) {
		st.Pop(e);
		cout << "元素" << e << "出栈\n";
		j++;
	}
	if (n == j)return true;
	return false;
}

static void Disp(int str[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << str[i];
	}
}



static bool isMatch(char str[], int n)
{
	SeqStackClass<char> st;
	int i = 0;
	char e;
	while (i < n)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			st.Push(str[i]);
		}
		else
		{
			if (str[i] == ')')
			{
				if (!st.Pop(e))return false;
				if (e != '(')return false;
			}


			if (str[i] == ']')
			{
				if (!st.Pop(e))return false;
				if (e != '[')return false;
			}


			if (str[i] == '}')
			{
				if (!st.Pop(e))return false;
				if (e != '{')return false;
			}
		}
		i++;
	}

	if (st.IsStackEmpty())return true;
	return false;


}

//回文判断
static bool isPalindrome(char str[], int n)
{
	SeqStackClass<char> st;
	int i = 0;
	while (i < n)
	{
		st.Push(str[i]);
		i++;
	}

	i = 0;
	char e;
	while (i < n)
	{
		st.Pop(e);
		if (e != str[i])return false;
		i++;
	}
	return true;


}


static int mainfsafsfa()
{
	int n = 9;
	char str[] = "123454321";

	if (isPalindrome(str, n))
	{
		cout << str << "是回文\n";
	}
	else {
		cout << str << "不是回文\n";
	}



	system("pause");
	return 0;
}

static int main131312()
{

	int n = 49;
	char str[] = "(((1+2)*3/(2-{4})+((1+265)*(58-96*54))*[{}()[]]))";
	if (isMatch(str, n))cout << str << "中括号是匹配的\n";
	else cout << str << "中括号不匹配\n";



	system("pause");
	return 0;
}


static int main2dfs354()
{

	SeqStackClass<int> s;
	s.Push(10);
	s.Push(100);
	s.Push(1000);
	s.Push(10000);
	s.Push(100000);

	int e;
	s.GetTop(e);
	cout << e << endl;
	int n = 4;
	int str[] = { 3, 2, 4, 1 };
	cout << "由1~" << n << "产生";
	Disp(str, n);
	cout << "的操作序列:\n";
	if (isSerial(str, n))
	{
		Disp(str, n);
		cout << "是合适的出栈序列\n";
	}
	else
	{
		Disp(str, n);
		cout << "不是合适的出栈序列\n";
	}

	system("pause");
	return 0;
}

