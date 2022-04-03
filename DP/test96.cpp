/*给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
  
        for(int i =2;i<=n;i++){
            for(int j =0;j<i;j++)
            { 
                dp[i] = dp[i] + dp[j]*dp[i-j-1];//这个我只能说是三棵树发现不了这个规律，的再多一点，记住吧反正是，尤其记住的是0个节点的情况
            }
        }
   
        return dp[n];

    }
};