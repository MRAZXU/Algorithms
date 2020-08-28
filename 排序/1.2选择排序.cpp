#include <iostream>
using namespace std;

void selectionSort (int a[], int n);
void print(int a[], int n ,int i);
 /*****************打印*****************/   
void print(int a[], int n ,int i){
  cout<<i <<":";
  for(int j= 0; j<n; j++){
    cout<<a[j] <<" ";
  }
  cout<<endl;
}
/***********************选择排序*******************************/
//1找到最小的，取其索引号
void selectionSort (int a[], int n){
    for(int i=0;i<n;i++)
    {
        int minindex=i;//设当前为最小索引
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[minindex])
            {
                 minindex=j;//当前值与后面的进行比较，取最小的
            }
        }
//2对其当前值与对最小值交换顺序        
        if(minindex==i)
            continue;
        else
        {
            //实际的排序位置
            //a[i]和a[minindex]交换位置
            int temp=a[minindex];
            a[minindex]=a[i];
            a[i]=temp;
        }
    }
}
/******************************************************/
int main(){
 int a[15] = {51,3,4,5,15,54,3,6,36,67,1,35,47,45,43};
  selectionSort(a,15);
  print(a,15,15);
}
