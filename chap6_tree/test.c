/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月07日 星期一 19时55分41秒
 ************************************************************************/

#include<stdio.h>



int fun(int i){

    if(i == 1){
        return i;
    }
    i = i*fun(i-1);
    
}


int main(){

    int i = 5;
    int sum;
    sum = fun(i);
    printf("%d\n",sum);

}
