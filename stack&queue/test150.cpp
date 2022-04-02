// it is a test
/* 根据 逆波兰表示法，求表达式的值。

有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

注意 两个整数之间的除法只保留整数部分。

可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

*/
#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> expression;
        unordered_set<string> symbol{"+","-","*","/"};
        for(string c : tokens){

        if(symbol.count(c)){
            int result_temp;
            int a = expression.top();
            expression.pop();
            int b = expression.top();
            expression.pop();
            if(c == "+"){result_temp = a+b;}
            else if(c == "-"){result_temp = b-a;}
            else if(c == "*"){result_temp = a*b;}
            else if(c == "/"){result_temp = b/a;}///z这里和减法容易出错啊被减数和被除数
            expression.push(result_temp);

        }else{
            expression.push(stoi(c));
        }


        }
        int result = expression.top();
        return result;
    }
};