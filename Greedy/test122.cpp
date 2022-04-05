#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
给定一个数组 prices ，其中 prices[i] 表示股票第 i 天的价格。

在每一天，你可能会决定购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以购买它，然后在 同一天 出售。
返回 你能获得的 最大 利润 。


*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int count =0;
        int result =0;

        //这道题最简单的方法也就是贪心算法，因为可以无限交易，那么只要交易有正值，立马就交易即可
        //双线result记录目前积累的最大值，count记录当前收益的取值

        for(int i =1; i < prices.size();i++){
            count = max(count,prices[i] - prices[i-1] + count);
            if(count > 0)
            {result += count;
            count =0;
            }

        }
        return result;
    }
};