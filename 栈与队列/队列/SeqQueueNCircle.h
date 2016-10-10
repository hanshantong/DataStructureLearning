#pragma once
#include <iostream>
using namespace std;

#define MAX_SIZE 256


template <typename T>
class SeqQueueNCircle {
	T *data;
	int front;
	int rear;
	int num; //队列中元素个数
public:
	SeqQueueNCircle();
	~SeqQueueNCircle();
	bool IsQueueEmpty();
	bool EnQueue(T e);
	bool Dequeue(T &e);
	int GetLength();
};


template <typename T>
int SeqQueueNCircle<T>::GetLength()
{
	return num;
}
template <typename T>
SeqQueueNCircle<T>::SeqQueueNCircle()
{
	data = new T[MAX_SIZE];
	front = rear = -1;
	num = 0;
}

template <typename T>
SeqQueueNCircle<T>::~SeqQueueNCircle()
{
	delete[] data;
	front = rear = -1;
	num = 0;
}

template <typename T>
bool SeqQueueNCircle<T>::IsQueueEmpty()
{
	return (front == rear);
}


template <typename T>
bool SeqQueueNCircle<T>::EnQueue(T e)
{
	if (MAX_SIZE - 1 == rear)return false;
	data[++rear] = e;
	num++;
	return true;
}


template <typename T>
bool SeqQueueNCircle<T>::Dequeue(T &e)
{
	if (front == rear)return false;
	e = data[++front];
	num--;
	return true;
}
