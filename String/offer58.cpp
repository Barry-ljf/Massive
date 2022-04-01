// it is a test
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string extract(string s, int n)
    {   
        string a(n,'0');//所有变量的初始化你还是要会的啊！
        for(int i = 0; i < n; i++)
        {
           a[i] = s[i]  ;
        }
        return a;

    }
    string reverseLeftWords(string s, int n) {
        int slow = 0;
        int fast = 0;
        string x = extract(s,n);
        for(;fast < s.length();fast++)
        {
            if(fast<n){
                continue;
            }else if(fast>=n){
                s[slow++] = s[fast];
            }
        }
        
        for(int i = slow,j=0; i<s.length(),j<n ; i++,j++)
        {
            s[i] = x[j];
        }

        return s;
    }
};