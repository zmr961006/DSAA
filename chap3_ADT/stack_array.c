/*************************************************************************
	> File Name: stack_array.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月04日 星期五 10时23分52秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define  MAX       10             /*栈的最大元素个数*/
#define  SUCCESS   0              /*成功返回 0*/
#define  FAIL      -1             /*失败返回 -1*/




typedef struct  stack_array{
    
    int stack_array[MAX];           /*我们的数组，栈的主体*/
    int TopOfStack      ;           /*指向栈顶*/
    int BaseOfStack     ;           /*指向栈顶底*/
    int Count           ;           /*统计栈中元素个数*/

}stack;


stack * stack_array_creat(void){

    stack * S;

    S = (stack *)malloc(sizeof(struct stack_array));

    if(!S){

        return  NULL;
    }

    return S;

}




void stack_array_init(stack *S){
  
    if(!S){

        return  ;

    }

    int i = 0; 
 
    for(i = 0;i < MAX ;i ++){

        S->stack_array[i] = 0;

    }

    S->TopOfStack  = -1 ;
    S->BaseOfStack =  0 ;
    S->Count       =  0 ;

}

int push(stack * S, int sum){
    if(!S){

        return FAIL;

    }
    S->stack_array[++S->TopOfStack] = sum;
    S->Count++;
    return SUCCESS;

}


int pop(stack * S){
    if(!S || !S->Count){
        
        return FAIL;

    }
    S->Count--;

    return S->stack_array[S->TopOfStack--];


}

int main(){
    
    stack * S;
    S = stack_array_creat();
    stack_array_init(S);
    int i = 0;
    for(i = 0;i < 9;i++){
        push(S,i);
        printf("%d\n",S->stack_array[i]);
    }
    
    printf("****%d\n",S->TopOfStack);
    for(i = 0;i < 9;i++){
        int test = 0 ;
        test = pop(S);
        printf(" %d ",test);
    }

}
