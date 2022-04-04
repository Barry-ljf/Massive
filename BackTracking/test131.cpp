#include<iostream>
#include<vector>
using namespace std;
/*给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

回文串 是正着读和反着读都一样的字符串。*/
class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    bool ishuiwen(string s){
        for(int i = 0 ,j = s.size()-1 ;i < j; i++ ,j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }

    void Backtracking(string s,int startindex){

     if(startindex == s.size() )//终止条件，不能继续扩大path得size了这里没有操作，因为要对每一个大小的size都进行分析，而不是针对特定的size
     {
         result.push_back(path);
         //是否在这里返回值，还待说明.好像需要
         return;
     }

     for(int i = startindex; i < s.size() ; i++){//对于同层的探索，来自于第一种情况谈到底之后，没有合适的回文子串，不压path
         string temp = s.substr(startindex,i - startindex +1);
         //path.push_back(temp);//每层的第一个数字都是从只切割一个字母开始的
         if(ishuiwen(temp) == true){
            path.push_back(temp);//每层的第一个数字都是从只切割一个字母开始的
            Backtracking(s,i +1);//递归下一次切的更深,注意这里的迭代是i而不是index。因为，递归的是在该层的i作为基础上的！
            path.pop_back();
         }



     }

    }
    vector<vector<string>> partition(string s) {
        Backtracking(s,0);
        return result;



    }
};