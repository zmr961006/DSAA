/*************************************************************************
	> File Name: queue_list.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月04日 星期五 14时55分25秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{

    int data;
    struct node *next;

}_node;

typedef struct _node{
    _node *head;
    _node *tail ;
    int count   ;
}_ctl;

void que_inq(_ctl *ctl,_node *node){

    if(NULL == ctl || NULL == node){

        return ;

    }
    if(!ctl->count){
        ctl->head = node ;
    }else{
        ctl->tail->next = node ;
    }

    ctl->tail = node ;
    node->next = NULL;
    ctl->count++;

}

_node * que_deq(_ctl * ctl){
    
    _node *rst = NULL;

    if(NULL == ctl){
        return NULL;
    }

    rst = ctl->head;

    if(rst){
        ctl->head = rst->next;
        ctl->count--;
        rst->next = NULL;
    }

    return rst;


}


void que_del(_ctl *ctl){
    
    _node *pos = NULL;
    if(NULL == ctl){
        return ;
    }
    
    pos = ctl->head;

    while(pos != NULL){
        ctl->head = pos->next;
        free(pos);
        pos = ctl->head;
    }

}

void que_create(_ctl *ctl ,int len){
    
    _node *pnt = NULL ;
    int fact = 0 ;

    if(NULL == ctl || len < 1){
        return ;
    }

    while(fact < len){
        pnt = (_node *)malloc(sizeof(_node));
        pnt->data = fact + 1;
        que_inq(ctl,pnt);
        fact++;
    }

    
}
