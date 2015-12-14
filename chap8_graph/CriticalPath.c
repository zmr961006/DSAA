/*************************************************************************
	> File Name: CriticalPath.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月12日 星期六 16时59分54秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>


#define  MAXVEX     20
#define  SUCCESS    1
#define  TURE       1
#define  FAIL       -1

#define MAX(x,y)       (((x)>(y))?(x):(y))
#define MAIN(x,y)      (((x)<(y))?(x):(y))


typedef struct ArcNode{         /* node type */
    
    int adjvex ;
    int weight ;
    struct ArcNode *next;

}ArcNode;

typedef struct active{          /*活动结构体*/
    int vex1;
    int vex2;
    int weight;
}active;

typedef struct top{
    int adjvex;
    int weight;
}EE;

typedef struct tpp{
    int adjvex;
    int weight;
}VE;

typedef struct VertexNode{     /*边表结构*/
    
    char vexdata ;
    ArcNode *head;
    int count;

}VertexNode;


typedef struct AdjList{      /*邻接表结构体*/
    
    VertexNode vertex[MAXVEX];
    int vexnum;
    int arcnum;


}AdjList;


static active act[MAXVEX];    /*事件最早*/
static active vct[MAXVEX];    /*事件最晚*/

void add_node(AdjList *G,int vex1,int vex2,int weight){

    ArcNode *p,*q;
    p = (ArcNode *)malloc(sizeof(struct ArcNode));
    p->adjvex = vex2  ;
    p->weight = weight;
    q = G->vertex[vex1].head;
    do{
        if(NULL == q){
            G->vertex[vex1].head  = p;
            G->vertex[vex1].count++;
            break;
        }else if(NULL == q->next){
            q->next = p;
            p->next = NULL;
            G->vertex[vex1].count++;     /*插入计数递增*/
            break;
        }else{
            q = q->next;
        }
    }while(1);
    
    return ;

}

void AdjList_create(AdjList *G,AdjList *N){     /*建立正逆两个邻接表*/
    
    int i,j,k;
    int vex1,vex2,weight;
    if(!G){
        printf("G need cast a spece\n");
        return ;
    }
    
    printf("please enter the vexnum and arcnum\n");

    scanf("%d,%d",&G->vexnum,&G->arcnum);
    N->vexnum = G->vexnum;
    N->arcnum = G->arcnum;
    for(i = 1;i <= G->vexnum;i++){

        G->vertex[i].head  = NULL;

    }


    for(i = 1;i <= G->arcnum;i++){
        printf("please enter the vex1 and vex2 and weight\n");
        scanf("%d,%d,%d",&vex1,&vex2,&weight);
        act[i].vex1 = vex1;
        act[i].vex2 = vex2;
        act[i].weight = weight;
        vct[i].vex1 = vex1;
        vct[i].vex2 = vex2;
        vct[i].weight = weight;
        

        add_node(G,vex1,vex2,weight);
        add_node(N,vex2,vex1,weight);
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
            printf("%d :",i);
            while(temp != NULL){
                printf("%d-%d ",temp->adjvex,temp->weight);
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

//void  set_EE(AdjList *N,int k,EE *EE,int i);  /*求第一个数组*/

void Topsort(AdjList *G,int *indegree,EE *EE,VE *VE){
    
    int i,j,k;
    get_in_degree(G,indegree);
    for(i = 1;i <= G->vexnum;i++){
        k = get_zero(G,indegree);
        if(k != -1){
            EE[i].adjvex = k;
            VE[i].adjvex = k;
            //printf("*******\n");
            //set_EE(G,k,EE,i);
            set_sub(G,indegree,k);
        }
    }
    

}


void  set_EE(AdjList *N,EE *EE){  /*求第一个数组*/
    int i,j,maxweight,k;
    ArcNode *temp;
    EE[1].weight = 0;
    for(i = 2;i <= N->vexnum;i++){
        j = EE[i].adjvex;
        k = N->vertex[j].count;
        temp = N->vertex[j].head;
        maxweight = EE[i-1].weight ; //N->vertex[EE[i-1].adjvex];
        printf("EE:%d maxweight:%d\n",EE[i-1].weight,temp->weight);
        printf("j = %d k = %d temp->adj = %d temp->wei:%d\n",j,k,temp->adjvex,temp->weight);
        do{
            if(maxweight < temp->weight){
                if(temp->adjvex == EE[i-1].adjvex){
                    maxweight = EE[i-1].weight + temp->weight;
                }else{
                    maxweight = temp->weight;
                }
            }
            k--;
            temp = temp->next;
        }while(k>0);
        EE[i].weight = maxweight;
    }
}

void set_VE(AdjList * G,VE *VE,EE *EE){
    int i,j,minweight,k;
    ArcNode *temp;
    VE[G->vexnum].weight = EE[G->vexnum].weight ;
    for(i = G->vexnum-1;i >= 1;i--){
        j=VE[i].adjvex;
        k = G->vertex[j].count;
        temp = G->vertex[j].head;
        minweight = 32767;
        do{
            if(minweight > temp->weight)
                minweight = VE[temp->adjvex].weight - temp->weight;
            k--;
            temp = temp->next;
            
        }while(k>0);
        VE[i].weight = minweight;
    }
}

void get_result(AdjList *G,AdjList *Nactive *act,active *vct,EE *EE,VE *VE){    /*比较每个活动的最早发生时间和最晚发生时间，找出相等的即为所求*/
    int i,j,k;
    int result;
    for(i = 1;G->vexnum;i++){
        if(result = min(EE(x),EE(y)) == min(VE(x),VE(y))){
            printf("the CPATH = %d",result);
        }
    }
}


int main(){
    AdjList *G,*N;
    G = (AdjList *)malloc(sizeof(struct AdjList));
    N = (AdjList *)malloc(sizeof(struct AdjList));
    int indegree[MAXVEX];
    AdjList_create(G,N);
    EE EE[MAXVEX];   /*每个事件的最早发生时间*/
    VE VE[MAXVEX];   /*每个事件的最迟发生时间*/
    
    Topsort(G,indegree,EE,VE);
    set_EE(N,EE);
    set_VE(G,VE,EE);
    
    get_result();

    

    int i;
    for(i = 1;i <= G->vexnum;i++){
        printf("%d :%d\n",VE[i].adjvex,VE[i].weight);
    }

}

