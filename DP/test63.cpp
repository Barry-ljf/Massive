#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 1 和 0 来表示。

 
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        //如何测试第二个维度的size？先假设为obstacleGrid[1].size();
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,0));//把vector全部赋值为0的操作要记住了哦
        if(!obstacleGrid.size() && !obstacleGrid[0].size()){
            return 0;
        }  
        if(obstacleGrid[0][0] == 1){return 0;}
        for(int i = 0 ; i<m ;i++){
            if(obstacleGrid[i][0] == 0)
            {
                dp[i][0] = 1;
            }
            else{
                break;//不能简单的只把故障点的路径设为0.要知道。第一排的故障点的右边和第一列额故障点的下面都是不可能再到达的地方。
            }
        }

        for(int j = 1 ; j< n ;j++){
            if(obstacleGrid[0][j] == 0)
            {
                dp[0][j] = 1;
            }
            else{
                break;
            }
        }

        for(int i = 1; i < m; i++){
            
            for(int j = 1; j<n; j++)
            {
                if(obstacleGrid[i][j] == 0){
                dp[i][j] = dp[i][j-1] + dp[i-1][j]; 
                }
                else{
                    dp[i][j] =0;
                }
            }
        }
        return dp[m-1][n-1];

    }
};

 