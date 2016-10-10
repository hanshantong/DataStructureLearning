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
			cout << "Ԫ��" << a[i] << "��ջ\n";
			i++;
			
		}
		else {
			st.Pop(e);
			cout << "Ԫ��" << e << "��ջ\n";
			j++;

		}
	}

	while (!st.IsStackEmpty() && (st.GetTop(e) && e == str[j])) {
		st.Pop(e);
		cout << "Ԫ��" << e << "��ջ\n";
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

//�����ж�
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
		cout << str << "�ǻ���\n";
	}
	else {
		cout << str << "���ǻ���\n";
	}



	system("pause");
	return 0;
}

static int main131312()
{

	int n = 49;
	char str[] = "(((1+2)*3/(2-{4})+((1+265)*(58-96*54))*[{}()[]]))";
	if (isMatch(str, n))cout << str << "��������ƥ���\n";
	else cout << str << "�����Ų�ƥ��\n";



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
	cout << "��1~" << n << "����";
	Disp(str, n);
	cout << "�Ĳ�������:\n";
	if (isSerial(str, n))
	{
		Disp(str, n);
		cout << "�Ǻ��ʵĳ�ջ����\n";
	}
	else
	{
		Disp(str, n);
		cout << "���Ǻ��ʵĳ�ջ����\n";
	}

	system("pause");
	return 0;
}

