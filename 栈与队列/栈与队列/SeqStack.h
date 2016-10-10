
#pragma once


#define MAX_SIZE   256
#include <iostream>
using namespace std;

template <typename T>
class SeqStackClass {
	T *data;
	int top;

public:
	SeqStackClass();
	~SeqStackClass();
	bool IsStackEmpty();
	bool Push(T e);
	bool Pop(T &e);
	bool GetTop(T &e);
};


template <typename T>
SeqStackClass<T>::SeqStackClass() {
	data = new T[MAX_SIZE];
	top = -1;
}


template <typename T>
SeqStackClass<T>::~SeqStackClass() {
	delete[] data;
}


template <typename T>
bool SeqStackClass<T>::IsStackEmpty() {
	return (-1 == top) ? true : false;
}


template <typename T>
bool SeqStackClass<T>::Push(T e) {
	if (top == (MAX_SIZE - 1))return false;
	top++;
	data[top] = e;
	return true;
}

template <typename T>
bool SeqStackClass<T>::Pop(T &e) {
	if (!IsStackEmpty())
	{
		e = data[top];
		top--;
		return true;
	}
	return false;

}


template <typename T>
bool SeqStackClass<T>::GetTop(T &e){
	if (IsStackEmpty())return false;
	e = data[top];
	return true;
}