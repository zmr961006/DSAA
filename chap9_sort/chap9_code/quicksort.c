/*************************************************************************
	> File Name: quicksort.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月16日 星期三 17时17分07秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int __quicksort(RecordList L,int low,int high){

    L.r[0] = L.r[low];
    while(low < high){

        while(low < high && L.r[high] >= L.r[0])
            --high;
        L.r[low] = L.r[high];
        while(low < high && L.r[low] < L.r[0])
            ++low;
        L.r[high] = L.r[low];

    }
    L.r[low] = L.r[0];

    return low;

}


void quicksort(RecordList L,int low,int high){
    
    if(low < high){
        pos = quicksort(L,low,high);
        __quicksort(L,low,pos-1);
        __quicksort(L,pos+1,high);

    }

}


