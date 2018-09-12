/*
*author：     tongzi
*date：       2018/09/12
*description：heap sort test
*
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class HeadSort
{
public:
	HeadSort();
	HeadSort(size_t sz=10);
	virtual ~HeadSort();

public:
	void create();  //create a heap
	void downJudge(int low, int high);
	void upJudge(int low, int high);

	void insert_heap(T& e);
	void delete_heap(T& e);

	void print()
	{
		for(int i=0; i < heap_size; ++i)
		{
			cout << heap[i] << " ";
		}
	}


	void heap_sort();

private:
	T* heap;

	size_t heap_size;

};

template<typename T>
void HeadSort<T>::heap_sort()
{
	//将堆顶元素和最后一个元素交换，然后向下调整
	for(int i = heap_size-1; i>0; --i)
	{
		swap(heap[i],heap[0]);
		downJudge(0,i-1);
	}
}

template<typename T>
HeadSort<T>::HeadSort(size_t sz)
{
	heap_size = sz;
	heap = new T[sz];

}

template<typename T>
HeadSort<T>::~HeadSort()
{
	if(nullptr != heap)
	{
		delete heap;
	}
}

template<typename T>
HeadSort<T>::HeadSort()
{
	heap = new T[10];
}


template <typename T>
void HeadSort<T>::create()
{
	for(int i = 0; i < heap_size; ++i)
	{
		cin >> heap[i];
	}
	for(int i = heap_size/2-1; i>=0; i--)
	{
		downJudge(i,heap_size);
	}
}

/*
*向下调整发生在创建堆和插入元素的时候的时候
*
*/
template <typename T>
void HeadSort<T>::downJudge(int low, int high)
{
	int i = low;
	int j = 2 * i;
	while(j <= high )
	{
		//寻找子节点中最小的元素，并将j指向这个元素
		if((j + 1) <= high && heap[j] > heap[j+1])//最小堆
		{
			++j;
		}

		//如果父节点比子节点的最小元素还大，则交换
		if(heap[i] > heap[j])
		{
			swap(heap[i],heap[j]);
			i = j;
			j = 2 * i;
		}else
		{
			break;
		}

	}

}

/*
*
*向上调整发生在删除堆顶元素的时候
*
*/
template <typename T>
void HeadSort<T>::upJudge(int low, int high)
{
	int i = high;
	int j = i / 2;  //父节点
	while(j >= low)
	{
		//父节点大于子节点
		if(heap[j] > heap[i])
		{
			swap(heap[j],heap[i]);
			i = j;
			j = i / 2;
		}else
		{
			break;
		}

	}


}


//test
int main()
{
	HeadSort<int> hs(8);
	hs.create();
	hs.print();
	cout << endl;
	hs.heap_sort();
	hs.print();


	return 0;
}




