#ifndef LRULISTNODE_H_INCLUDED
#define LRULISTNODE_H_INCLUDED

#include <iostream>
using namespace std;


template <typename T,typename E>
struct CacheNode  //�����еĽڵ�
{
    T key;        //��
    E value;      //ֵ
    CacheNode(T k,E val):key(k),value(val){};
    CacheNode<T,E>* pre;      //ָ��ǰ���ڵ�
    CacheNode<T,E>* next;     //ָ������ڵ�
};

template <typename T,typename E>
class LRUChacheList     //LRU��
{
public:
    //���캯��
    LRUChacheList(int sz,T key,E val):mSize(sz)
    {
        mHead = new  CacheNode<T,E>(key,val);
        mHead->next = nullptr;
        mHead->pre = nullptr;
        mCurrentSize = 0;
    }

    //����������
    virtual ~LRUChacheList()
    {
         if (nullptr == mHead->next) //ֻ��ͷ���
         {
             delete mHead;

         }else //�ж���ڵ�
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

    //������ֵ
    void setKey(T key,E value)
    {
        CacheNode<T,E>* ret=nullptr;
        if (findKey(key,ret) == false) //��ǰcacheû�ж�Ӧ����ֵ
        {
            if (mCurrentSize == mSize)  //cache�Ѿ��� ��ɾ������β���Ľڵ�
            {
                 CacheNode<T,E>* p = mHead->pre;
                 CacheNode<T,E>* q = p->pre;
                 mHead->pre = q;
                 q->next = mHead;
                 delete p;
                 --mCurrentSize;
            }

            //�½��ڵ� �����뵽����ͷ��
            CacheNode<T,E>* s = new  CacheNode<T,E>(key,value);
            ++mCurrentSize;
            if (mHead->next == nullptr)  //��һ�β���ڵ�ʱ
            {
                mHead->next = s;
                s->pre = mHead;
                s->next = mHead;
                mHead->pre = s;
                return;
            }

            //�ڶ����Ժ����ڵ�
            mHead->next->pre = s;
            s->next = mHead->next;
            mHead->next = s;
            s->pre = mHead;

        }else  //����ҵ���Ӧ�ļ�ֵ ���������ֵ
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

    //��ȡ��Ӧ����ֵ
    bool getValue(T& key,E& val)
    {
         CacheNode<T,E>* ret=nullptr;
         if(true == findKey(key,ret))  //�ҵ�
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

         //û�ҵ�
         return false;
    }

    //��ӡcache�еĽڵ��ֵ
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

    //����<<
    ostream& operator<< (CacheNode<T,E>& s)
    {
        return cout<<s.value;
    }

protected:
    //��cache���Ƿ���ڶ�Ӧ�ļ� �����ڽ��ڵ�ͨ������s���� ��������true
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

    //��ֵ ��ͨ������s���ظĽڵ�
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
    int mSize;           //cache��������
    int mCurrentSize;     //cache�ĵ�ǰ����
    CacheNode<T,E>* mHead;   //�����ͷ��� ���ڹ�������
};



#endif // LRULISTNODE_H_INCLUDED
