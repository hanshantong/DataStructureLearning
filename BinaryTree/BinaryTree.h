#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;



typedef char DataType;
struct BTNode
{
    DataType data;
    BTNode* leftChild;
    BTNode* rightChild;
};

class BinaryTree
{
    public:
        BinaryTree();
        BinaryTree(const BinaryTree& bt)=delete;
        BinaryTree& operator=(const BinaryTree& bt)=delete;
        virtual ~BinaryTree();

        void createBinaryTree();  //广义表创建二叉树
        void creatLevelBinaryTree();  //层次建立二叉树
        void PreOrder();
        void MiddleOrder();
        int getHeight();

        void NonRecursiveMiddleOrder();  //非递归中序遍历
        void NonRecursivePreOrder();    //非递归前序遍历
        void NonRecursicePostOrder();    //非递归后序遍历


    protected:

    private:
        BTNode* mRoot;
        void insidePreOrder(BTNode* btn);
        void insideMiddleOrder(BTNode* btn);
        int insideGetHeigth(BTNode* btn);
        void dispose(BTNode* btn);
};



#endif // BINARYTREE_H
