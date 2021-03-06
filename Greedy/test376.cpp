#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。

例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。

相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。

给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。

*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)return nums.size();
        int cur_diff = 0;
        int pre_diff = 0;//这个是假设第0个位置之前的差值为0的情况
        int result =1;//默认最后一个是一个峰

        for(int i = 0; i< nums.size() - 1;i++){//这里减1是因为最后的两个数字决定的最后一位不用管了都算是摆动，直接加1
            cur_diff = nums[i+1] - nums[i];
            if(cur_diff > 0 && pre_diff<=0 || cur_diff <0 && pre_diff >=0){
                    
                result++;
                pre_diff = cur_diff;

            }
        }

        return result;

    }
};