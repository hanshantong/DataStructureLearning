#pragma once
#include "LinkedStack.h"
#include "CircleLinkedQueue.h"
#include <iostream>
using namespace std;

template <typename T>
struct BTNode
{
	T data;
	BTNode *lchild;
	BTNode *rchild;
};


template <typename T>
class BTNodeClass
{
public:
	BTNode<T> *root;

public:
	BTNodeClass();
	~BTNodeClass();
	void CreateBTNode(char *str);
	void DispBTNode();
	BTNode<T> *FindNode(T x);
	int BTNodeHeight();
	void PreOrder();//�������
	void MediumOrder();//�������
	void PostOrder();//�������
	void LevelOrder(); //��α���
	int NodeCount();//��ڵ����
	void printLeaves();//���Ҷ�ӽڵ�
	BTNode<T>** GetRoot();
	void CreateBTree(BTNode<T> &r);  //�ݹ齨��������
	int Node2Child();  //��Ϊ2�Ľڵ�
	int Node1Child();  //��Ϊ1�Ľڵ�

	void CopyTree(BTNodeClass<T> &t2);
	int Level(T x);  //�ڵ�ֵΪx���ڵĶ�
	bool Ancestor(T x); //�ڵ�ֵΪx����������
	void Parent(T x);  //�ڵ�ֵΪx��˫��
private:
	void DestroyBTree(BTNode<T> *root);
	void Display(BTNode<T> *r);  //
	BTNode<T> *Find(BTNode<T> *r, T x);
	int Height(BTNode<T> *r);
	int Level(BTNode<T> *r, T x, int h);
	bool Ancestor(BTNode<T> *r, T x);
	void Parent(BTNode<T> *r,T x);  //�ڵ�ֵΪx��˫��


	/*���ֱ����㷨*/
	void PreOrder(BTNode<T> *r);  //�������
	void MediumOrder(BTNode<T> *r); //�������
	void PostOrder(BTNode<T> *r);  //�������
	void LevelOrder(BTNode<T> *r); //��α���

	int NodeCount(BTNode<T> *r); //��ڵ����
	void PrintLeaves(BTNode<T> *r);

	void PreOrderNotFac(BTNode<T> *r);  //��������ķǵݹ��㷨
	void MediumOrderNotFac(BTNode<T> *r); //��������ķǵݹ��㷨
	void PostOrderNotFac(BTNode<T> *r);   //��������ķǵݹ��㷨

	int Node2Child(BTNode<T> *r);  //��Ϊ2�Ľڵ�
	int Node1Child(BTNode<T> *r);  //��Ϊ1�Ľڵ�
	void CopyTree(BTNode<T> *t1, BTNode<T>* &t2);
};


template <typename T>
void BTNodeClass<T>::LevelOrder()
{
	LevelOrder(root);
}


template <typename T>
void BTNodeClass<T>::LevelOrder(BTNode<T> *r)
{
	CircleLinkedQueue<BTNode<T> *> queue;
	BTNode<T> *p;
	queue.EnQueue(r);
	while (!queue.IsQueueEmpty())
	{
		queue.Dequeue(p);
		cout << p->data;
		if (p->lchild != NULL)
		{
			queue.EnQueue(p->lchild);
		}

		if (p->rchild != NULL)
		{
			queue.EnQueue(p->rchild);
		}

	}
}


template <typename T>
void BTNodeClass<T>::PostOrderNotFac(BTNode<T> *r)
{
	LinkStackClass<BTNode<T>*> st;
	BTNode<T> *p = r,*q = NULL;
	bool flag = false;

	do
	{
		while (p)
		{
			st.Push(p);
			p = p->lchild;
		}
		q = NULL;
		flag = true;

		while (!st.IsStackEmpty() && true == flag)
		{
			st.GetTop(p);
			if (p->rchild == q)
			{
				cout << p->data;
				st.Pop(p);
				q = p;
			}
			else
			{
				p = p->rchild;
				flag = false;
			}
		}

	} while (!st.IsStackEmpty());
	
}

template <typename T >
void BTNodeClass<T>::MediumOrderNotFac(BTNode<T> *r)
{
	LinkStackClass<BTNode<T>*> st;
	BTNode<T> *p = r;
	while (!st.IsStackEmpty() || p != NULL)
	{
		while (p)
		{
			st.Push(p);
			p = p->lchild;
		}

		p = st.Pop();
		if (p != NULL)
		{
			cout << p->data;
			p = p->rchild;

		}



	}

}


template <typename T>
void BTNodeClass<T>::PreOrderNotFac(BTNode<T> *r)
{
	//�ⷨ1
	/*LinkStackClass<BTNode<T>*> st;
	BTNode<T> *p;
	if (NULL != r)st.Push(r);
	while (!st.IsStackEmpty())
	{
		p = st.Pop();
		cout << p->data;
		if (p->rchild != NULL)
		{
			st.Push(p->rchild);
		}
		if (p->lchild != NULL)
		{
			st.Push(p->lchild);
		}

	}*/

	//�ⷨ2
	LinkStackClass<BTNode<T>*> st;
	BTNode<T> *p = r;
	while (!st.IsStackEmpty() || p != NULL)
	{

		while (p != NULL)  //���ʸ��ڵ㼰������������
		{
			cout << p->data;
			st.Push(p);
			p = p->lchild;
		}

		if (!st.IsStackEmpty())
		{
			p = st.Pop();
			p = p->rchild;
		}

	}



}


