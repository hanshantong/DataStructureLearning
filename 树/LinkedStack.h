#pragma once 

#define MAX_SIZE   256
#include <iostream>
using namespace std;


template <typename T>
struct LinkStack {
	T data;
	LinkStack *next;
};

template <typename T>
class LinkStackClass {
	LinkStack<T> *head;
	int num;
public:
	LinkStackClass();
	~LinkStackClass();
	bool IsStackEmpty();
	void Push(T e);
	bool Pop(T &e);
	T Pop();
	bool GetTop(T &e);
	int GetLength();
};


template <typename T>
T LinkStackClass<T>::Pop()
{
	LinkStack<T> *q;
	T x;
	if (head->next != NULL)
	{
		q = head->next;
		head->next = q->next;
		x = q->data;
		return x;
	}
	return NULL;
}


template <typename T>
int LinkStackClass<T>::GetLength() {
	return num;
}

template <typename T>
LinkStackClass<T>::LinkStackClass()
{
	head = new LinkStack<T>();
	head->next = NULL;
	num = 0;
}


template <typename T>
LinkStackClass<T>::~LinkStackClass()
{
	LinkStack<T> *p = head, *q;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		delete q;
		num--;
	}
}

template <typename T>
bool LinkStackClass<T>::IsStackEmpty()
{
	return (head->next == NULL);
}


template <typename T>
void LinkStackClass<T>::Push(T e)
{
	LinkStack<T> *s = new LinkStack<T>();
	s->data = e;
	s->next = head->next;
	head->next = s;
	num++;
}


template <typename T>
bool LinkStackClass<T>::Pop(T &e)
{
	LinkStack<T> *q;
	if (NULL == head->next)return false;
	q = head->next;
	head->next = q->next;
	e = q->data;
	delete q;
	num--;
	return true;

}


template <typename T>
bool LinkStackClass<T>::GetTop(T &e)
{
	LinkStack<T> *p;
	if (NULL == head->next)return false;
	p = head->next;
	e = p->data;
	return true;
}


template <typename T>
static void Reverse(LinkStackClass<T> &st) {
	int length = st.GetLength();
	T *temp = new T[length + 1];
	int i = 0;
	T e;
	while (!st.IsStackEmpty())
	{
		st.Pop(e);
		temp[i] = e;
		i++;
	}
	i = length - 1;
	while (i >= 0) {
		st.Push(temp[i]);
		i--;
	}
	delete temp;
}

