#pragma once
#include <iostream>
using namespace std;
#define MAX_SIZE (256)
#include <string>


struct LinkedNode
{
	char data;
	LinkedNode *next;
};

class LinkedString
{

	LinkedNode *head;
public:
	LinkedString();
	~LinkedString();
	LinkedString& operator =(const char *str);
	LinkedString& operator = (LinkedString &t);
	LinkedString& operator + (LinkedString &t);


	int GetLength();
	LinkedString& SubString(int i, int j);
	LinkedString& InsertString(int i, LinkedString &s);
	LinkedString& DelString(int i, int j);
	LinkedString& ReplaceString(int i, int j, LinkedString &s);
	void Display();
	bool isEqual(LinkedString &s);
	int StrCmp(LinkedString &s);
	int Match(LinkedString &s);

	friend ostream& operator << (ostream &output, LinkedString &s);
	friend istream& operator >> (istream &output, LinkedString &s);
	
};


static void makeNext(const char P[], int next[])
 {
	     int q, k;//q:模版字符串下标；k:最大前后缀长度
	     int m = strlen(P);//模版字符串长度
	     next[0] = 0;//模版字符串的第一个字符的最大前后缀长度为0
	     for (q = 1, k = 0; q < m; ++q)//for循环，从第二个字符开始，依次计算每一个字符对应的next值
		     {
		         while (k > 0 && P[q] != P[k])//递归的求出P[0]···P[q]的最大的相同的前后缀长度k
			             k = next[k - 1];          //不理解没关系看下面的分析，这个while循环是整段代码的精髓所在，确实不好理解  
		         if (P[q] == P[k])//如果相等，那么最大相同前后缀长度加1
			         {
			             k++;
			        }
		        next[q] = k;
		    }
	 }



int main()
{


	char *test = "abababca";
	int res[8];
	makeNext(test, res);
	for (int i = 0; i < 8; i++)cout << res[i] << " ";



	/*LinkedString s1, s2,s3;
	s1 = "abcdefghj"; 
	s3 = "a";
	s2 = "hj";
	cout << s1.Match(s2) << endl;*/


	/*
	cout << s1 << endl << s2 << endl << s3 << endl;
	s3 = s2;
	cout << "s2赋值给s3的结果\n";
	cout << s3 << endl << s2 << endl;*/

	/*s1 = "1234asdfg"; s2 = "5678";
	cout << "s1+s2=" << s1 + s2 << endl;

	cout << s1.GetLength() << endl;*/
	system("pause");
	return 0;

}


int LinkedString::Match(LinkedString &t)
{
	LinkedNode *s = head->next;
	LinkedNode *p = t.head->next;
	LinkedNode *q = s;
	int k = 0;
	while (p != NULL && q != NULL)
	{
		
		if (p->data == q->data)
		{
			p = p->next;
			q = q->next;
			//k++;
		}
		else
		{
			p = t.head->next;
			q = s->next;
			k ++;
			s = s->next;
		}
	}
	if (NULL == p) return k;
	else return -1;
}


int LinkedString::GetLength()
{
	LinkedNode *p = head->next;
	int i = 0;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}

	return i;
}


ostream& operator << (ostream &output, LinkedString &s)
{
	LinkedNode *p = s.head->next;
	while (p != NULL)
	{
		output << p->data;
		p = p->next;
	}

	return output;
}



LinkedString::LinkedString()
{
	head = new LinkedNode();
	head->next = NULL;
}

LinkedString::~LinkedString()
{
	LinkedNode *p = head->next,*q;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		delete q;
	}

}

LinkedString& LinkedString::operator = (const char *str)
{
	
	LinkedNode *p = head,*s;
	int i = 0;
	while ('\0' != str[i])
	{
		s = new LinkedNode();
		s->next = NULL;
		s->data = str[i];

		p->next = s;
		p = s;
		i++;
	}
	return *this;
}

LinkedString& LinkedString::operator = (LinkedString &t)
{
	LinkedNode *p = t.head->next;
	LinkedNode *q = head->next;
	LinkedNode *s;

	/*如果当前串不为空，则先置空**/
	while (q != NULL)
	{
		s = q;
		q = q->next;
		delete s;
	}
	q = head;
	while (p != NULL)
	{
		s = new LinkedNode();
		s->next = NULL;
		s->data = p->data;
		q->next = s;
		q = s;
		p = p->next;
	}

	return *this;
}

LinkedString& LinkedString::operator + (LinkedString &t)
{
	static LinkedString ls;
	LinkedNode *p = head->next;
	LinkedNode *s;
	LinkedNode *r = ls.head;

	while (p != NULL)
	{
		s = new LinkedNode();
		s->data = p->data;
		s->next = NULL;

		r->next = s;
		r = s;
		p = p->next;
	}

	p = t.head->next;
	while (p != NULL)
	{
		s = new LinkedNode();
		s->data = p->data;
		s->next = NULL;

		r->next = s;
		r = s;
		p = p->next;
	}
	return ls;

}
