#include<string>
#include<iostream>
#include<vector>
#include <unordered_set>
/*编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。



*/

using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> table={89,145,42,20,4,16,37,58};//这个是循环的规律，轻易别这么做哈哈哈哈哈
        
           while(table.find(n) == table.end() && n != 1 )
           {    
               int num = 0;
               while(n)
               {
                   num += (n%10)*(n%10);
                   n=n/10;
               }
               n = num;

           }

            if(table.find(n) != table.end()){
                return false;
            }

       return true;

       
    }
};