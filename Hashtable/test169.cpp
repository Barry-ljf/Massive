#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        int majority = 0,result = 0;
        for(int num: nums){
            ++count[num];
            if(count[num] > majority){
                result  = num;
                majority = count[num];
            }

        }
        return result;

    }
};