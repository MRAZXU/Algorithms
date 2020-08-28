#include <stdio.h>
#include <stdlib.h>    
//插值查找是二分查找的改进
//背记插值公式就是了
/********************************************************/
int Search_Insert(int *a,int key,int n)
{
   int low=0,mid,high=n-1;
   while (low<=high)
   {
       mid=low+(high-low)*((key-a[low])/(a[high]-a[low]));
       if(key<a[mid])  high=mid-1;
       else if (key>a[mid]) low=mid+1;
       else return mid+1;
   }
    return 0;
}
/********************************************************/
int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10,11};//有序
    int b[]={9,8,5,4,7,1,5,56,3,2,85,46,15};//无序 输了 7位于5
    int key=7;
    int k=Search_Insert(a,key,sizeof(a)/sizeof(*a));
    printf( "the key is in %d (0 means not found)\n",k);
    return 0;
}