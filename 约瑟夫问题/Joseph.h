#ifndef JOSEPH_H
#define JOSEPH_H

#include <stdio.h>
typedef struct _ListNode
{
    size_t number;
     _ListNode *next;
}ListNode;

class Joseph
{

    private:
        Joseph()
        {

        }

    public:
        Joseph(size_t total,size_t start);
        virtual ~Joseph();
        void printJsequence();
    protected:
        void JosephSequence();
    private:
        size_t mTotal;
        size_t mStart;
        ListNode* mHead;
};

Joseph::Joseph(size_t total,size_t start)
{
    mTotal = total;
    mStart = start;
    ListNode *r,*p;
    mHead = new ListNode();
    mHead->next = nullptr;
    mHead->number = 1;
    r = mHead;

    //建立单链表,包含mTotal个节点
    for (size_t i=2; i <= mTotal; ++i)
    {
        p = new ListNode();
        p->number = i;
        r->next = p;
        r = p;
    }

    r->next = mHead;  //将链表连成循环链表

}

void Joseph::printJsequence()
{
    JosephSequence();
}

//输出约瑟夫序列
void Joseph::JosephSequence()
{

    ListNode *p,*q;
    size_t j = 1;
    for (size_t i=1; i <= mTotal; ++i)
    {
        j = 1;
        p = mHead;
        while (j < mStart-1)//从1数到mStart
        {
            p = p->next;
            ++j;
        }

        q = p->next;  //q是第mStartge节点，将该节点从循环单链表中移除
        p->next = q->next;
        printf("%d ",q->number);
        delete q;
        q = nullptr;
        mHead = p->next;
    }
}

Joseph::~Joseph()
{

}



#endif // JOSEPH_H
