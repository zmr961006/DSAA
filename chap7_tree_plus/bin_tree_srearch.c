/*************************************************************************
	> File Name: bin_tree_srearch.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月15日 星期二 10时36分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int KeyType ;

typedef struct Node{

    KeyType key;
    struct Node *lchild;
    struct Node *rchild;

}BSTNode,*BSTree;


BSTree SearchBST(BSTree bst,KeyType K){
    BSTree q;
    q = bst;
    while(q){
        if(q->key == K)
            return q;
        if(K < q->key){  
            q = q->lchild;
        }else{
            q = q->rchild;
        }
    }
    return NULL;
}


BSTree SearchBST(BSTree bst,KeyType K){
    if(!bst){
        return NULL;
    }else if(bst->key == K){
        return bst;
    }else if(k < bst->key){
        return SearchBST(bst->lchild,key);
    }else{
        return SeatchBST(bst->rchild,key);
    }
}


void InsertBST(BSTree *bst,KeyType K){
    BiTree S;
    if(*bst == NULL){
        S = (BSTree)malloc(sizeof(struct BSTNode));
        S->key = K;
        S->lchild = NULL;
        S->rchild = NULL;
        bst = S;
    }else if(K <(*bst)->Key){
        return InsertBST(&((*bst)->lchild),K);
    }else if(K >(*bst)->Key){
        return InsertBST(&((*bst)->rchild),K);
    }

}

void Create(BSTree *bst){
    KeyType key;
    *bst = NULL;
    scanf("%d",&key);
    while(key != ENDKEY){
        InsertBST(bst,key);
        scanf("%d",&key);
    }
}

BSTNode * DelBST(BSTree bst,KeyType K){
    BSTNode *p,*f,*s,*q;
    p = bst;
    f = NULL;
    while(p){
        if(p->key == K){
            break;
        }
        f = p;
        if(p->key>K){
            p = p->lchild;
        }else{
            p = p->rchild;
        }
    }
    if(p->lchild == NULL){
        return bst;
    }
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
            q->rchild = s->lchild;
        }
        p->key = s->key;
        free(s);
    }
    return bst;
}

