#include<iostream>
#include<string>
#include<vector>
using namespace std;
/* 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

返回 你可以获得的最大乘积 。

 */
class Solution{
    public:
    int integerBreak(int n){
        vector<int> dp(n+1,0);//这里的数据也要注意，因为数据是10的话，这里考虑到了dp[0]因此就是要在数据上加1，否则的话把dp[1]当成2，就要让dp[1]=1
        
        dp[2] = 1;//1*1=1 dp[0],dp[1]均没有意义
        for(int i = 3;i < n+1; i++){
            for(int j = 1;j < i;j++){
            dp[i] = max(dp[i],max(j*dp[i-j],j*(i-j)));
            }//为什么有j(i-j)这个呢，是因为j +（i-j）这两部分都是前面的数据没办法给的，这个只能记住。。。
        }
        return dp[n];

    }
};