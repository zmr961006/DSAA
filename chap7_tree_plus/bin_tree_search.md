#第七章  二叉排序树

##二叉排序树

二叉排序树（BST）也就是二叉查找树。满足以下性质的特殊二叉树。

1.如果左子树不为空，则左子树上的所有结点的值均小于根结点的值。

2.如果右子树不为空，则右子树上的所有结点的值均大于根结点的值。

3.它的左，右子树也都是二叉排序树，毕竟树的一个基本属性就是递归性。

###关于二叉排序树的性能分析

二叉排序树的查找最差情况于顺序查找相同，ASL=(n+1)/2 .

最好的情况与折半查找相同，ASL =  log2N .

###关于二叉排序树的一些操作

```
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define  MAXSIZE  1000

typedef int  KeyType;

typedef struct Node{

    KeyType obj;
    struct Node *rchild;
    struct Node *lchild;

}Node,*Bstree;

```
####查找
```
Node *SearchBST(Node *bst,KeyType K){
    
    Node *q;
    q = bst;
    while(q){
        if(q->obj == K){
            return q;
        }else if(K < q->obj){
            q = q->lchild;
        }else{
            q = q->rchild;
        }
    }

    return NULL;
}

Node *SearchBST_B(Node *bst,KeyType K){
    
    if(!bst){
        return NULL;
    }else if(bst->obj == K){
        return bst;
    }else if(K < bst->obj){
        return SearchBST_B(bst->lchild,K);
    }else if(K > bst->obj){
        return SearchBST_B(bst->rchild,K);
    }
}

```
####插入
```
void InsertBST(Node **bst,KeyType K){
    
    Node *s;
    if(*bst == NULL){
        s = (Node *)malloc(sizeof(struct Node));
        s->obj = K;
        s->lchild = NULL;
        s->rchild = NULL;
        *bst = s;
        //printf("%d\n",bst->obj);
    }else if((*bst)->obj > K){
        InsertBST(&(*bst)->lchild,K);
    }else if((*bst)->obj < K){
        InsertBST(&(*bst)->rchild,K);
    }

}

```

####创建

```
Node ** Created_bst(Node **bst){
    KeyType key;
    *bst = NULL;
    int count ;
    printf("please enter count\n");
    scanf("%d",&count);
    while(count > 0){
        printf("please enter the num \n");
        scanf("%d",&key);
        printf("%p\n",bst);
        InsertBST(bst,key);
        
        count--;
    }
    
    return bst;
}


遍历：
void show(Node *root){
    if(root){
        show(root->lchild);
        printf("%d ",root->obj);
        show(root->rchild);

    }else{

        return ;

    }
}


```
###删除

```
Node * Delete(Node * node,KeyType K){
    Node *p,*f,*s,*q;
    p = *node;
    f = NULL;
    while(p){
        if(p->obj == K){
            break;
        }
        f = p;
        if(p->obj > K){
            p = p->lchild;
        }else{
            p = p->rchild;
        }
    }
    if(p == NULL)
        return bst;
    if(p->lchild == NULL){
        if(f == NULL){
            bst = p->rchild;
        }else if(f->lchild == p){
            f->lchild = p->rchild;
        }else{
            f->rchild = p->rchild;
        }
        free(p);
    }else{
        q = p;
        s = p->lchild;
        while(s->rchild){
            q = s;
            s = s->rchild;
        }
        if(q == p){
            q->lchild = s->lchild;
        }else{
            q->rchild = s->rchild;
        }
        p->obj = s->obj;
        free(s);
    }
    return node;

}

```

