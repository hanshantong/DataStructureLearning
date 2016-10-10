#include "LinkStackClass.h"

static void transPostExpress(char *str,char *&res)
{
	LinkStackClass<char> st;
	int i = 0;
	int j = 0;
	char ch;
	char e;
	while (str[i] != '\0')
	{
		ch = str[i];
		switch (ch)
		{

		case '(':
			st.Push(ch);
			break;
		case ')':
			while (!st.IsStackEmpty() && st.GetTop(e) && e != '(')
			{
				st.Pop(e);
				res[j++] = e;

			}
			st.Pop(e);  //µ¯³ö'('
			break;

		case '+':
		case '-':
			while (!st.IsStackEmpty() && st.GetTop(e) && e != '(')
			{
				st.Pop(e);
				res[j++] = e;
			}
			st.Push(ch);
			break;
		case '*':
		case '/':
			while (!st.IsStackEmpty() && st.GetTop(e) && e != '(' && (e == '*' || e == '/'))
			{
				st.Pop(e);
				res[j++] = e;
			}
			st.Push(ch);
			break;

		default:
			res[j++] = ch;
			break;
		}
		i++;
	}
	while (!st.IsStackEmpty())
	{
		st.Pop(e);
		res[j++] = e;
	}
}




int main()
{
	char *str = "A-B/(C+D)+E*F";
	char *res = new char[20];
	memset(res,0,20);

	transPostExpress(str, res);
	cout << res;
	system("pause");
	return 0;
}