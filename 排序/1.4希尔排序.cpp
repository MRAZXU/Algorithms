#include <iostream>
using namespace std;

void ShellSort (int a[], int n);
void print(int a[], int n ,int i);
 /*****************打印*****************/   
void print(int a[], int n ,int i){
  cout<<i <<":";
  for(int j= 0; j<n; j++){
    cout<<a[j] <<" ";
  }
  cout<<endl;
}
/******************************************************/
/*但希尔排序是非稳定排序算法。
先将整个待排序的记录序列分割成为若干递减增量子序列分别进行直接插入排序.
*/
//do while
void ShellSort (int a[], int n)
{
    int step=1;
    int i,j=0;
    //递减增量序列的划分是关键
    while(step<n/3)
    {
        step=3*step+1;//寻找合适的增量序列
        //比n的三分之一小的3的倍数多1 这里是4
    }//step=4
    //开始排序
    while(step>=1)//4->1
    { 
        //里面就是一个1-->>step的插入法
        for(i=step;i<n;i++)//和插值法一样都是从第二项开始比第一项
        {
            int j=i;
            int target=a[i];
            //挪位和前面的元素比
            while (j>=step&&target<a[j-step])//如果比保存的元素大就向前
            {
              a[j]=a[j-step];
              j-=step;
            }
            a[j]=target;//插入
        }
        step=step/3;
    }     
}
/******************************************************/
int main()
{
  int a[15] = {51,3,4,5,15,54,3,6,36,67,1,35,47,45,43};
ShellSort(a,15);
  print(a,15,15);
}
