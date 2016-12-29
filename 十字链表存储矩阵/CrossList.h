#ifndef CROSSLIST_H_INCLUDED
#define CROSSLIST_H_INCLUDED
#include <iostream>

using namespace std;
typedef int ElementType;
typedef struct MatrixNode*  PtrMatrix;

//节点数据
typedef struct TermNode
{
	int row;
	int col;
	ElementType data;
};

typedef enum { Head = 0, Term }NodeTag;

//十字链表的定义
typedef struct MatrixNode
{
	PtrMatrix down; //列指针
	PtrMatrix right;  //行指针
	NodeTag tag;  //用于标识是头结点还是数据节点
	union
	{
		PtrMatrix next;
		TermNode term;
	}URegion;

};

PtrMatrix Find(PtrMatrix head, int row, int col)
{
	PtrMatrix s = head->right;
	while (s != head)
	{
		if (s->URegion.term.row == row && s->URegion.term.col == col)
		{
			return s;
		}
		s = s->right;
	}
	return nullptr;
}

PtrMatrix CreateCrossList(ElementType **a, int row, int col)
{
	int cnt = 0;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (0 != a[i][j])
				++cnt;
		}
	}

	PtrMatrix ret = (PtrMatrix)malloc(sizeof(MatrixNode));
	ret->tag = NodeTag::Term;
	ret->URegion.term.row = row;
	ret->URegion.term.col = col;
	ret->URegion.term.data = cnt;

	PtrMatrix s = ret;

	PtrMatrix down = nullptr;
	PtrMatrix right = nullptr;



	//建立列的头结点,循环单链表
	for (int i = 0; i < col; ++i)
	{
		PtrMatrix n = (PtrMatrix)malloc(sizeof(MatrixNode));

		n->tag = NodeTag::Head;
		if (s->tag == NodeTag::Head)
		{
			s->URegion.next = n;
			s->down = nullptr;
			s->right = nullptr;
		}
		else
		{
			s->right = n;
			s->URegion.next = nullptr;
		}

		s = n;
	}
	s->URegion.next = ret;


	s = ret;
	//建立行的头结点,循环单链表
	for (int i = 0; i < row; ++i)
	{
		PtrMatrix n = (PtrMatrix)malloc(sizeof(MatrixNode));

		n->tag = NodeTag::Head;
		if (s->tag == NodeTag::Head)
		{
			s->URegion.next = n;
			s->down = nullptr;
			s->right = nullptr;
		}
		else
		{
			s->down = n;
			s->URegion.next = nullptr;
		}

		s = n;
	}
	s->URegion.next = ret;

	s = nullptr;
	PtrMatrix rowPtr = ret->down;
	right = rowPtr;


	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (0 != a[i][j])
			{
				s = (PtrMatrix)malloc(sizeof(MatrixNode));
				s->tag = NodeTag::Term;
				s->URegion.term.data = a[i][j];
				s->URegion.term.row = i;
				s->URegion.term.col = j;

				right->right = s;
				right = s;

			}

		}
		//处理完一行

		right->right = rowPtr;
		rowPtr = rowPtr->URegion.next;
		right = rowPtr;

	}


	//连接列链表
	rowPtr = ret->down;
	right = rowPtr;
	PtrMatrix colPtr = ret->right;
	down = colPtr;
	for (int i = 0; i < col; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			if (0 != a[j][i])
			{
				PtrMatrix f = Find(right, j, i);
				if (nullptr != f)
				{
					down->down = f;
					down = down->down;
				}

			}
			right = right->URegion.next;
		}
		down->down = colPtr;
		down = colPtr->URegion.next;
		colPtr = colPtr->URegion.next;
		right = ret->down;
	}

	return ret;
}


#endif // CROSSLIST_H_INCLUDED
