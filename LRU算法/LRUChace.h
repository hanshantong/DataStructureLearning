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
        if (mCacheMap.find(k) == mCacheMap.end()) //�Ҳ�����Ӧkey��ֵ
        {
            if (mSize == mCacheList.size()) //��������,�����һ��Ԫ�ش�������ȥ��
            {
                mCacheMap.erase(mCacheList.back().key);
                mCacheList.pop_back();
            }

            //�����µ�ֵ
            mCacheList.push_front(Node(k,val));
            mCacheMap[k] = mCacheList.begin();  //����������
        }else //�ҵ���Ӧ�ļ�ֵ
        {
            (mCacheMap[k])->value = val;
            mCacheList.splice(mCacheList.begin(),mCacheList,mCacheMap[k]);  //�����·��ʵ������ƶ�������ͷ
            mCacheMap[k] = mCacheList.begin();
        }
    }

    int getValue(int k)
    {
        if (mCacheMap.find(k) == mCacheMap.end())//�Ҳ���
        {
            return -1;
        }

        //�ѵ�ǰ���ʵ������ƶ�������ͷ
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
