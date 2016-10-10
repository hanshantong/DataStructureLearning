

#define MAX_SIZE  256
#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>



template <typename T>
struct DLinkList
{
	T data;
	DLinkList<T> *prior;
	DLinkList<T> *next;
	int freq;//����Ƶ��
};


template <typename T>
class CDLinkListClass {
public:
	DLinkList<T> *dhead;
public:
	CDLinkListClass<T>();
	~CDLinkListClass<T>();

	void CreateListF(T a[], int n);
	void CreateListR(T b[], int n);
	void DispList();
	int ListLength();
	bool GetElem(int i, T &e);
	int LocateElem(T e);
	bool ListInsert(int i, T e);
	bool ListDelete(int i);
	void Sort();  //����

	void Reverse();//��������


	//	friend int   MyFindLast(LinkListClass<T> &L, T x);
	template <typename T> friend bool DelNode(CDLinkListClass<T> &L, T x);

};


template <typename T>
bool CDLinkListClass<T>::ListDelete(int i) {
	int length = ListLength();
	int j = 0;
	DLinkList<T> *p = dhead;
	DLinkList<T> *q;
	if (i < 1 || i > length)return false;
	else {
	Label:if (j < i - 1){
		j++;
		p = p->next;

		goto Label;
	}

		  q = p->next;
		  p->next = q->next;
		  q->next->prior = p;
		  delete q;
		  return true;


	}
}


template <typename T>
bool CDLinkListClass<T>::ListInsert(int i, T e) {
	DLinkList<T> *s, *p;
	p = dhead;
	int j = 0;
	int length = ListLength();
	if (i < 1 || i > length)return false;
	else {
		while (j < i - 1 && p != NULL)
		{
			p = p->next;
			j++;
		}

		s = new DLinkList<T>();
		s->data = e;

		s->next = p->next;
		p->next->prior = s;
		p->next = s;
		s->prior = p;
		return true;


	}
}



template <typename T>
bool CDLinkListClass<T>::GetElem(int i, T &e) {
	int length = ListLength();
	DLinkList<T> *p = dhead;
	if (i < 1 || i > length)return false;
	else {
		for (int j = 0; j < i; j++, p = p->next);
		if (NULL != p)e = p->data;
		return true;
	}
}



template <typename T>
int CDLinkListClass<T>::ListLength() {
	int i = 0;
	DLinkList<T> *p = dhead;
	while (p->next != dhead) {
		i++;
		p = p->next;
	}
	return i;
}

template <typename T>
CDLinkListClass<T>::CDLinkListClass<T>() {
	dhead = new DLinkList<T>();
	dhead->next = NULL;
	dhead->prior = NULL;
}


template <typename T>
void CDLinkListClass<T>::DispList() {
	DLinkList<T> *p = dhead->next;
	while (p->next != dhead)
	{
		cout << p->data << "->";
		p = p->next;
	}
	cout << p->data << endl;
}


template <typename T>
CDLinkListClass<T>::~CDLinkListClass<T>() {

}


template <typename T>
void CDLinkListClass<T>::CreateListF(T a[], int n) {
	DLinkList<T> *s;
	int i = 0;
	for (i = 0; i < n; i++) {
		s = new DLinkList<T>();
		s->data = a[i];
		s->next = dhead->next;
		if (dhead->next != NULL)
			dhead->next->prior = s;
		if (NULL == dhead->next)
		{
			s->next = dhead;
			dhead->prior = s;
		}
			
		dhead->next = s;
		s->prior = dhead;

	}
}


template <typename T>
void CDLinkListClass<T>::CreateListR(T a[], int n) {
	DLinkList<T> *s, *p;
	p = dhead;
	int i = 0;
	for (i = 0; i < n; i++) {
		s = new DLinkList<T>();
		s->data = a[i];

		s->next = p->next;
		p->next = s;
		s->prior = p;
		p = s;


	}
	p->next = dhead;
	dhead->prior = p;
}


/**��Ԫ����*/
template <typename T>
bool DelNode(CDLinkListClass<T> &L, T x) {
	DLinkList<T> *p = L.dhead->next;
	for (; p != L.dhead && p->data != x; p = p->next);
	if (L.dhead == p)return false;
	else
	{
		p->prior->next = p->next;
		p->next->prior = p->prior;
		delete p;
		return true;
	}
}


int main()
{
	CDLinkListClass<int> d;
	int a[10] = { 21, 10, 58, 96, 24, 75, 203, 654, 873, 489 };

	d.CreateListF(a, 10);
	d.DispList();
	
	cout << d.ListLength() << endl;

	
	int e;
	d.GetElem(1, e);
	cout << e << endl;
	
	d.ListInsert(1, 2874);
	d.DispList();
	
	d.ListDelete(6);
	d.DispList();
	
	cout << "ɾ���ڵ��:\n";
	DelNode(d, 2874);
	d.DispList();
	

	system("pause");
	return 0;
}