template <typename T>
void BTNodeClass<T>::Parent(T x)
{
	Parent(root,x);
}

template <typename T>
void BTNodeClass<T>::Parent(BTNode<T> *r, T x)
{
	if (NULL == r);
	else if ((r->lchild != NULL && r->lchild->data == x) || (r->rchild != NULL && r->rchild->data == x))
	{
		cout << r->data << "\n";
	}
	else
	{
		Parent(r->lchild, x);
		Parent(r->rchild, x);
	}
}


template <typename T>
bool BTNodeClass<T>::Ancestor(T x)
{
	 return Ancestor(root,x);
}

template <typename T>
bool BTNodeClass<T>::Ancestor(BTNode<T> *r, T x)
{


	if (NULL == r)return false;
	else if (r->lchild != NULL && r->lchild->data == x)
	{
		cout << r->data << " ";
		return true;
	}
	else if (r->rchild != NULL && r->rchild->data == x)
	{
		cout << r->data << " ";
		return true;
	}
	else if (Ancestor(r->lchild, x) || Ancestor(r->rchild, x))
	{
		cout << r->data << " ";
		return true;
	}
	else return false;

	

}


template <typename T>
int BTNodeClass<T>::Level(T x)
{
	return Level(root,x,1);
}


template <typename T>
int BTNodeClass<T>::Level(BTNode<T> *r, T x, int h)
{
	int k = 0;
	if (NULL == r)return 0;
	else if (x == r->data)return h;
	else
	{
		k = Level(r->lchild, x, h + 1);
		if (k != 0)return k;
		else return Level(r->rchild, x, h + 1);
	}
}
template <typename T>
void BTNodeClass<T>::CopyTree(BTNodeClass<T> &t2)
{
	CopyTree(root,t2.root);
}

template <typename T>
void BTNodeClass<T>::CopyTree(BTNode<T> *t1, BTNode<T>* &t2)
{
	if (NULL == t1)t2 = t1;
	else
	{
		t2 = new BTNode<T>();
		t2->data = t1->data;
		CopyTree(t1->lchild,t2->lchild);
		CopyTree(t1->rchild,t2->rchild);
	}
}


template <typename T>
int BTNodeClass<T>::Node1Child()
{
	return Node1Child(root);
}


template <typename T>
int BTNodeClass<T>::Node1Child(BTNode<T> *r)
{
	//�ݹ�ʵ��
	//if (NULL == r)return 0;
	//else if ((r->lchild != NULL && r->rchild == NULL) || (r->lchild == NULL && r->rchild != NULL))return 1 + Node1Child(r->lchild) + Node1Child(r->rchild);
	//else if (r->lchild != NULL && r->rchild != NULL)return Node1Child(r->lchild) + Node1Child(r->rchild); //����Ϊ2��ʲôҲ����������������
	//else return 0;

	//�������
	int i = 0;
	int n = 0, m = 0;
	if (NULL == r)return 0;
	else if (r->lchild != NULL || r->rchild != NULL)
	{
		if ((r->lchild != NULL && r->rchild == NULL) || (r->lchild == NULL && r->rchild != NULL))
		{
			cout << r->data << " "; 
			i = 1;
		}
		
			n = Node1Child(r->lchild);
			m = Node1Child(r->rchild);
			return i + n + m;
		
	}
	else return 0;
}



template <typename T>
int BTNodeClass<T>::Node2Child()
{
	return Node2Child(root);
}


template <typename T>
int BTNodeClass<T>::Node2Child(BTNode<T> *r)
{
	if (NULL == r)return 0;
	else if (r->lchild != NULL && r->rchild == NULL)return 0;
	else if (r->lchild == NULL && r->rchild != NULL)return 0;
	else if (r->lchild == NULL && r->rchild == NULL)return 0;
	else return 1 + Node2Child(r->lchild) + Node2Child(r->rchild);
}







template <typename T>
BTNode<T>** BTNodeClass<T>::GetRoot()
{
	return &root;
}

template <typename T>
void BTNodeClass<T>::CreateBTree(BTNode<T> &p)
{
	
	char ch;
	cin >> ch;
	if ('#' == ch)p = NULL;
	else
	{
		p = new BTNode<T>();
		p->data = ch;
		
		CreateBTree(p->lchild);
		CreateBTree(p->rchild);
	}
}


template <typename T>
void BTNodeClass<T>::printLeaves()
{
	PrintLeaves(root);
}
template <typename T>
void BTNodeClass<T>::PrintLeaves(BTNode<T> *r)
{
	if (NULL == r);
	else if (r->lchild == NULL && r->rchild == NULL)cout << r->data << " ";
	else {
		PrintLeaves(r->lchild);
		PrintLeaves(r->rchild);
	}
}

