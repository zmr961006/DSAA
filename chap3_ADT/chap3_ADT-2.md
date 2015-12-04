#第三章   栈 与 队列

#前言

    上一篇说了栈，这篇来说说队列，依然是使用数组与链表这两种
    数据结构来具体实现。
    
#队列

队列（queue)  也是表，然而，使用队列时插入在一端进行而在另一端进行删除操作。

对与队列而言，不论是使用队列或者使用链表都是快速的O（1）时间完成操作。

####核心思想
     
     先进先出
     
#队列的数组实现

##几个需要注意的点
队列可以使用数组与链表实现

数组实现：
    
        其实数组实现就是我们常说的循环队列，循环队列的应用很多，比如作为缓冲区使用，内核就
        是使用队列原理实现的内核缓冲区。
        然而更重要的就是判断空队列，判断满队列的方法了，根据设置不同方法也不尽相同， 我们这
        里使用的是少用一块空间的方法，判断队列空或者满。当然我们这里也是不保证线程安全的，
        如果你需要保证线程安全，简单的就加一把锁，多处理器加自旋锁。也可以考虑无锁技术。
        
##数组实现队列的一些前提

```
#define   MAX   10

#define   SUCCESS  0
#define   FAIL     -1

/*这是一个循环队列，使用少用一个空间的办法解决判满判空的问题*/

typedef struct queue{
    int front;
    int rear ;
    int count;
    int * queue_array;      /*这里使用一个指针也是为了以后能动态开辟大小空间*/
                            /*在linux kernel 中也有int * queue_array[0] 这
                            种写法，都是为了动态扩大*/
}queue;


```

##创建队列

```
queue * queue_create(void){
    queue * Q;
    Q = (queue *)malloc(sizeof(struct queue));
    Q->queue_array = (int *)malloc(sizeof(int) * MAX);

    Q->front = Q->rear = MAX -1;
    Q->count = 0;
    return Q;
}

```

##入队操作
```
int queue_in(queue * Q,int num){
    
    if(!Q){
        return FAIL;
    }

    if((Q->rear+1) % MAX == Q->front){

        return FAIL;

    }else{

        Q->rear = (Q->rear + 1)%MAX;
        Q->queue_array[Q->rear] = num;
        Q->count++;

    }
    

    return SUCCESS;

}

```

##出队操作

```
int queue_out(queue * Q){
    if(!Q){
        return FAIL;
    }
    if(Q->front == Q->rear){
        return FAIL;
    }else{
        
        Q->front = (Q->front+1)%MAX;
        Q->count--;
        return Q->queue_array[Q->front];

    }
}

```

##判断队满
```
int EmptyisQueue(queue *Q){
    
    if(Q->front == Q->rear){

        return SUCCESS;

    }else{

        return FAIL;

    }
}


```


#队列的链表实现

##前提条件
```
typedef struct node{

    int data;
    struct node *next;

}_node;

typedef struct _node{
    _node *head;
    _node *tail ;
    int count   ;
}_ctl;

```

##入队操作
```
void que_inq(_ctl *ctl,_node *node){

    if(NULL == ctl || NULL == node){

        return ;

    }
    if(!ctl->count){
        ctl->head = node ;
    }else{
        ctl->tail->next = node ;
    }

    ctl->tail = node ;
    node->next = NULL;
    ctl->count++;

}

```

##出队操作

```
_node * que_deq(_ctl * ctl){
    
    _node *rst = NULL;

    if(NULL == ctl){
        return NULL;
    }

    rst = ctl->head;

    if(rst){
        ctl->head = rst->next;
        ctl->count--;
        rst->next = NULL;
    }

    return rst;


}

```

##删除一个队列
```
void que_del(_ctl *ctl){
    
    _node *pos = NULL;
    if(NULL == ctl){
        return ;
    }
    
    pos = ctl->head;

    while(pos != NULL){
        ctl->head = pos->next;
        free(pos);
        pos = ctl->head;
    }

}

```

##创建一个队列
```
void que_create(_ctl *ctl ,int len){
    
    _node *pnt = NULL ;
    int fact = 0 ;

    if(NULL == ctl || len < 1){
        return ;
    }

    while(fact < len){
        pnt = (_node *)malloc(sizeof(_node));
        pnt->data = fact + 1;
        que_inq(ctl,pnt);
        fact++;
    }

    
}

```

