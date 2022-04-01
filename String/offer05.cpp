#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        int oldsize = s.size();
        int count = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == ' '){
                count++;
            }
        }
        //int newsize = s.size()+2*count;
        //s.resize(newsize);
        s.resize(s.size()+2*count);
        int newsize = s.size();
        for(int i = oldsize - 1,j = newsize - 1; i < j ; i--,j-- )
        {
            if(s[i] != ' ')
            {
                s[j] = s[i];
            }
            else{
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j = j-2;
            }
        }


        
        return s;


    }
};