/*************************************************************************
	> File Name: find_list.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月14日 星期一 21时10分54秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 1000

typedef  int KeyType ;

typedef struct record{

    KeyType key;

}RecordType;

typedef struct SeqRlist{
    RecordType r[MAXSIZE + 1];
    int length;
}SeqRlist;

int Seqsearch(SeqRlist L,KeyType K){
    L.r[0].key = K;
    i = L.length;
    while(L.r[i].key != K){
        i--;
    }
    returni;

}
