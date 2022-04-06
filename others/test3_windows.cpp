#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
/*给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int count = 0;//记录最长字符长度；
        int left = -1;//左指针
        unordered_set<char> single;//记录是否有重复字符串
        for(int right  = 0; right < s.size(); right++){

            
            while(left < right && single.count(s[right]))//相等了就不用再比较了直接right作为新的起点,因此起始时要把left设置为-1.
            {
                single.erase(s[left+1]);
                left++;
            }
            single.insert(s[right]);//这个插入的操作要放在删除之前啊，否则加一个必定可以count它本身
            count = max(count,(right - left));
        }
        return count;

    }
};