#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {//这个思路真的太刁了
     int cover = 0;
     if(nums.size() == 1){
         return true;
     }
     for(int i = 0; i <=cover;i++){//这一个cover表示了他能到的很多地方，动态的改变cover，就是表示在我每一步可达的范围内，我能够扩展的最远距离。
        cover =  max(nums[i]+i,cover);
        if(cover >= nums.size()-1)return true;
     }
     return false;

    }
};

/*以下是你自己的思路，执行不了，很明显的想要看到，是有这个cover的想法在的，就是cover内的所有的值都是你的起点，想要每一个都尝试以下，但是对于该问题来说，确实没必要，且看上述解答，关键就是这个范围如果能够覆盖就可以达成目标*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
    for(int loop : nums){
    for(int i = 0; i<loop;i++){
        //loop = nums[i];
        int position = i;
        while(position < nums.size())
        {
            position = nums[position]+nums[nums[position]+position] ;
            if(position == nums.size()-1)return true;
        }
        

    }
    }
        return false;
    }
};