/*************************************************************************
	> File Name: Hash_simple.c
	> Author: 
	> Mail: 
	> Created Time: 2015年12月15日 星期二 20时55分19秒
 ************************************************************************/

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

