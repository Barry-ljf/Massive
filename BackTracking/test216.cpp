#include<iostream>
#include<vector>
using namespace std;
/*找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

只使用数字1到9
每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

*/

class Solution {
public:   
    vector<int> path;
    vector<vector<int>> result;
    bool sumistrue(vector<int> path,int n){
        int sum=0;
        for(int i =0 ; i<path.size();i++){
            sum = sum + path[i];
        }
        return sum == n? true:false;

    }
    // int sumis(vector<int> path,int n){
    //     int sum=0;
    //     for(int i =0 ; i<path.size();i++){
    //         sum = sum + path[i];
    //     }
    //     return sum ;

    // }
    void Backtracking(int k, int n,int startindex) {
        // if(sumis(path,n)>n){return;}//剪枝操作，这个是否可以达到加入13x的结果已经找到，直接从14开始呢？不清初
        if(path.size() == k){
            if(sumistrue(path,n))
            result.push_back(path);
            return;
        }
        for(int i = startindex; i<=9 - (k-path.size())+1; i++ ){
            path.push_back(i);
           
            Backtracking(k,n,i+1);
             if(sumistrue(path,n)){//这里是刘家甫认为的剪枝操作，这里才能实现真正的剪枝，那就是13x已经没结果的时候，直接从14x开始。
                path.pop_back();
                break;
            }
            
            path.pop_back();
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        if(n == 1 && k>1){return result;}
        Backtracking(k,n,1);
        return result;
    }
};