#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
/*
nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。

给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。

对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定 nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。

返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。

 

*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> result(nums1.size(),-1);
        unordered_map<int,int> uuu;
        for(int i = 0; i < nums1.size(); i++){
            uuu[nums1[i]] =i;
        }
        stack<int> wocao;
        wocao.push(0);
        for(int i = 0; i < nums2.size(); i++){
            if(nums2[i] == nums2[wocao.top()]){
                wocao.push(i);
            
            }else if(nums2[i] < nums2[wocao.top()]){
                wocao.push(i);
            }else{
                while(!wocao.empty() && nums2[i] > nums2[wocao.top()]){
                    if(uuu.count(nums2[wocao.top()])){
                        int index = uuu[nums2[wocao.top()]];//nums2[wocao.top()]这个地方容易忽略啊，切记！索引的是栈顶的元素，当前遍历的是比栈顶元素右边大的值啊！
                        result[index] = nums2[i];
                    }
                    wocao.pop();
                }
                wocao.push(i);
            }


        }
        return result;


        //目前见到的两个单调栈的问题都可以使用两层for循环去做，因此我们遇见单调栈的问题不要慌。
        // vector<int> result(nums1.size(),-1);
        // for(int i = 0 ; i< nums1.size(); i++){
        //     int findindex ;
        //     for(int j = 0 ; j < nums2.size();j++ ){
        //         if(nums2[j] == nums1[i]){findindex = j;}
        //     }
        //     for(int j = findindex;j < nums2.size();j++)
        //     {
        //         if(nums2[j] > nums1[i]){
        //             result[i] = nums2[j];
        //             break;
        //         }
        //     }
        // }
        // return result;
    }
};

