#ifndef LRULISTNODE_H_INCLUDED
#define LRULISTNODE_H_INCLUDED

#include <iostream>
using namespace std;


template <typename T,typename E>
struct CacheNode  //链表中的节点
{
    T key;        //键
    E value;      //值
    CacheNode(T k,E val):key(k),value(val){};
    CacheNode<T,E>* pre;      //指向前驱节点
    CacheNode<T,E>* next;     //指向后续节点
};

template <typename T,typename E>
class LRUChacheList     //LRU类
{
public:
    //构造函数
    LRUChacheList(int sz,T key,E val):mSize(sz)
    {
        mHead = new  CacheNode<T,E>(key,val);
        mHead->next = nullptr;
        mHead->pre = nullptr;
        mCurrentSize = 0;
    }

    //虚析构函数
    virtual ~LRUChacheList()
    {
         if (nullptr == mHead->next) //只有头结点
         {
             delete mHead;

         }else //有多个节点
         {
            CacheNode<T,E>* p = mHead->next;
            CacheNode<T,E>* q = nullptr;
            while (p != mHead)
            {
                q = p;
                p = p->next;
                delete q;
            }
            delete mHead;
         }

    }

    //设置新值
    void setKey(T key,E value)
    {
        CacheNode<T,E>* ret=nullptr;
        if (findKey(key,ret) == false) //当前cache没有对应键的值
        {
            if (mCurrentSize == mSize)  //cache已经满 则删除链表尾部的节点
            {
                 CacheNode<T,E>* p = mHead->pre;
                 CacheNode<T,E>* q = p->pre;
                 mHead->pre = q;
                 q->next = mHead;
                 delete p;
                 --mCurrentSize;
            }

            //新建节点 并插入到链表头部
            CacheNode<T,E>* s = new  CacheNode<T,E>(key,value);
            ++mCurrentSize;
            if (mHead->next == nullptr)  //第一次插入节点时
            {
                mHead->next = s;
                s->pre = mHead;
                s->next = mHead;
                mHead->pre = s;
                return;
            }

            //第二次以后插入节点
            mHead->next->pre = s;
            s->next = mHead->next;
            mHead->next = s;
            s->pre = mHead;

        }else  //如果找到对应的键值 则更新它的值
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

    //获取对应键的值
    bool getValue(T& key,E& val)
    {
         CacheNode<T,E>* ret=nullptr;
         if(true == findKey(key,ret))  //找到
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

         //没找到
         return false;
    }

    //打印cache中的节点的值
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

    //重载<<
    ostream& operator<< (CacheNode<T,E>& s)
    {
        return cout<<s.value;
    }

protected:
    //找cache中是否存在对应的键 若存在将节点通过参数s返回 函数返回true
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

    //找值 并通过参数s返回改节点
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
    int mSize;           //cache的总容量
    int mCurrentSize;     //cache的当前容量
    CacheNode<T,E>* mHead;   //链表的头结点 用于管理链表
};



#endif // LRULISTNODE_H_INCLUDED
