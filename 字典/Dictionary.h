#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;


template <typename K,typename V>
 struct DicDataNode
{
	K key;
	V value;
	DicDataNode *next;
};



template <typename K, typename V>
class Dictionary
{
private:
	DicDataNode<K,V> *head;

public:
	Dictionary();
	~Dictionary();
	void Add(K key, V value);
	void Remove(K key);
	void Remove(V value);
	bool Contains(K key)const;
	bool Contains(V value);
	DicDataNode<K, V>* Search(K key)const;
	DicDataNode<K, V>* Previous(K key)const;
	void Display()const;



};

int main()
{
	Dictionary<int, string> *myDic = new Dictionary<int, string>();
	myDic->Add(1, "曹操");
	myDic->Add(2, "刘备");
	myDic->Add(3, "孙权");
	myDic->Add(4, "吕布");
	myDic->Add(5, "郭嘉");
	myDic->Add(6, "贾诩");
	myDic->Add(7, "诸葛亮");
	

	myDic->Display();
	myDic->Remove(4);
	myDic->Display();


	Dictionary<int, string> dic;
	dic.Add(1, "诸葛亮");
	dic.Add(2, "庞统");
	dic.Add(3, "姜维");
	dic.Add(4, "司马懿");
	dic.Add(5, "邓艾");
	dic.Add(6, "荀彧");
	dic.Add(7, "许攸");
	dic.Add(8, "杨修");
	dic.Add(9, "张郃");
	dic.Add(10, "张辽");
	dic.Add(11, "关羽");
	dic.Display();

	system("pause");
	return 0;
}


template <typename K, typename V>
Dictionary<K, V>::Dictionary()
{
	head = new DicDataNode<K, V>();
	/*head->key = NULL;
	head->value = NULL;*/
	head->next = NULL;
}


template <typename K, typename V>
Dictionary<K, V>::~Dictionary()
{
	DicDataNode<K, V> *p = head->next;
	while (p != NULL)
	{
		DicDataNode<K, V> *q = p;
		p = p->next;
		delete q;
	}
}
template <typename K, typename V>
void Dictionary<K, V>::Display()const
{
	DicDataNode<K, V> *p = head->next;
	while (NULL != p && NULL != p->next)
	{
		cout << "(" << p->key << "," << p->value << ")" << ",";
		p = p->next;
	}
	cout << "(" << p->key << "," << p->value << ")\n";

}

template <typename K, typename V>
void Dictionary<K, V>::Add(K key, V value)
{
	if (Contains(key))
	{
		//MessageBox(NULL, (LPCWSTR)"you can't insert a same key!!!", (LPCWSTR)"Tips", 0);
		return;
	}
	DicDataNode<K, V> *p = head;
	//指向最后一个节点
	while (NULL != p && NULL != p->next)
	{
		p = p->next;
	}
	DicDataNode<K, V> *s = new DicDataNode<K, V>();
	s->key = key;
	s->value = value;
	p->next = s;
	s->next = NULL;

}

template <typename K, typename V>
void Dictionary<K, V>::Remove(K key)
{
	
	if (Contains(key))
	{
		DicDataNode<K, V>* q = Search(key);
		DicDataNode<K, V>* p = Previous(key);
		if (NULL != p && NULL != q)
		{
			p->next = q->next;
			delete q;
		}
	}
}

template <typename K, typename V>
bool Dictionary<K, V>::Contains(K key)const
{
	DicDataNode<K, V> *p = head->next;
	while (NULL != p && key != p->key)
	{
		p = p->next;
	}
	if (NULL != p)
	{
		return true;
	}	
	return false;
}

template <typename K, typename V>
DicDataNode<K, V>* Dictionary<K, V>::Search(K key)const
{
	DicDataNode<K, V>* ret = NULL;
	DicDataNode<K, V> *p = head->next;
	while (NULL != p && key != p->key)
	{
		p = p->next;
	}
	if (NULL != p)
	{
		ret = p;
	}
	return ret;
}



template <typename K, typename V>
DicDataNode<K, V>* Dictionary<K, V>::Previous(K key)const
{
	DicDataNode<K, V>* ret = NULL;
	DicDataNode<K, V> *p = head->next;
	while (NULL != p->next && key != p->next->key)
	{
		p = p->next;
	}
	if (NULL != p)
	{
		ret = p;
	}
	return ret;
}


