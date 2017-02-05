/*************************************************************************
	> File Name: adt.c
	> Author: 
	> Mail: 
	> Created Time: 2017年01月22日 星期日 11时46分06秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define N  100

typedef struct node{
    
    int data;
    int deep;
    struct node * left;
    struct node *right;

}Node;

Node * root = NULL;
int node_num  =  0;
int buf[N]        ;

int insert_node(Node * root,int data);

Node * NewNode(int init){
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->data  = init;
    p->left = NULL;
    p->right = NULL;

    return p;

}



int buildtree(Node * r,int node_num){
    
    int i = 0;
    if(root == NULL){
        root = NewNode(buf[0]);
    }
    for(i = 1;i < node_num;i++){

        insert_node(root,buf[i]);

    }


}

int insert_node(Node * Root,int data){
    
    Node * p = Root;
    Node *obj;
    while(p != NULL){
        obj = p;
        if(p->data  == data){
            return 0;
        }
        p = (data < p->data ) ? p->left : p->right;
    }
    Node *temp = NewNode(data);
    if(obj->data < data){
        obj->right = temp;
    }else{
        obj->left  = temp;
    }
    
    return 0;

}


int search_tree(Node * root){
    
    if(root){
        search_tree(root->left);
        printf("%d ",root->data);
        search_tree(root->right);
    }


}

Node * findmin(Node * start){

    if(start != NULL){
        start = start->left;
    }

    return start;
}



Node * delete(Node * Root,int Data){
    Node * temp;
    if(Root == NULL){
        return NULL;
    }else{
        if(Data < Root->data){
            Root->left = delete(Root->left,Data);
        }else{
            if(Data > Root->data){
                Root->right = delete(Root->right,Data);
            }else{
                if(Root->left && Root->left){   
                    temp = findmin(Root->right);
                    Root->data  = temp->data;
                    Root->right = delete(Root->right,Root->data);
                }else{
                    temp = Root;
                    if(Root->left == NULL){
                        Root = Root->right;
                    }else if(Root->right == NULL){
                        Root = Root->left;
                    }
                    free(temp);
                }
            }
        }
    }
    return Root;
}


int main(int argc, char **argv){
    
    scanf("%d",&node_num);
    printf("%d\n",node_num);
    int i = 0;
    for(i = 0;i < node_num;i++){
        
        scanf("%d",&buf[i]);

    }

    buildtree(root,node_num);
    search_tree(root);

    return 0;
}


