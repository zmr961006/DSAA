/*************************************************************************
	> File Name: binary_insertion_sort.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月15日 星期二 22时34分03秒
 ************************************************************************/

#include<stdio.h>

void BiInsertSort(Recordlist L){
    int i,j,k;
    int low,high;
    
    for(i = 2;i <= L.lenghth;i++){
        if(L.r[i] < L.r[i-1]){
            L.r[0] = L.r[i];
            low = 1;
            high = i-1;
            while(low <= high){
                mid = (low + high)/2;
                if(L.r[0] < L.r[mid]){
                    high = mid -1;
                }else{
                    low = mid + 1;
                }
                
            }

            for(j = i-1;j >= low;j--){
                L.r[j+1] = L.r[j];
                L.r[low] = L.r[0];
            }
        }
    }


}
