#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
        vector<int> path;
        vector<vector<int>> result;//全局变量，不需要返回值
    void backtracking(int n, int k,int startindex){

        if(path.size() == k){
            result.push_back(path);
            return;
        }

        for(int i =startindex; i <= n - (k-path.size())+1 ;i++ ){//优化剪枝
            path.push_back(i);
            backtracking(n,k,i+1);//这里的i+1记得是为了下一步从第二个位置出发了
            path.pop_back();//这个是对当前的刚加的那一位进行pop，是为了遍历到下次同类型的数值。
        }
        
    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return result;


    }
};