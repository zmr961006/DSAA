#第八章  图论及其算法

##最短路径

##前言
    
    这是图论的最后一个部分了，吸取之前的教训，我总以为自己写的代码比书上的好，但是上次关键路径
    把我教育了，我写得确实没书上的好，也有自己对算法不是很熟练的关系，所以最短路径这里我打算
    把思路先搞清，然后先学习书上的代码，再看看自己有没有更好的想法，然后不要自以为是。先学会走
    ，才能学会跑。
    以上。
    
##Dijkstra 算法

最短路径一般分为两种情况：
    
    单源点最短路径问题
    
    每对顶点之间的最短路径问题
    
这个算法就是解决单源点最短路径的一个常用算法是Dijkstra ，说白一点就是求解一个点，到各个点
之间的最短路径的方法。

我尽量描述清楚这个算法的步骤吧。
存在一个集合S，存放源点逐步到达的顶点。

1.确定源点到它可以到达的顶点之间的距离。

2.选择一个最短距离，并将这个顶点入集合S。

3.将已经入过集合的顶点置为空，表示以后都不会选择它。

4.继续从1开始，直到所有顶点都被置空。


```
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

            if(!path[j][0] && dist[j] < mindist){   /*未进入S且当前路径小与 
            
            最小*/
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
                    while(path[k][t] != 0){   /*将当前路径记录下来，复制置前
                    的路径然后添加最新的结点*/
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

```

##Floyd 算法

我还是尽量描述清楚这个算法的步骤吧。

前提：建立矩阵F，用于记录路径长度。能到达的路径都直接给于权值，不能到达的则设置无穷值。

这就是我们的F0矩阵，显然只是初始化了而已。

1.让顶点经过第一个顶点V0，然后比较路径（Vi,Vj)与路径（Vi,V0,Vj)的路径长度较短的一个。

2.往复这个步骤，然后经过n 次后就把n个顶点都考虑在路径中了。

3.最终得到的这个F矩阵就保存了所有的路径之间的关系了，注意中间斜对角线始终是0


这个代码比较好理解，就是循环多。
```
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


```