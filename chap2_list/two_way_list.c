/*************************************************************************
	> File Name: two_way_list.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月03日 星期四 21时15分32秒
 ************************************************************************/

#include<stdio.h>

int list_del(Node *node){

    if(!node){
        return -1;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;

}


int list_add(Node *node,Node * newnode){
    if(!node || !newnode){
        return -1;
    }
#ifdef AddTail
    newnode->prev = node->prev   ;
    newnode->next = node         ;
    newnode->prev->next = newnode;
    newnode->next->prev = newnode;
#else
    newnode->next = node->next   ;
    newnode->prev = node         ;
    newnode->next->prev = newnode;
    newnode->prev->next = newnode;
#endif

    return 0;

}


