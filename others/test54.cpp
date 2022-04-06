#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //对于如何求矩阵的size
        int summary = matrix.size() * matrix[0].size();//矩阵的长宽之积。
        //cout<<summary;
        int num =1;
        vector<int> result;
        int a = 0, b = 0,c = matrix[0].size() -1,d = matrix.size()-1;
        while(1){
            if(result.size() == summary)break;
            //以下的四个式子很容易晕，这样确定会好一点：
            //首先确定执行完之后的加加减减，顺序是第一行最后一列，最后一行，第一列，那么也就是b->c->d->a
            //然后确定每次执行的不变量的位置来写push_back里面的i，相对应得不变量就是所在行列，也是接下来改变的值：b->c->d->a
            //初始值，按照顺序就应该是a，b，c，d，根据初始值和移动方向确定终止的值。
            for(int i = a; i <= c ; i++){result.push_back(matrix[b][i]); num++;}
            b++;

            if(result.size() == summary)break;
            for(int i = b; i <= d ; i++){result.push_back(matrix[i][c]); num++;}
            c--;

            if(result.size() == summary)break;
            for(int i = c; i >= a  ; i--){result.push_back(matrix[d][i]); num++;}
            d--;
            
            if(result.size() == summary)break;
            for(int i = d ; i >= b  ; i--){result.push_back(matrix[i][a]); num++;}
            a++;
            
        }
        return result;


    }
};