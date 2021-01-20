#第四章   串 及其一些算法

#前言
 
   其实字符串这里感觉就没有什么数据结构，应要说的话，KMP ，BF ，FF 这些其实是算法的范畴，但是国内的一些数据结构书非要把C 标准库的一些string 中的函数拿出来硬是凑出了数据结构串这章节的内容，也是够了。
   
    之前说过，这篇文档主要是小结一些东西，能应对学校考试，了解一些其他没有学过的数据结构，
    能和面试对接这才是我们需要的。精研算法的童鞋请绕路。
    
    遂决定这章以下面的路线杂谈
    
    1.概念（考试用，选择填空题）
    2.面试小技巧
    3.KMP
    
    
##概念

####串
        串是由零个或多个字符组成的有限序列。
        
####长度
        串中字符的数目n 称为串的长度。
        
####空串
        零个字符的串称为空串。
  
####子串
        串中任意个连续的字符组成的子序列称为该串的子串。
        
####主串
        包含子串的串相应地称之为主串。
        
####相等
        称两个串相等，当且仅当这两个串的值相等。
####空格串
        由一个或多个空格组成的串称之为字符串。
####求子串的个数
        n(n + 1)/2 + 1   n:串中字符的个数，再加上一个空串，空串是任何字符串的字串。
        
####<string.h>
     这个头文件中的函数基本用法需要知道，因为这是C语言的内容，所以此不再赘述。
     
##面试小技巧

        很多面试题都有实现一个strcmp,strcat,strcpy等等这些函数。其实，实现并不难，考察的是
        编程习惯。
        
        我这里使用glibc的源码来说明一些问题，以strcpy 为例。
      
```
char * strcpy(char * dest,const char *src){
    char c ;
    char *s = (char *)src;
    const ptrdiff_t off = dest -s -1;
    
    do{
         c = *s++ ;
         s[off] = c;
    }while(c != '\0);
      
    return dest;
    
}
libc_hidden_builtin_def (strcpy)
```
这就是strcpy 的源码,是不是很难看懂？没事有我在，可以给你解释清楚，包括后边我们发现就算是glibc 库也有一些不尽人意的地方。

想看懂这段代码，需要一些你曾经不知道的东西。
首先注意const 的使用，这很关键。我们防止不小心修改我们的源信息，还是使用const 比较好。

其次注意类型转换，然后注意这个类型，估计很多程序猿都不知道这个类型，普及下，这是两个指针相减的结果类型，主要是求出两个指针的相对偏移量，unisgned long int 类型，接着看着两条语句：

```
c = *S++;    /* 首先将S 的值赋给 C*/

S[off] = c; /*然后将C 的值赋给S[off] 完成给dest头指针的赋值*/
            /*注意每次循环以后S的值其实改变了，所以一直都在给dest赋值*/
     
```
这段代码还是很精致的，但是我为什么说还有缺陷呢？有点鸡蛋里挑骨头了，既然是让我们写，我们还必须考虑到判空的情况，所以增加两条判断是否有NULL 还是很出彩的。

例如：
```
if(!dest || !src){
     return NULL;
}
```

再看一个strcat

```
/* Append SRC on the end of DEST.  */
char *
strcat (dest, src)
     char *dest;
     const char *src;
{
  char *s1 = dest;
  const char *s2 = src;
  char c;

  /* Find the end of the string.  */
  do
    c = *s1++;
  while (c != '\0');

  /* Make S1 point before the next character, so we can increment
     it while memory is read (wins on pipelined cpus).  */
     
  /*这里检查了下一个字符是否可读，如果不可读直接就在这里发生错误终止程序，
  防止即使写了入了字符串，后边却不可读出的情况*/
  
  s1 -= 2;

  do
    {
      c = *s2++;
      *++s1 = c;
    }
  while (c != '\0');

  return dest;
}
```


