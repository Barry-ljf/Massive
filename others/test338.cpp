#include<iostream>
#include<vector>
using namespace std;
/*
给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。*/
// class Solution {
// public:
/*动态规划*/
vector<int> countBits(int n) {
    //假设dp[n]表示nbit的1的数量
    //迭代公式：
    vector<int> dp(n+1,0);
    dp[0] = 0;
    int highbit =0;
    for(int i =1; i<= n;i++)
    {
        if((i &(i-1)) == 0)//这个地方的括号很关键
        {
            highbit = i;
            dp[i] = 1;
        }
        else{
            dp[i] = dp[i-highbit] + 1;
        }
    }
    return dp;

}


/*更改count1函数，利x&()x-1,即可使得时间复杂度是O(logn)*/
    // int count_one(int n){
    //     int count = 0;
    //     if(n==0)return 0;
    //     while(n != 0){
    //         n = n&(n-1);
    //         count++; 
    //     }
    //     return count;
    // }
// /*以下是最复杂的解法，时间复杂度是O(n2)*/
//     int count_one(int n){
//         int count = 0;
//         if(n==0)return 0;
//         while(n != 0){
//             count = count + (n & 1);
//             n = n>>1;
//         }
//         return count;
//     }


    // vector<int> countBits(int n) {
    //     vector<int> result;
    //     for(int i = 0; i <= n;i++){
    //         result.push_back(count_one(i));
    //     }
    //     return result;


    // }
//};