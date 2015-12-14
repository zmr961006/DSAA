/*************************************************************************
	> File Name: DFS.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月09日 星期三 22时25分35秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define  MAXVEX      20  
#define  INFINITY    0

typedef int vextype ;

typedef struct AdjMatrix{

    int arcs[MAXVEX][MAXVEX];
    vextype vex[MAXVEX];
    int vexnum         ;
    int arcnum         ;

}AdjMatrix ;




void DFS(AdjMatrix *G,int i);

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

        /*printf("please enter weight\n");      
        scanf("%d",&weight);
        */
        G->arcs[vex1][vex2] = 0;     /*test weight = 0*/
        G->arcs[vex2][vex1] = 0;
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


void TraverseGraph(AdjMatrix *G,int index){
    int i;
    for(i = 1;i <= G->vexnum;i++){
        G->vex[i] = 0;
    }
    for(i = 1;i <= G->vexnum;i++){
        if(!G->vex[i])
            DFS(G,i);
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


void DFS(AdjMatrix *G,int i){
    
    int w;
    printf("%d \n",i);
    G->vex[i] = 1;
    w = FirstAdjvex(G,i);
    while(w != -1){
        if(!G->vex[i])
            DFS(G,w);
        w = NextAdjvex(G,i,w);
    }

}




int main(){
    AdjMatrix *G;
    G = (AdjMatrix *)malloc(sizeof(struct AdjMatrix));
    AdjMatrix_create(G);
    TraverseGraph(G,1);
    return 0;
}

