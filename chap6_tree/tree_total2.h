/*************************************************************************
	> File Name: tree_total2.h
	> Author: 
	> Mail: 
	> Created Time: 2015年12月07日 星期一 21时08分22秒
 ************************************************************************/

#ifndef _TREE_TOTAL2_H
#define _TREE_TOTAL2_H


typedef struct node {

    char data;
    struct node *lchild;
    struct node *rchild;

}node ,*tree;


typedef struct _node{

    node *pos;
    struct _node *next;

}_node;

typedef struct stack{
    
    int count   ;
    _node *top  ;
    _node *base ;

}stack;

typedef struct queue{
    
    int count   ;
    _node *tail ;
    _node *rear ;

}queue;




#endif
