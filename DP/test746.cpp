#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 0){
            return 0;
        }
        
        vector<int> dp(cost.size());

        dp[0] = cost[0];
        dp[1] = cost[1];//这一点你没想明白，可以直接从1出发，直接支付15
        //dp[2] = min(dp[0]+cost[2],dp[1]+cost[2]);
        for(int i =2; i < cost.size(); i++){
            dp[i] = min(dp[i-1],dp[i-2])+cost[i];
        }
        //dp[cost.size()-1] = min(dp[cost.size()-2],dp[cost.size()-3]);

        return min(dp[cost.size()-1],dp[cost.size()-2]);//最后的结果也是从倒数第二步的花费和倒数第一部的花费过来的！！！！！！！

        


    }
};