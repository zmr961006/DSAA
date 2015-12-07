#第六章   树（2）

##前言
    
    上以小节主要小结了一些树的基本知识，以及二叉树的一些简单操作，这一节主要小结以下问题：
       1. 非递归遍历二叉树
       2. 树与森林
       
       
###非递归遍历二叉树

####先序遍历

    非递归先序遍历二叉树，比较容易理解。方法如下：
    1.首先将根结点入栈，然后依次入其左子树，直到左子树为NULL。
    2.如果栈非空，就弹出栈顶元素，然后进入右子树。
    
    ```
    void pre_tree(node *root){
    
    node *p;
    stack *S;
    S = INIT_stack();
    p = root;
    while(p || isEmpty(S)){
            
        while(p){
            printf(" %c ",p->data);
            push(S,p);
            p = p->lchild;
        }

        if(isEmpty(S)){
            p = pop(S);
            p = p->rchild;
        }

    }   
    printf("\n");
}

    ```
 

####中序遍历

    非递归中序遍历二叉树，直接说通用的简洁的。方法如下：
    从根结点开始，当前结点存在或栈不为空 ，重复如下两个步骤。
    1. 若当前结点存在，则当前结点进栈，并进入其左子树。
    2. 否则，退栈并访问出栈结点，然后进入其右子树。
    
    ```
    void med_tree(node * root){
    
    node *p;
    stack *S;
    S = INIT_stack();
    p = root ;
    while(p || isEmpty(S)){
        if(p != NULL){
            push(S,p);
            p = p->lchild;
        }else{
            p = pop(S);
            printf(" %c ",p->data);
            p = p->rchild;
        }
    }
    printf("\n");
}

    ```    

####后序遍历
    
    非递归后序遍历二叉树，比先序和中序能复杂一些。方法如下：
    1.当前结点开始进栈，并进入其左子树，重复直到当前结点为空。
    2.如果栈非空，判断栈顶p的右子树是否非空，右子树是否刚刚访问过，如果是就退栈，访问 p结点，p赋给q,p置空；不是，则进入p的右子树。
    
    ```
    void post_tree(node *root){
    node *p,*q;
    stack *S;
    S = INIT_stack();
    p = root ;
    while(p || isEmpty(S)){
        while(NULL != p){
            push(S,p);
            p = p->lchild;
        }
        if(isEmpty(S)){
            p = gettop(S);
            if(p->rchild == NULL || p->rchild == q){
                p = pop(S);
                printf(" %c ",p->data);
                q = p;
                p = NULL;
            }else{
                p = p->rchild;
            }
        }
    
    }

    printf("\n");
}

    ```
    
    