#ifndef MINHEAD_H
#define MINHEAD_H
#include<iostream>
using namespace std;

#define DEFAULT_SIZE    (100)

template <typename E>
class MinHeap
{
    public:
        MinHeap(int sz = DEFAULT_SIZE);
        MinHeap(E arr[],int len);
        virtual ~MinHeap();

        bool Insert(const E& x);  //插入元素到最小堆中
        bool isEmpty()const{return (0==mCurrentSize) ? true : false;} //最小堆是否为空
        bool isFull()const{return (mCurrentSize == mMaxHeadSize) ? true : false;}   //最小堆是否已满
        void MakeEmpty(){mCurrentSize = 0;} //将最小堆置空
        bool RemoveMin(E& x);  //将堆中的最小元素删除

        void print()
        {
            for(int i=0; i < mCurrentSize; ++i)
                cout << mHeap[i] << " ";
            cout << endl;
        }

        std::ostream& operator<< (E& e)
        {
            return cout<<e;
        }

        /*
        bool operator<(E& e1,E& e2)
        {
            return e1>e2 ? true : false;
        }
        */

    protected:

    private:
        E* mHeap;   //存放最小堆中元素的数组
        int mCurrentSize;  //最小堆当前元素个数
        int mMaxHeadSize;   //最小堆允许存放的最大元素个数
        void siftDown(int start, int stop);  //从start到stop下滑调整成为最小堆
        void siftUp(int start);  //从start到0上滑调整成为最小堆

};

/*构造函数*/
template <typename E>
MinHeap<E>::MinHeap(int sz)
{
    mMaxHeadSize = sz>DEFAULT_SIZE ? sz : DEFAULT_SIZE;
    mHeap = new E[mMaxHeadSize];
    if(nullptr == mHeap)
    {
        cerr << "堆存储空间分配失败!!!\n";
        exit(1);
    }
    mCurrentSize = 0;
}

/*构造函数*/
template <typename E>
MinHeap<E>::MinHeap(E arr[],int len)
{
    mMaxHeadSize = len>DEFAULT_SIZE ? len : DEFAULT_SIZE;
    mHeap = new E[mMaxHeadSize];
    if(nullptr == mHeap)
    {
        cerr << "堆存储空间分配失败!!!\n";
        exit(1);
    }

    for(int i=0; i < len; ++i)
    {
        mHeap[i] = arr[i];
    }
    mCurrentSize = len;
    int currentPos = (mCurrentSize-1-1)/2;
    while(currentPos >= 0)
    {
        siftDown(currentPos,mCurrentSize-1);
        --currentPos;
    }

}


/*析构函数*/
template<typename E>
MinHeap<E>::~MinHeap()
{
    delete []mHeap;
}

/*自上而下调整成最小堆*/
template<typename E>
void MinHeap<E>::siftDown(int start,int stop)
{
    int i = start;
    int j = 2*i+1;
    E temp = mHeap[i];
    while(j <= stop)
    {
        if(j < stop && mHeap[j] > mHeap[j+1])//让j指向左右子女中的最小值
        {
            ++j;
        }

        if(temp <= mHeap[j])  //temp小的话 则不用调整
            break;
        else
        {
            mHeap[i] = mHeap[j];
            i = j;
            j = 2*i+1;
        }
    }
    mHeap[i] = temp;
}

/*自下而上调整成最小堆*/
template<typename E>
void MinHeap<E>::siftUp(int start)
{
     int j =start;
     int i = (j-1)/2;
     E temp = mHeap[j];
     while(j > 0)
     {
        if (temp >= mHeap[i])
        {
            break;
        }
        else
        {
            mHeap[j] = mHeap[i];
            j = i;
            i = (i-1)/2;
        }
     }
     mHeap[j] = temp;
}


template <typename E>
bool MinHeap<E>::Insert(const E& x)
{
    if(mCurrentSize == mMaxHeadSize)
    {
        cerr << "Heap Full!!!\n";
        return false;
    }

    mHeap[mCurrentSize] = x;
    siftUp(mCurrentSize);
    ++mCurrentSize;
    return true;
}

/*将堆中的最小元素删除*/
template<typename E>
bool MinHeap<E>::RemoveMin(E& x)
{
    if(0 == mCurrentSize)
    {
        cerr << "Heap Empty\n";
        return false;
    }

    x = mHeap[0];
    mHeap[0] = mHeap[mCurrentSize-1];
    --mCurrentSize;
    siftDown(0,mCurrentSize-1);
    return true;
}

#endif // MINHEAD_H
