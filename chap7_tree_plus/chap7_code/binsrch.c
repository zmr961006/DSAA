/*************************************************************************
	> File Name: binsrch.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月14日 星期一 21时52分04秒
 ************************************************************************/

#include<stdio.h>


int binsrch(seqlist L,keytype K){

    int low = 1;
    int high = L.length;
    int mid;
    while(low <= high){
        mid = (low + high)/2;
        if(K == L.r[mid].key){
            return mid;
        }else if(K < L.r[mid].key){
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }

    return 0;

}
