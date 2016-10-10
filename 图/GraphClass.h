#ifndef _GRAPH_CLASS_H_
#define _GRAPH_CLASS_H_
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;
#include <assert.h>

#define MAX_SIZE (50)
#define MAXV_SIZE	(4)
#define INF	(65535)
//邻接矩阵
struct VertexType
{
	int no;
	char info[MAX_SIZE];
};

template <typename T>
struct MGraph  //图邻接矩阵类型
{
	T edges[MAXV_SIZE][MAXV_SIZE];
	int n;  //定点数
	int e;  //边数
	VertexType ver[MAXV_SIZE];  //存放顶点信息
};


/*边节点数据类型*/
template <typename T>
struct ArcNode
{
	int adjvex;  //该边的终点编号
	ArcNode* nextarc;  //指向下一条边的指针
	T weight;  //权值
};

/*表头节点数据类型*/
template <typename T>
struct VNode
{
	char info[MAX_SIZE];
	ArcNode<T> *firstarc;
};

/*图的邻接表类型*/
template <typename T>
struct ALGraph
{
	VNode<T> adjlist[MAXV_SIZE];
	int n;
	int e;
};

template <typename T>
class GraphClass
{
private:
	MGraph<T> g; //图的邻接矩阵
	ALGraph<T> *G;  //图的邻接表
public:
	GraphClass();
	virtual ~GraphClass();

	/*通过边数组a，顶点数n和边数e建立图的邻接矩阵*/
	void CreateMGraph(T a[][MAXV_SIZE], int n, int e);
	/*输出图的邻接矩阵*/
	void DisplayMGraph();
	
	/*通过边数组a，顶点数n和边数e建立图的邻接矩阵*/
	void CreateALGraph(T a[][MAXV_SIZE], int n, int e);
	void DisplayALGraph();

private:
	void DestroyGraph(); //销毁图的邻接表
};

template <typename T>
GraphClass<T>::GraphClass()
{
	G = nullptr;
}


template <typename T>
GraphClass<T>::~GraphClass()
{
	
	DestroyGraph();

}

template <typename T>
void GraphClass<T>::DestroyGraph()
{
	assert(nullptr != G);
	ArcNode<T> *pre, *p;
	for (int i = 0; i < G->n; ++i)
	{
		pre = (G->adjlist[i]).firstarc;
		while (nullptr != pre)
		{
			p = pre->nextarc;
			delete pre;
			pre = p;
		}


	}
	delete G;
}

template <typename T>
void GraphClass<T>::CreateMGraph(T a[][MAXV_SIZE], int n, int e)
{
	g.n = n;
	g.e = e;
	for (int i = 0; i < g.n; ++i)
	{
		for (int j = 0; j < g.n; ++j)
		{
			g.edges[i][j] = a[i][j];
			
		}
	}
}

template <typename T>
void GraphClass<T>::DisplayMGraph()
{
	
	for (int i = 0; i < g.n; ++i)
	{
		for (int j = 0; j < g.n; ++j)
		{
			if (g.edges[i][j] == INF)
			{
				cout << "∞ ";
			}
			else
			{
				cout << g.edges[i][j] << " ";
			}
		}
		cout << endl;
	}
		
}

template <typename T>
void GraphClass<T>::CreateALGraph(T a[][MAXV_SIZE], int n, int e)
{
	G = new ALGraph<T>();
	G->n = n;
	G->e = e;
	ArcNode<T> *p = nullptr;
	for (int i = 0; i < G->n; ++i)
		G->adjlist[i].firstarc = nullptr;

	for (int i = 0; i < G->n; ++i)
	{
		for (int j = G->n - 1; j >= 0; --j)
		{
			if (0 != a[i][j] && INF != a[i][j])
			{
				p = new ArcNode<T>();
				p->adjvex = j;
				p->weight = a[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}
	}
}

template <typename T>
void GraphClass<T>::DisplayALGraph()
{
	ArcNode<T> *p = nullptr;
	for (int i = 0; i < G->n; ++i)
	{
		cout << "[" << i << "]";
		p = G->adjlist[i].firstarc;
		if (nullptr != p)cout << "→";
		while (nullptr != p)
		{
			cout << p->adjvex << "(" << p->weight << ") ";
			p = p->nextarc;
		}
		cout << endl;
	}
}

#endif