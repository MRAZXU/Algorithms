#include <iostream>
using namespace std;
void bubbleSort(int a[], int n);
void print(int a[], int n ,int i);
 /*****************打印*****************/   
void print(int a[], int n ,int i){
  cout<<i <<":";
  for(int j= 0; j<n; j++){
    cout<<a[j] <<" ";
  }
  cout<<endl;
}
 /**************冒泡排序（优化）********************/   
 //在第i次扫描前，还要对已经排序的元素进行扫描
 //引入flag
void bubbleSort(int a[], int n)
{
  int flag=0;
  for(int i =0 ; i< n-1; ++i)
  {
    flag=0;
    for(int j = 0; j < n-i-1; ++j)
    {
      if(a[j] > a[j+1])
      {
        int tmp = a[j] ;  //交换
        //需要有中间值
        a[j] = a[j+1] ;
        a[j+1] = tmp;
        flag=1;
      }
    }
    if(flag!=1) return;//如果已经发生交换则跳出循环
  }
}
/***********鸡尾酒排序(左右开工)**********要会这个************/
void  Cocktailsort(int a[], int n)
{
  int left=0;
  int right=n-1;
      while(left<right){
        //前半轮，将最大元素放到后面
        for(int i=left;i<right;i++){
            if(a[i]>a[i+1]){
                std::swap(a[i],a[i+1]);
            }
        }
        right--;
        //后半轮，将最小元素放到前面
        for(int i=right;i>left;i--){
            if(a[i]<a[i-1]){
                std::swap(a[i],a[i-1]);
            }
        }
        left++;
    }
}
int main(){
 int a[15] = {51,3,4,5,15,54,3,6,36,67,1,35,47,45,43};
  bubbleSort(a,15);
  print(a,15,15);
}
