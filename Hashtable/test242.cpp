#include<string>
#include<iostream>

using namespace std;
/*给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以不考虑输出结果的顺序 。*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26]={0};
        for(int i =0; i<s.length();i++)
        {
            record[s[i]-'a']++;

        }
        for(int i =0; i<t.length();i++)
        {
            record[t[i]-'a']--;
        }
        for(int i =0; i<26;i++)
        {
            if(record[i] != 0)
            {return false;}

        }
        return true;

    }
};