

#define MAX_SIZE  256
#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>





template <typename T>
struct LinkList
{
	T data;
	LinkList<T> *next;
};



template <typename T>
class CLinkListClass {
public:
	LinkList<T> *head;
public:
	CLinkListClass<T>();
	~CLinkListClass<T>();

	void CreateListF(T a[], int n);
	void CreateListR(T b[], int n);
	void DispList();
	int ListLength();
	bool GetElem(int i, T &e);
	int LocateElem(T e);
	bool ListInsert(int i, T e);
	bool ListDelete(int i);
	void Sort();  //ÉýÐò

	void Reverse();//Á´±íÄæÐò


	template <typename T> friend int   MyFindLast(CLinkListClass<T> &L, T x);
	template <typename T> int Count(CLinkListClass<T> &L, T x);
	template <typename T> void Comb(CLinkListClass<T> &L1, CLinkListClass<T> &L2);

};






template <typename T>
int   MyFindLast(CLinkListClass<T> &L, T x) {
	LinkList<T> *p = L.head->next;
	int i = 0;
	int k = 0;
	while (p->next != L.head) {
		i++;
		if (p->data == x)
		{
			k = i;
		}
		p = p->next;
	}
	return k;
}



template <typename T>
void CLinkListClass<T>::Reverse() {
	LinkList<T> *p = head->next;
	LinkList<T> *q;
	head->next = head;
	while (p->next != head) {
		q = p->next;
		p->next = head->next;
		head->next = p;
		p = q;
	}
}



template <typename T>
void CLinkListClass<T>::Sort() {
	LinkList<T> *p, *q;
	for (p = head->next; p->next != head; p = p->next)
		for (q = head->next; q->next != head; q = q->next) {
			if (q->data > q->next->data)
			{
				q->data = q->data ^ q->next->data;
				q->next->data = q->data ^ q->next->data;
				q->data = q->data ^ q->next->data;
			}
		}
}



template <typename T>
bool CLinkListClass<T>::ListDelete(int i) {
	int length = ListLength();
	int j = 1;
	LinkList<T> *p = head;
	LinkList<T> *q;
	if (i <1 || i > length)return false;
	else {
		while (j < i) {
			p = p->next;
			j++;
		}
		q = p->next;
		p->next = q->next;
		delete q;
		return true;
	}

}

template <typename T>
bool CLinkListClass<T>::ListInsert(int i, T e) {
	LinkList<T> *p, *s;
	p = head;
	int j = 1;
	int length = ListLength();
	if (i > length || i < 1) return false;
	else {
		while (j < i)
		{
			j++;
			p = p->next;
		}

		s = new LinkList<T>();
		s->data = e;
		s->next = p->next;
		p->next = s;

		return true;

	}

}

template <typename T>
int CLinkListClass<T>::LocateElem(T e) {
	LinkList<T> *p;
	int i = 1;
	p = head->next;
	while (p->next != head && p->data != e) {
		p = p->next;
		i++;
	}
	if (NULL == p) return 0;
	else return i;
}

template <typename T>
bool CLinkListClass<T>::GetElem(int i, T &e) {
	int j = 0;
	LinkList<T> *p;
	p = head;
	while (j < i && p->next != head) {
		j++;
		p = p->next;
	}

	if (NULL == p)
	{
		return false;
	}
	else
	{
		e = p->data;
		return true;
	}
}

template <typename T>
int CLinkListClass<T>::ListLength() {
	LinkList<T> *p = head->next;
	int i = 0;
	while (p != head) {
		i++;
		p = p->next;
	}
	return i;
}

template <typename T>
void CLinkListClass<T>::DispList() {
	LinkList<T> *p;
	p = head->next;
	while (p->next != head) {
		cout << p->data << "->";
		p = p->next;
	}
	cout << p->data;
	cout << endl;

}


template <typename T>
CLinkListClass<T>::CLinkListClass() {
	head = new LinkList<T>();
	head->next = NULL;
}


template <typename T>
CLinkListClass<T>::~CLinkListClass() {
	LinkList<T> *pre, *p;
	pre = head;
	p = pre->next;
	while (pre->next != head) {
		delete pre;
		pre = p;
		p = p->next;
	}
	delete pre;
}


template <typename T>
void CLinkListClass<T>::CreateListF(T a[], int n) {
	LinkList<T> *s;
	int i;
	head->next = NULL;
	for (i = 0; i < n; i++)
	{
		s = new LinkList<T>();
		s->data = a[i];
		s->next = head->next;
		if (NULL == s->next) {
			s->next = head;
		}
		head->next = s;
	}
}


template <typename T>
void CLinkListClass<T>::CreateListR(T a[], int n) {
	LinkList<T> *s, *p;
	p = head;
	int i;
	for (i = 0; i < n; i++) {
		s = new LinkList<T>();
		s->data = a[i];

		s->next = head;
		p->next = s;
		p = s;
	}
}


/**ÓÑÔªº¯Êý*/

template <typename T>
int Count(CLinkListClass<T> &L, T x) {
	int iCount = 0;
	LinkList<T> *p = L.head->next;
	for (; p != L.head; p = p->next)
	{
		if (p->data == x)iCount++;
	}
	return iCount;
}

template <typename T>
void Comb(CLinkListClass<T> &L1, CLinkListClass<T> &L2) {
	LinkList<T> *p, *q;
	p = L1.head;
	q = L2.head;
	while (p->next != L1.head)p = p->next;
	p->next = L2.head->next;

	while (q->next != L2.head)q = q->next;
	q->next = L1.head;
	L2.head->next = L2.head;
}

int main21()
{

	CLinkListClass<int> s,k;
	int a[10] = { 15, 10, 12, 29, 16, 10, 18, 19, 25, 28 };
	int b[10] = {874,596,256,258,268,239,249,246,245,247};
	s.CreateListR(a, 10);
	k.CreateListR(b, 10);
	k.DispList();
	s.DispList();

	
	cout << s.ListLength() << endl;
	
	int e;
	s.GetElem(2, e);
	cout << e << endl;
	
	cout << s.LocateElem(25) << endl;
	
	cout << s.ListInsert(10, 289) << endl;
	s.DispList();
	
	cout << s.ListDelete(1) << endl;
	s.DispList();
	

	s.Sort();
	s.DispList();
	
	cout << MyFindLast(s, 10) << endl;
	
	s.Reverse();
	s.DispList();
	/* << MyFindLast(s, 10) << endl;*/

	cout << Count(s, 10) << endl;
	system("pause");
	return 0;
}


int main874() {

	CLinkListClass<int> s, k;
	int a[10] = { 15, 10, 12, 29, 16, 10, 18, 19, 25, 28 };
	int b[10] = { 874, 596, 256, 258, 268, 239, 249, 246, 245, 247 };
	s.CreateListR(a, 10);
	k.CreateListR(b, 10);
	
	s.DispList();
	k.DispList();

	Comb(s, k);
	s.DispList();

	k.DispList();




	system("pause");
	return 0;
}