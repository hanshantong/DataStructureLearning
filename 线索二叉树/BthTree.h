#pragma once
#include <iostream>
#include "LinkedStack.h"
using namespace std;

template <typename T>
struct BthNode
{
	T data;
	BthNode *lchild;
	BthNode *rchild;
	char ltag;
	char rtag;
};

template <typename T>
class BthTree
{
	BthNode<T> *r;
	BthNode<T> *root;
	BthNode<T> *pre;

public:
	BthTree();
	~BthTree();
	void CreateTree(char *str);
	void DispBthNode();
	void CreatBTreeThread();
	void ThInOrder();  //中序线索化
	void PreOrder(); //先序线索遍历
	void CreatePreOrder(); //建立以root为头节点的线索二叉树
	void CreatePostOrder();
	void PostOrder();
	BthNode<T>* PostParent(BthNode<T>* child);  //求后序线索二叉树的父节点
private:
	BthNode<T> * Parent(BthNode<T>* child);
	void DestroyBtree(BthNode<T> *r);
	void Display(BthNode<T> *r);
	void Thread(BthNode<T> *&p);
	void InitBTree(BthNode<T> *&t);
	void PreInitBTree(BthNode<T> *&t);
	void PostInitBTree(BthNode<T> *&t);
};


template <typename T>
BthNode<T>* BthTree<T>::Parent(BthNode<T>* child)
{
	return PostParent(child);
}

template <typename T>
BthNode<T>* BthTree<T>::PostParent(BthNode<T>* child)
{
	BthNode<T> *temp = r;
	if (NULL == temp)return NULL;
	else if (NULL != temp && 0 == temp->ltag && temp->lchild == child)return temp;
	else
	{
		temp = temp->lchild;
		while ( 0 == temp->ltag   || 0 == temp->rtag )
		{
			if (0 == temp->ltag && child == temp->lchild)
				return temp;
			else if (0 == temp->rtag && child == temp->rchild)
				return temp;
			if (0 == temp->rtag)
			{
				temp = temp->lchild;
			}
			else
				temp = temp->lchild;

			if (1 == temp->ltag && 1 == temp->rtag)
				temp = r->rchild;
		}
		
	}
	return temp;

}


template <typename T>
void BthTree<T>::CreatePostOrder()
{

	root = new BthNode<T>();
	root->ltag = 0;
	root->rtag = 1;
	if (NULL == r)
	{
		root->lchild = root;
		root->ltag = 0;
		root->rchild = NULL;
		root->rtag = 1;
	}
	else
	{
		root->lchild = r;
		pre = root;
		PostInitBTree(r);
		root->rchild = pre;
		pre->rchild = root;
		pre->rtag = 1;
	}


}

/*这个函数还有问题**/
template <typename T>
void BthTree<T>::PostOrder()
{
	BthNode<T> *p = root->lchild;
	BthNode<T> *parent = NULL;
	while (true)
	{
		if (0 == p->ltag)
			p = p->lchild;
		else if (0 == p->rtag)
			p = p->rchild;
		else
			break;
	}

	while (root != parent)
	{
		cout << p->data;
		parent = PostParent(p);
		if (1 == p->rtag)
			p = p->rchild;
		else if (0 == parent->rtag) 
			p = parent->rchild;
		else if (1 == parent->rtag)
			p = parent;
	}

}


template <typename T>
void BthTree<T>::PostInitBTree(BthNode<T> *&t)
{
	if (NULL != t)
	{
		PostInitBTree(t->lchild);
		PostInitBTree(t->rchild);
		if (NULL == t->lchild)
		{
			t->ltag = 1;
			t->lchild = pre;
		}
		else
		{
			t->ltag = 0;
		}

		if (NULL == pre->rchild)
		{
			pre->rtag = 1;
			pre->rchild = t;
		}
		else
		{
			pre->rtag = 0;
		}
		pre = t;



	}
}


template <typename T>
void BthTree<T>::PreOrder()
{
	BthNode<T> *p = root->lchild;
	while (root != p)
	{
		cout << p->data;
		if (0 == p->ltag )
		{
			
			p = p->lchild;
			
		}
		else p = p->rchild;


	}



}


template <typename T>
void BthTree<T>::CreatePreOrder()
{
	root = new BthNode<T>();
	root->ltag = 0;
	root->rtag = 1;
	if (NULL == r)
	{
		root->lchild = root;
		root->ltag = 0;
		root->rchild = NULL;
		root->rtag = 1;
	}
	else
	{
		root->lchild = r;
		pre = root;
		PreInitBTree(r);
		root->rchild = pre;
		pre->rchild = root;
		pre->rtag = 1;
	}
}

