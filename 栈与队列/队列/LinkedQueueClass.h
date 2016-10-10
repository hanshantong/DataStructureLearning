#pragma once
#include <iostream>
using namespace std;

#define MAX_SZIE (256)

template <typename T>
struct LinkedNode {
	T data;
	LinkedNode *next;
};


template <typename T>
struct LinkedQueue {
	LinkedNode<T> *front;
	LinkedNode<T> *rear;
};


template <typename T>
class LinkedQueueClass {
	LinkedQueue<T> *Q;
public:
	LinkedQueueClass();
	~LinkedQueueClass();
	bool IsQueueEmpty();
	void EnQueue(T e);
	bool Dequeue(T &e);
	int GetLength();

};



template <typename T>
int LinkedQueueClass<T>::GetLength()
{

	
}


template <typename T>
LinkedQueueClass<T>::LinkedQueueClass()
{
	Q = new LinkedQueue<T>();
	Q->front = NULL;
	Q->rear = NULL;
}

template <typename T>
LinkedQueueClass<T>::~LinkedQueueClass()
{
	LinkedNode<T> *p = Q->front,*q;
	while (p)
	{
		q = p;
		p = p->next;
		delete q;
	}
	delete Q;

}

template <typename T>
bool LinkedQueueClass<T>::IsQueueEmpty()
{
	return (NULL == Q->rear);
}


template <typename T>
void LinkedQueueClass<T>::EnQueue(T e)
{
	LinkedNode<T> *s = new LinkedNode<T>();
	s->next = NULL;
	s->data = e;
	if (Q->rear == NULL)
	{
		Q->front = s;
		Q->rear = s;
	}
	else
	{
		Q->rear->next = s;
		Q->rear = s;
	}

}


template <typename T>
bool LinkedQueueClass<T>::Dequeue(T &e)
{
	LinkedNode<T> *p = Q->front;
	if (Q->rear == NULL)return false;
	else {
		
		if (Q->front == Q->rear)
			Q->front = Q->rear = NULL;
		Q->front = p->next;
		e = p->data;
		delete p;
		return true;
	}
}