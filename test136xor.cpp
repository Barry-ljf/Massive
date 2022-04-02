#include<iostream>
#include<vector>
using namespace std;
/*给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？


*/
//实际上如果不限制运行的话可以使用哈希表来做
class Solution {
public:
    int singleNumber(vector<int>& nums) {//不需要额外空间的方法，就往位运算上想位运算我知道这么位运算我是真的没想到
        int result = 0;
        for(int i =0 ; i<nums.size(); i++){
        //for(int a:nums){
            result ^= nums[i]; 
        }
        return result;
    }
};