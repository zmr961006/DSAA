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


void AdjList_create(AdjList *G){
    
    int i,j,k;
    if(!G){
        printf("G need cast a spece\n");
        return ;
    }

    printf("please enter the vexnum and arcnum\n");

    scanf("%d,%d",&G->vexnum,&G->arcnum);
    for(i = 1;i <= G->vexnum;i++){
        ArcNode *p,*q;
        G->vertex[i]->head = q;
        do{
            
            p = (ArcNode *)malloc(sizeof(struct ArcNode));
            printf("please enter the node about this node\n");
            scanf("%d",p->adjvex);
            if(p->adjvex == -1){
                q->next == NULL;
                break;
            }
            p->weight = G->vertex[p->adjvex].weight;
            q->next = p;
            p = q;
            
        }while(1);
    }
    
    
}


