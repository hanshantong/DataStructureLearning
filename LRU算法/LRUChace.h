#ifndef LRUCHACE_H_
#define LRUCHACE_H_

#include <iostream>

#include <list>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef struct _Node
{
    int key;
    int value;
    _Node(int k,int val):key(k),value(val){};
}Node;

class LRUChache
{
public:
    LRUChache(int sz):mSize(sz)
    {}

    void setValue(int k,int val)
    {
        if (mCacheMap.find(k) == mCacheMap.end()) //找不到对应key的值
        {
            if (mSize == mCacheList.size()) //缓存已满,将最后一个元素从链表中去掉
            {
                mCacheMap.erase(mCacheList.back().key);
                mCacheList.pop_back();
            }

            //插入新的值
            mCacheList.push_front(Node(k,val));
            mCacheMap[k] = mCacheList.begin();  //插入新数据
        }else //找到对应的键值
        {
            (mCacheMap[k])->value = val;
            mCacheList.splice(mCacheList.begin(),mCacheList,mCacheMap[k]);  //将最新访问的数据移动到链表头
            mCacheMap[k] = mCacheList.begin();
        }
    }

    int getValue(int k)
    {
        if (mCacheMap.find(k) == mCacheMap.end())//找不到
        {
            return -1;
        }

        //把当前访问的数据移动到链表头
        mCacheList.splice(mCacheList.begin(),mCacheList,mCacheMap[k]);
        mCacheMap[k] = mCacheList.begin();

        return mCacheMap[k]->value;
    }

    void print()
    {
        for(list<Node>::iterator it = mCacheList.begin(); it != mCacheList.end(); ++it)
            cout << (*it).value << " ";
        cout << endl;
    }

private:
    list<Node> mCacheList;
    unordered_map<int,list<Node>::iterator> mCacheMap;
    int mSize;

};




#endif // LRUCHACE_H_
