#include<string>
#include<iostream>
#include<vector>
#include <unordered_set>
#include <unordered_map>
/*#include<string>
#include<iostream>
#include<vector>
#include <unordered_set>
/*给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。
*/


using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> cmap;
        for(int a :nums1 )
        {
            for(int b : nums2)
            {
                cmap[a+b]++;
            }
        }
            int count = 0;
            for(int c : nums3){
                for(int d : nums4){
                    if(cmap.find(-c-d) != cmap.end())
                    {
                        //count = count + cmap.count(-c-d);//count的是key
                        count = count + cmap[-c-d];
                    }
                }
            }
        return count;

    }
};