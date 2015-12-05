/*************************************************************************
	> File Name: my_strcpy.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月05日 星期六 15时02分36秒
 ************************************************************************/

#include<stdio.h>
#include<stddef.h>

char * my_strcpy(char *dest,const char * src){

    char c ;
    char *S = (char *)src;
    const ptrdiff_t off = dest -S -1;
    //printf("diff %d\n",off);
    do{
        c = *S++;
        S[off] = c;
        //printf(" %d ",off);
    }while(c != '\0');

    return dest;
}

int main(){
    char dest[10];
    int a[100];
    char src[10] = "hello zmr";

    my_strcpy(dest,src);
    
    printf("%s\n",dest);
}
