/*************************************************************************
	> File Name: selectSort.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月16日 星期三 17时38分15秒
 ************************************************************************/

#include<stdio.h>



void SelectSort(RecordList L){

    int i,j,k;
    for(i = 1;i <= L.length-1;i++){
        k = i;
        for(j = i+1;j <= L.lenghth-1;j++){
            if(L.r[i] < L.r[k])
                k = j;
            if(k != i){
                t = L.r[i];
                L.r[i] = L.r[k];
                L.r[k] = t;
            }
        }
    }


}
