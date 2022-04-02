//it is a test
/*
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

*/
#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> ljf;
        //if(s.size() == 0) return s;
        for(char c : S)
        {
            if( ljf.empty() || c != ljf.top())
            {
                ljf.push(c);
            }
            else{
                ljf.pop();
            }
        }
        int length =ljf.size();
        string s1(length,'0');
        // while (!ljf.empty()) { // 将栈中元素放到result字符串汇总
        //     s1 += ljf.top();//这个地方有一个点就是说这个加法非常的灵性
        //     ljf.pop();
        // }
        
        for(int i = 0; i < length; i++)
        {
            s1[i] = ljf.top();
            ljf.pop();
        }
        //还有一个reverse函数需要好好的记一下
        reverse (s1.begin(), s1.end()); 
        return s1;

    }
};
