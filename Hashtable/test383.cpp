#include<string>
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
    bool canConstruct(string ransomNote, string magazine) {
        int library[26] = {0};//请记住这个写法
        int judge_number = 0;
        for(int i = 0 ; i < magazine.length() ; i++ ){
            library[magazine[i]-'a']++;
        }

        for(int i = 0 ; i < ransomNote.length() ; i++ ){
            library[ransomNote[i]-'a']--;
        }
        for(int i = 0 ; i < ransomNote.length() ; i++ ){
            if(library[ransomNote[i]-'a'] < 0)
            {
                return false;
            }
            // if(library[magazine[i]-'a'] = 0 && ransomNote[i] != 0)
            // {
            //     return true;
            // }
        }
        return true;


    }
};