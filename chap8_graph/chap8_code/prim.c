/*************************************************************************
	> File Name: prim.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月10日 星期四 16时03分44秒
 ************************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define  MAXVEX      20  
#define  INFINITY    32767

typedef int vextype ;

typedef struct AdjMatrix{

    int arcs[MAXVEX][MAXVEX];
    vextype vex[MAXVEX];
    int vexnum         ;
    int arcnum         ;

}AdjMatrix ;

typedef struct closedge{

    int adjvex;
    int lowcost;

}closedge;


void  AdjMatrix_create(AdjMatrix *G){
    
    int i,j,k,weight,vex1,vex2;
    printf("vexnum  and  arcnum：\n");

    scanf("%d,%d",&G->vexnum,&G->arcnum);


    for(i = 1; i <= G->vexnum;i++){            /*init the graph*/
        for(j = 1; j <= G->vexnum;j++){
            G->arcs[i][j] = INFINITY ;
        }
    }
    
    for(k = 1;k <=G->arcnum;k++){
        printf("please enter vex1 and vex2 and weight\n");
        scanf("%d,%d,%d",&vex1,&vex2,&weight);
        
        G->arcs[vex1][vex2] = weight;
        G->arcs[vex2][vex1] = weight;
    }  


}

static closedge  local[MAXVEX];          /*全局的标识数组*/

void prim(AdjMatrix * G,int start){
    int i,e,k,m,min;
    local[start].lowcost = 0;

    for(i = 1;i <= G->vexnum;i++){      /*第一次初始化全局数组*/
        if(i != start){
            local[i].adjvex = start ;
            local[i].lowcost = G->arcs[start][i];   
        }
    }
    printf("start :%d\n",start);    /*打印开始结点*/
    for(e = 1; e <= G->vexnum-1;e++){
        min = INFINITY;
        for(k = 1;k <= G->vexnum;k++){
            if(local[k].lowcost != 0 && local[k].lowcost < min){
                m = k;
                min = local[k].lowcost;
            }
        }
        local[m].lowcost = 0;      
        printf("%d\n",m);            /*打印后边遍历的结点*/
        for(i = 1;i <= G->vexnum;i++){
            if(i != m && G->arcs[m][i] < local[i].lowcost){
                local[i].lowcost = G->arcs[m][i];
                local[i].adjvex = m;
            }
        }
    }

}

int main(){

    AdjMatrix *G;
    G = (AdjMatrix *)malloc(sizeof(AdjMatrix));
    AdjMatrix_create(G);
    prim(G,1);

}



