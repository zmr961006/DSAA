/*************************************************************************
	> File Name: Floyd.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月14日 星期一 19时54分43秒
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

        printf("please enter vex1, vex2 and weight\n");
        scanf("%d,%d,%d",&vex1,&vex2,&weight);
        
        G->arcs[vex1][vex2] = weight;

    }  


}



void  Floyd(AdjMatrix *G,int F[][MAXVEX]){

    int path[MAXVEX][MAXVEX];
    int i,j,k;

    for(i = 1;i <= G->vexnum;i++){
        for(j = 1;j <= G->vexnum;j++){
            F[i][j] = G->arcs[i][j];
            path[i][j] = INFINITY;
        }
    }

    for(i = 1;i <= G->vexnum;i++){
        for(j = 1;j <= G->vexnum;j++){
            for(k = 1;k <= G->vexnum;k++){
                if(F[i][j] > F[i][k] + F[k][j]){
                    F[i][j] = F[i][j] + F[k][j];
                    path[i][j] = F[i][k] + F[k][j];
                }
            }
        }
    }

}


int main(){
    AdjMatrix *G;
    G = (AdjMatrix *)malloc(sizeof(struct AdjMatrix));

    int  F[MAXVEX][MAXVEX];

    Floyd(G,F);
    
}
