#第九章 排序 冒泡排序

##冒泡排序

冒泡排序（Bubble Sort），是一种计算机科学领域的较简单的排序算法。
它重复地走访过要排序的数列，一次比较两个元素，如果他们的顺序错误就把他们交换过来。走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。
这个算法的名字由来是因为越大的元素会经由交换慢慢“浮”到数列的顶端，故名。


##冒泡排序运作

冒泡排序算法的运作如下：（从后往前）
1.比较相邻的元素。如果第一个比第二个大，就交换他们两个。
2.对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
3.针对所有的元素重复以上的步骤，除了最后一个。
4.持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

##排序代码

```
void BubbleSort(RecordList L){

    int i,j,k;
    int t;
    for(i = 1;i <= L.length-1;j++){
        for(j = 1;j <= L.length -i ;j++){
            if(L.r[j] > L.r[j+1]){
                t = L.r[j];
                L.r[j] = L.r[j+1];
                L.r[j+1] = t;
            }
        }
    }
}

一个递归实现

void sort(int *add,int len)
{
    int fact = 0 , isorderd = 0;
    if(len <= 1 || !add){
        return;
    }

    while(fact < len-1){
        if(add[fact] > add[fact+1]){
            add[fact]   ^= add[fact+1];
            add[fact+1] ^= add[fact];
            add[fact]   ^= add[fact+1];
            isorderd    = 1;
        }
        fact++;
    }
    if(!isorderd){
        return;
    }
    sort(add,len-1);
}

```