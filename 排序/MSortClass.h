#pragma once
#include<iostream>
using namespace std;
const int MAX_SIZE = 100;

template <typename T>
struct RecType
{
	T key;
	char data;
};
template <typename T>
class MSortClass
{
private:
	RecType<T> R[MAX_SIZE];
	int length;
public:
	MSortClass()
	{
		length = 0;

	}
	void SetK(T a[],int n);				 //建立顺序表的关键字
	void DispR();						//输出R的所有元素
	void InsertSort();					 //直接插入排序
	void BinInsertSort();				//折半插入排序
	void ShellSort();					//希尔排序
	void BubbleSort();					 //冒泡排序
	void QuickSort();                     //快速排序
	void QuickSort(int s,int t);         //快速排序
	void SelectSort();					//选择排序
	void HeapSort();					 //堆排序
	void sift(int low, int high);       //堆排序的调整

	void MergeSort2();					//二路归并排序
private:
	void Merge1(int low, int mid, int high);   //将两个有序段归并为一个有序段
	void MergePass(int len);

};


template <typename T>
void MSortClass<T>::MergeSort2()
{
	for (int i = 1; i < length; i = 2 * i)
		MergePass(i);
}

template <typename T>
void MSortClass<T>::MergePass(int len)
{
	int i = 0;
	for (i = 0; i + 2 * len - 1 < length; i = 2 * len + i)
		Merge1(i, i + len - 1,i + 2 * len - 1);
	if (i + len - 1 < length)
		Merge1(i, i + len - 1, length - 1);
}

template <typename T>
void MSortClass<T>::Merge1(int low, int mid, int high)
{
	RecType<T> *R1 = new RecType<T>[high - low + 1];
	int i = low;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= high)
	{
		if (R[i].key < R[j].key)
		{
			R1[k] = R[i];
			i++;
			k++;
		}
		else
		{
			R1[k] = R[j];
			j++;
			k++;
		}
		
	}

	
	while (i <= mid)
	{
		
		R1[k++] = R[i];
		i++;
	}

	
	while (j <= high)
	{

		R1[k++] = R[j];
		j++;
	}

	for (k = 0, i = low; i <= high; k++, i++)
		R[i] = R1[k];
	delete[] R1;
		
}



template <typename T>
void MSortClass<T>::HeapSort() //堆排序
{
	int i;
	RecType<T> temp;
	for (i = length / 2 - 1; i >= 0; i--)
	{
		sift(i, length);
	}

	for (i = length-1; i >= 1; i--)
	{
		temp = R[0];
		R[0] = R[i];
		R[i] = temp;
		sift(0, i);
	}


	/*
	
	int i;
	RecType<T> temp;
	for (i = length / 2 - 1; i >= 0; i--)
		sift(i, length);
	for (i = length-1; i >= 1; i--)
	{
		temp = R[0];
		R[0] = R[i];
		R[i] = temp;
		sift(0, i);
	}
	*/

}


template <typename T>
void MSortClass<T>::sift(int low, int high)//堆排序的调整
{
	
	int i = low;
	int j = 2 * i + 1;
	RecType<T> temp = R[i];
	while (j < high)
	{
		if (j + 1 < high && R[j].key < R[j + 1].key)
			j++;
		if (R[j].key > temp.key)
		{
			R[i] = R[j];
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
	R[i] = temp;



	/*
	int i = low;
	int j = 2 * i+1;
	RecType<T> temp = R[i];
	while (j < high)
	{
		if (j + 1 < high && R[j].key < R[j + 1].key)
			j++;
		if (R[j].key > temp.key)
		{
			R[i] = R[j];
			i = j;
			j = 2 * i+1;
		}
		else   //假设节点i的做字树和右子树均已经是堆
			break;
	}
	R[i] = temp;
	
	
	*/

}




template <typename T>
void MSortClass<T>::SelectSort()
{
	int min;
	RecType<T> temp;
	for (int i = 0; i < length - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (R[j].key < R[min].key)
				min = j;
		}

		if (i != min)
		{
			temp = R[i];
			R[i] = R[min];
			R[min] = temp;
		}
	}
}

template <typename T>
void MSortClass<T>::QuickSort()
{
	QuickSort(0,length-1);
}

template <typename T>
void MSortClass<T>::QuickSort(int s, int t)
{
	int i = s;
	int j = t;
	RecType<T> temp;
	if (s < t)
	{
		temp = R[s];
		while (i != j)  //从区间两端开始交替向中间扫描 直到i==j为止
		{
			while (j > i && R[j].key >= temp.key)
				j--;
			R[i] = R[j];
			while (i < j && R[i].key <= temp.key)
				i++;
			R[j] = R[i];
		}
		R[i] = temp;
		QuickSort(s,i-1);
		QuickSort(i+1,t);
	}
}


template <typename T>
void MSortClass<T>::BubbleSort()
{
	RecType<T> temp;
	bool exchanged = false;
	for (int i = 0; i < length - 1; i++)
	{
		exchanged = false;
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (R[j].key > R[j + 1].key)
			{
				temp = R[j];
				R[j] = R[j + 1];
				R[j + 1] = temp;
				exchanged = true;
			}
		}
		if (!exchanged)
			return;
	}
}


template <typename T>
void MSortClass<T>::ShellSort()
{
	int i, j, d;
	RecType<T> temp;
	d = length / 2;
	while (d > 0)
	{
		for (i = d; i < length; i++)
		{
			temp = R[i];
			j = i - d;
			while (j >= 0 && R[j].key > temp.key)
			{
				R[j + d] = R[j];
				j = j - d;
			}
			R[j + d] = temp;
		}
		d = d / 2;
	}
}


template <typename T>
void MSortClass<T>::DispR()
{
	for (int i = 0; i < length; i++)
	{
		cout << R[i].key << " ";
	}
	cout << endl;
}


template <typename T>
void MSortClass<T>::SetK(T a[], int n)
{
	length = n;
	for (int i = 0; i < length; i++)
	{
		R[i].key = a[i];
	}
}


//直接插入排序
template <typename T>
void MSortClass<T>::InsertSort()
{
	int i = 0;
	int j = 0;
	RecType<T> temp;
	for (i = 1; i < length; i++)
	{
		if (R[i].key < R[i - 1].key)
		{
			j = i - 1;
			temp = R[i];
			do
			{
				R[j + 1] = R[j];
				j--;
			} while (j >= 0 && R[j].key > temp.key);
			R[j + 1] = temp;
		}

	}

}


//二分插入排序
template <typename T>
void MSortClass<T>::BinInsertSort()
{
	int j;
	int low;
	int high;
	int mid;
	RecType<T> temp;
	
	for (int i = 1; i < length; i++)
	{
		low = 0;
		high = i - 1;
		temp = R[i];
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (R[mid].key > R[i].key)
			{
				high = mid - 1;
			}
			else if (R[mid].key < R[i].key)
			{
				low = mid + 1;
			}
			
		}

		for (j = i; j > low; j--)
		{
			R[j] = R[j - 1];
		}
		R[j] = temp;


	}

}


