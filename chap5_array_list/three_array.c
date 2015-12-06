/*************************************************************************
	> File Name: three_array.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月06日 星期日 14时11分33秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define   MAX   1000

typedef struct triple{
    
    int row,col;
    int value  ;

}triple;


typedef struct TS{

    triple data[MAX + 1];
    int rows,cols,nums;

}TS;

void fast(TS *A,TS *B){
    int num[MAX];
    int position[MAX];

    B->rows = A->cols;
    B->cols = A->rows;
    B->nums = A->nums;

    int col,row;
    int p,q    ;
    if(B->nums){
        for(col = 1;col < A->cols;col++)
            num[col] = 0;
        for(col = 1;col <=A->nums;col++){
            num[A->data[col].col]++;
        }

        /*int i;                  //test num,非0元素个数
        for(i = 1;i <= 5;i++){
            printf("%d ",num[i]);
        }

        printf("\n");
        */


        position[1] = 1;
        for(col = 2;col <= A->nums;col++){
            position[col]= position[col-1] + num[col-1];
            
        }
        
        /*int j;               //test 每一行第一非零元素转置后的行数
        for(j = 1; j <= A->nums;j++){
            printf("%d ",position[j]);
        }
        */
        printf("\n");


        for(p = 1;p <= A->nums;p++){
            col = A->data[p].col;
            q = position[col];
            B->data[q].row = A->data[p].col;
            B->data[q].col = A->data[p].row;
            B->data[q].value = A->data[p].value;
            position[col]++;
            //printf("%d  %d  %d\n",B->data[q].row,B->data[q].col,B->data[q].value);
        }

    }
}

int main(){
    TS *A;
    TS *B;
    A = (TS *)malloc(sizeof(struct TS));
    B = (TS *)malloc(sizeof(struct TS));
    A->data[1].row = 1;
    A->data[1].col = 2;
    A->data[1].value = 14;


    A->data[2].row = 1;
    A->data[2].col = 5;
    A->data[2].value = -5;


    A->data[3].row = 2;
    A->data[3].col = 2;
    A->data[3].value = -7;

    A->data[4].row = 3;
    A->data[4].col = 1;
    A->data[4].value = 36;

    A->data[5].row = 3;
    A->data[5].col = 4;
    A->data[5].value = 28;

    A->rows = 3;
    A->cols = 5;
    A->nums = 5;
 
    int i,j ;
    for(i = 1;i <= A->nums;i++){
        
        printf("%d  %d   %d \n",A->data[i].row,A->data[i].col,A->data[i].value);
        
    }

    fast(A,B);

    printf("\n\n");


    for(j = 1;j <=5;j++){
        
        printf("%d  %d   %d \n",B->data[j].row,B->data[j].col,B->data[j].value);

    }

}

