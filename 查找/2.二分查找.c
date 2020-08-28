#include <stdio.h>
#include <stdlib.h>    
//二分查找只能查找有序列
/********************************************************/
int Search_Bin(int *a,int key,int n)
{
   int low=0,mid,high=n-1;
   while (low<=high)
   {
       mid=low+(high-low)/2;//这样写可以防止数据溢出
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
    int k=Search_Bin(a,key,sizeof(a)/sizeof(*a));
    printf( "the key is in %d (0 means not found)\n",k);
    return 0;
}
    /*
    class Solution {
public:
    int find(vector<int>& arr, int target)
    {
        int size = arr.size();
        int left = 0;
        int right = size - 1;
        int mid = 0;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (target < arr[mid]) right = mid;
            else left = mid + 1;
        }
        return arr[left] > target ? left : left + 1;
    }

    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        // value的上下界[0, arr[size - 1]]
        int size = arr.size();
        vector<int> prefixSum(size, 0);
        for (int i = 0; i < size; i++)
        {
            if (i == 0) prefixSum[i] = arr[i];
            else prefixSum[i] = prefixSum[i - 1] + arr[i];
        }
        int ans = 0;
        int diff = INT_MAX;
        for (int i = 0; i <= arr[size - 1]; i++)
        {
            int cur = find(arr, i);
            int sum = 0;
            if (cur < size) sum = prefixSum[cur] - arr[cur] + (size - cur) * i;
            else sum = prefixSum[cur - 1];
            if (abs(target - sum) < diff)
            {
                ans = i;
                diff = abs(target - sum);
            }
        }
        return ans;
    }
};
    */
    dp[i][j] = max(dp[i-1][j-1]+(A[i-1] == B[j-1]?1:0),dp[i-1][j],dp[i][j-1])