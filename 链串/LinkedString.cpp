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
	     int q, k;//q:ģ���ַ����±ꣻk:���ǰ��׺����
	     int m = strlen(P);//ģ���ַ�������
	     next[0] = 0;//ģ���ַ����ĵ�һ���ַ������ǰ��׺����Ϊ0
	     for (q = 1, k = 0; q < m; ++q)//forѭ�����ӵڶ����ַ���ʼ�����μ���ÿһ���ַ���Ӧ��nextֵ
		     {
		         while (k > 0 && P[q] != P[k])//�ݹ�����P[0]������P[q]��������ͬ��ǰ��׺����k
			             k = next[k - 1];          //�����û��ϵ������ķ��������whileѭ�������δ���ľ������ڣ�ȷʵ�������  
		         if (P[q] == P[k])//�����ȣ���ô�����ͬǰ��׺���ȼ�1
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
	cout << "s2��ֵ��s3�Ľ��\n";
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

	/*�����ǰ����Ϊ�գ������ÿ�**/
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
