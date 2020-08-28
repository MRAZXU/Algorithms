#include <iostream>
using namespace std;

void InsertSort (int a[], int n);
void print(int a[], int n ,int i);
 /*****************打印*****************/   
void print(int a[], int n ,int i){
  cout<<i <<":";
  for(int j= 0; j<n; j++){
    cout<<a[j] <<" ";
  }
  cout<<endl;
}
/*********************直接插入法(向前插)**********On2***********************/
//没有用网页上的逻辑（向后插）
void InsertSort (int a[], int n)
{
    for(int i=1;i<n;i++)//从第二个元素开始
    {
        int j=i;
        int target=a[i];//提出来保存准备插入
        //挪位和前面的元素比
        while (j>=1&&target<a[j-1])//如果比保存的元素大就向前
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=target;//插入
    }
}
/***********************二分插入（前插）*******On2但是比直接法要高一点************************/
//分治思想，以后会经常看到
//其实就是二分查找用在插入里面
void Bin_InsertSort (int a[], int n)
{
for ( int i = 1; i < n; i++)
    {
        int target=a[i];//提出来保存准备插入
        int left=0;  //左侧边界值
        int right=i-1;  //右侧边界值
        while (left <= right)
        {
            int mid = (left+right) / 2;  //中间值
            if(target< a[mid] )
            {
                right = mid - 1;   //把右侧边界缩小，在中间值得左边进行寻找
            }
            else 
            {
                left = mid + 1;  //把左侧边界加大，在中间值得右边进行寻找
            }            
        }
        for ( int j = i-1; j >= left; j--)  //将left到i-1之间的数都往后移动一个位置
        //注意如果要插入的数比前面排好序的数都小（都大）,则不会进入到该循环内，则此时将不会有数进行位置的移动
        {
            a[j+1] = a[j];
        }
        a[left] = target;      //将要插入的数值插入到合适位置       
    }   
}
/******************************************************/
int main()
{
  int a[15] = {51,3,4,5,15,54,3,6,36,67,1,35,47,45,43};
  InsertSort(a,15);
  print(a,15,15);
}
