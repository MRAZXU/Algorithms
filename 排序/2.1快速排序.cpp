#include <iostream>
using namespace std;
 /*****************打印*****************/   
void print(int a[], int n ,int i){
  cout<<i <<":";
  for(int j= 0; j<n; j++){
    cout<<a[j] <<" ";
  }
  cout<<endl;
}
//关键在于partition函数
/***********非随机划分函数*****************/
static int partition_norand(int a[],int left,int right)
{
    int med=a[left];//med默认为第一个，在非随机中

    int mark;
    int low=left;
    int high=right;
    //两种方法的目的是一致的：将比med小的移动到前面，大的移动到后面
  //1.----单边循环法
    /*
    mark=left;
    int i;
    for(i=left+1;i<=right;i++)
    {
      if(a[i]<=med)
      {
        mark++;//保证始终都是哪一个
        std::swap(a[mark],a[i]);
      }
    }
    //med和重合部分的交换
    std::swap(a[mark],a[left]);//最后一次将第一个位置放在他应该在的位置
    */
   
  //2.这个复杂度高 但是思路更为清晰 适合死记硬背---双边循环法
    while (low!=high)
    {
      //将比med（第一个）小的移动到前面 条件是个跳过条件
      while((low<high)&&(a[high]>med)) {high--;}
    //2.1 //if(low<high) a[low++]=a[high];
      //将比med（第一个）大的移动到后面
      while((low<high)&&(a[low]<=med)) {low++;}
    //2.1//if(low<high) a[high--]=a[low];
      //对跳过后符合交换条件的进行交换      
    //2.2
      std::swap(a[low],a[high]);
    }
    //med和重合部分的交换
    std::swap(a[low],a[left]);//最后一次将第一个位置放在他应该在的位置  
    

    //return mark;    //法1返回值
    return low;    //法2返回值

}
/***********随机划分函数*****************/
int partition(int a[],int left,int right)
{
  //三数取中
  int randmo=(right-left)+left;//从left到right-left内的随机数
  std::swap(a[randmo],a[left]);
  return partition_norand(a,left,right);
  //不套用也成
  /*
  int i=left-1;
    int j;
    for(j=left;j<right;j++)
    {
      if(a[j]<=a[right])
      {
        ++i;//保证始终都是哪一个
        if(i!=j)
        {
        std::swap(a[i],a[j]);          
        }
      }
    }
    ++i;
    std::swap(a[i],a[right]);//最后一次将第一个位置放在他应该在的位置
    return i;*/
}
/********************快排函数（递归实现）**********************************/
void QuickSort (int a[],int low,int high)
{
  if(low<high)
  {
    int p=partition(a,low,high);
    QuickSort(a,low,p-1);//前半递归
    QuickSort(a,p+1,high);//后半递归
  }
}
/********************快排函数（非递归实现---使用栈）**********************************/

/******************************************************/
int main()
{
  int a[15] = {51,3,4,5,15,54,3,6,36,67,1,35,47,45,43};
  int b[5]={2,3,5,1,6};
  QuickSort(a,0,14);
  print(a,15,15);

  return 0;
}
