/*************************************************************************
	> File Name: linjie.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月09日 星期三 16时58分26秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define  MAXVEX      20  
#define  INFINITY    0

typedef int vextype ;

typedef struct AdjMatrix{

    int arcs[MAXVEX][MAXVEX];
    vextype vex[MAXVEX];
    int vexnum         ;
    int arcnum         ;

}AdjMatrix ;


void  AdjMatrix_create(AdjMatrix *G){
    
    int i,j,k,weight,vex1,vex2;
    printf("vexnum  and  arcnum：\n");

    scanf("%d,%d",&G->vexnum,&G->arcnum);


    for(i = 1; i <= G->vexnum;i++){            /*init the graph*/
        for(j = 1; j <= G->vexnum;j++){
            G->arcs[i][j] = INFINITY ;
        }
    }
    
    for(k = 0;k < G->arcnum;k++){
        printf("please enter vex1 and vex2\n");
        scanf("%d,%d",&vex1,&vex2);

        printf("please enter weight\n");
        scanf("%d",&weight);
        
        G->arcs[vex1][vex2] = weight;
        G->arcs[vex2][vex1] = weight;
    }  


}


void show(AdjMatrix *G){
    
    int i,j;
    for(i = 1;i <= G->vexnum;i++)
         for(j = 1;j <= G->vexnum;j++){
            printf("%d ",G->arcs[i][j]);
            if(j % G->vexnum == 0){
                printf("\n");
            }

        }


}


int main(){
    
    AdjMatrix *G;
    G = (AdjMatrix *)malloc(sizeof(struct AdjMatrix));
    AdjMatrix_create(G);
    show(G);

    return 0;

}