template <typename T>
void BthTree<T>::PreInitBTree(BthNode<T> *&t)
{
	if (NULL != t)
	{
		if (t->lchild == NULL)
		{
			t->ltag = 1;
			t->lchild = pre;  //前驱线索
			
			
		}
		else
		{
			t->ltag = 0;
		}

		if (pre->rchild == NULL)
		{
			pre->rtag = 1;
			pre->rchild = t;
			
		}
		else
		{
			t->rtag = 0;
		}
		pre = t;
		//cout << t->data;
		if (0 == t->ltag )
		   PreInitBTree(t->lchild);
		if (0 == t->rtag )
		   PreInitBTree(t->rchild);



	}

}



/*中序线索化二叉树**/
template <typename T>
void BthTree<T>::InitBTree(BthNode<T> *&t)
{
	if (NULL != t)
	{
		InitBTree(t->lchild);
		if (NULL == t->lchild)  //没有左孩子
		{
			t->lchild = pre;  //前驱线索
			t->ltag = 1;

		}
		else
		{
			t->ltag = 1;
		}

		if (NULL == pre->rchild) //前驱没有右孩子
		{
			pre->rchild = t;  //后继线索
			pre->rtag = 1;
		}
		else
		{
			pre->rtag = 0;
		}

		pre = t;
		InitBTree(t->rchild);



	}




}


template <typename T>
void BthTree<T>::Thread(BthNode<T> *&t)
{
	/*
	if (NULL != p)
	{
		Thread(p->lchild);
		if (NULL == p->lchild)
		{
			p->lchild = pre;
			p->ltag = 1;
		}
		else
		{
			p->ltag = 0;
		}
		if (NULL == pre->rchild)
		{
			pre->rchild = p;
			pre->rtag = 1;
		}
		else
		{
			pre->rtag = 0;
		}

		pre = p;
		Thread(p->rchild);
	}*/


	if (NULL != t)
	{
		if (0 == t->ltag || NULL != t->lchild)
			Thread(t->lchild);

		if (NULL == t->lchild)
		{
			t->ltag = 1;
			t->lchild = pre;
		}
		else
		{
			t->ltag = 0;
		}

		if (NULL == pre->rchild)
		{
			pre->rtag = 1;
			pre->rchild = t;
		}
		else
		{
			pre->rtag = 0;
		}
		pre = t;
		if (0 == t->rtag || NULL != t->rchild)
			Thread(t->rchild);
	}




}

template <typename T>
void BthTree<T>::ThInOrder()
{
	BthNode<T> *p = root->lchild;
	while (root != p)
	{
		while (root != p && 0 == p->ltag)
		{
			p = p->lchild;
		}
		cout << p->data;
		while (1 == p->rtag && p->rchild != root)
		{
			p = p->rchild;
			if (NULL != p)
			   cout << p->data;
		}
		p = p->rchild;
	}
}

template <typename T>
BthTree<T>::BthTree()
{
	r = NULL;
	root = NULL;
	pre = NULL;
}

template <typename T>
void BthTree<T>::DestroyBtree(BthNode<T> *t)
{
	if (NULL != t)
	{
		DestroyBtree(t->lchild);
		DestroyBtree(t->rchild);
		delete t;
	}
}

template <typename T>
BthTree<T>::~BthTree()
{
	DestroyBtree(r);
}

template <typename T>
void BthTree<T>::CreatBTreeThread()
{
	root = new BthNode<T>();
	root->ltag = 0;
	root->rtag = 1;
	root->rchild = r;
	if (NULL == r)
	{
		root->ltag = 0;
		root->lchild = root;
		root->rtag = 1;
		root->rchild = NULL;
	}
	else
	{
		root->lchild = r;
		pre = root;
		Thread(r);
		pre->rchild = root;
		pre->rtag = 1;
		root->rchild = pre;
	}
}





template <typename T>
void BthTree<T>::CreateTree(char *str)
{
	BthNode<T> *p = NULL;
	LinkStackClass<BthNode<T>*> st;
	BthNode<T> *e;
	char ch;
	int k;
	int j = 0;
	while (str[j] != '\0')
	{
		ch = str[j];
		switch (ch)
		{
		case '(':
			k = 1;
			st.Push(p);
			break;
		case ')':

			st.Pop(e);
			break;
		case ',':
			k = 2;
			break;

		default:
			p = new BthNode<T>();
			p->lchild = NULL;
			p->rchild = NULL;
			p->data = ch;
			if (NULL == r)r = p;
			else
			{
				switch (k)
				{
				case 1:
					st.GetTop(e);
					e->lchild = p;
					break;
				case 2:
					st.GetTop(e);
					e->rchild = p;
					break;
				default:
					break;
				}
			}

			break;
		}


		j++;
	}

}


template <typename T>
void BthTree<T>::Display(BthNode<T> *t)
{
	if (NULL != t)
	{
		cout << t->data;
		if (t->lchild != NULL || t->rchild != NULL)
		{
			cout << "(";
			Display(t->lchild);
			if (t->rchild != NULL)
				cout << ",";
			Display(t->rchild);
			cout << ")";
		}
	}
}


template <typename T>
void BthTree<T>::DispBthNode()
{
	Display(r);
}