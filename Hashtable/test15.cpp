#include<string>
#include<iostream>
#include<vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>

/*#include<string>
#include<iostream>
#include<vector>
#include <unordered_set>
/*给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。


*/


using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> result;
       sort(nums.begin(),nums.end());
       for(int i = 0; i<nums.size(); i++)
       {
           if(nums[i] > 0)//排序之后的数组第一个指向正值，后面就不可能在小于0了
           {
               return result;
           }
        //    if(nums[i] == nums[i+1])//这是个错误的检测重复的方法
        //    {
        //        continue;
        //    }
          if(i>0 && nums[i] == nums[i-1])//理论上必须要先尝试一个值之后才去处理重复值
           {
               continue;
           }
           int left = i+1;
           int right = nums.size() - 1;
           while(left < right)
           {    
               if(nums[i]+nums[left]+nums[right] < 0)
               {
                   left++;
                   while(left < right && nums[left] == nums[left-1] )left++;//如果重复继续往后走，仍然是先做完实验在去重，
               }
               else if(nums[i]+nums[left]+nums[right] > 0){
                   right--;
                  while(left < right && nums[right] == nums[right+1]) right--;
               }
               else{
                   result.push_back({nums[i],nums[left],nums[right]});
                   //去重逻辑应该放在找到一个三元组之后
                   //这里对于left < right是为了防止全0的情况？是的
                   while(left < right &&  nums[left] == nums[left+1] ){left++;}
                   while(left < right && nums[right] == nums[right-1]  ){right--;}
                   left++;
                   right--;

               }

               
               



           }
       }
       return result;
    }
};
