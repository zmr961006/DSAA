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



/*int main(){
    AdjList * G;
    G = (AdjList *)malloc(sizeof(struct AdjList));
    AdjList_create(G);
    show(G);

}*/


