#第五章   数组 与 广义表 与 散列表

#前言
  
  这章主要说说多维数组，广义表，和散列表吧。学校并没有提及到散列表，但是散列表这个东西超重要的，拿出来说说好了，知道它是什么，怎么用，在哪里用就好了。
  

##多维数组和压缩矩阵

###数组

  其实数组这个东西我们接触的挺早了，C语言就有啊，数组到是也可以看成是一个基本的数据结构吧，接触数据结构也一段时间了，唯一感觉就是看起来越简单的数据结构，往往越灵活，使用越广泛，较为复杂的数据结构它使用的地方却很受限制，但是在特定的方面却表现优异。
  
  先说考点吧，多维数组这里就是主要以选择填空，完成题为主，大多都是计算地址的题。在我个人看来这部分的东西只要“记住”公式基本考试就没有问题了。
  
  
以下数组的下标都从1开始！！！  
####一维数组

LOC(A[i])  = LOC(A[1]) + (i-1)*L

####二维数组

#####行序主序存储


LOC(A[i][j]) = LOC(A[i][j]) + (n * (i-1) + (j-1))*L

#####列序主序存储

LOC(A[i][j]) = LOC(A[i][j]) + (m * (j-1) + (i-1))*L

#####N维数组

很少考，用的都很少，有兴趣的可以自己补充，本文档可以自由转载与修改。

###压缩矩阵

    
        压缩矩阵包括三角矩阵，对角矩阵，稀疏矩阵的处理等，一个一个说吧。
        
####三角，对角矩阵
   主要还是以算地址位主，真心不难，有兴趣的自己推导吧，这里直接给出公式：
   
   行序为主：
   
       上三角矩阵：LOC(A[i][j]) = LOC(A[1][1]) + (i-1)(2n-i+2)/2+j-i
       
       下三角矩阵：LOC(A[i][j]) = LOC(A[1][1]) + i(i-1)/2+j-1
       
       对角矩阵：LOC(A[i][j]) = LOC(A[1][1]) + 2(i-j)+j-1
       
####稀疏矩阵

   稀疏矩阵按照字面上的理解就是包含很少的元素的矩阵，关于这个少到什么程度还是由一个简单的计算方法。
   假设在M*N 个元素的矩阵中，其中有T个不为0的元素，n = (t)/(m*n)  当n <= 0.05我们就把他称之为稀疏矩阵了。
   
   对于稀疏矩阵我们一般使用三原组的方式存储，只使用行，列，元素。三个要素来存储一个矩阵的信息，毕竟稀疏矩阵本来元素就很少。

####三原组快速逆置矩阵

使用三原组其实就是为了快速对稀疏矩阵进行操作，这就是它需要做的事，接下来我们一步一步的探索三原组是如何为我们节省时间的。分析过程是伪代码，后边会有可运行的代码。

####step one
    
    最普通的逆置方法：
```
  void reserve_int(int **T,int **M,int col,int row){
    int i,j;
    for(i = 1;i < col;i++)
        for(j = 1;j < row;j++)
            T[i][j] = M[i][j];


}  
```

这是通用的矩阵逆置，时间复杂度是O(M * N)  这种算法几乎把所有的元素都过了一遍，很多时候我们并不需要.但是在处理很密很密的那种矩阵的时候，这种做法还是很有效的。

####step two  

我们需要另想办法，所以我们选择安列序递增进行转置：扫描三元组，并按照列序优先的原则，每一次都找列序最小的，如果找到就按照顺序存入三元组。

```
void reserve_int2(TS *A,TS *B){
    int i,j,k;
    B->rows = A->cols;
    B->cols = A->rows;
    if(B->nums > 0 ){
        j = 1;
        for(k = 1;k <= A->cols;k++)
            for(i = 1;i <= A->nums;i++)
                 if(A->data[i].col == k){
                    B->data[j].row = A->data[i].col;
                    B->data[j].col = A->data[i].row;
                    B->data[j].value = A->data[i].value;
                    j++;
                }
    }
}

```
代码并不重要，先要理解思想，这个复杂度就是O(row * num)了，毕竟只扫描了三元组，所以说我们的改进是有效的，时间复杂度成功下降了。

####step  three 

但是对于这样的稀疏矩阵由该怎么办？

