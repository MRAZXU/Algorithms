#include <stdio.h>
#include <stdlib.h>    
//可以无序也可以有序
/********************************************************/
/*
int Search_seq(int *a,int key,int n)
{
    int num=0;
    for(int i=0;i<n;i++)
    {
        ++num;
        if(a[i]==key)
        {
            return num;
        }
    }
    return 0;
}
*/
int Search_seq(int *a,int key,int n)//带哨兵的顺序
{
    int i;
    int temp=a[0];
    a[0]=key;//设置哨兵
    i=n;
    while(a[i]!=key) i--;
    a[0]=temp;
     return i+1;
}
/********************************************************/
int main()
{
    int a[] = {0,1,4,35,47,53,62,7,78,88,99};//8
    int b[]={9,8,5,4,7,1,5,56,3,2,85,46,15};//5
    int key=7;
    int k=Search_seq(a,key,sizeof(a)/sizeof(*a));
    printf( "the key is in %d (0 means not found)\n",k);
    printf( " %d\n",a[0]);
    return 0;
}