#include<iostream>
#include<vector>
using namespace std;
/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。


*/
class Solution {
public:
    vector<string> letter_map = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> result;
    string s;
    void Backtracking(string digits,int index){//实际上，我们之前所做的所有的递归，也都是从一个集合选一个，然后从另外一个集合选择下一个，只是说原来的这两个集合是一个而已。

    if(s.size() ==  digits.size()){//当输入的数字都push后就在儿停着
        result.push_back(s);
        return; 
    }
    
    int order = digits[index] - '0';
    string field = letter_map[order];
    for(int i =0 ; i<field.size() ;i++){//从可筛选的范围中一一取值
    s.push_back(field[i]);
    Backtracking(digits,index + 1);//递归的下一层是可选择的第二个集合，不是集合本身了，因此要加1，相应的，对应的加1之后对应的集合也应该随之更改通过map[index]的方式。
    s.pop_back();

    }

    }

    vector<string> letterCombinations(string digits) {
        result.clear();
        if(digits == ""){return result;}

        Backtracking(digits,0);
        return result;

    }
};