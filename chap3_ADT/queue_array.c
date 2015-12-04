/*************************************************************************
	> File Name: queue_array.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月04日 星期五 13时32分00秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define   MAX   10

#define   SUCCESS  0
#define   FAIL     -1

/*这是一个循环队列，使用少用一个空间的办法解决判满判空的问题*/

typedef struct queue{
    int front;
    int rear ;
    int count;
    int * queue_array;      /*这里使用一个指针也是为了以后能动态开辟大小空间*/
                            /*在linux kernel 中也有int * queue_array[0] 这种写法，都是为了动态扩大*/
}queue;


queue * queue_create(void){
    queue * Q;
    Q = (queue *)malloc(sizeof(struct queue));
    Q->queue_array = (int *)malloc(sizeof(int) * MAX);

    Q->front = Q->rear = MAX -1;
    Q->count = 0;
    return Q;
}

int queue_in(queue * Q,int num){
    
    if(!Q){
        return FAIL;
    }

    if((Q->rear+1) % MAX == Q->front){

        return FAIL;

    }else{

        Q->rear = (Q->rear + 1)%MAX;
        Q->queue_array[Q->rear] = num;
        Q->count++;

    }
    

    return SUCCESS;

}

int queue_out(queue * Q){
    if(!Q){
        return FAIL;
    }
    if(Q->front == Q->rear){
        return FAIL;
    }else{
        
        Q->front = (Q->front+1)%MAX;
        Q->count--;
        return Q->queue_array[Q->front];

    }
}


int EmptyisQueue(queue *Q){
    
    if(Q->front == Q->rear){

        return SUCCESS;

    }else{

        return FAIL;

    }
}


int main(){
    queue *Q;
    Q = queue_create();
    int i ;
    for(i = 0;i < 5;i++){
        queue_in(Q,i);
    }
 
    for(i = 0;i < 5;i++){
        int test;
        test = queue_out(Q);
        printf("%d ",test);
        printf("\n");
    }

}

