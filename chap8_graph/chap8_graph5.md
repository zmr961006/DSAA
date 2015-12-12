#第八章   图论及其算法（四）

#拓扑排序和关键路径

##拓扑排序

有向图的弧可以看成是顶点之间的一种制约关系的一种描述。我们将顶点表示活动，弧表示活动优先关系的有向无环图，称为顶点表示活动的网，简称AOV 网，图中不允许出现回路。

对于一个AOV 网一般满足以下的情况的时候我们称之为拓扑序列。
(1)网中的所有顶点都在序列中。
(2)若顶点Vi到Vj存在一条关键路径，则在线性序列中，Vi一定存在Vj之前

构造一个拓扑序列的操作称之为拓扑排序。
实际上，拓扑排序就是离散数学中由某个集合上的一个偏序集上的一个偏序得到该集合上的一个全序操作。

代码实现步骤：
1.建立邻接表
2.初始化入度数组
3.开始拓扑
4.在拓扑的过程中依次打印出入度为0的结点


```
这里依然只展示核心步骤的代码，完全可执行代码，已附在目录中
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

void Topsort(AdjList *G,int *indegree){   /*拓扑主函数*/
    
    int i,j,k;
    get_in_degree(G,indegree);    /*初始化存储度的数组*/
    for(i = 1;i <= G->vexnum;i++){
        k = get_zero(G,indegree);    /*获得度为0的项*/
        if(k != -1){
            printf("%d \n",k);
            set_sub(G,indegree,k);   /*获得度为0的项的时候它所有出度元素的入度--*/
        }
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




```



##关键路径



###一些概念
关键路径一般有如下的性质：
(1)只有在某项顶点所代表的事件发生后，从该顶点发出的所有有向边所代表的活动才能开始；

(2)只有在进入某一顶点的各个有向边所代表的活动均已完成，该顶点所代表的事件才能发生；




####源点
    
    网中只有一个入度为0的顶点称之为源点。
####汇点

    仅有一个出度为0的顶点称之为汇点。
    
####关键路径

    从汇点到源点中具有最长路径长度的路径称为关键路径。
    
