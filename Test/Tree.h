  typedef struct _BTNode
  {
	  int data;
	  struct _BTNode *lchild;
	  struct _BTNode *rchild;
  }BTNode;
  
  int CreateBiTree(BTNode **T)
  {
	  int ch;
	  scanf("%d",&ch);
	  if (-1 == ch)
	  {
		  *T = NULL;
		  return 0;
	  }
	  else
	  {
		  *T = (BTNode*)malloc(sizeof(BTNode));
		  if (NULL == *T)
		  {
			  printf("fail\n");
			  return 0;
		  }
		  else
		  {
			  (*T)->data = ch;
			  printf("输入%d左子节点：",ch);
			  CreateBiTree(&((*T)->lchild));
			  
			  printf("输入%d右子节点：",ch);
			  CreateBiTree(&((*T)->rchild));
			  
		  }
	  }
	  return 1;
	  
  }
  
  
  ///先序遍历二叉树
  void PreOrderBiTree(BTNode *T)
  {
	  if (NULL == T)
	  {
		  return;
	  }
	  printf("%d ",T->data);
	  PreOrderBiTree(T->lchild);
	  PreOrderBiTree(T->rchild);  
  }
  
    ///中序遍历二叉树
  void PreOrderBiTree(BTNode *T)
  {
	  if (NULL == T)
	  {
		  return;
	  }
	 
	  PreOrderBiTree(T->lchild);
	  printf("%d ",T->data);
	  PreOrderBiTree(T->rchild);  
  }
  
      ///后序遍历二叉树
  void PreOrderBiTree(BTNode *T)
  {
	  if (NULL == T)
	  {
		  return;
	  }
	 
	  PreOrderBiTree(T->lchild);
	  PreOrderBiTree(T->rchild);  
	  printf("%d ",T->data);
  }
  
  ////二叉树的深度
  int TreeDeep(BTNode *T)
  {
	  int deep = 0;
	  if (NULL != T)
	  {
		  int leftDeep = TreeDeep(T->lchild);
		  int rightDeep = TreeDeep(T->rchild);
		  deep = leftDeep >= rightDeep ? leftDeep + 1 : rightDeep + 1;
	  }
	  return deep;
  }
  
  //叶节点数
  int LeafCount(BTNode *T)
  {
	  static int count = 0;
	  if(NULL != T)
	  {
		  if(T->lchild == NULL && T->rchild)
		  {
			  count++;
		  }
		  LeafCount(T->lchild);
		  LeafCount(T->rchild);
	  }
	  return count;
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  