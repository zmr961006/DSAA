/*************************************************************************
	> File Name: bin_tree_srearch.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月15日 星期二 10时36分28秒
 ************************************************************************/

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

void show(Node *root){
    if(root){
        show(root->lchild);
        printf("%d ",root->obj);
        show(root->rchild);

    }else{

        return ;

    }
}


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


int main(){
   
    Node **bst;
    bst = (Node **)malloc(sizeof(Node));
    bst = Created_bst(bst);
    show(*bst);


}
