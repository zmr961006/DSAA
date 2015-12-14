/*************************************************************************
	> File Name: BFS.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月10日 星期四 08时15分13秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define  MAXVEX    20
#define  INFINITY  0

typedef int  vextype;

typedef struct AdjMatrix{
    
    int arcs[MAXVEX][MAXVEX];
    vextype vex[MAXVEX];
    int  vexnum;
    int  arcnum;

}AdjMatrix;

typedef struct node{

    int adjvex;
    struct node * next;

}node ;

typedef struct queue{

    struct node *rear;
    struct node *tail;
    int count;

}queue;


queue * queue_init(){

    queue * Q;
    Q = (queue *)malloc(sizeof(struct queue));
    Q->rear = NULL;
    Q->tail = NULL;
    Q->count = 0;
    return Q;
}

void queue_inq(queue *Q,int v){
    if(!Q){
        return;
    }
    node * p;
    p = (node *)malloc(sizeof(node));
    p->adjvex = v;
    if(Q->count == 0){
        Q->rear = Q->tail = p;
    }else{
        p->next =Q->tail;
        Q->tail = p;
    }
}

int queue_deq(queue *Q){
    if(!Q){
        return -1;
    }
    if(Q->count <= 0){
        return -1;
    }
    
    node *temp;
    temp = Q->rear;
    Q->rear = Q->rear->next;

    return temp->adjvex;
}

int isEmpty(queue * Q){
    if(Q->count == 0){
        return 1;
    }else if(Q->count < 0){
        return -1;
    }else{
        return 0;
    }
}


void AdjMatrix_create(AdjMatrix *G){
    int i,j,k,weight,vex1,vex2;

    printf("vexnum and arcnum: \n");

    scanf("%d,%d",&G->vexnum,&G->arcnum);

    for(i = 1 ;i <= G->vexnum;i++){
        for(j = 1;j <= G->vexnum;j++){
            G->arcs[i][j] = INFINITY;
        }
    }
    printf("%d %d\n",G->vexnum,G->arcnum);
    for(k = 1;k <= G->arcnum;k++){

        printf("please enter vex1 and vex2\n");

        scanf("%d,%d",&vex1,&vex2);
    
        G->arcs[vex1][vex2] = 0;
        G->arcs[vex2][vex1] = 0;

    }
}


int FirstAdjvex(AdjMatrix *G,int i){
    int j ;
    for(j = 1;j <= G->vexnum;j++){
        if(G->arcs[i][j] != 0){
            printf("j = %d\n",j);
            return j;
        }
    }
    return -1;
}

int NextAdjvex(AdjMatrix *G,int i,int w){
    int j;
    for(j = 1;j <= G->vexnum;j++){
        if(G->arcs[i][j] != 0  &&  j!= w){
            return j;
        }
    }
    return -1;
}


void BFS(AdjMatrix *G,int v){
    printf("%d\n",v);
    G->vex[v] = 1;
    queue * Q;
    int w;
    Q = queue_init();
    queue_inq(Q,v);
    while(!isEmpty(Q)){
        v = queue_deq(Q);
        w = FirstAdjvex(G,v);
        while(w != -1){
            if(!G->vex[w]){
                printf("%d\n",w);
                G->vex[w] = 1;
                queue_inq(Q,w);
            }
            w = NextAdjvex(G,v,w);   
        }
    }
}



void TraverG(AdjMatrix * G,int v){
    int i ;
    for(i = 1;i <= G->vexnum;i++){
        G->vex[i] = 0;
    }
    for(i = 1; i <= G->vexnum;i++){
        if(!G->vex[i]){
            BFS(G,i);
        }
    }
}



int main(){
    AdjMatrix * G;
    G = (AdjMatrix *)malloc(sizeof(AdjMatrix));
    AdjMatrix_create(G);
    TraverG(G,1);
    return 0;
}
