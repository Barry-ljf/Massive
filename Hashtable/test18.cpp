#include<string>
#include<iostream>
#include<vector>
#include <unordered_set>
#include <unordered_map>
#include<algorithm>
/*#include<string>
#include<iostream>
#include<vector>
#include <unordered_set>
/*给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

*/


using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> wangdongchu;
        sort(nums.begin(),nums.end());
        for(int i = 0; i< nums.size(); i++){
            // if(nums[i] > target){//细节1：不需要剪枝，因为当目标值为0的时候，剪枝是因为指导正整数相加一定大于0，但是如果任意数是负数（-3+（-2）=-5越加越小）
            //     return wangdongchu;
            // }
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i+1;j < nums.size()-1;j++){
            // if(nums[j] > target){
            //     return wangdongchu;
            // }
            if(j>i+1 && nums[j] == nums[j-1]){//细节2，并不是原封不动的照搬，因为一定要保证j-1是用过的！才能去重！j>1是很显然不对的i=1，j=2就会出错
                 continue;
            }
             int left = j+1;
             int right = nums.size()-1;
             while(left < right){
                 if(nums[i] + nums[j] == target - (nums[left] + nums[right])){
                    wangdongchu.push_back({nums[i] , nums[j] , nums[left] , nums[right]});
                    while(left < right && nums[left] == nums[left + 1]){left++;}
                    while(left < right && nums[right] == nums[right - 1]){right--;}
                    left++;
                    right--;
                 }
                 else if(nums[i] + nums[j] > target - (nums[left] + nums[right]))
                 {
                     
                     while(left < right && nums[right] == nums[right - 1]){right--;}
                     right--;
                     
                 }
                 else{
                     
                     while(left < right && nums[left] == nums[left + 1]){left++;}
                     left++;
                     
                 }
             }

            }
        }
        return wangdongchu;

    }
};