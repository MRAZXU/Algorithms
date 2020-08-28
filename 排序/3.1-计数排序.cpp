#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//后面的算法就要用Vector了
/************************基于数组特性****************************************/
/*************************计数排序*****************************/
//虽然时间空间复杂度由于一切基于比较的排序算法
//但是对于非整数，过于大的数据量的数组，并不适用
void CountSort(vector<int>&a,vector<int>&b)
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

    //2.创建统计数组并统计对应元素的个数
    vector<int> countArray(d+1, 0);
	for (int i = 0; i<a.size(); i++)
		countArray[a[i]-min]++;//这里减min的目的是优化计数数组的空间
	
	//3.统计数组变形，后面的键值出现的位置为前面所有键值出现的次数之和
	for (int i = 1; i<d+1; i++)
		countArray[i]+=countArray[i-1];

	//4.倒序遍历原始数列，通过统计数组的_______将键值放到目标位置
    //通过计数数组下标逆序遍历，逆序写入sortArray

	for (int i =a.size()-1; i >=0; i--)	// 此处逆序是为了保持相同键值的稳定性
    {
        b[countArray[a[i]-min]-1] = a[i];
        countArray[a[i]-min]--;
    }

}

/********************************************************************/
int main()
{
    vector<int> a={51,3,4,5,15,54,3,6,36,67,1,35,47,45,43};
    vector<int> b(a.size(), 0);

    CountSort(a, b);

	for (int i = 0; i < b.size(); ++i)
		cout << b[i] << "  ";
	cout << endl;


}
