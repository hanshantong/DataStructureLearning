#pragma once
#include <iostream>
using namespace std;

#define MAX_SZIE (256)

template <typename T>
struct CLinkedNode {
	T data;
	CLinkedNode *next;
};


template <typename T>
class CircleLinkedQueue
{
	CLinkedNode<T> *rear;//始终指向队尾
public:
	CircleLinkedQueue();
	~CircleLinkedQueue();
	bool IsQueueEmpty();
	void EnQueue(T e);
	bool Dequeue(T &e);

};



template <typename T>
CircleLinkedQueue<T>::CircleLinkedQueue()
{
	rear = NULL;
}

template <typename T>
CircleLinkedQueue<T>::~CircleLinkedQueue()
{
	CLinkedNode<T> *p = rear, *q;
	if (NULL == rear)return;
	else
	{
		p = rear->next;
		while (p != rear)
		{
			q = p;
			p = p->next;
			delete q;
		}
		delete p;
	}

}

template <typename T>
bool CircleLinkedQueue<T>::IsQueueEmpty()
{
	return (NULL == rear);
}


template <typename T>
void CircleLinkedQueue<T>::EnQueue(T e)
{
	CLinkedNode<T> *s = new CLinkedNode<T>();
	s->next = NULL;
	s->data = e;
	if (rear == NULL)
	{
		rear = s;
		rear->next = s;
	}
	else
	{
		s->next = rear->next;
		rear->next = s;
		rear = s;

	}

}


template <typename T>
bool CircleLinkedQueue<T>::Dequeue(T &e)
{
	CLinkedNode<T> *p;
	if (rear == NULL)return false;
	else {
		if (rear == rear->next)
		{
			e = rear->data;
			delete rear;
			rear = NULL;
			return true;
		}
		p = rear->next;
		e = p->data;
		rear->next = p->next;
		delete p;
		return true;
	}
}