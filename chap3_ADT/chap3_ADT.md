#第三章  栈 与 队列

#前言
   
   栈与队列也是两个重要的数据结构，很多更加复杂的数据结构都是以他们为基础的，这里我们只小结用法与链表，数组的两种实现。
    
    
#栈

    栈（stack) 是限制插入和删除只能在一个位置的表，该位置是表的末端，叫做栈的（top)对栈的
    基本操作有push 和 pop .
    
    
   push : 相当于插入一个值。
   pop  : 相当于弹出一个值。
   
####核心思想：  先进后出

   
      
#栈的数组实现


####一些需要注意的点
@数组实现避免了使用大量的指针，也是一种较为流行的实现。

@使用数组最大的问题就是大小的问题，其实数组的大小反而到不算是一种问题，在很多典型且稳定的
应用中，在任意时刻栈元素的实际个数不会太大。声明一个足够大的数组且不至于浪费空间通常也不是一个太难的问题，但是如果做不到这一点还是使用链表吧，能节省不少空间。   
 
@一个影响栈的执行效率的问题根多的问题是错误检测。像我们实现链表的时候检测错误这个动作是频繁发生的。现在很多计算机已经将栈作为它的指令系统的一部份了，所以说就仅仅说栈的操作是花费不了什么时间的，我们也就没有什么理由忽略错误检测的代码，但是过于冗长的代码还是应当尽量避免，因为聪明的你总是有办法减化错误判断代码。


##栈的数组实现结构体

```
#define  MAX       10             /*栈的最大元素个数*/
#define  SUCCESS   0              /*成功返回 0*/
#define  FAIL      -1             /*失败返回 -1*/




typedef struct  stack_array{
    
    int stack_array[MAX];           /*我们的数组，栈的主体*/
    int TopOfStack      ;           /*指向栈顶*/
    int BaseOfStack     ;           /*指向栈顶底*/
    int Count           ;           /*统计栈中元素个数*/

}stack;


``` 

##栈的创建

```
stack * stack_array_creat(void){

    stack * S;

    S = (stack *)malloc(sizeof(struct stack_array));

    if(!S){

        return  NULL;
    }

    return S;

}

```
##栈的初始化

```
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

```
    
##入栈PUSH

```
int push(stack * S, int sum){
    if(!S){

        return FAIL;

    }
    S->stack_array[++S->TopOfStack] = sum;
    S->Count++;
    return SUCCESS;

}

```

##出栈POP

```
int pop(stack * S){
    if(!S || !S->Count){
        
        return FAIL;

    }
    S->Count--;

    return S->stack_array[S->TopOfStack--];


}

```

#栈的链表实现

###栈的链表实现的一些说明

```
#define   SUCCESS   0

#define   FAIL      -1

typedef struct  node{
    
    int data;
    struct node *next;

}_node;


typedef struct nodectl{
    
    _node * top;
    _node *base;
    int count  ;
}_ndctl;



栈的链表实现有很多种表现，这也只是其中的一种，不过这种写法有一个值得学习的地方就是这里使用了一个nodectl 控制结构，这种写法其实也是体现了一种面向对象的思想，值的考量一番。

```


##栈的初始化

```

void stack_init(_ndctl *ctl){
    
    memset(ctl,0x00,sizeof(_ndctl));

}


```
 
##入栈操作

```
void push(_ndctl * ctl,_node *node){
    
    if(NULL == ctl && NULL == node){
        return ;
    }
    if(NULL == ctl->top){
        ctl->top = node ;
        ctl->base = node ;
    }else{
        node->next = ctl->top ;
        ctl->top   = node     ;
    }
    ctl->count++;

}


```

##出栈操作

```
_node *pop(_ndctl *ctl){
    
    _node *p;
    if(NULL == ctl){
        return NULL;
    }

    p = ctl->top;
    
    if(ctl->count > 0){
        ctl->top = ctl->top->next;
        ctl->count--;
    }

    return p;

}

```

##删除一个栈
```
void stack_destory(_ndctl * ctl){

    _node * temp;
    if(NULL == ctl){
        
        return ;
    }

    while(0 < ctl->count){

        ptemp = ctl->top->next;
        free(ctl->top);
        ctl->top = ptemp;
        ctl->count--;

    }

}

```

 