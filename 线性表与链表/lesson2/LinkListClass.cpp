

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
class LinkListClass;


template <typename T>
int MyFindLast(LinkListClass<T> &L, T x);






template <typename T>
class LinkListClass {
public:
	LinkList<T> *head;
public:
	LinkListClass<T>();
	~LinkListClass<T>();

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


	template <typename T> friend int   MyFindLast(LinkListClass<T> &L, T x);


};






template <typename T>
int   MyFindLast(LinkListClass<T> &L, T x) {
	LinkList<T> *p = L.head->next;
	int i = 0;
	int k = 0;
	while (p != NULL) {
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
void LinkListClass<T>::Reverse() {
	LinkList<T> *p = head->next;
	LinkList<T> *q;
	head->next = NULL;
	while (p != NULL) {
		q = p->next;
		p->next = head->next;
		head->next = p;
		p = q;
	}
}



template <typename T>
void LinkListClass<T>::Sort() {
	LinkList<T> *p, *q;
	for (p = head->next; p != NULL; p = p->next)
		for (q = head->next; q->next != NULL; q = q->next) {
			if (q->data > q->next->data)
			{
				q->data = q->data ^ q->next->data;
				q->next->data = q->data ^ q->next->data;
				q->data = q->data ^ q->next->data;
			}
		}
}



template <typename T>
bool LinkListClass<T>::ListDelete(int i) {
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
bool LinkListClass<T>::ListInsert(int i, T e) {
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
int LinkListClass<T>::LocateElem(T e) {
	LinkList<T> *p;
	int i = 1;
	p = head->next;
	while (p != NULL && p->data != e) {
		p = p->next;
		i++;
	}
	if (NULL == p) return 0;
	else return i;
}

template <typename T>
bool LinkListClass<T>::GetElem(int i, T &e) {
	int j = 0;
	LinkList<T> *p;
	p = head;
	while (j < i && p != NULL) {
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
int LinkListClass<T>::ListLength() {
	LinkList<T> *p = head->next;
	int i = 0;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

template <typename T>
void LinkListClass<T>::DispList() {
	LinkList<T> *p;
	p = head->next;
	while (p->next) {
		cout << p->data << "->";
		p = p->next;
	}
	cout << p->data;
	cout << endl;

}


template <typename T>
LinkListClass<T>::LinkListClass() {
	head = new LinkList<T>();
	head->next = NULL;
}


template <typename T>
LinkListClass<T>::~LinkListClass() {
	LinkList<T> *pre, *p;
	pre = head;
	p = pre->next;
	while (pre->next != NULL) {
		delete pre;
		pre = p;
		p = p->next;
	}
	delete pre;
}


template <typename T>
void LinkListClass<T>::CreateListF(T a[], int n) {
	LinkList<T> *s;
	int i;
	head->next = NULL;
	for (i = 0; i < n; i++)
	{
		s = new LinkList<T>();
		s->data = a[i];
		s->next = head->next;
		head->next = s;
	}
}


template <typename T>
void LinkListClass<T>::CreateListR(T a[], int n) {
	LinkList<T> *s, *p;
	p = head;
	int i;
	for (i = 0; i < n; i++) {
		s = new LinkList<T>();
		s->data = a[i];
		s->next = NULL;
		p->next = s;
		p = s;
	}
}


/**ÓÑÔªº¯Êý*/


int main12()
{

	LinkListClass<int> s;
	int a[10] = { 15, 10, 12, 29, 16, 10, 18, 19, 25, 28 };

	s.CreateListR(a, 10);
	s.DispList();

	/*
	cout << s.ListLength() << endl;
	int e;
	s.GetElem(2, e);
	cout << e << endl;
	cout << s.LocateElem(15) << endl;
	cout << s.ListInsert(-1, 289) << endl;
	s.DispList();

	cout << s.ListDelete(1) << endl;
	s.DispList();
	*/
	s.Sort();
	s.DispList();

	cout << MyFindLast(s, 10) << endl;
	s.Reverse();
	s.DispList();
	cout << MyFindLast(s, 10) << endl;

	system("pause");
	return 0;
}