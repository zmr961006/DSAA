/*************************************************************************
	> File Name: mergesort.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月18日 星期五 09时23分29秒
 ************************************************************************/

#include<stdio.h>


void  mergesort(RecordList L,RecordList CopyL,int left,int right){
    int middle;
    if(left < right){
        middle = (left+right)/2;
        mergesort(L,CopyL,left,middle);
        mergesort(L,CopyL,middle+1,right);
        Merge(L,CopyL,left,right,middle);
    }
}

void Merge(RecordList L,RecordList CopyL ,int left,int right,int middle){
    int i,p1,p2;
    for(i = left;i <= right;i++){
        CopyL.r[i] = L.r[i];
    }
    p1 = left;
    p2 = middle+1;
    i = left;

    while(p1 <= middle && p2 <= right){
        if(CopyL.r[p1] <= CopyL.r[p2]){
            L.r[i] = CopyL.r[p1];
            p1++;
        }else{
            L.r[i] = CopyL.r[p2];
            p2++;
        }
        i++;

    }
    while(p1 <= middle){
        L.r[i] = CopyL.r[p1];
        i++;
        p1++;
    }
    while(p2 <= right){
        L.r[i] = CopyL.r[p2];
        i++;
        p2++;
    }
}
