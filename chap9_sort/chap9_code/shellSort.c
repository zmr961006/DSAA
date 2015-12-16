/*************************************************************************
	> File Name: shellSort.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月16日 星期三 16时42分21秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void shellSort(RecordList L,int dk){
    int i,j;
    for(i = dk=1;i <= L.length;i++){
        if(L.r[i] < L.r[i-dk]){
            L.r[0] = L.r[i];
            for(j = i-dk;j >0 && (L.r[0] < L.r[j]);j -= dk){
                L.r[r+dk] = L.r[0];
            }
        }
    }
}

void shellSort_S(RecordList L,int dlta[]){
    int k;
    for(k = 0;k <L.length;k++)
        shellSort(L,dlta[k]);
}
