#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。


*/
class Solution {
public:
    vector<int> path ;
    vector<vector<int>> result;
    int sum1(vector<int>& candidates){
        int sum =0;
        for(int i =0;i<candidates.size();i++){
            sum = sum + candidates[i];
        }
        return  sum;
    }
    void Bscktracking(vector<int>& candidates, int target,int startindex){
        if(sum1(path) > target)
        {
            return;
        }
        if(sum1(path) == target){
            result.push_back(path);
            return;
        }

        for(int i = startindex ; i <candidates.size();i++ ){//这里小于的是被选择的数组的大小
        if (i > startindex && candidates[i] == candidates[i - 1]) {//在这里跳过，这和break不同这个只是从1，3，4跳了一个4到了1，3，5：[1 3 4 4 5]
                continue;
            }   
            path.push_back(candidates[i]);
            Bscktracking(candidates,target,i+1);//不重复，所以选择下一个
            path.pop_back();

        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());//这个是排序把相邻的相同的给能够跳过
        Bscktracking(candidates,target,0);
        // set<vector<int>> result_1(result.begin(),result.end());
        // vector<vector<int>> result_2(result_1.begin(),result_2.end());
        return result;
    }
};