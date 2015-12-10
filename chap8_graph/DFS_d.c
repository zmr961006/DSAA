/*************************************************************************
	> File Name: DFS_d.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月10日 星期四 08时10分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

