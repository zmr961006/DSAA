/*************************************************************************
	> File Name: stack_list.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月04日 星期五 12时52分11秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define   SUCCESS   0

#define   FAIL      -1

typedef struct  node{
    
    int data;
    struct node *next;

}_node;


typedef struct nodectl{
    
    _node * top;
    _node *base;
    int count  ;
}_ndctl;



void stack_init(_ndctl *ctl){
    
    memset(ctl,0x00,sizeof(_ndctl));

}


void push(_ndctl * ctl,_node *node){
    
    if(NULL == ctl && NULL == node){
        return ;
    }
    if(NULL == ctl->top){
        ctl->top = node ;
        ctl->base = node ;
    }else{
        node->next = ctl->top ;
        ctl->top   = node     ;
    }
    ctl->count++;

}

_node *pop(_ndctl *ctl){
    
    _node *p;
    if(NULL == ctl){
        return NULL;
    }

    p = ctl->top;
    
    if(ctl->count > 0){
        ctl->top = ctl->top->next;
        ctl->count--;
    }

    return p;

}

void stack_destory(_ndctl * ctl){

    _node * temp;
    if(NULL == ctl){
        
        return ;
    }

    while(0 < ctl->count){

        ptemp = ctl->top->next;
        free(ctl->top);
        ctl->top = ptemp;
        ctl->count--;

    }

}

