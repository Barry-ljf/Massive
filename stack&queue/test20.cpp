//it is a test
/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
 

*/
#include<iostream>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0)
        {
            return false;
        }
        unordered_map<char,char> symbol{
            {')','('},
            {'}','{'},
            {']','['}
        };

        stack<char> stupid;
        for(char ch : s)
        {
            if(symbol.count(ch))
            {
                if(stupid.empty() || stupid.top() != symbol[ch])
                {return false;}
                else{
                    stupid.pop();
                }
            }
            else{
                stupid.push(ch);
            }
        }
        if(stupid.empty())return true;
        else{return false;}


    }
};