0 1 3 0 0 0 0 0 0 

0 4 0 0 0 0 0 0 0 

1 2 0 0 0 0 0 0 0 

我们可以发现我们的稀疏矩阵元素全都在前3列，所以如果还用上边的方法我们会多扫描后边全是0的列，所以需要再次改进，使用非零元素的个数来控制循环。当扫描完前边的三列后直接让循环结束。

```
void reserve_int2(TS *A,TS *B){
    int i,j,k;
    B->rows = A->cols;
    B->cols = A->rows;
    if(B->nums > 0 ){
        j = 1;
        for(k = 1;k <= A->cols;k++)
            for(i = 1;i <= A->nums;i++)
                 if(A->data[i].col == k){
                    B->data[j].row = A->data[i].col;
                    B->data[j].col = A->data[i].row;
                    B->data[j].value = A->data[i].value;
                    j++;
                }
            if(j > A->nums)
		break;
    }
}

```


####step four

我们又改进了一步，但是很明显，又有问题出现了，如果是这样的矩阵：

1 0 0 0 0 0 2 0 0 0 0 

0 0 0 1 0 0 0 0 0 0 0  

0 0 0 0 0 0 0 0 0 1 0


如果说像这样的矩阵我们又该如何是好？
我们可以在每次外循环就是每次从下一列扫描的时候直接找当前的有非零元素存在的最小列，这样就能解决问题了。

```
void reserve_int3(TS *A,TS *B){

    int i,j,min;
    B->rows = A->cols;
    B->cols = A->rows;
    B->nums = A->nums;

    i = 1;

    while(i <= A->nums){
        min = 1;
        for(j = 2 ; k <= A->nums;j++)
            if(A->data[j].col < A->data[min].col)
                min = j;
        B->data[i].row = A->data[min].col;
        B->data[i].col = A->data[min].row;
        N->data[i].value = A->data[min].value;
        i++;

        A->data[min].col = A->cols+1;
    }
}

```

接下来就是我们的一次定位快速转置了，明天说。

duang !!! 第二天了，今天就是昨天的明天，我们来学习如何如一次定位快速转置，首先我们说说为什么需要一次定位快速转置，之前的所有转置方法都需要，转置动作完成后重新排序以求得到的结果是列序递增的，并且使用了双重循环。


####一次定位快速转置

这个算法只需要对被扫描的三元组表只扫描一次，使得所有的元素在被扫描一次后就能被放到自己应有的位置。

但是实现这个算法，我们必须要知道转置后这个元素应当在三元组表的什么位置，我们需要知道这一列的第一个非零元素的位置，以单拿到了每一列第一个非零元素的位置，我们就能一次把这个元素放到三元组表的对应位置，后边的元素也就能放到对应的位置了。

于是我们增加两个向量来记录，每一列的非零元素个数，以及每一列第一个非零元在转置后的恰当位置，由此得出公式

@position[1] = 1;
@position[col] = position[col] + num[col-1]    上一个非零元的位置+非零元个数


```
#define   MAX   1000

typedef struct triple{
    
    int row,col;
    int value  ;

}triple;


typedef struct TS{

    triple data[MAX + 1];
    int rows,cols,nums;

}TS;

void fast(TS *A,TS *B){
    int num[MAX];
    int position[MAX];

    B->rows = A->cols;
    B->cols = A->rows;
    B->nums = A->nums;

    int col,row;
    int p,q    ;
    if(B->nums){
        for(col = 1;col < A->cols;col++)
            num[col] = 0;
        for(col = 1;col <=A->nums;col++){
            num[A->data[col].col]++;
        }

        position[1] = 1;
        for(col = 2;col <= A->nums;col++){
            position[col]= position[col-1] + num[col-1];
            
        }
            
        printf("\n");

        for(p = 1;p <= A->nums;p++){
            col = A->data[p].col;
            q = position[col];
            B->data[q].row = A->data[p].col;
            B->data[q].col = A->data[p].row;
            B->data[q].value = A->data[p].value;
            position[col]++;
            
        }

    }
}


```

转置之后是按照行排序转置好的，如图第一个是源矩阵，第二个是转置后的矩阵,因为使用了列号确定了转置后的行号,（沿袭了书上的例子）。


![fast](./fast.png)
    