template <typename T>
int BTNodeClass<T>::NodeCount()
{
	return NodeCount(root);
}


template <typename T>
int BTNodeClass<T>::NodeCount(BTNode<T> *r)
{
	//�������
	/*int iCount = 0;
	int n = 0, m = 0;
	if (NULL == r)return 0;
	else
	{
		cout << r->data << " ";
		
		iCount = 1;
		n = NodeCount(r->lchild);
		m = NodeCount(r->rchild);
		return m + n +iCount ;
	}*/

	//�������
	/*int iCount = 0;
	int n = 0, m = 0;
	if (NULL == r)return 0;
	else
	{
		
		n = NodeCount(r->lchild);
		cout << r->data << " ";
		iCount = 1;
		m = NodeCount(r->rchild);
		return m + n + iCount;
	}*/

	//�������
	/*int iCount = 0;
	int n = 0, m = 0;
	if (NULL == r)return 0;
	else
	{

		n = NodeCount(r->lchild);
		m = NodeCount(r->rchild);
		cout << r->data << " ";
		iCount = 1;
		return m + n + iCount;
	}*/

	/*if (NULL == r)return 0;
	else return NodeCount(r->lchild) + NodeCount(r->rchild) + 1;*/
	
	if (NULL == r)return 0;
	else return 1 + NodeCount(r->lchild) + NodeCount(r->rchild);

}



template <typename T>
void BTNodeClass<T>::PostOrder()
{
	cout << "\n�ݹ�������:\n";
	PostOrder(root);
	cout << "\n�ǵݹ�������:\n";
	PostOrderNotFac(root);
}


template <typename T>
void BTNodeClass<T>::PostOrder(BTNode<T> *r)
{
	if (r != NULL)
	{

		PostOrder(r->lchild);
		PostOrder(r->rchild);
		cout << r->data << "";
	}
}



template <typename T>
void BTNodeClass<T>::MediumOrder()
{
	MediumOrder(root);
	cout << "\n��������ǵݹ��㷨:\n";
	MediumOrderNotFac(root);
}


template <typename T>
void BTNodeClass<T>::MediumOrder(BTNode<T> *r)
{
	if (r != NULL)
	{
		
		MediumOrder(r->lchild);
		cout << r->data;
		MediumOrder(r->rchild);
	}
}





template <typename T>
void BTNodeClass<T>::PreOrder()
{
	//PreOrder(root);   //�ݹ����
	PreOrderNotFac(root);//�ǵݹ����
}


template <typename T>
void BTNodeClass<T>::PreOrder(BTNode<T> *r)
{
	if (r != NULL)
	{
		cout << r->data << " ";
		PreOrder(r->lchild);
		PreOrder(r->rchild);
	}
}


template <typename T>
int BTNodeClass<T>::BTNodeHeight()
{
	return Height(root);
}


template <typename T>
int BTNodeClass<T>::Height(BTNode<T> *r)
{
	int ilchild = 0;
	int irchild = 0;
	if (NULL == r) return 0;
	else
	{
		ilchild = Height(r->lchild);
		irchild = Height(r->rchild);
		return ilchild > irchild ? (ilchild + 1) : (irchild + 1) ;
	}
}

template <typename T>
BTNode<T> *BTNodeClass<T>::FindNode(T x)
{
	return Find(root,x);
}



template <typename T>
BTNode<T>* BTNodeClass<T>::Find(BTNode<T> *r,T x)
{
	BTNode<T> *p = NULL;
	if (NULL == r)return NULL;
	else
	{
		if (x == r->data)return r;
		else
		{
			p = Find(r->lchild, x);
			if (NULL != p)return p;
			else
			{
				return Find(r->rchild, x);
			}

		}
	}
}

template <typename T>
BTNodeClass<T>::BTNodeClass()
{
	root = NULL;
}

template <typename T>
BTNodeClass<T>::~BTNodeClass()
{
	DestroyBTree(root);
}


template <typename T>
void BTNodeClass<T>::DestroyBTree(BTNode<T> *r)
{
	if (NULL != r)
	{
		DestroyBTree(r->lchild);
		DestroyBTree(r->rchild);
		delete r;
	}
}


template <typename T>
void BTNodeClass<T>::CreateBTNode(char *str)
{
	BTNode<T> *p = NULL;
	LinkStackClass<BTNode<T>*> st;
	BTNode<T> *e;
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
			p = new BTNode<T>();
			p->lchild = NULL;
			p->rchild = NULL;
			p->data = ch;
			if (NULL == root)root = p;
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
void BTNodeClass<T>::Display(BTNode<T> *r)
{
	if (NULL != r)
	{
		cout << r->data;
		if (r->lchild != NULL || r->rchild != NULL)
		{
			cout << "(";
			Display(r->lchild);
			if (r->rchild != NULL)
				cout << ",";
			Display(r->rchild);
			cout << ")";
		}
	}
}


template <typename T>
void BTNodeClass<T>::DispBTNode()
{
	Display(root);
}