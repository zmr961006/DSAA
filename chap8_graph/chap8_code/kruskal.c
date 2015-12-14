/*************************************************************************
	> File Name: kruskal.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月10日 星期四 20时06分15秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define   MAXVEX      20
#define   INFINITY    32767


typedef int vextype ;

typedef struct AdjMatrix{
    
    int arcs[MAXVEX][MAXVEX];
    vextype vex[MAXVEX];
    int vexnum;
    int arcnum;

}AdjMatrix;


typedef struct group{

    int  vex1;
    int  vex2;
    int  weight;

}group;

typedef struct top_group{
    
    group  topgroup[MAXVEX];
    int vexnum;
    int arcnum;

}top_group;


typedef struct arc{
    
    int vex1;
    int vex2;
    int weight;
    struct arc *next;

}arc;


typedef struct set{

    arc vexarry[MAXVEX];
    int array_count;

}set;


void AdjMatrix_create(AdjMatrix *G,top_group * topgroup){

    int i,j,k,weight,vex1,vex2;

    printf("vexnum  and arcnum: \n");

    scanf("%d,%d",&G->vexnum,&G->arcnum);

    printf("vex  arc :%d  %d\n",G->vexnum,G->arcnum);
    topgroup->vexnum = G->vexnum;
    topgroup->arcnum = G->arcnum;

    for(i = 1;i <= G->vexnum;i++){
        for(j = 1;j <= G->vexnum;j++){
            G->arcs[i][j] = INFINITY;
        }
    }
    
    for(k = 1; k <= G->arcnum;k++){
        printf("please enter vex1, vex2 and weight \n");
        scanf("%d,%d,%d",&vex1,&vex2,&weight);

        topgroup->topgroup[k].vex1 = vex1;
        topgroup->topgroup[k].vex2 = vex2;
        topgroup->topgroup[k].weight = weight;

        G->arcs[vex1][vex2] = weight;
        G->arcs[vex1][vex2] = weight;
    }

}



void creat_sort(top_group *topgroup){    /*这里我选用冒泡排序，其实可以选择更好的堆排序*/
    
    int flag,i,j,k;
    flag = 1;
    int temp_vex1,temp_vex2,temp_weight;
    group p;
    for(i = 1;i <= topgroup->vexnum-1 && flag ;i++){
        flag = 0;    
        for(j = 1;j <= topgroup->vexnum-1;j++){
            if(topgroup->topgroup[j].weight > topgroup->topgroup[j+1].weight){
                    p = topgroup->topgroup[j];
                    topgroup->topgroup[j] = topgroup->topgroup[j+1];
                    topgroup->topgroup[j+1] = p;
            }
        }
    }
 
}


void creat_set_top(AdjMatrix *G,set *S){
    int i,j,k;

    for(i = 1;i <= G->vexnum;i++){
        S->vexarry[i].vex1 = i;
        S->vexarry[i].vex2 = -1;
        S->vexarry[i].weight = -1;
        S->vexarry[i].next = NULL;
    }
}

int  charge(top_group *topgroup,set *S,int i){
    int t_vex1,t_vex2,t_weight;
    int j,k;
    arc *q,*t;

    t = (arc *)malloc(sizeof(struct arc));

    t_vex1 = topgroup->topgroup[i].vex1;
    t_vex2 = topgroup->topgroup[i].vex2;
    t_weight = topgroup->topgroup[i].weight;
    
    for(j = 1;j <=topgroup->vexnum;j++ ){
        if(S->vexarry[j].vex1 == t_vex1){
            arc *p;
            p = (arc *)malloc(sizeof(struct arc));
            if(S->vexarry[j].next == NULL){
                p->vex1 = t_vex2;
                S->vexarry[j].next = p;
            }else{
                arc *temp;
                temp = S->vexarry[j].next;
                do{
                    if(NULL == temp->next){
                        break;
                    }else{
                        temp = temp->next;
                        if(temp->vex1 == t_vex2){
                            return 0;
                        }
                    }
                }while(1);

            }
        }else{
            if(S->vexarry[j].vex1 == t_vex2){
                arc *p;
                p = (arc *)malloc(sizeof(struct arc));
                if(S->vexarry[j].next == NULL){
                    p->vex1 = t_vex1;
                    S->vexarry[j].next = p;
                }else{
                    arc *temp;
                    temp = S->vexarry[j].next;
                    do{
                        if(NULL == temp->next){
                            break;
                        }else{
                            temp = temp->next;
                            if(temp->vex2 == t_vex1){
                                return 0;
                            }
                        }
                    }while(1);
                }
            }
        }
    }
    
    return 1;
}


void kruskal(AdjMatrix *G,top_group *topgroup,set *S){
    
    int i,j,k;
    int  flag;
    for(i = 1;i <= G->arcnum;i++){
        flag = charge(topgroup,S,i);
        if(flag == 1){
            printf("%d %d\n",topgroup->topgroup[i].vex1,topgroup->topgroup[i].vex2);
        }

    }

}

int main(){
    
    AdjMatrix *G;
    G = (AdjMatrix *)malloc(sizeof(struct AdjMatrix));
    top_group *topgroup;
    topgroup = (top_group *)malloc(sizeof(struct AdjMatrix));
    set *S;
    S = (set *)malloc(sizeof(struct set));

    AdjMatrix_create(G,topgroup);
    creat_sort(topgroup);
    creat_set_top(G,S);
    kruskal(G,topgroup,S);




}
