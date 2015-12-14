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

void Dijkstra(AdjMatrix *G,int start,int end,int *dist,int path[][MAXVEX]){
    int mindist,i,j,k,t = 1;
    for(i = 1;i <= G->vexnum;i++){  
        dist[i] = G->arcs[start][i];   /*初始化dist为start到每一个顶点的距离*/
        if(G->arcs[start][i] != INFINITY)   /*如果开始结点可以到达某棵结点，则路径集合中加入这个结点*/
            path[i][1] = start;
        path[i][0] = 0;            /*初始化很重要，不然会出错，也可以到外面初始化*/
    }
    path[start][0] = 1;        /*表示开始结点已经被表示为进入S集合*/
    for(i = 2;i <= G->vexnum;i++){   /*寻找各条最短路径*/

        mindist = INFINITY;          /*初始化最小距离为INFINITY*/
        for(j = 1;j <= G->vexnum;j++){  /*选取权值最小路径*/

            if(!path[j][0] && dist[j] < mindist){   /*未进入S且当前路径小与 最小*/
                k = j;                       
                mindist = dist[j];
            }
            if(mindist == INFINITY){ 
                continue;
            }
     
            path[k][0] = 1;
            for(j = 1;j <= G->vexnum;j++){  /*修改路径*/
                if(!path[j][0] && G->arcs[k][j] < INFINITY && dist[k]+G->arcs[k][j] < dist[j]){
                    dist[j] = dist[k] + G->arcs[k][j];
                    t = 1;
                    while(path[k][t] != 0){   /*将当前路径记录下来，复制置前的路径然后添加最新的结点*/
                        path[j][t] = path[k][t];
                        t++;
                    }
                    path[j][t] = k;
                    path[j][t+1] = 0;
                }
            }
        }
    }


}

int main(){
    AdjMatrix *G;
    G = (AdjMatrix *)malloc(sizeof(struct AdjMatrix));
    AdjMatrix_create(G);
    int dist[MAXVEX];
    int path[MAXVEX][MAXVEX];
    Dijkstra(G,1,4,dist,path);
    int i;
    for(i = 1;i <= 5;i++){
        printf("%d \n",dist[i]);
    }
}
