#pragma once
#include <iostream>
using namespace std;
#define MAX_SIZE (256)
template <typename T>

//class SeqQueueCircle {
//	T *data;
//	int front;
//	int rear;
//	
//public:
//	SeqQueueCircle();
//	~SeqQueueCircle();
//	bool IsQueueEmpty();
//	bool EnQueue(T e);
//	bool Dequeue(T &e);
//	int GetLength();
//};
//
//
//
//template <typename T>
//int SeqQueueCircle<T>::GetLength()
//{
//	int tp = rear - front;
//	
//	if (tp < 0)tp = -tp;
//	//cout << tp << endl;
//	return /*(tp + MAX_SIZE) % MAX_SIZE*/ tp;
//}
//template <typename T>
//SeqQueueCircle<T>::SeqQueueCircle()
//{
//	data = new T[MAX_SIZE];
//	front = rear = -1;
//	
//}
//
//template <typename T>
//SeqQueueCircle<T>::~SeqQueueCircle()
//{
//	delete[] data;
//	front = rear = 0;
//	
//}
//
//template <typename T>
//bool SeqQueueCircle<T>::IsQueueEmpty()
//{
//	return (front == rear);
//}
//
//
//template <typename T>
//bool SeqQueueCircle<T>::EnQueue(T e)
//{
//	if (front == (rear+1) % MAX_SIZE)return false;
//	rear = (rear + 1) % MAX_SIZE;
//	data[rear] = e;
//	
//	return true;
//}
//
//
//template <typename T>
//bool SeqQueueCircle<T>::Dequeue(T &e)
//{
//	if (front == rear)return false;
//	front = (front + 1) % MAX_SIZE;
//	e = data[front];
//	
//	return true;
//}


class SeqQueueCircle {
	T *data;
	int front;
	int count;

public:
	SeqQueueCircle();
	~SeqQueueCircle();
	bool IsQueueEmpty();
	bool EnQueue(T e);
	bool Dequeue(T &e);
	int GetLength();
};



template <typename T>
int SeqQueueCircle<T>::GetLength()
{
	
	return count;
}
template <typename T>
SeqQueueCircle<T>::SeqQueueCircle()
{
	data = new T[MAX_SIZE];
	front = 0;
	count = 0;

}

template <typename T>
SeqQueueCircle<T>::~SeqQueueCircle()
{
	delete[] data;
	front = count = 0;

}

template <typename T>
bool SeqQueueCircle<T>::IsQueueEmpty()
{
	return (0 == count);
}


template <typename T>
bool SeqQueueCircle<T>::EnQueue(T e)
{
	int rear;
	rear = (front + count) % MAX_SIZE;
	if (rear ==  MAX_SIZE)return false;
	rear = (rear + 1) % MAX_SIZE;
	data[rear] = e;
	count++;
	return true;
}


template <typename T>
bool SeqQueueCircle<T>::Dequeue(T &e)
{
	if (0 == count)return false;
	front = (front + 1) % MAX_SIZE;
	count--;
	e = data[front];

	return true;
}