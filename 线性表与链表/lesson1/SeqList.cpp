#define MAX_SIZE  256

#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>

template <typename T> 
class SeqListClass;

template <typename T> 
void MyMerge(SeqListClass<T> &s1, SeqListClass<T> &s2, SeqListClass<T> &s3);


template <typename T>
class SeqListClass {
//public:
	T *data;
	int length;
public:
	SeqListClass();
	~SeqListClass();
	void CreateList(T a[],int n);
	void DispList();
	int ListLength();
	bool GetElem(int i, T &e);
	int LocateElem(T e);
	bool ListInsert(int i, T e);
	bool ListDelete(int i);
	void Reverse();
	bool DeleteElem(T x);
public:
	template <typename T> friend void MyMerge(SeqListClass<T> &s1, SeqListClass<T> &s2, SeqListClass<T> &s3);

};


template <typename T>
 void MyMerge(SeqListClass<T> &s1, SeqListClass<T> &s2, SeqListClass<T> &s3) {
	int i = 0;
	int j = 0;
	int k = 0;


	while (i < s1.length && j < s2.length) {
		if (s1.data[i] <= s2.data[j]) {
			s3.data[k] = s1.data[i];
			i++; k++; 
		}
		else{
			s3.data[k] = s2.data[j];
			j++; k++; 
		}
	}

	while (i < s1.length) {
		s3.data[k] = s1.data[i];
		i++; k++;  
	}

	while (j < s2.length) {
		s3.data[k] = s2.data[j];
		j++; k++; 

	}
	s3.length = k;
}


template <typename T>
bool SeqListClass<T>::DeleteElem(T x) {
	int i = 0;
	while ((i++) < length && x != data[i]);
	if (i >= length) {
		
		return false;
	}
	else {
		for (int j = i; j < length; j++) {
			data[j] = data[j + 1];
		}
		length--;
		return true;
	}
}



template <typename T>
void SeqListClass<T>::Reverse() {
	
	for (int i = 0; i < length / 2; i++) {
		data[i] = data[i] ^ data[length - 1 - i];
		data[length - 1 - i] = data[i] ^ data[length - 1 - i];
		data[i] = data[i] ^ data[length - 1 - i];
	}

}

template <typename T>
SeqListClass<T>::SeqListClass() {
	data = new T[MAX_SIZE];
	length = 0;
}


template <typename T>
SeqListClass<T>::~SeqListClass() { 
	if (NULL != data)
		delete[]data; 
}



template <typename T>
void SeqListClass<T>::CreateList(T a[], int n) {
	int i = 0;
	for (i = 0; i < n; i++) {
		data[i] = a[i];
	}
	length = i;
}


template <typename T>
void SeqListClass<T>::DispList() {
	if (length > 0) {
		for (int i = 0; i < length; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
	
	
}


template <typename T>
int SeqListClass<T>::ListLength() {
	return length;
}
template <typename T>
bool SeqListClass<T>::GetElem(int i, T &e) {
	if (i < 1 || i > length) {
		return false;
	}
	else {
		e = data[i - 1];
		return true;
	}

}


template <typename T>
int SeqListClass<T>::LocateElem(T e) {
	int i = 0;
	while (i < length && data[i] != e)i++;
	if (i >= length)return 0;
	else return i + 1;
}

template <typename T>
bool SeqListClass<T>::ListInsert(int i,T e) {
	int j;
	if (i < 1 || i > length + 1)return false;
	else
	{
		for (j = length; j >= i; j--) {
			data[j] = data[j - 1];
		}
		data[i-1] = e;
		length++;
		return true;
	}
}


template <typename T>
bool SeqListClass<T>::ListDelete(int i) {
	int j = 0;
	if (i < 1 || i > length)return false;
	else {
		for (j = i; j < length; j++) {
			data[j-1] = data[j];
		}
		length--;
		return true;
	}
}


int main()
{
	SeqListClass<int> s;
	SeqListClass<int> L;
	SeqListClass<int> s3;


	int a[10] = { 10, 12, 13, 15, 16, 17, 18, 20, 89, 987 };
	int b[7] = { 1,6,100, 150, 156, 324, 741 };
	s.CreateList(a, 10);
	L.CreateList(b,7);

	s.DispList();
	L.DispList();

	MyMerge(s,L,s3);
	s3.DispList();


	/*s.DeleteElem(20);
	s.DispList();*/

	/*s.DispList();

	cout << s.ListLength() << endl;
	int b;
	s.GetElem(2, b);
	cout << b << endl;

	cout << s.LocateElem(89) << endl;

	s.ListInsert(2,100);
	s.DispList();

	s.ListDelete(11);
	s.DispList();

	s.Reverse();
	s.DispList();*/




	system("pause");

	return 0;
}