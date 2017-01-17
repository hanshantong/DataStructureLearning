#ifndef LRULISTNODE_H_INCLUDED
#define LRULISTNODE_H_INCLUDED

#include <iostream>
using namespace std;


template <typename T,typename E>
struct CacheNode
{
    T key;
    E value;
    CacheNode(T k,E val):key(k),value(val){};
    CacheNode<T,E>* pre;
    CacheNode<T,E>* next;
};

template <typename T,typename E>
class LRUChacheList
{
public:
    LRUChacheList(int sz,T key,E val):mSize(sz)
    {
        mHead = new  CacheNode<T,E>(key,val);
        mHead->next = nullptr;
        mHead->pre = nullptr;
        mCurrentSize = 0;
    }
    virtual ~LRUChacheList()
    {

    }
    void setKey(T key,E value)
    {
        CacheNode<T,E>* ret=nullptr;
        if (findKey(key,ret) == false)
        {
            if (mCurrentSize == mSize)
            {
                 CacheNode<T,E>* p = mHead->pre;
                 CacheNode<T,E>* q = p->pre;
                 mHead->pre = q;
                 q->next = mHead;
                 delete p;
                 --mCurrentSize;
            }
            CacheNode<T,E>* s = new  CacheNode<T,E>(key,value);
            ++mCurrentSize;
            if (mHead->next == nullptr)
            {
                mHead->next = s;
                s->pre = mHead;
                s->next = mHead;
                mHead->pre = s;
                return;
            }
            mHead->next->pre = s;
            s->next = mHead->next;
            mHead->next = s;
            s->pre = mHead;

        }else
        {
            if(nullptr != ret)
            {

                 ret->pre->next = ret->next;
                 ret->next->pre = ret->pre;

                 mHead->next->pre = ret;
                 ret->next = mHead->next;
                 mHead->next = ret;
                 ret->pre = mHead;
                 ret->value = value;
            }
        }
    }
    bool getValue(T& key,E& val)
    {
         CacheNode<T,E>* ret=nullptr;
         if(true == findKey(key,ret))
         {
             if(nullptr != ret)
            {
                 CacheNode<T,E>* tmp;
                 ret->pre->next = ret->next;
                 ret->next->pre = ret->pre;

                 mHead->next->pre = ret;
                 ret->next = mHead->next;
                 mHead->next = ret;
                 ret->pre = mHead;
                 val = ret->value;
            }
            return true;
         }
         return false;
    }

    void print()
    {
        if (nullptr == mHead)
            return ;

        CacheNode<T,E>* p = mHead->next;
        while (p != mHead)
        {
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }

    ostream& operator<< (CacheNode<T,E>& s)
    {
        return cout<<s.value;
    }

protected:
    bool findKey(T key,CacheNode<T,E>*& s)
    {
        if (nullptr == mHead->next)
            return false;

        CacheNode<T,E>* p = mHead->next;
        while (p != mHead)
        {
            if (key == p->key)
            {
                s = p;
                return true;
            }

            p = p->next;
        }

        return false;
    }

    bool findValue(E val,CacheNode<T,E>*& s)
    {
        if (mHead->next == nullptr)
            return false;

        CacheNode<T,E>* p = mHead->next;
        while (p != mHead)
        {
            if (p->value == val)
            {
                s = p;
                return true;
            }
            p = p->next;
        }
        return false;
    }
private:
    int mSize;
    int mCurrentSize;
    CacheNode<T,E>* mHead;
};



#endif // LRULISTNODE_H_INCLUDED
