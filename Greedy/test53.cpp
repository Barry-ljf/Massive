#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。

 */
//两种方法贪心和动归，但是明显都有一个双线任务。
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;//这个就是记录当前的最小值的，这样写是因为全是负数的时候也是可以用的 ，不能单纯的设置为0
        int count= 0;
        for(int i =0; i< nums.size();i++){
            count   = count +nums[i];//每一步必须要加，因为这就是规则，只要是序列就得往前加
            if(count > result){
                result = count;//加的过程中，累计的结果不一定越加越大，但是只要是正值，就可以保留，但是大于之前记录的最大值的时候，那就可以记下来
            }
            if(count <0){
                count =0;//这是贪心的地方，也算不上什么贪心，就是说当累加为负数的时候，对接下来的和没有任何帮助。
            }
        }
        return result;


        // vector<int>dp(nums.size());
        // int result = nums[0];//又是双线思维，一线是比较当前的取值，另外一线是记录之前的大值，针对于这种问题，无论是动态规划还是贪心算法，都存在这一特点
        // dp[0] = nums[0];
        // for(int i =1 ; i < nums.size() ; i++){
        //     dp[i] = max(nums[i],nums[i]+dp[i-1]);
        //     result = max(result,dp[i]);
        // }
        // return result;


    }
};