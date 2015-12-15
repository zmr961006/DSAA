#第七章   哈希

##散列（哈希）

    Hash，一般翻译做“散列”，也有直接音译为“哈希”的，就是把任意长度的输入（又叫做预映射， pre
    -image），通过散列算法，变换成固定长度的输出，该输出就是散列值。这种转换是一种压缩映射，
    也就是，散列值的空间通常远小于输入的空间，不同的输入可能会散列成相同的输出，所以不可能从散
    列值来唯一的确定输入值。简单的说就是一种将任意长度的消息压缩到某一固定长度的消息摘要的函数
    。
    
##基本概念

* 若结构中存在和关键字K相等的记录，则必定在f(K)的存储位置上。由此，不需比较便可直接取得所查记录。称这个对应关系f为散列函数(Hash function)，按这个事先建立的表为散列表。
* 
* 
* 对不同的关键字可能得到同一散列地址，即key1≠key2，而f(key1)=f(key2)，这种现象称碰撞。具有相同函数值的关键字对该散列函数来说称做同义词。综上所述，根据散列函数H(key)和处理冲突的方法将一组关键字映象到一个有限的连续的地址集（区间）上，并以关键字在地址集中的“象” 作为记录在表中的存储位置，这种表便称为散列表，这一映象过程称为散列造表或散列，所得的存储位置称散列地址。
* 若对于关键字集合中的任一个关键字，经散列函数映象到地址集合中任何一个地址的概率是相等的，则称此类散列函数为均匀散列函数(Uniform Hash function)，这就是使关键字经过散列函数得到一个“随机的地址”，从而减少冲突。


###一般使用的哈希函数

1.线性探测再散列
    
    每次线性的探测+1.

2.二次探测再散列
    
    每次线性的+-(n^2).
    
3.随机探测再散列

    使用伪随机函数.
    
    
###几种哈希表的ASL

线性探测法      1/2(1+1/(1-a))    
            
             1/2[1+1/(1-a)^2]
 
二次线性探测法   (1/a)ln(1-a)  

                1/(1-a)
        
链地址法        1+a/2

           a+e^(-a)     
    
###一个简单的实现
```
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HASHSIZE 11
#define DEL      -1


typedef struct {

    int key;
   
}Datatype;

typedef struct {
    
    Datatype data;
    int times;

}Hashtable[HASHSIZE];


```
    
    
```
int HashFunc(int key){
    
    return key % HASHSIZE;
}

int Collision(int di){
    
    return (di + 1) % HASHSIZE;
}


int HashSearch(Hashtable ht,Datatype x){
    int address;
    address = HashFunc(x.key);

    while(ht[address].data.key != 0 && ht[address].data.key != x.key)
        address = Collision(address);

    if(ht[address].data.key == x.key){
        return address;
    }else{
        return -1;
    }

}

int HashInsert(Hashtable ht,Datatype x){
    
    int address;
    address = HashFunc(x.key);
    if(address >= 0){
        return 0;
    }
    ht[-address].data = x;
    ht[-address].times = 1;

    return 1;

}


void Createht(Hashtable ht,Datatype L[],int n){
    int i;
    for(i = 0;i < HASHSIZE;i++){

        ht[i].data.key = 0;
        ht[i].times = 0      ;
    }
    for(i = 0;i < n;i++)
        HashInsert(ht,L[i]);
}

int HashDel(Hashtable ht,Datatype x){
    
    int address;
    address = HashFunc(x.key);
    if(address >= 0){
        ht[address].data.key = DEL;
        return 1;
    }
    
    return 0;
}

```