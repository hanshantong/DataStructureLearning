#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define MAX_SIZE 256
template <typename T> class TwoSet;
template <typename T>
class Set {
	T *data;
	int n;
public:
	Set();
	virtual ~Set();
	bool IsIn(T e);
	bool Insert(T e);
	bool Remove(T e);
	void Display();
	friend class TwoSet<T> ;

};

template <typename T>
Set<T>::Set() {
	data = new T[MAX_SIZE];
	n = 0;
}


template <typename T>
Set<T>::~Set() {
	delete[] data;
}

template <typename T>
bool Set<T>::IsIn(T e) {
	for (int i = 0; i < n; i++) {
		if (e == data[i])
			return true;
	
	}
	return false;
}


template <typename T>
bool Set<T>::Insert(T e) {

	if (IsIn(e))return false;
	else {
		data[n] = e;
		n++;
		return true;
	}

}


template <typename T>
bool Set<T>::Remove(T e) {
	int i = 0;
	int j = 0;
	while (i < n && data[i] != e) {
		i++;
	}
	if (i >= n)return false;
	else {
		for (j = i; i < n; j++) {
			data[j] = data[j + 1];
		}
		n--;
		return true;
	}
}

template <typename T>
void Set<T>::Display() {
	for (int i = 0; i < n; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

template <typename T>
class TwoSet {
public:
	bool Union(Set<T> &s1, Set<T> &s2, Set<T> &s3);
	bool Intersection(Set<T> &s1, Set<T> &s2, Set<T> &s3);
	bool Differcence(Set<T> &s1, Set<T> &s2, Set<T> &s3);

};


template <typename T>
bool TwoSet<T>::Union(Set<T> &s1, Set<T> &s2, Set<T> &s3) {
	if (&s1 == &s2)return false;
	for (int i = 0; i < s1.n; i++) {
		s3.Insert(s1.data[i]);
	}
	for (int j = 0; j < s2.n; j++) {
		if (!s1.IsIn(s2.data[j])) {
			s3.Insert(s2.data[j]);
		}
	}
	return true;
}


template <typename T>
bool TwoSet<T>::Intersection(Set<T> &s1, Set<T> &s2, Set<T> &s3) {
	if (&s1 == &s2)return false;
	for (int i = 0; i < s1.n; i++) {
		if (s2.IsIn(s1.data[i])) {
			s3.Insert(s1.data[i]);
		}

	}
	return true;
}

template <typename T>
bool TwoSet<T>::Differcence(Set<T> &s1, Set<T> &s2, Set<T> &s3) {
	if (&s1 == &s2)return false;
	for (int i = 0; i < s1.n; i++) {
		if (!s2.IsIn(s1.data[i])) {
			s3.Insert(s1.data[i]);
		}
		
	}
	return true;
}


int main()
{
	Set<int> s1, s2, s3, s4, s5;
	TwoSet<int> t;
	s1.Insert(1);
	s1.Insert(4);
	s1.Insert(2);
	s1.Insert(6);
	s1.Insert(8);
	s1.Display();


	s2.Insert(2);
	s2.Insert(5);
	s2.Insert(3);
	s2.Insert(6);
	s2.Display();

	cout << "s1和s2的并集:\n";
	t.Union(s1, s2, s3);
	s3.Display();

	cout << "s1和s2的交集:\n";
	t.Intersection(s1, s2, s4);
	s4.Display();
	

	cout << "s1和s2的差集:\n";
	t.Differcence(s1, s2, s5);
	s5.Display();
	system("pause");
	return 0;
}
