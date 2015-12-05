/*************************************************************************
	> File Name: next_.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月05日 星期六 17时00分32秒
 ************************************************************************/

#include<stdio.h>

void get_next(int *next,char *p){
    int i ,n ,k;

    n = strlen(p)
    next[1] = next[0] = 0;
    k = 0;
    for(i = 2;i <= n;i++){
        for(; k != 0 && p[k] != p[i-1];k = next[k]){
            if(p[k] == p[i-1])
                k++;

        }
        next[i] = k;
    }
}
