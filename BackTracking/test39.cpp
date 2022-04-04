#include<iostream>
#include<vector>
using namespace std;
/*给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 target 的不同组合数少于 150 个。

*/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    int sumis(const vector<int>& sum1){
        int sum = 0;
        for(int i = 0; i<sum1.size();i++ ){
            sum = sum + sum1[i];
        }
        return sum;
    }

    void Backtracking(const vector<int>& candidates, int target,int startindex){
 
            // while(sumis(path) < target){//这里的限制条件才是你输出的向量的个数，如果这里没有限制的话，就不需要考虑这行代码
            //     Backtracking(path,target,startindex);
            // }
            if(sumis(path) > target){
                return;//求稳一手
            }
            if(sumis(path) == target){
                result.push_back(path);
                return;
            }
            


        for(int i =startindex; i< candidates.size(); i++ ){//这个地方超了，不好弄，这个i的含义是，你所选择的数字的范围，而不是你所输出的向量的个数！！！
                                                            //就好比这个candidate，里面的元素个数就是可选择对象的个数，包括1-9的9也是对象的个数。
            path.push_back(candidates[i]);
            Backtracking(candidates,target,i);
            path.pop_back();


        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        Backtracking(candidates,target,0);
        return result;

    }
};