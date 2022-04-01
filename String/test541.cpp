#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.length(); i += 2*k)
        {
            if((s.length() - i) >= k){
                for(int j = i, q = j + k-1 ;j < q;j++,q--)
                {
                    swap(s[j],s[q]);
                    
                }
            }

            else {

                for(int j = i, q = s.length()-1;j < q;j++,q--)
                swap(s[j],s[q]);
            }
            
        }return s;

    }
};