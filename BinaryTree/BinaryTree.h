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

        void createBinaryTree();  //�������������
        void creatLevelBinaryTree();  //��ν���������
        void PreOrder();
        void MiddleOrder();
        int getHeight();

        void NonRecursiveMiddleOrder();  //�ǵݹ��������
        void NonRecursivePreOrder();    //�ǵݹ�ǰ�����
        void NonRecursicePostOrder();    //�ǵݹ�������


    protected:

    private:
        BTNode* mRoot;
        void insidePreOrder(BTNode* btn);
        void insideMiddleOrder(BTNode* btn);
        int insideGetHeigth(BTNode* btn);
        void dispose(BTNode* btn);
};



#endif // BINARYTREE_H
