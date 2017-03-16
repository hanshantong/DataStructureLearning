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

        bool Insert(const E& x);  //����Ԫ�ص���С����
        bool isEmpty()const{return (0==mCurrentSize) ? true : false;} //��С���Ƿ�Ϊ��
        bool isFull()const{return (mCurrentSize == mMaxHeadSize) ? true : false;}   //��С���Ƿ�����
        void MakeEmpty(){mCurrentSize = 0;} //����С���ÿ�
        bool RemoveMin(E& x);  //�����е���СԪ��ɾ��

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
        E* mHeap;   //�����С����Ԫ�ص�����
        int mCurrentSize;  //��С�ѵ�ǰԪ�ظ���
        int mMaxHeadSize;   //��С�������ŵ����Ԫ�ظ���
        void siftDown(int start, int stop);  //��start��stop�»�������Ϊ��С��
        void siftUp(int start);  //��start��0�ϻ�������Ϊ��С��

};

/*���캯��*/
template <typename E>
MinHeap<E>::MinHeap(int sz)
{
    mMaxHeadSize = sz>DEFAULT_SIZE ? sz : DEFAULT_SIZE;
    mHeap = new E[mMaxHeadSize];
    if(nullptr == mHeap)
    {
        cerr << "�Ѵ洢�ռ����ʧ��!!!\n";
        exit(1);
    }
    mCurrentSize = 0;
}

/*���캯��*/
template <typename E>
MinHeap<E>::MinHeap(E arr[],int len)
{
    mMaxHeadSize = len>DEFAULT_SIZE ? len : DEFAULT_SIZE;
    mHeap = new E[mMaxHeadSize];
    if(nullptr == mHeap)
    {
        cerr << "�Ѵ洢�ռ����ʧ��!!!\n";
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


/*��������*/
template<typename E>
MinHeap<E>::~MinHeap()
{
    delete []mHeap;
}

/*���϶��µ�������С��*/
template<typename E>
void MinHeap<E>::siftDown(int start,int stop)
{
    int i = start;
    int j = 2*i+1;
    E temp = mHeap[i];
    while(j <= stop)
    {
        if(j < stop && mHeap[j] > mHeap[j+1])//��jָ��������Ů�е���Сֵ
        {
            ++j;
        }

        if(temp <= mHeap[j])  //tempС�Ļ� ���õ���
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

/*���¶��ϵ�������С��*/
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

/*�����е���СԪ��ɾ��*/
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
