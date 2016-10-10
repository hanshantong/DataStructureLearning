//#include "SeqStackClass.cpp"
#include "SeqStack.h"
//#include "Test.h"

class ExpressionClass {
	char *exp;
	char postexp[MAX_SIZE];
	int pnum;//postexp元素个数

public:
	ExpressionClass();
	~ExpressionClass(){ //delete exp; delete[] postexp; 
	}
	void SetExp(char *exp);
	void Trans();
	bool GetValue(double &v);
	void Display();

};

ExpressionClass::ExpressionClass()
{
	exp = NULL;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		postexp[i] = '\0';
	}
}



bool ExpressionClass::GetValue(double &v)
{
	SeqStackClass<double> st;
	int i = 0;
	double a, b, c, d;
	char ch;
	while (i < pnum)
	{
		ch = postexp[i];
		switch (ch)
		{
		case '+':
			st.Pop(a);
			st.Pop(b);
			c = b + a;
			st.Push(c);
			break;
		case '-':
			st.Pop(a);
			st.Pop(b);
			c = b - a;
			st.Push(c);
			break;
		case '*':
			st.Pop(a);
			st.Pop(b);
			c = b * a;
			st.Push(c);
			break;
		case '/':
			st.Pop(a);
			st.Pop(b);
			if (0 != a)
			{
				c = b / a;
				st.Push(c);
			}
			
			break;
		default:
			d = 0;
			while (ch >= '0' && ch <= '9')
			{
				d = 10 * d + (ch - '0');
				ch = postexp[++i];
			}
			st.Push(d);

			break;
		}
		i++;
	}
	st.GetTop(v);
	return true;
}


void ExpressionClass::Display()
{
	cout << postexp << endl;
}

void ExpressionClass::SetExp(char *exp)
{
	this->exp = exp;
}

void ExpressionClass::Trans()
{
	int i = 0;
	int j = 0;
	SeqStackClass<char> op;
	char ch, e;
	while (exp[i] != '\0')
	{
		ch = exp[i];
		if (ch == '(')op.Push(ch);
		else if (')' == ch)
		{
			while (!op.IsStackEmpty() && (op.GetTop(e) && e != '('))
			{
				op.Pop(e);
				postexp[j++] = e;
			}

			op.Pop(e);//将(退栈
			
		}
		else if (ch == '+' || ch == '-')
		{
			while (!op.IsStackEmpty() && (op.GetTop(e) && e != '('))
			{
				op.Pop(e);
				postexp[j++] = e;
			}
			op.Push(ch);
		}
		else if (ch == '*' || ch == '/')
		{
			while (!op.IsStackEmpty() && (op.GetTop(e) && e != '(' && (e == '*' || e == '/')))
			{
				op.Pop(e);
				postexp[j++] = e;
			}
			op.Push(ch);
		}
		else
		{
			while (ch >= '0' && ch <= '9')
			{
				postexp[j++] = ch;
				i++;
				if (exp[i])ch = exp[i];
				else break;
			}

			i--;
			postexp[j++] = '#';
		}
		i++;
	}

	while (!op.IsStackEmpty())
	{
		op.Pop(e);
		postexp[j++] = e;
	}
	pnum = j;
}

int maingdgfdgdd()
{
	//Test t;
	//t.display();

	ExpressionClass ec;
	char *exp = "1+2*3";
	ec.SetExp(exp);
	ec.Trans();
	ec.Display();

	double v;
	bool ret = ec.GetValue(v);
	if (ret)
		cout << endl << v << endl;

	system("pause");
	return 0;
}
