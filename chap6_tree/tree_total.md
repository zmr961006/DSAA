#第六章 树

##前言

        经过两天的努力终于写到树了。前面的也总算基本说清了，到树这一章了，我打算不局限
        于课本，多了解一些东西也是好的。
        
        遂决定以下学习路线：
        
        1.树的基本概念
        
        2.二叉树
        
        3.AVL树
        
        4.B树
        
        5.红黑树
        
        6.树在文件系统中的使用
        
##树的基本概念

###为什么要使用树，或者说树有什么优势？

        对于大量的数据，链表的线性访问时间太慢，不宜使用。然而如果使用树就可以达到O(logN) 
        时间复杂度，至少保证了最坏时间复杂度的上界，绝大多数的操作的时间复杂度都可以稳定在O(logN).
        
###树的基本概念，背景知识。
        本来不想看学校的教材的，但是没办法，就考试而言，还是学校的教材比有参考性。

####树的定义

    树的定义一般采取递归定义的方法，由一个根结点，根结点没有前驱结点，但是回有多个后继结点。
    但是每一个后继结点又可以当作一个新的根结点。
    
####子树

    除过根结点的其他后继元素，都可以当作这棵树的子树，每棵子树的根结点有且只有一个直接的前驱。
    
####树的表示方法

    这个主要还是答选择，填空题，所以需要说下，相关的图就不画了。
    1.树形图表示法
    2.嵌套集合表示法
    3.广义表表示法
    4.凹入表示法
    
###树的基本术语

####结点
    
    包含一个数据元素以及若干指向其子树的分支。
    
####结点的度

    结点拥有子树的个数称为该结点的度。
    
####树的度

    树中所有结点的度的最大值。
    
####叶子结点

    度为0的结点称为叶子结点，也称之为终端结点。
    
####内部结点

    度不为0的结点称为内部结点，也称之为分支结点或非终端结点。
    
####孩子结点
    
    结点的子树的根称为该结点的孩子的结点。
    
####双亲结点

    结点是其子树的根称为该结点的孩子的结点。
    
####兄弟结点
    
    同一双亲的孩子结点之间互称兄弟结点
    
####堂兄弟

    双亲是兄弟的结点或堂兄弟的结点互称兄弟结点
   
####祖先结点

    结点的祖先结点是指从根到该结点的路经上的所有结点。
    
####结点的层次

    结点的层次从树根开始定义，根为第一层，根的孩子称为第二层，以此类推
    
####树的深度

    树中所有结点层次的最大值称为树的深度，也称树的高度。
    
####前辈

    层号比该结点层号小的结点都可以称之为该结点的前辈。
    
####后辈

    层号比该结点层号大的结点，都可称为该结点的后辈。
    
####森林

    多棵树就组成森林。（这个说的有点随意）
    
####有序树与无序树

    树中结点的各棵子树从左到右是特定次序的树称为有序树，否则称为无序树。
    
以上就是所有树的定义。

    
##二叉树

    定义： 二叉树是一棵树，其中每个结点都不能有多于两个的儿子。
    
##二叉树的性质
    
###性质1

    在一棵二叉树的第i层上至多有2^(i-1)个结点。
    证明：数学归纳法证明之
    
###性质2

    深度为k的二叉树至多有2^k -1 个结点。
    证明：普通计算即可证明
   
###性质3

    对于任意一棵二叉树T，若终端结点数为N0,度为2的结点数为N2，则N0 = N2 + 1 ；
    证明：略
    
###满二叉树

    深度为K且含有2^(k)-1 个结点的二叉树称为满二叉树。
    
###满二叉树的连续编号

    很简单顾名思义，我们从根开始依次从左到右标号就好了。
    
###完全二叉树

    深度为k,结点为n (n <= 2 ^ k -1)的二叉树，当且仅当其n个结点与满二叉树中1到表n 的结点
    位置一一对应时，称之为完全二叉树。
    就是最后一个叶子结点必须是左孩子，并且前边的所有叶子结点必须满员。
    
###性质4

    具有N个结点的完全二叉树深度为 log2N  向下取整 + 1.
    
###性质5

    对与含有n个结点的完全二叉树，如果按照对满二叉树结点进行连续编号的方式，对所有从1开
    始顺序编号，则对于任意序列号i的结点有：
    i ,双亲结点序号为i/2 向下取整。
    2i <= n ,则结点的左孩子序号为2i,否则无左孩子
    2i+ 1 <= n, 则结点的右孩子序号为2i + 1,否则无右孩子
    
以上性质完毕。

###二叉树的存储方式

    这里主要以递归建立为例，非递归建立很简单，可以使用队列，核心操作是出队，入队。也可
    以使用栈来辅助实现，核心操作是获得栈顶元素。
    
```
树的基本结点结构
node *binary_tree_create(){
        char  ch;
        node *S;
        ch = getchar();
        if(ch == '#'){
            return NULL;
        }
        S = (node *)malloc(sizeof(node));
        S->data = ch ;
        S->lchild = binary_tree_create();
        S->rchild = binary_tree_create();

        return S;
}

```

###二叉树的递归方式遍历

####先序遍历：
```
void pre_tree(node *s){
    
    if( s ){

        printf(" %c ",s->data);
        pre_tree(s->lchild);
        pre_tree(s->rchild);
    
    }
}

```

####中序遍历：
```
void med_tree(node *s){
    
    if( s ){

        med_tree(s->lchild);
        printf(" %c ",s->data);
        med_tree(s->rchild);

    }
}

```

####后序遍历：

```
void post_tree(node *s){
    if( s ){

        next_tree(s->lchild);
        next_tree(s->rchild);
        printf(" %c ",s->data);

    }
}

```

###二叉树的其他操作

####求二叉树的结点数：

```
方法一：
static int nodenum;    /*也可以写局部静态变量，把它写到函数内部*/
int get_nodesum_global(node *s){

    if(s){
        get_nodesum_global(s->lchild);
        get_nodesum_global(s->rchild);
        nodenum++;
    }

}

方法二：

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

方法三：
void get_nodesum_three(node *s ,int *n)
{
    if(s)
    {
       *n++;
       get_nodesum_three(s->lchild,n);
       get_nodesum_three(s->rchild,n);
    }
    else
    {
       return ;
    } 
 
} 
 


```

####求叶子结点的数目
     
     直接找左右孩子都为NULL的结点好了。
```
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

```
####求树的高度

```
方法一：

使用全局变量计数，注意这里从根开始，所以h = 1.
static int depth = 0;
int tree_depth_global(node *s,int h){

    if(s){
        if(depth < h)
            depth = h;
            
        tree_depth_global(s->lchild,h+1);
        tree_depth_global(s->rchild,h+1);

    }

}


方法二：
使用局部变量计数.

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


```

####打印叶子结点

使用递归也很方便
```
void show_leaf(node *s){
    
    if(s){
        if(s->lchild == NULL &&  s->rchild == NULL){
            printf(" %c ",s->data);
        }
        show_leaf(s->lchild);
        show_leaf(s->rchild);

    }
    

}

```

####递归方法创建二叉树，简单创建

```
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

```

####获得一个结点的双亲结点

```
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

```


####判断相似二叉树

```
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

```

####横向打印二叉树

```
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

```

####反转二叉树

```
node *invertTree(node *s){
    
    if(s == NULL){
        return NULL;
    }

    node *temp;
    temp = s->lchild;
    s->lchild = invertTree(s->rchild);
    s->rchild = invertTree(temp);
}

```

    