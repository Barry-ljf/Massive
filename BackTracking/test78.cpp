#include<iostream>
#include<vector>
using namespace std;
/*给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。*/
class Solution {
public:
    vector<vector<int>> result;
    vector<int>path;
    vector<int>NUL;

    
    void Backtracking(vector<int>& nums,  int index  ){
        if(path.size() == nums.size()){
            //result.push_back(path);//这里好像不用加
            return;

        }

        for(int i = index ; i < nums.size();i++ ){
            path.push_back(nums[i]);
            result.push_back(path);
            Backtracking(nums,i+1);//一层一层的往深处递归到最后一个层，每一层都会记住值得。
            path.pop_back();

        }


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        NUL.clear();
        result.push_back(NUL);
        Backtracking(nums,0);
        return result;

    }
};