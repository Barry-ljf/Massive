#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
/*给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

*/

/*第一个答案的时间复杂度比较高O（n^2）*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> repeated(nums.begin(),nums.end());
        vector<int> result;
        for(int i = 0 ; i < nums.size()-1;i++)
        {
            for(int j = i+1 ; j <nums.size();j++)
            {
                if(nums[i]+nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;


    }
};

/*第二个答案的时间复杂度比较高O（n）*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> comeon;
        for(int i = 0; i < nums.size();i++){
            int temp = target - nums[i];
            auto iter = comeon.find(temp);
            if(iter != comeon.end())
            {
                return {iter->second,i};
            }
            comeon.insert(pair<int,int>(nums[i],i));
              
        }
       // return 0;//错误的写法！！！
        return {};
    }
};