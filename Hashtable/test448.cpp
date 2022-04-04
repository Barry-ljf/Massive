#include<string>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {//时间复杂度O（n）,空间复杂度O（1）
        int x = 0; 
        int size = nums.size();
        vector<int> result;
        for(int num : nums){
            x = (num-1) % size;//用现在的值作为新的nums的序列，可以直接用x，为什么要取模呢，因为用到了加模的这一个过程！！，取模可以保有原来的值作为序列
            nums[x] = nums[x]+size;//到最后一会发现，只有没有的值它对应的序列没有加任何数字还是原来的的数字。
        }//为什么会减1呢，是因为1到n有n个数字，但是存放的最大index只有n-1个。
        for(int i = 0; i< nums.size();i++)
        {
            if(nums[i] <= size ){
                result.push_back(i+1);

            }
        }
        // vector<int> result;
        // set<int> aa(nums.begin(),nums.end());
        // for(int i =1; i<= nums.size();i++)
        // {
        //     if(aa.count(i) == 0)result.push_back(i);
        // }
        // return result;
    }
};