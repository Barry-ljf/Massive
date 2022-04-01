// it is a test
#include<string>
#include<vector>
#include<iostream>
using namespace std;
/*给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。*/
class Solution {
public:
    void nextable(int* next , const string &s){
        int j = 0;
        next[0] =j;//这里注意定义传过来的是地址！！！！！不要再写int了！！
        for(int i = 1; i < s.size();i++ ){
        while(j>0 && s[j] != s[i])
        {
            //j = j-1;//不可以这样写有错误了参考ababba得到：001223，因为这种会导致很大的问题就是，当不相等的时候，前面积累的应该全部消失
            j = next[j-1];//得到001201
        }
        if(s[j] == s[i]) j++;
        
        next[i] = j;
        
        }
    }
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 0){return false;}
        int next[s.size()];
        nextable(next,s);
        if(next[s.size()-1] != 0 && s.size() % (s.size() - next[s.size()-1] ) == 0)return true;
        
        return false;
        




   
    }
};