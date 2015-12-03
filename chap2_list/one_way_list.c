/*************************************************************************
	> File Name: one_way_list.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月03日 星期四 19时46分36秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


#define  SUCCESS    0
#define  FAIL       -1

typedef struct Node{

    int num;

    struct Node *next;

}Node;



Node * list_create(void);
int list_delete(Node *head,Node * pos);



Node *list_create(void){
    
    Node *head,*head2,*head3,*head4;
    head = (Node *)malloc(sizeof(Node));
    head2 = (Node *)malloc(sizeof(Node));
    head3 = (Node *)malloc(sizeof(Node));
    head4 = (Node *)malloc(sizeof(Node));

    head->num = 0;
    head2->num = 1;
    head3->num = 2;
    head4->num = 3;

    head->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = NULL;

    return head;
}

int list_delete(Node *head,Node * pos){
    
    if(!head || !pos){
        return FAIL;
    }

    Node *temp = head->next;
    while(temp){
        if(temp->next->num == pos->num){
            temp->next = temp->next->next;
            return SUCCESS;
        }
        temp = temp->next;
    }

    return FAIL;

}

int list_add(Node *node,Node *pos){
    
    if(!node || !pos){
        return FAIL;
    }

    pos->next = node->next;
    node->next = pos;
    
    return SUCCESS;
}

Node * reserve_list(Node *head){
    if(!head){
        return NULL;
    }
    Node *ptemp = head ;
    Node *prev  = NULL ;
    Node *pnext = NULL ;
    while(ptemp){
        pnext = ptemp->next;
        if(!pnext){
            head = ptemp;
        }

        ptemp->next = prev ;
        prev = ptemp  ;
        ptemp = pnext ;
    }

    return head;
}


Node * mergeTwolist(Node *list1, Node *list2){

    if(!list1 || !list2){
        return NULL;
    }

    Node * result ;
    result = (Node *)malloc(sizeof(struct Node));
    Node * temp = result ;
    while(list1 && list2){
        if(list1->num < list2->num){

            result->next = list1;
            list1 = list1->next ;

        }else{
            
            result->next = list2;
            list2 = list2->next ;
        }

        result = result->next ;
    }

    if(list1)
        result->next = list1 ;
    if(list2)
        result->next = list2 ;

    return  temp;
}


void show_list(Node *head){
    while(head){
        printf(" %d ",head->num);
        head = head->next;
    }
    printf("\n");
}



int main(){
    Node *head;
    head = list_create();
    head = reserve_list(head);
    show_list(head);

}

