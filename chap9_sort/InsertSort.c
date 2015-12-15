/*************************************************************************
	> File Name: InsertSort.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月15日 星期二 22时15分57秒
 ************************************************************************/

#include<stdio.h>

#define MAXSIZE 1000

typedef struct list{

    int r[MAXSIZE+1];
    int length;

}list_array;


void InsertSort(list_array L){
    int i,j;
    for(i = 2;i <= L.length;i++){
        if(L.r[i]< L.r[i-1]){
            L.r[0] = L.r[i];
            for(j = i-1;L.r[0]<L.r[j];j--)
                L.r[j+1] = L.r[j];
            L.r[j+1] = L.r[0];
        }
    }
}



