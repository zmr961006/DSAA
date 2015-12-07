/*************************************************************************
	> File Name: binary_tree.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月06日 星期日 20时27分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{

    char data;
    struct node *lchild;
    struct node *rchild;

}node,*tree;


node *binary_tree_create(void);
void pre_tree(node *s);
void med_tree(node *s);
void post_tree(node *s);
int  get_nodesum_global(node *s);
int  get_nodesum_local(node *s);
void show_leaf(node *s);
int get_leaf_sum(node *s);
int tree_depth_global(node *tree,int h);
int tree_depth_local(node * s);
node * tree_get_parent(node *s,node *obj);
int like(node *tree1,node *tree2);
int tree_tree_show(node *s,int h);
node *invertTree(node *s);

node *invertTree(node *s){
    
    if(s == NULL){
        return NULL;
    }

    node *temp;
    temp = s->lchild;
    s->lchild = invertTree(s->rchild);
    s->rchild = invertTree(temp);
}


int tree_tree_show(node *s,int h){
    
    if(s == NULL){
        return 0;
    }
    int i;
    tree_tree_show(s->rchild,h+1);
    for(i = 0;i < h;i++)
        printf(" ");
    printf("%c\n",s->data);
    tree_tree_show(s->lchild,h+1);

}



int like(node *tree1,node *tree2){
    int like1,like2;

    if(tree1 == NULL && tree2 == NULL){
            return 1;
    }else if(tree1 == NULL || tree2 == NULL){
            return 2;
    }else{
            like1 = like(tree1->lchild,tree2->lchild);
            like2 = like(tree1->rchild,tree2->rchild);

        return(like1 && like2);

    }

}


node * tree_get_parent(node *s,node *obj){
    
    node *p;
    if(s == NULL){
        return NULL;
    }

    if(s->lchild == obj || s->rchild == obj)
        return s;

    p = tree_get_parent(s->lchild,obj);
    if(p){
        return p;
    }
    p = tree_get_parent(s->rchild,obj);
    if(p){
        return p;
    }
    

}




static int nodenum;
int get_nodesum_global(node *s){

    if(s){
        get_nodesum_global(s->lchild);
        get_nodesum_global(s->rchild);
        nodenum++;
    }

}

int get_leaf_sum(node *s){
    
    int lsum,rsum;
    if(s == NULL){

        return 0;
    }

    if((s->lchild == NULL) && (s->rchild == NULL)){

        return 1;
    }

    lsum = get_leaf_sum(s->lchild);
    rsum = get_leaf_sum(s->rchild);

    return (lsum + rsum);


}

static int depth = 0;
int tree_depth_global(node *s,int h){

    if(s){
        if(depth < h)
            depth = h;
        tree_depth_global(s->lchild,h+1);
        tree_depth_global(s->rchild,h+1);

    }

}

int tree_depth_local(node * s){

    int numl,numr,depth;
    if(s){

        numl = tree_depth_local(s->lchild);
        numr = tree_depth_local(s->rchild);

        depth = (numl > numr ? numl:numr) + 1;
        
        return depth;

    }else{

        return 0;

    }

}



void show_leaf(node *s){
    
    if(s){
        if(s->lchild == NULL &&  s->rchild == NULL){
            printf(" %c ",s->data);
        }
        show_leaf(s->lchild);
        show_leaf(s->rchild);

    }
    

}


int get_nodesum_local(node *s){
    int rnum  ;
    int lnum;
    int sum;
    if(s){
        
        lnum = get_nodesum_local(s->lchild);
        lnum++;
        rnum = get_nodesum_local(s->rchild);
        rnum++;
        sum = lnum + rnum;
        return sum;
        
    }else{
        
        return 0;
    }
      
}


node *binary_tree_create(){
        char  ch;
        node *S;
        ch = getchar();
        if(ch == '#'){
            return NULL;
        }
        S = (node *)malloc(sizeof(struct node));
        S->data = ch ;
        S->lchild = binary_tree_create();
        S->rchild = binary_tree_create();

        return S;
}



void pre_tree(node *s){
    
    if( s ){

        printf(" %c ",s->data);
        pre_tree(s->lchild);
        pre_tree(s->rchild);
    
    }
}

void med_tree(node *s){
    
    if( s ){

        med_tree(s->lchild);
        printf(" %c ",s->data);
        med_tree(s->rchild);

    }
}


void post_tree(node *s){
    if( s ){

        post_tree(s->lchild);
        post_tree(s->rchild);
        printf(" %c ",s->data);

    }
}


int main(){
    node *root;
    int sum = 0;
    int a = 0;
    root = binary_tree_create();
    pre_tree(root);
    printf("\n");
    /*med_tree(root);
    printf("\n");
    post_tree(root);
    printf("\n");
    get_nodesum_global(root);
    printf("nodesum = %d\n",nodenum);
    a = get_nodesum_local(root);
    printf("localsum = %d\n",a);
    
    show_leaf(root);
    printf("\n");
    int sum_leaf;
    sum_leaf = get_leaf_sum(root);
    printf("sum = %d\n",sum_leaf);
    
    tree_depth_global(root,1);
    printf("depth = %d\n",depth);
    
    int temp = tree_depth_local(root);
    printf(" %d \n",temp);
    */
    a = get_nodesum_global(root);
    printf("a = %d\n",a);
}




