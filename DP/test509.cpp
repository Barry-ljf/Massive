#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：*/
class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1);//注意使用数组的格式必须对已知大小的进行赋值，否则要使用push_back！！！！！！不要搞混查询和赋值
        if (n <= 1) return n;
        dp[0]=0;
        dp[1]=1;
        int iresult;
        for(int i =2;i <= n;i++ )
        {
            dp[i] = dp[i-1] + dp[i-2];
            iresult = dp[i];
        }
        return dp[n];

    }
};