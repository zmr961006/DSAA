#第八章 图论及其算法（三）

##最小生成树

###prim 算法

    普里姆算法（Prim算法），图论中的一种算法，可在加权连通图里搜索最小生成树。意即由此算法
    搜索到的边子集所构成的树中，不但包括了连通图里的所有顶点，且其所有边的权值之和亦为最小。
    该算法于1930年由捷克数学家沃伊捷赫·亚尔尼克发现；并在1957年由美国计算机科学家罗伯特·普里姆
     独立发现；1959年，艾兹格·迪科斯彻再次发现了该算法。因此，在某些场合，普里姆算法又被称
     为DJP算法、亚尔尼克算法或普里姆－亚尔尼克算法。    

(1).输入：一个加权连通图，其中顶点集合为V，边集合为E；

(2).初始化：Vnew = {x}，其中x为集合V中的任一节点（起始点），Enew = {},为空；

(3).重复下列操作，直到Vnew = V：

a.在集合E中选取权值最小的边<u, v>，其中u为集合Vnew中的元素，而v不在Vnew集合当中，并
且v∈V（如果存在有多条满足前述条件即具有相同权值的边，则可任意选取其中之一）；

b.将v加入集合Vnew中，将<u, v>边加入集合Enew中；
4).输出：使用集合Vnew和Enew来描述所得到的最小生成树。

```
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

```

PS：时间复杂度为O(n^2),适合稠密图。

###Kruskal 算法


```
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

```
    

###拓扑排序


