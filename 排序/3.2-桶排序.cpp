#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
/*****************************桶排序***************************************/
//为了应对计数排序的1.范围不能太大 2.元素必须是正整数的缺点
//将计数单位变成了一个范围-----一个桶
void BucketsSort(vector<double>&a,vector<double>&b)
{

  // 确保待排序容器非空
	if (a.size() == 0)
		return;
    //1.得到数列的最大值和最小值，计算差值
    int min=0;
    int max=0;   
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>max) max=a[i];
        if(a[i]<min) min=a[i];
    }
    int d=max-min;

    //2.初始化桶
    int  bucketSize =a.size();
    int bucketCount = floor(d/bucketSize) + 1; //浮点数向下取整
    vector<double> buckets [bucketCount];

	  //3.利用映射函数将数据分配到各个桶中
	  for (int i = 1; i<a.size(); i++)
    {
      int bi=floor(a[i]-min)/bucketSize;
      buckets[bi].push_back(a[i]);
    }
		
	  //4.对每一个桶的元素进行排序，再放入数组
    for (int i=0;i<bucketCount;i++)
     {
        sort(buckets[i].begin(),buckets[i].end());// 对每个桶进行排序，这里使用了插入排序
        for (int j = 0; j < buckets[i].size(); j++)
         {
            b.push_back(buckets[i][j]);
         }
     }   

}
/********************************************************************/
int main()
{
    vector<double> a={51.3,3.1,4.2,5.4,15,54,3,6,36,67,1,3.5,47,45,43};
    vector<double> b;

    BucketsSort(a, b);

	for (int i = 0; i < b.size(); ++i)
		cout << b[i] << "  ";
	cout << endl;


}