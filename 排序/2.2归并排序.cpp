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
//归并的思想(分治思想)在单向链表合并中也有用到
//归并排序：先分割(MergeSort中递归)+归并(Merge中实现，并且实现部分排序功能)
/*1*************************Merge***********************************/
void Merge(int a[],int start, int mid, int end)
{
   //申请空间来存放两个有序区归并后的临时区域
  int *temp = (int *)malloc((end-start+1) * sizeof(int)); 
  int i=start;
  int j=mid+1;
  int k=0;
  while(i <= mid && j <= end)
  {
    if(a[i]<a[j])
    {
      temp[k++]=a[i++];//小的先放入临时数组
    }
    else
    {
      temp[k++]=a[j++];
    }
  }
  while(i<=mid) temp[k++]=a[i++];
  while(j<=end) temp[k++]=a[j++];
  //将堆空间排序的数据整合到原来数组中
  for(i=0;i<k;i++) a[start+i]=temp[i];
  free(temp);
}
/*2*************************MergeSort***********************************/
void MergeSort(int a[],int start, int end)
{
  int mid = start + (end - start) / 2;
  if (start >= end) return;
  //分
  MergeSort(a, start, mid);
  MergeSort(a, mid + 1, end);
  //合
  Merge(a, start, mid, end);
}
int main()
{
  int a[15] = {51,3,4,5,15,54,3,6,36,67,1,35,47,45,43};
  MergeSort(a,0,14);
  print(a,15,15);
  return 0;
}