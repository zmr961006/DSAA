/*************************************************************************
	> File Name: array_list.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月05日 星期六 21时37分36秒
 ************************************************************************/

#include<stdio.h>



void reserve_int(int **T,int **M,int col,int row){
    int i,j;
    for(i = 1;i < col;i++)
        for(j = 1;j < row;j++)
            T[i][j] = M[i][j];


}


void reserve_int2(TS *A,TS *B){
    int i,j,k;
    B->rows = A->cols;
    B->cols = A->rows;
    if(B->nums > 0 ){
        j = 1;
        for(k = 1;k <= A->cols;k++)
            for(i = 1;i <= A->nums;i++)
                 if(A->data[i].col == k){
                    B->data[j].row = A->data[i].col;
                    B->data[j].col = A->data[i].row;
                    B->data[j].value = A->data[i].value;
                    j++;
                }
            if(j > A->nums)
		break;
    }
}


void reserve_int3(TS *A,TS *B){

    int i,j,min;
    B->rows = A->cols;
    B->cols = A->rows;
    B->nums = A->nums;

    i = 1;

    while(i <= A->nums){
        min = 1;
        for(j = 2 ; k <= A->nums;j++)
            if(A->data[j].col < A->data[min].col)
                min = j;
        B->data[i].row = A->data[min].col;
        B->data[i].col = A->data[min].row;
        N->data[i].value = A->data[min].value;
        i++;

        A->data[min].col = A->cols+1;
    }
}



