#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
/*给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。

*/
//这里用到了双向队列，他是队列的底层实现的方法除了front和back之外，比较特殊的就是有pop.back()\pop.front()\push.back()\push.front()
class Solution {
public:
class mypueue{
public:
    deque<int> que;
    void pop(int val){
        if(!que.empty() && val == que.front())
        {
            que.pop_front();
        }
    }
    void push(int val){
        while(!que.empty() && val > que.back() )
        {
            que.pop_back();
        }
        que.push_back(val);
    }
    int front()
    {
        
        return que.front();
    }
};
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    mypueue que;
    for(int i = 0; i < k; i++){
        que.push(nums[i]);
    }
    result.push_back(que.front());

    for(int i = k; i<nums.size(); i++){
        que.pop(nums[i-k]);//这个地方特别绕啊，他是数组里面的k个里面的第一个，如果数组是123的话，也就是1，但是窗口划过呢最后在队列里面只能留下3，因此这个数字和pop不相等也就不会pop（这个是类里面的pop条件），然后若是721这样的数字，实际上是一个都不会删除的保留下来，那么下一个数字想要进来必须删除第一个7同样的道理

        que.push(nums[i]);
        result.push_back(que.front());
    
    }
    return result;


}

//这个是自己想的时间复杂度太高了，不然是可以的
// /*时间复杂度显然是n的平方这个时间复杂度太大了*/
//     int k_maxval(vector<int> nums,int start,int end)
//     {
//         for(int j = start + 1 ; j < end ; j++){//未确定区间
//             if(nums[j] < nums[j-1])
//             {nums[j] = nums[j-1];}
//         }
//         return nums[end - 1];
//     }
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {

//         vector<int> result;//实际上可以确定数组的大小：num.size() - k + 1;
//         for(int i = 0; i<nums.size() - k + 1; i++)
//         {
//            result.push_back(k_maxval(nums,i,i+k));
//         }

//        return result; 
//     }
};