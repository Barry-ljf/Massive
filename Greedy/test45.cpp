#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
给你一个非负整数数组 nums ，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

假设你总是可以到达数组的最后一个位置。


*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int cover =0;//存储cover范围内当前的最远目标
        int count =0;
        int temp = 0;//存储cover范围内可以达到的最远目标


        for(int i =0; i< nums.size() -1;i++){
            
            temp = max(temp,nums[i]+i);//cover范围内可达到的最远目标的可能值
            if(i == cover){//数组中的每个元素代表你在该位置可以跳跃的最大长度。也就是如果你覆盖范围是5，那么5以内的任何位置你可以一次跳到，这是这个方法的前提
                cover = temp;
                count++;
            }
        }
        return count;

    }
};
//这是基本方法;其实是一样的
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         if (nums.size() == 1) return 0;
//         int curDistance = 0;    // 当前覆盖最远距离下标
//         int ans = 0;            // 记录走的最大步数
//         int nextDistance = 0;   // 下一步覆盖最远距离下标
//         for (int i = 0; i < nums.size(); i++) {
//             nextDistance = max(nums[i] + i, nextDistance);  // 更新下一步覆盖最远距离下标
//             if (i == curDistance) {                         // 遇到当前覆盖最远距离下标
//                 if (curDistance != nums.size() - 1) {       // 如果当前覆盖最远距离下标不是终点
//                     ans++;                                  // 需要走下一步
//                     curDistance = nextDistance;             // 更新当前覆盖最远距离下标（相当于加油了）
//                     if (nextDistance >= nums.size() - 1) break; // 下一步的覆盖范围已经可以达到终点，结束循环
//                 } else break;                               // 当前覆盖最远距离下标是集合终点，不用做ans++操作了，直接结束
//             }
//         }
//         return ans;
//     }
// };