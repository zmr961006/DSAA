/*************************************************************************
	> File Name: tree_total2.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月07日 星期一 21时06分57秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./tree_total2.h"


stack *INIT_stack(void);           /*  init the satck */
node *pop(stack * S);              /*  pop  */
int push(stack *S,node * node);    /*  push */
node *gettop(stack *S);            /*  gettop */             
queue * INIT_queue();              /*  init the queue */
int queue_inq(queue *Q,node *pos); /*  queue_inq */
int isEmpty(stack *S);             /*  return 1:not empty; 0:empty; -1:error */
void levelorder(node *root);       /*  base on queue traval the bin_tree */
int isEmpty_q(queue *Q);           /*  return 1:not empty; 0:empty; -1:error*/
node* queue_deq(queue *Q);         /*  out of queue */

int isEmpty_q(queue * Q){

    if(Q->count == 0){
        return 0;
    }else if(Q->count < 0){
        return -1;
    }else if(Q->count > 0){
        return 1;
    }

}


void levelorder( node *root ){
    queue * Q;
    Q = INIT_queue();
    node *temp;
    temp = root ;
    queue_inq(Q,temp);
    while(isEmpty_q(Q)){
        temp = queue_deq(Q);
        printf("%c ",temp->data);
        if(temp->lchild != NULL)
            queue_inq(Q,temp->lchild);
        if(temp->rchild != NULL)
            queue_inq(Q,temp->rchild);
    }
    

}



stack* INIT_stack(){
    stack *S;
    S = (stack *)malloc(sizeof(struct stack));
    if(NULL == S){
        return NULL;
    }
    S->top = S->base = NULL ;
    S->count = 0   ;
    return S;
}


node *pop(stack * S){
    if(NULL == S){
        return NULL;
    }

    _node *pos  ;
    pos = S->top;
    S->top = S->top->next;
    S->count--;


    return pos->pos;
    
}


int push(stack *S,node * node){
    if(NULL == S){
        return -1;
    }

    _node *pos;
    pos = (_node *)malloc(sizeof(struct _node));
    pos->pos = node ;
    if(S->count == 0){
        S->top = S->base = pos ;
        S->count++;
    }else{
        pos->next = S->top;
        S->top = pos      ;
        S->count++;
    }

}


node *gettop(stack *S){

    if(NULL == S){
        return NULL;
    }
    node *pos;
    return (pos = S->top->pos);

}


queue * INIT_queue(){
    
    queue *Q;
    Q = (queue *)malloc(sizeof(struct queue));
    if(NULL == Q){
        return NULL;
    }
    
    Q->tail = Q->rear = NULL;
    Q->count = 0;

    return Q;


}


int queue_inq(queue *Q,node *pos){
    
    _node *temp;

    temp = (_node *)malloc(sizeof(struct _node));
    temp->pos = pos;

    if(Q->count == 0){
        Q->rear = Q->tail = temp;
        Q->count++;
    }else{
        Q->tail->next = temp;
        Q->tail = temp      ;
        Q->count++;
    }

}

node* queue_deq(queue *Q){
    if(NULL == Q){
        return NULL;
    }

    if(Q->count == 0){
        printf("out of queue\n");
    }
    _node *temp;
    if(Q->count > 0){
        temp = Q->rear;
        Q->rear = Q->rear->next;
        Q->count--;
        
        return  (temp->pos);
    }

}

node * bin_tree_create(){
    char ch ;
    node *S;
    ch = getchar();
    if(ch == '#'){
        return NULL;
    }
    S = (node *)malloc(sizeof(struct node));
    S->data = ch ;
    S->lchild = bin_tree_create();
    S->rchild = bin_tree_create();

    return S;

}

int isEmpty(stack *S){
    
    if(S->count == 0){
        return 0;
    }else if(S->count > 0 ){
        return 1;
    }else if(S->count < 0 ){
        return -1;
    }

}



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



int main(){
    
    node *R;
    R = bin_tree_create();
    pre_tree(R);
    med_tree(R);
    post_tree(R);
    levelorder(R);
    printf("\n");

}
