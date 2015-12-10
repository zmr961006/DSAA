#第八章  图论及其算法（二）

##图的遍历

###深度优先遍历

    深度优先遍历类似于树的先根遍历。就是从一个结点开始，每次按照往最深遍历，如果图是连通的，
    那么就能遍历完成，如果图不是连通的，就找到没有遍历的顶点开始继续遍历直到遍历整个图。
   
```
这里只写了主要函数的代码，其他完整代码在附录
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

int FirstAdjvex(AdjMatrix *G,int i){    /*这两个寻找顶点的函数中间还是使用了循环，在考虑进一步优化*/
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



非递归遍历：
void  DFS(Graph *G,int v){
    stack *S;
    S = INIT_stack();
    int vex[MAXVEX];

    push(S,v);
    while(!isEmpty(S)){
        v = pop(S);
        if(!vex[v]){
            visit(v);
            vex[v] = 1;
        }
        w = FirstAdjVertex(G,v);
        while(w != -1){
            if(!vex[w])
                push(S,w);
            w = NextAdjVertex(G,v,w);
        }
    }

}

```
   
   
   
###广度优先遍历

    图的广度优先遍历相似于树的按照层次遍历，所以可以借助队列完成遍历。
    每次访问到一个顶点都将它入队，当队头元素出队时，将其未被访问的邻接点入队，每个顶点只入队
    一次。
    
```
void BFS(AdjMatrix *G,int v){
    printf("%d\n",v);
    G->vex[v] = 1;
    queue * Q;
    int w;
    Q = queue_init();
    queue_inq(Q,v);
    while(!isEmpty(Q)){
        v = queue_deq(Q);
        w = FirstAdjvex(G,v);
        while(w != -1){
            if(!G->vex[w]){
                printf("%d\n",w);
                G->vex[w] = 1;
                queue_inq(Q,w);
            }
            w = NextAdjvex(G,v,w);   
        }
    }
}



void TraverG(AdjMatrix * G,int v){
    int i ;
    for(i = 1;i <= G->vexnum;i++){
        G->vex[i] = 0;
    }
    for(i = 1; i <= G->vexnum;i++){
        if(!G->vex[i]){
            BFS(G,i);
        }
    }
}


```
   