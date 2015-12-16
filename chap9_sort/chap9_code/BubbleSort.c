/*************************************************************************
	> File Name: BubbleSort.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月16日 星期三 16时58分17秒
 ************************************************************************/

#include<stdio.h>


void BubbleSort(RecordList L){

    int i,j,k;
    int t;
    for(i = 1;i <= L.length-1;j++){
        for(j = 1;j <= L.length -i ;j++){
            if(L.r[j] > L.r[j+1]){
                t = L.r[j];
                L.r[j] = L.r[j+1];
                L.r[j+1] = t;
            }
        }
    }
}


