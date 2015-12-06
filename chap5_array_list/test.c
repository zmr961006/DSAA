/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月06日 星期日 15时35分01秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>



void fun(int *A){
   
    A[1] = 1;
    A[2] = 2;
    A[3] = 4;

}

int main(){

    int *A;
    A = (int *)malloc(sizeof(int) * 5);
    int i;
    fun(A);
    for(i = 1; i <= 5;i++){
        printf("%d\n",A[i]);
    }



}
