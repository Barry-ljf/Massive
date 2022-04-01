#include<string>
#include<iostream>
#include<vector>
#include <unordered_set>
/*给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。*/
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> nums_store(nums1.begin(),nums1.end());//这是容器之间的赋值转换的方法，值得学习，可以好好看一看
        for(int item : nums2){//这个语句的意思和python非常的像，item直接替换的就是nums2里面的函数
            if(nums_store.find(item) != nums_store.end())
            {
                result.insert(item);//容器的函数插入
            }
            
        }
        return vector<int>(result.begin(),result.end());//这是容器之间的赋值转换的方法，值得学习，可以好好看一看
    }

};