#include <stdio.h>
#include <stdlib.h>    
//其实这种方法也是插值法的变种
//也是在mid上面做文章，在黄金比例中分割数组
/*********************斐波那契数组***********************************/
int Fib_num(int i)
{
    if(i<2) return i==0?0:1;
    return Fib_num(i-1)+ Fib_num(i-2);
}
int  *  Fibonacciin(int n)//函数不能返回一个数组，可以用全局变量和堆空间解决
{
    int *F=(int*)malloc(n*sizeof(int));//并不推荐这样做，最好是void(int*F,int n)
    for( int i=0;i<n;i++)
    {
        F[i]=Fib_num(i);
    }
    return F;
}
/*********************斐波那契查找***********************************/
int Search_BST(int *a,int key,int n)
{

    return 0;
}

/********************************************************/
int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10,11};//有序
    int b[]={9,8,5,4,7,1,5,56,3,2,85,46,15};//无序 输了 7位于5
    int key=7;
    int i=0;
    int k=Search_Fib(a,key,sizeof(a)/sizeof(*a));
    printf( "the key is in %d (0 means not found)\n",k);
    return 0;
}