#include "BinaryTree.h"
#include "Qeque.h"


BinaryTree::BinaryTree()
{
    //ctor
    mRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
    //dtor
    cout << "\n������:\n";
    dispose(mRoot);  //ʹ�ú���������������

}

/*���ٶ�����*/
 void BinaryTree::dispose(BTNode* btn)
 {
     if (nullptr == btn)
        return;
     else
     {
         dispose(btn->leftChild);
         dispose(btn->rightChild);
         cout << btn->data;
         delete btn;
         btn = nullptr;
     }

 }


 /*��δ���������**/
 void BinaryTree::creatLevelBinaryTree()
 {
     char ch=getchar();
     Qeque<BTNode*> q;
     BTNode* s = nullptr;

     if (ch != '#' && ch != '\n')
    {
        s = new BTNode();
        s->data = ch;
        s->leftChild = nullptr;
        s->rightChild = nullptr;
        q.enterQeque(s);
        mRoot = s;
    }

     while(!q.isEmpty())
     {
        ch = getchar();
        q.deQeque(s);
        if(ch != '\n' && ch != '#')
        {
            s->leftChild = new BTNode();
            s->leftChild->data = ch;
            q.enterQeque(s->leftChild);
        }else if(ch == '#')
        {
            s->leftChild = nullptr;
        }
        /*else
        {
            break;
        }*/

        ch = getchar();
        if(ch != '\n' && ch != '#')
        {
            s->rightChild = new BTNode();
            s->rightChild->data = ch;
            q.enterQeque(s->rightChild);
        }else if(ch == '#')
        {
            s->rightChild = nullptr;
        }
     }
 }

 /*���ù������������**/
void BinaryTree::createBinaryTree()
{
    char ch;
    char flag = -1;
    BTNode* p = nullptr;
    BTNode* st[100]={nullptr};
    int top = -1;
    while((ch=getchar()) != '\n')
    {
        switch(ch)
        {
        case '(':
            st[++top] = p;  //���游�ڵ�
            flag = 0;
            break;
        case ',':
            flag = 1;
            //top++;
            break;
        case ')':
            top--;
            break;
        default:
            p = new BTNode();
            p->data = ch;
            p->leftChild = nullptr;
            p->rightChild = nullptr;

            if (nullptr == mRoot)
                mRoot = p;
            else
            {
                switch(flag)
                {
                case 0:
                    st[top]->leftChild = p;
                    break;
                case 1:
                    st[top]->rightChild = p;
                    break;
                default:
                    break;
                }
            }
            break;
        }
    }
}

/*�ǵݹ����*/
void BinaryTree::NonRecursiveMiddleOrder()
{
    BTNode* t = mRoot;
    BTNode* st[100] = {nullptr};
    int top = -1;
    while(t || (-1 != top))
    {
        while(t)
        {
            st[++top] = t;
            t = t->leftChild;
        }
        if(-1 != top)
        {
            t = st[top--];
            cout << t->data;
            t = t->rightChild;
        }
    }
}

/*�ǵݹ�ǰ�����**/
void BinaryTree::NonRecursivePreOrder()
{
    BTNode* t = mRoot;
    BTNode* st[100] = {nullptr};
    int top = -1;
    while(t || (-1 != top))
    {
        while(t)
        {
            st[++top] = t;
            cout << t->data;
            t = t->leftChild;
        }
        if(-1 != top)
        {
            t = st[top--];

            t = t->rightChild;
        }
    }
}


/*�ǵݹ�������*/
void BinaryTree::NonRecursicePostOrder()
{
    BTNode* t = mRoot;
    BTNode* st[100] = {nullptr};
    int top = -1;
    BTNode* q = nullptr;
    bool flag = false;
    do
    {
        while(t)
        {
            st[++top] = t;
            t = t->leftChild;
        }
        q = nullptr;    //q��ʾջ���ڵ��ǰһ���Ѿ����ʹ��Ľڵ����Ϊ��
        flag = true;   //��ʾ�������Ѿ����ʻ���Ϊ��
        while(-1 != top && flag == true)
        {
            t = st[top];
            if (t->rightChild == q)
            {
                cout << t->data;
                top--;
                q = t;      //qָ��δ���ʵĽڵ�
            }else
            {
                t = t->rightChild;
                flag = false;   //��ʱt��������δ����
            }
        }
    }while(-1 != top);
}


/*ǰ�����**/
void BinaryTree::insidePreOrder(BTNode* btn)
{
    if(nullptr == btn)
        return;
    if (nullptr != btn)
    {
        cout << btn->data;
        insidePreOrder(btn->leftChild);
        insidePreOrder(btn->rightChild);
    }
}


/*ǰ�����**/
void BinaryTree::PreOrder()
{
    insidePreOrder(mRoot);
}


/*��ȡ���ĸ߶�**/
int BinaryTree::getHeight()
{
    insideGetHeigth(mRoot);
}


/*��ȡ���ĸ߶�**/
int BinaryTree::insideGetHeigth(BTNode* btn)
{
    if (btn == nullptr)
        return 0;
    else
    {
        int leftHeight = insideGetHeigth(btn->leftChild);
        int rightHeigth = insideGetHeigth(btn->rightChild);
        return (leftHeight>rightHeigth) ? leftHeight+1 : rightHeigth+1;
    }
}

/*�������**/
void BinaryTree::MiddleOrder()
{
    insideMiddleOrder(mRoot);
}


/*�������**/
void BinaryTree::insideMiddleOrder(BTNode* btn)
{

    if (nullptr == btn)
        return;
    else
    {
        insideMiddleOrder(btn->leftChild);
        cout << btn->data;
        insideMiddleOrder(btn->rightChild);
    }


}