##下来说下KMP 
  KMP 暂时只说两种思路吧，一种是学校老师教偏经验的用法，另一种是更为通用的更一般的用法。
  考试的形式主要以选择题，完成题为主。
  KMP 相信大家上数据结构课的时候都学习过了，确实不容易理解，复杂的证明就不说了。
  我们从几个方面来谈谈这个KMP。 
  以下所有都以
  
       
  父串：a c a b a a b a a b  c  a  c  a  a  b  c
       
         1 2 3 4 5 6 7 8
  子串：a    b    a    a    b   c   a   c
  

  
为例。  
  
###KMP 干了什么？
  
  首先给你两个字符串，A 与 B ，需要你判断A 是不是 在B中，如果是返回A的位置，如果我们无脑的使用循环比较，复杂读为O（lenth(A)*lenth(B)) ,使用KMP是O（lenth(A) + lenth(B)) .确实减少了时间复杂度。
   KMP 就干了一件这事。
   
###KMP 的两种用法
   KMP 的两种用法就是根据我们使用计算next 的值的方法不同，使用next 的值的不同来区分的。
   
####首先说下求next的广泛使用方式
    next 值就是为了减少重复比较的一种预处理方式。对于每一个字符元素求其之前包括自己在
    内的前缀串与后缀串的最长的公有元素的长度。
    由上边假设的题目条件：
    
    字符       next值    next标号
    a          0           1
    ab         0           2
    aba        1           3
    abaa       1           4
    abaab      2           5
    abaabc     0           6
    abaabca    1           7
    abaabcac   1           8
    
    这种算法使用公式： 移动位数 = 已匹配的字符数 - 对应的部分匹配值
    
    所以这种算法出来的next 就是0011201

    第一趟  a c a b a a b a a b c a c a a b c
           a b a a b c a c
           偏移 = 1 - next[1] = 1
           
    第二趟  a c a b a a b a a b c a c a a b c   
             a b a a b c a c
           没有匹配到，偏移= 1
           
    第三趟  a c a b a a b a a b c a c a a b c
               a b a a b c a c
           偏移 = 5 - next[5] = 3;
           
    第四趟  a c a b a a b a a b c a c a a b c
                     a b a a b c a c
                     
           完成匹配
           
求next值的代码：
```
void get_next(int *next,char *p){
    int i ,n ,k;

    n = strlen(p)
    next[1] = next[0] = 0;
    k = 0;
    for(i = 2;i <= n;i++){
        for(; k != 0 && p[k] != p[i-1];k = next[k]){
            if(p[k] == p[i-1])
                k++;

        }
        next[i] = k;
    }
}

```
           
以上就是使用比较广泛的一种用法，下来说学校学的一种方法。

###KMP 的快速使用方式

学校教授的方法一种可以快速求出next值的方法，当然需要它自己的比较方法。

个人感觉这个方法有点“暴力”。

a  b  a  a  b  c  a  c

0  1  1  2  2  3  1  2

        next    next值       元素
        1        0           a
        2        1           b      前边两个都是直接写 0 1
        3        1           a      比较前一个字符与next[2] 不相等1
        4        2           a      比较前一个字符与next[3] 相等+1 = 2
        5        2           b      同上不等接着比较S[next[2]] 相等+1 = 2 
        6        3           c      同上比较相等 +1 = 3
        7        1           a      同上比较 不相等为1
        8        2           c      同上比较 相等+1  = 2
        
得出next 值后进行匹配

第一趟
        
        a c a b a a b a a b c a c a a b c
        a b a a b c a c
        偏移：  c != b next[2]  = 1;
        
第二趟

        a c a b a a b a a b c a c a a b c
          a b a a b c a c
        偏移： a != c  next[1] = 0;偏移为0 向后偏移1
        
第三趟

        a c a b a a b a a b c a c a a b c
            a b a a b c a c
        偏移：         a != c next[6] = 3 ;
        
第四趟
    
        a c a b a a b a a b c a c a a b c
                  a b a a b c a c 
                  
        匹配完成。！！！
        
总的来说想要精研算法的还是去看算法导论吧。
