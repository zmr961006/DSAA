/*************************************************************************
	> File Name: linjieb.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月09日 星期三 18时02分03秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define  MAXVEX    20
#define  TURE      1
#define  FAIL      -1

typedef struct ArcNode{         /* node type */
    
    int adjvex ;
    int weight ;
    struct ArcNode *next;

}ArcNode;


typedef struct VertexNode{
    
    char vexdata ;
    ArcNode *head;

}VertexNode;


typedef struct AdjList{
    
    VertexNode vertex[MAXVEX];
    int vexnum;
    int arcnum;


}AdjList;

//static int indegree[MAXVEX];

void add_node(AdjList *G,int vex1,int vex2,int weight){

    ArcNode *p,*q;
    p = (ArcNode *)malloc(sizeof(struct ArcNode));
    p->adjvex = vex2  ;
    p->weight = weight;
    q = G->vertex[vex1].head;
    do{
        if(NULL == q){
            G->vertex[vex1].head  = p;
            break;
        }else if(NULL == q->next){
            q->next = p;
            p->next = NULL;
            break;
        }else{
            q = q->next;
        }
    }while(1);
    
    return ;

}

void AdjList_create(AdjList *G){
    
    int i,j,k;
    int vex1,vex2,weight;
    if(!G){
        printf("G need cast a spece\n");
        return ;
    }
    
    printf("please enter the vexnum and arcnum\n");

    scanf("%d,%d",&G->vexnum,&G->arcnum);

    for(i = 1;i <= G->vexnum;i++){

        G->vertex[i].head  = NULL;

    }


    for(i = 1;i <= G->arcnum;i++){
        printf("please enter the vex1 and vex2 and weight\n");
        scanf("%d,%d,%d",&vex1,&vex2,&weight);
        add_node(G,vex1,vex2,weight);
        
    }

}


void show(AdjList *G){
    ArcNode *temp;
    int i;

    for(i = 1;i <= G->vexnum;i++){
        temp = G->vertex[i].head;
        if(temp == NULL){
            printf("____________");
        }else{
            while(temp != NULL){
                printf("%d ",temp->adjvex);
                temp = temp->next;
            }
        }   
        printf("\n");
    }
}



void get_in_degree(AdjList *G,int *indegree){
    
    int i;
    ArcNode *temp;
    for(i = 1; i <= G->vexnum; i++){

        indegree[i] = 0;

    }

    for(i = 1;i <= G->vexnum;i++){

        temp = G->vertex[i].head;
        while(temp != NULL){
            indegree[temp->adjvex]++;
            temp = temp->next;
        }

    }

}

int get_zero(AdjList *G,int *indegree){
    
    int i,j;
    for(i = 1;i <= G->vexnum;i++){
        if(indegree[i] == 0){
            indegree[i] = -1;
            return i;
        }
    }
    return FAIL;   
}

int set_sub(AdjList *G,int *indegree,int a){
    int i,j;
    ArcNode *temp;
    temp = G->vertex[a].head;
    while(temp != NULL){
        indegree[temp->adjvex]--;
        temp = temp->next;
    }
    
}


void Topsort(AdjList *G,int *indegree){
    
    int i,j,k;
    for(i = 1;i <= G->vexnum;i++){
        k = get_zero(G,indegree);
        if(k != -1){
            printf("%d \n",k);
            set_sub(G,indegree,k);
        }
    }


}

int main(){
    
    //wait test

}
