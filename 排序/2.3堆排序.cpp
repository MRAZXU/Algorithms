
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
/*******************************堆排序************************************/

//这里的二叉堆可以背一背
/*
* @param array 待调整的堆
* @param parentIndex 要下沉的父节点
* @param length 堆的有效大小
*/
//下沉调整
static void downadjust(int a[],int dad,int length)
{
    //temp保存父节点的值
	int temp = a[dad];
	int son = dad*2+1;
	while (son<=length)//若子节点在范围内才做比较
    { //如果有右孩子，且右孩子大于左孩子的值，定位右孩子
		if (son + 1 <=length && a[son]<a[son+1]) 
			son++;
        //如果父节点大于子节点代表调整完成，直接跳出函数
		if (a[dad] > a[son]) 
			break;
		else { 
            //否则交换父子內容再继续子节点与孙节点比較
			swap(a[dad], a[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
    a[dad]=temp;
}

static void heapsort(int a [],int length)
{
    //1.将无顺的数组结构构建成二叉堆 复杂度O（n） i从最后一个父节点开始调整
	for (int i=length/2 - 1;i>=0;i--)
		downadjust(a,i,length-1);
    //2.循环删除堆顶元素，并将元素移动到结合尾部O((n-1)logn)~>O(nlog(n) 开始堆排序
	//先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完成
	for (int i=length-1;i>0;i--) 
    {
		swap(a[0], a[i]);
		downadjust(a,0,i-1);
	}
}

/********************************************************************/
int main()
{
  int a[15] = {51,3,4,5,15,54,3,6,36,67,1,35,47,45,43};
  heapsort(a,15);
  print(a,15,15);
}
