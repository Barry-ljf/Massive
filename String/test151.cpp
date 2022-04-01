#include<iostream>
#include<string>
using namespace std;
/*给你一个字符串 s ，颠倒字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

*/
//有几个非常关键的点，那就是如果用void函数企图不返回值而直接更改数组，那传过来的应该是指针
//快慢指针并非双层循环，慢指针是在快指针满足一定的条件的时候赋值
//while循环中的++条件必须给++设置一个范围。
class Solution {
public:
    void reverse(string &s,int start,int end){
        for(int i = start, j = end; i<j;i++ , j--)
        {
            swap(s[i],s[j]);
        }
    }
    void removextralSpace(string &s){
            int slow = 0;
            int fast = 0;
            while(s.length() > 0 && s.length() - fast > 0 && s[fast] == ' '){
                fast++;//这个步骤就是为了把单词前面所有的空格走完
            }

            for(;fast<s.length();fast++)  {
                if (fast - 1 > 0//确保初始大于0
                && s[fast - 1] == s[fast]
                && s[fast] == ' ') {
            continue;
        } else {
            s[slow++] = s[fast];
        }
    }
                if(slow-1> 0 && s[slow-1] == ' '){
                    s.resize(slow-1);
                }
                else{
                     s.resize(slow);
                }
       

    }


       void removeExtraSpaces(string& s) {
        int slowIndex = 0, fastIndex = 0; // 定义快指针，慢指针
        // 去掉字符串前面的空格
        while (s.length() > 0 && fastIndex < s.length() && s[fastIndex] == ' ') {
            fastIndex++;
        }
        for (; fastIndex < s.length(); fastIndex++) {
            // 去掉字符串中间部分的冗余空格
            if (fastIndex - 1 > 0
                    && s[fastIndex - 1] == s[fastIndex]
                    && s[fastIndex] == ' ') {
                continue;
            } else {
                s[slowIndex++] = s[fastIndex];
            }
        }
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') { // 去掉字符串末尾的空格
            s.resize(slowIndex - 1);
        } else {
            s.resize(slowIndex); // 重新设置字符串大小
        }
    }
    string reverseWords(string s) {
        removextralSpace(s);
        reverse(s,0,s.length()-1);
        for(int j = 0,i = 0;j<s.length();j++){
        i = j;
        while(j < s.size() && s[j] != ' ')
        {
            j++;
        }
        reverse(s,i,j-1);
        
        }
        return s;
    }
};