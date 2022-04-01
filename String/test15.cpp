// it is a test
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    void prefixtable(int *next, const string &s){
        int j = 0;
        next[0] = 0;
        for(int i = 1;i < s.size();i++){
            while(j>0 && s[j] != s[i]){
                j = next[j - 1];
            }
            if(s[j] == s[i])j++;

            next[i] = j;
            
        }
}
    int strStr(string haystack, string needle) {
        if(needle.size() == 0){return 0;}
        int j = 0;
        int next[needle.size()];//数组定义为{}和如左定义的区别，前者好像没有实体，都不分配地址。
        prefixtable(next,needle);
        for(int i = 0;i < haystack.size(); i++)
        {
            while(j>0 && haystack[i] != needle[j]){//这里的j和i，j是用来给模式串的因为他对应了前缀表
                j = next[j - 1];
            }
            if(haystack[i] == needle[j]) j++;
            
            if(j == needle.size())return i - needle.size() + 1;
        }
        return -1;
    }
};